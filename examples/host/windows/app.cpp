#include "../../app.hpp"

#include <SDKDDKVer.h>
#include <windows.h>
#include <gl/gl.h>
#include "gl/glext.h"
#include "gl/wglext.h"

# include "GrContext.h"
# include "gl/GrGLInterface.h"
# include "SkImage.h"
# include "SkSurface.h"

# include "SkBitmap.h"
# include "SkData.h"
# include "SkImage.h"
# include "SkPicture.h"
# include "SkSurface.h"
# include "SkCanvas.h"
# include "SkPath.h"
# include "GrBackendSurface.h"

constexpr auto sizex = 640;
constexpr auto sizey = 480;
constexpr unsigned IDT_TIMER1 = 100;

class Window {
public:
	LPTSTR windowClass;	// Window Class
	HGLRC RC;			// Rendering Context
	HDC	DC;				// Device Context
	HWND WND;			// Window
	DWORD style;

	struct Config {
		int width;
		int	height;
		int posX;
		int posY;
		bool windowed;
	} config;

	Window();
	~Window();
	void showMessage(LPCWSTR message);
	int create(HINSTANCE hInstance, int nCmdShow);
	ATOM registerClass(HINSTANCE hInstance);
	void adjustSize();
	void center();
	void render();
	void swapBuffers();
	void destroy();
	static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:

};



///////////////////////////////////////////////////////////

Window::Window() {

	config.width = sizex;
	config.height = sizey;
	config.posX = CW_USEDEFAULT;
	config.posY = 0;
	config.windowed = true;
	style = WS_CAPTION | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
}

///////////////////////////////////////////////////////////

Window::~Window() {
}

///////////////////////////////////////////////////////////

void Window::showMessage(LPCWSTR message) {

	MessageBox(0, message, L"Window::create", MB_ICONERROR);
}

///////////////////////////////////////////////////////////

int Window::create(HINSTANCE hInstance, int nCmdShow) {

	windowClass = MAKEINTATOM(registerClass(hInstance));
	if (windowClass == 0) {
		showMessage(L"registerClass() failed.");
		return 1;
	}

	// create temporary window

	HWND fakeWND = CreateWindow(
		windowClass, L"Fake Window",
		style,
		0, 0,						// position x, y
		1, 1,						// width, height
		NULL, NULL,					// parent window, menu
		hInstance, NULL);			// instance, param

	HDC fakeDC = GetDC(fakeWND);	// Device Context

	PIXELFORMATDESCRIPTOR fakePFD;
	ZeroMemory(&fakePFD, sizeof(fakePFD));
	fakePFD.nSize = sizeof(fakePFD);
	fakePFD.nVersion = 1;
	fakePFD.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	fakePFD.iPixelType = PFD_TYPE_RGBA;
	fakePFD.cColorBits = 32;
	fakePFD.cAlphaBits = 8;
	fakePFD.cDepthBits = 24;

	const int fakePFDID = ChoosePixelFormat(fakeDC, &fakePFD);
	if (fakePFDID == 0) {
		showMessage(L"ChoosePixelFormat() failed.");
		return 1;
	}

	if (SetPixelFormat(fakeDC, fakePFDID, &fakePFD) == false) {
		showMessage(L"SetPixelFormat() failed.");
		return 1;
	}

	HGLRC fakeRC = wglCreateContext(fakeDC);	// Rendering Contex

	if (fakeRC == 0) {
		showMessage(L"wglCreateContext() failed.");
		return 1;
	}

	if (wglMakeCurrent(fakeDC, fakeRC) == false) {
		showMessage(L"wglMakeCurrent() failed.");
		return 1;
	}

	// get pointers to functions (or init opengl loader here)

	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
	wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
	if (wglChoosePixelFormatARB == nullptr) {
		showMessage(L"wglGetProcAddress() failed.");
		return 1;
	}

	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
	wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
	if (wglCreateContextAttribsARB == nullptr) {
		showMessage(L"wglGetProcAddress() failed.");
		return 1;
	}

	if (config.windowed == true) {
		adjustSize();
		center();
	}

	// create a new window and context

	WND = CreateWindow(
		windowClass, L"OpenGL Window",	// class name, window name
		style,							// styles
		config.posX, config.posY,		// posx, posy. If x is set to CW_USEDEFAULT y is ignored
		config.width, config.height,	// width, height
		NULL, NULL,						// parent window, menu
		hInstance, NULL);				// instance, param

	DC = GetDC(WND);

	const int pixelAttribs[] = {
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_ALPHA_BITS_ARB, 8,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
		WGL_SAMPLES_ARB, 4,
		0
	};

	int pixelFormatID; UINT numFormats;
	const bool status = wglChoosePixelFormatARB(DC, pixelAttribs, NULL, 1, &pixelFormatID, &numFormats);

	if (status == false || numFormats == 0) {
		showMessage(L"wglChoosePixelFormatARB() failed.");
		return 1;
	}

	PIXELFORMATDESCRIPTOR PFD;
	DescribePixelFormat(DC, pixelFormatID, sizeof(PFD), &PFD);
	SetPixelFormat(DC, pixelFormatID, &PFD);

	const int major_min = 4, minor_min = 0;
	const int contextAttribs[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, major_min,
		WGL_CONTEXT_MINOR_VERSION_ARB, minor_min,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
//		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
		0
	};

	RC = wglCreateContextAttribsARB(DC, 0, contextAttribs);
	if (RC == NULL) {
		showMessage(L"wglCreateContextAttribsARB() failed.");
		return 1;
	}

	// delete temporary context and window

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(fakeRC);
	ReleaseDC(fakeWND, fakeDC);
	DestroyWindow(fakeWND);
	if (!wglMakeCurrent(DC, RC)) {
		showMessage(L"wglMakeCurrent() failed.");
		return 1;
	}

	// init opengl loader here (extra safe version)

	SetWindowText(WND, L"GL Version" /*reinterpret_cast<LPCSTR>(glGetString(GL_VERSION))*/);
	ShowWindow(WND, nCmdShow);


   SetWindowLongPtrW(WND, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

   // Create 16ms (60Hz) timer
   // SetTimer(WND, IDT_TIMER1, 16, (TIMERPROC) nullptr);


	return 0;
}

///////////////////////////////////////////////////////////

ATOM Window::registerClass(HINSTANCE hInstance) {

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = WindowProcedure;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszClassName = L"Core";

	return RegisterClassEx(&wcex);
}

///////////////////////////////////////////////////////////
// Adjust window's size for non-client area elements
// like border and title bar

void Window::adjustSize() {

	RECT rect = { 0, 0, config.width, config.height };
	AdjustWindowRect(&rect, style, false);
	config.width = rect.right - rect.left;
	config.height = rect.bottom - rect.top;
}

///////////////////////////////////////////////////////////

void Window::center() {

	RECT primaryDisplaySize;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &primaryDisplaySize, 0);	// system taskbar and application desktop toolbars not included
	config.posX = (primaryDisplaySize.right - config.width) / 2;
	config.posY = (primaryDisplaySize.bottom - config.height) / 2;
}

///////////////////////////////////////////////////////////

void Window::render() {

	// glClearColor(0.0f, 0.0f, 1.0f, 1.0f);	// rgb(33,150,243)
	// glClear(GL_COLOR_BUFFER_BIT);

   auto interface = GrGLMakeNativeInterface();
   sk_sp<GrContext> ctx = GrContext::MakeGL(interface);

   GrGLint buffer;
   glGetIntegerv(GL_FRAMEBUFFER_BINDING, &buffer);
   GrGLFramebufferInfo info;
   info.fFBOID = (GrGLuint) buffer;
   SkColorType colorType = kRGBA_8888_SkColorType;

   info.fFormat = GL_RGBA8;
   GrBackendRenderTarget target(sizex, sizey, 0, 8, info);

   sk_sp<SkSurface> surface(
      SkSurface::MakeFromBackendRenderTarget(ctx.get(), target,
      kBottomLeft_GrSurfaceOrigin, colorType, nullptr, nullptr));

   if (!surface)
      throw std::runtime_error("Error: SkSurface::MakeRenderTarget returned null");

   SkCanvas* canvas = surface->getCanvas();

   canvas->clear(SK_ColorRED);

   SkPaint paint;
   paint.setColor(SK_ColorBLUE);

   SkRect rect = SkRect::MakeXYWH(10, 10, 128, 128);
   canvas->drawRect(rect, paint);

   //SkPath path;
   //path.addRect({ 10, 10, 128, 128 });
   //canvas->drawPath(path, paint);

    canvas->flush();

}

///////////////////////////////////////////////////////////

void Window::swapBuffers() {

	SwapBuffers(DC);
}

///////////////////////////////////////////////////////////

void Window::destroy() {

	wglMakeCurrent(NULL, NULL);
	if (RC) {
		wglDeleteContext(RC);
	}
	if (DC) {
		ReleaseDC(WND, DC);
	}
	if (WND) {
		DestroyWindow(WND);
	}

   // KillTimer(WND, IDT_TIMER1);
}

///////////////////////////////////////////////////////////

LRESULT CALLBACK Window::WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	auto param = GetWindowLongPtrW(hWnd, GWLP_USERDATA);
	Window* window = reinterpret_cast<Window*>(param);

	switch (message) {
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
			// KillTimer(WND, IDT_TIMER1);
		}
		break;

	case WM_CLOSE:
		PostQuitMessage(0);
		// KillTimer(WND, IDT_TIMER1);
		break;

	// case WM_TIMER:
	// 	{
	// 		window->render();
	// 		window->swapBuffers();
	// 	}
   //       break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;		// message handled
}

namespace cycfi::artist
{
   void init_paths()
   {
      // // Before anything else, set the working directory so we can access
      // // our resources
      // char resource_path[PATH_MAX];
      // get_resource_path(resource_path);
      // add_search_path(resource_path);
   }
}

int run_app(
   int argc
 , const char* argv[]
 , extent window_size
 , color bkd
 , bool animate
)
{
   Window window;

	if (window.create(nullptr, true) != 0) {
		PostQuitMessage(1);
	}

	MSG msg;
	bool active = true;
	while (active) {
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				active = false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		window.render();
		window.swapBuffers();
	}
	window.destroy();

	return msg.wParam;

	// return 0;
}

void stop_app()
{
}


