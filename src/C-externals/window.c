#include "window.h"
#include "parser.h"

volatile struct blist *bodylist_mem;
LPCRITICAL_SECTION crit_section;

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
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    16,
    0, 0,
    PFD_MAIN_PLANE,
    0,
    0, 0, 0
  };

  switch(message)
  {
      case WM_DESTROY:
        CloseHandle(GET_hStdOut());
        FreeConsole();
        PostQuitMessage(0);
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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
  configurations.WIDTH = 1920.0f;
  configurations.HEIGHT = 1080.0f;

  char line[256];
  FILE* CameraSettingsFile = fopen("../Resource Files/configurations/CameraSettings.cfg", "r");
  if (CameraSettingsFile == NULL)
  {
    printf("The CameraSettings.cfg file did not open\n");
    return 16;
  }

  while (fgets(line, sizeof(line), CameraSettingsFile))
  {
    switch(line[0])
    {
      case 'R':
        MoveMemory(line, line+20, (size_t)get_strlen(line) - 20 + 1);
        configurations.RenderDistance = atoi(line);
        break;
      case 'f':
        MoveMemory(line, line+8, (size_t)get_strlen(line) - 8 + 1);
        configurations.fov = atoi(line);
        break;
      case 'N':
        MoveMemory(line, line+14, (size_t)get_strlen(line) - 14 + 1);
        configurations.nearestZ = (float)atof(line);
        break;
      case 'F':
        MoveMemory(line, line+14, (size_t)get_strlen(line) - 14 + 1);
        configurations.farthestZ = (float)atof(line);
        break;
    }
  }
  fclose(CameraSettingsFile);

  FILE* WorldSettingsFile = fopen("../Resource Files/configurations/WorldSettings.cfg", "r");
  if (WorldSettingsFile == NULL)
  {
    printf("The WorldSettings.cfg file did not open\n");
    return 16;
  }

  while (fgets(line, sizeof(line), WorldSettingsFile))
  {
    switch(line[0])
    {
      case 'C':
        MoveMemory(line, line+20, get_strlen(line) - 20 + 1);
        configurations.CHUNK_XYZ_SIZE = atoi(line);
        configurations.CHUNK_AREA = configurations.CHUNK_XYZ_SIZE * configurations.CHUNK_XYZ_SIZE;
        configurations.CHUNK_VOLUME = configurations.CHUNK_XYZ_SIZE * configurations.CHUNK_XYZ_SIZE * configurations.CHUNK_XYZ_SIZE;
        break;
      case 'O':
        MoveMemory(line, line+19, get_strlen(line) - 19 + 1);
        configurations.octaves_noise = atoi(line);
        break;
      case 'A':
        MoveMemory(line, line+21, get_strlen(line) - 21 + 1);
        configurations.amplitude_noise = (float)atof(line);
        break;
      case 'F':
        MoveMemory(line, line+21, get_strlen(line) - 21 + 1);
        configurations.frequency_noise = (float)atof(line);
        break;
      case 'N':
        MoveMemory(line, line+22, get_strlen(line) - 22 + 1);
        configurations.normalized_noise = atoi(line);
        break;
      case 'T':
        MoveMemory(line, line+20, get_strlen(line) - 20 + 1);
        configurations.terrain_render = atoi(line);
        break;
      case 'B':
        MoveMemory(line, line+19, get_strlen(line) - 19 + 1);
        configurations.blocky_render = atoi(line);
        break;
      case 'M':
        MoveMemory(line, line+18, get_strlen(line) - 18 + 1);
        configurations.model_render = atoi(line);
        break;
      case 'E':
        MoveMemory(line, line+22, get_strlen(line) - 22 + 1);
        configurations.efficient_render = atoi(line);
        break;
    }
  }
  fclose(WorldSettingsFile);

  configurations.tanHalfFOV = (float)tan(degreesToRadians(configurations.fov) / 2.0);
  configurations.aspectRatio = configurations.WIDTH / configurations.HEIGHT;
  configurations.scale = 1.0f / (float)tan(configurations.fov * 0.5f * GHOSTYMATH_PI / 180.0f);

  //init_ModuleSystem();
  //init_ComponentSystem();
  init_NoiseGenerator();
  init_PerlinGenerator();

  const wchar_t CLASS_NAME[]  = L"VoxelEngine";
  LPCWSTR TITLE = L"TestWindow";

  WNDCLASS classStruct = { 0 };

  classStruct.style =  CS_HREDRAW
                     | CS_VREDRAW
                     | CS_OWNDC;
  classStruct.lpfnWndProc = WndProc;
  classStruct.hInstance = hInstance;
  classStruct.lpszClassName = CLASS_NAME;

  if(!RegisterClass(&classStruct))
  {
    MessageBoxW(0,
             L"CALL TO REGISTERCLASS FAILED",
             L"-=ERROR=-",
             MB_OK | MB_ICONERROR);
    return FALSE;
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

  WindowHandle = hwnd;

  uintVector_Push(&programIDs, glCreateProgram());
  uintVector_Push(&programIDs, glCreateProgram());

  GLuint vertexShader = set_Shader(programIDs->values[0], "../Resource Files/shaders/voxelVertexShader.glsl", VERTEX);
  GLuint geometryShader = set_Shader(programIDs->values[0], "../Resource Files/shaders/voxelGeometryShader.glsl", GEOMETRY);
  GLuint fragmentShader = set_Shader(programIDs->values[0], "../Resource Files/shaders/voxelFragmentShader.glsl", FRAGMENT);

  glLinkProgram(programIDs->values[0]);
  glUseProgram(programIDs->values[0]);

  GLuint vertexPostProcessShader = set_Shader(programIDs->values[1], "../Resource Files/shaders/vertexPostProcShader.glsl", VERTEX);
  GLuint fragmentPostProcessShader = set_Shader(programIDs->values[1], "../Resource Files/shaders/fragmentPostProcShader.glsl", FRAGMENT);

  glLinkProgram(programIDs->values[1]);

  glGenTextures(1, &textures[0]);
  glBindTexture(GL_TEXTURE_2D, textures[0]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
  glGenerateMipmap(GL_TEXTURE_2D);

    glActiveTexture(GL_TEXTURE_2D);

  //glBindFramebuffer(GL_FRAMEBUFFER, 0);
  //glBindRenderbuffer(GL_RENDERBUFFER, 0);

  /*
  glBlitFramebuffer(0, 0, width, height,
                    0, 0, smallWidth, smallHeight,
                    GL_COLOR_BUFFER_BIT, GL_LINEAR);
  */

  //GLuint textureID;
  //glGenTextures(1, &textureID);

  // "Bind" the newly created texture : all future texture functions will modify this texture
  //glBindTexture(GL_TEXTURE_2D, textureID);

  // Give the image to OpenGL
  //glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  /*const GLubyte* extensions = glGetString(GL_EXTENSIONS);
  printf("%s", extensions);*/

  m4_projViewMatrix = make_projViewMatrix();
  m4_MVPMatrix = make_MVPMatrix();
  load_MVPMatrix();

  LARGE_INTEGER timeNow, timePrev;
  LARGE_INTEGER Frequency;

  QueryPerformanceFrequency(&Frequency);

  setup_world();
  /*
  CreateAndLoadCollider(new_vec3(16, 0, 0), new_vec3(16, 16, 0),
                        new_vec3(0, 0, 0), new_vec3(0, 16, 0),
                        new_vec3(16, 0, 16), new_vec3(16, 16, 16),
                        new_vec3(0, 0, 16), new_vec3(0, 16, 16));
  */

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
          PostMessage(hwnd, WM_CLOSE, 0, 0);
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

void GH_InitWindow(int (*EntryPoint)(), char* path)
{
  if(WindowStatus != RUNNING)
  {
    init_ConsoleSystem();
    Write_CommandLineHelpMenu();
    ComponentsThreads = new_dynHandleArray();

    struct blist bodylist = get_body_from_json(path);
    //LoadPlanetProperties();
    //struct bodies bodylist = *GetBodyList();

    if (!InitializeCriticalSectionAndSpinCount(&crit_section, 0x80000400))
    {
        printf("Critical section did not initialize!");
        printf("%lu", GetLastError());
    }

    bodylist_mem = malloc(sizeof(bodylist));
    if (bodylist_mem == NULL)
    {
      free((struct blist*)bodylist_mem);
    }
    memcpy((struct blist*)bodylist_mem, &bodylist, sizeof(bodylist));

    struct ENTRYPOINT_INPUT* input = malloc(sizeof(struct ENTRYPOINT_INPUT));
    if (input == NULL)
    {
      free(input);
    }

    input->bodylist = bodylist;
    input->shared_mem = bodylist_mem;
    input->crit_section = &crit_section;


    HANDLE ENTRYPOINT = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)EntryPoint, input, 0, NULL);

    dynHandleArray_AddBack(&ComponentsThreads, CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)wWinMain, NULL, 0, NULL));
    dynHandleArray_AddBack(&ComponentsThreads, ENTRYPOINT);

    WriteEventSignal = CreateEvent(
        NULL,                // default security attributes
        TRUE,                // manual-reset event
        FALSE,               // initial state is nonsignaled
        TEXT("ResetSignal")  // object name
    );

    WindowStatus = RUNNING;

    SetEvent(WriteEventSignal);
    WaitForMultipleObjects(ComponentsThreads->size, ComponentsThreads->handles, TRUE, INFINITE);
  }
}
