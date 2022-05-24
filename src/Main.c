#include "window.h"
#include "worldManager.component.h"

int physics_thread(struct ENTRYPOINT_INPUT* input)
{
  volatile struct blist* shared_mem = input->shared_mem;
  struct blist bodylist = input->bodylist;
  LPCRITICAL_SECTION* crit_section = input->CRIT_SECTION;

  free(input);

  while(1)
  {
    bodylist = ProcessPhysics(&bodylist);
    BOOL res = TryEnterCriticalSection(crit_section);
    if (res == 0)
    {
        continue;
    }
    memcpy(shared_mem->planets, bodylist.planets, sizeof(struct body) * bodylist.size);
    LeaveCriticalSection(crit_section);
  }

  return 86; //haha yes
}

int main(int argc, char** argv)
{
  char* path;

  if (argc >= 2)
  {
    path = malloc(sizeof(argv[1]));
    path = argv[1];
  }
  else
  {
      path = "../../Sol_6_body.json";
  }

  //Build.exe = 9 char
  //This is horrible, but Windows has poor LPWSTR to char* conversation and its documentation leaves much to be desired.
  char* abs_path = argv[0];
  abs_path[strlen(abs_path) - 9] = 0x00;

  char* f_path = concat_string(abs_path, path);
  
  GH_InitWindow(physics_thread, f_path);

  return 0;
}
