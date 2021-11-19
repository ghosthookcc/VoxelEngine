#include "window.h"

LRESULT CALLBACK WndProc(HWND hwnd,
                         unsigned int message,
                         WPARAM wParam, LPARAM lParam)
{
  RECT Screen;
  GLuint PixelFormat;
  static PIXELFORMATDESCRIPTOR pfd =
  {
    sizeof(PIXELFORMATDESCRIPTOR),
    1,
    PFD_DRAW_TO_WINDOW |
    PFD_SUPPORT_OPENGL |
    PFD_DOUBLEBUFFER,
    PFD_TYPE_RGBA,
    16,
    0, 0, 0, 0, 0, 0,
    0,
    0,
    0,
    0, 0, 0, 0,
    16,
    0,
    0,
    PFD_MAIN_PLANE,
    0,
    0, 0, 0
  };

  switch(message)
  {
      case WM_DESTROY:
      case WM_CLOSE:
          ChangeDisplaySettings(NULL, 0);

          wglDeleteContext(hRC);
          ReleaseDC(hwnd, hDC);

          DestroyWindow(hwnd);
          PostQuitMessage(0);
          break;
      case WM_CREATE:
          hDC = GetDC(hwnd);

          if(!hDC)
          {
            MessageBoxW(0,
                       L"CALL TO GETDC FAILED",
                       L"-=ERROR=-",
                       MB_OK | MB_ICONERROR);
            PostQuitMessage(0);

            return FALSE;
          }

          PixelFormat = ChoosePixelFormat(hDC, &pfd);
          if(!PixelFormat)
          {
            MessageBoxW(0,
                       L"CALL TO CHOOSEPIXELFORMAT FAILED",
                       L"-=ERROR=-",
                       MB_OK | MB_ICONERROR);
            PostQuitMessage(0);

            return FALSE;
          }
          if(!SetPixelFormat(hDC, PixelFormat, &pfd))
          {
            MessageBoxW(0,
                       L"CALL TO SETPIXELFORMAT FAILED",
                       L"-=ERROR=-",
                       MB_OK | MB_ICONERROR);
            PostQuitMessage(0);

            return FALSE;
          }

          hRC = wglCreateContext(hDC);
          if(!hRC)
          {
            MessageBoxW(0,
                       L"CALL TO WGLCREATECONTEXT FAILED",
                       L"-=ERROR=-",
                       MB_OK | MB_ICONERROR);
            PostQuitMessage(0);

            return FALSE;
          }
          if(!wglMakeCurrent(hDC, hRC))
          {
            MessageBoxW(0,
                       L"CALL TO WGLMAKECURRENT FAILED",
                       L"-=ERROR=-",
                       MB_OK | MB_ICONERROR);
            PostQuitMessage(0);

            return FALSE;
          }

          GetClientRect(hwnd, &Screen);
          glInit(Screen.right, Screen.bottom);
          break;
      default:
          return DefWindowProc(hwnd, message, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain()
{
  HINSTANCE hInstance = NULL;
  HINSTANCE hPrevInstance = NULL;
  LPSTR lpCmdLine = 0;
  int nCmdShow = SW_SHOW;

  configurations.WIDTH = 1920.0f;
  configurations.HEIGHT = 1080.0f;

  configurations.RenderDistance = 16;
  configurations.fov = 45.0f;
  configurations.tanHalfFOV = (float)tan(degreesToRadians(configurations.fov) / 2.0);
  configurations.aspectRatio = configurations.WIDTH / configurations.HEIGHT;

  configurations.nearestZ = 0.1f;
  configurations.farthestZ = 1000.0f;

  LPCWSTR CLASS_NAME = L"VoxelEngine";
  LPCWSTR TITLE = L"TestWindow";

  WNDCLASSEXW classStruct = {0};

  classStruct.cbSize = sizeof(WNDCLASSEXW);
  classStruct.style =  CS_HREDRAW
                       | CS_VREDRAW
                       | CS_OWNDC;
  classStruct.lpfnWndProc = (WNDPROC)WndProc;
  classStruct.cbClsExtra = 0;
  classStruct.cbWndExtra = 0;
  classStruct.hInstance = hInstance;
  classStruct.hIcon = NULL;
  classStruct.hCursor = NULL;
  classStruct.hbrBackground = NULL;
  classStruct.lpszMenuName = NULL;
  classStruct.lpszClassName = CLASS_NAME;
  classStruct.hIconSm = NULL;

  if(!RegisterClassEx(&classStruct))
  {
    MessageBoxW(0,
             L"CALL TO REGISTERCLASS FAILED",
             L"-=ERROR=-",
             MB_OK | MB_ICONERROR);
  }

  HWND hwnd = CreateWindowEx(
      0,
      CLASS_NAME,
      TITLE,

      WS_OVERLAPPEDWINDOW | WS_VISIBLE,

      CW_USEDEFAULT, CW_USEDEFAULT,
      (int)configurations.WIDTH, (int)configurations.HEIGHT,

      NULL,
      NULL,
      hInstance,
      NULL
  );

  if(!hwnd)
  {
    MessageBoxW(0,
               L"CALL TO CREATEWINDOW FAILED",
               L"-=ERROR=-",
               MB_OK | MB_ICONERROR);

    return FALSE;
  }

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);
  SetFocus(hwnd);
  wglMakeCurrent(hDC, hRC);
  initGLFuncs();

  uintVector_Push(&programIDs, glCreateProgram());

  GLuint vertexShader = set_Shader(programIDs->values[0], "../Resource Files/shaders/voxelVertexShader.glsl", VERTEX);
  GLuint geometryShader = set_Shader(programIDs->values[0], "../Resource Files/shaders/voxelGeometryShader.glsl", GEOMETRY);
  GLuint fragmentShader = set_Shader(programIDs->values[0], "../Resource Files/shaders/voxelFragmentShader.glsl", FRAGMENT);

  glLinkProgram(programIDs->values[0]);
  glUseProgram(programIDs->values[0]);

  m4_projViewMatrix = make_projViewMatrix();
  m4_MVPMatrix = make_MVPMatrix();
  load_MVPMatrix();

  LARGE_INTEGER timeNow, timePrev;
  LARGE_INTEGER Frequency;

  QueryPerformanceFrequency(&Frequency);

  Mesh testmesh1;
  Mesh testmesh2;

  float vertices[] =
  {
    -0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,

    -0.5f, 0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,

    0.5f, 0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,

    -0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,

    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, 0.5f,
  };

  float vertices2[] =
  {
    -0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,

    -0.5f, 0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,

    0.5f, 0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,

    -0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,

    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, 0.5f,
  };

  unsigned char indices[] =
  {
    0, 1, 3,
    3, 1, 2,
    4, 5, 7,
    7, 5, 6,
    8, 9, 11,
    11, 9, 10,
    12, 13, 15,
    15, 13, 14,
    16, 17, 19,
    19, 17, 18,
    20,
  };

  unsigned char indices2[] =
  {
    0, 1, 3,
    3, 1, 2,
    4, 5, 7,
    7, 5, 6,
    8, 9, 11,
    11, 9, 10,
    12, 13, 15,
    15, 13, 14,
    16, 17, 19,
    19, 17, 18,
    20,
  };

  testmesh1.vertices = new_DynFloatArrayFromFloatArray(vertices, 60);
  testmesh1.edges = new_DynUByteArrayFromUByteArray(indices, 31);

  testmesh2.vertices = new_DynFloatArrayFromFloatArray(vertices2, 60);
  testmesh2.edges = new_DynUByteArrayFromUByteArray(indices2, 31);

  loadToVAO(testmesh1);
  loadToVAO(testmesh2);

  MSG message = {0};
  int running = 1;

  while(WindowStatus == RUNNING)
  {
    if (GetKeyState(VK_ESCAPE) & 0x8000)
    {
      running = 0;

      message.message = WM_QUIT;

      TranslateMessage(&message);
      DispatchMessage(&message);
    }

    while(PeekMessage(&message, 0, 0, 0, PM_REMOVE))
    {
      if(message.message == WM_QUIT)
      {
          running = 0;
      }

      TranslateMessage(&message);
      DispatchMessage(&message);
    }

    QueryPerformanceCounter(&timeNow);

    Update();
    Render();

    SwapBuffers(hDC);

    QueryPerformanceCounter(&timePrev);

    DeltaTime.QuadPart = timePrev.QuadPart - timeNow.QuadPart;
    DeltaTime.QuadPart *= 1000000;
    DeltaTime.QuadPart /= Frequency.QuadPart;
  }

  WindowStatus = STOPPED;

  CLEANUP();
  unset_Shader();
  glDeleteProgram(programIDs->values[0]);

  return 0;
}

void GH_InitWindow(void (*EntryPoint)())
{
  if(WindowStatus != RUNNING)
  {
    ComponentsThreads = new_dynHandleArray();
    dynHandleArray_Add(&ComponentsThreads, CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)EntryPoint, NULL, 0, NULL));
    dynHandleArray_Add(&ComponentsThreads, CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WinMain, NULL, 0, NULL));

    WriteEventSignal = CreateEvent(
        NULL,                // default security attributes
        TRUE,                // manual-reset event
        FALSE,               // initial state is nonsignaled
        TEXT("ResetSignal")  // object name
    );

    init_ComponentSystem();
    init_ModuleSystem();

    WindowStatus = RUNNING;

    SetEvent(WriteEventSignal);
    WaitForMultipleObjects(ComponentsThreads->size, ComponentsThreads->handles, TRUE, INFINITE);
  }
}
