#include "console.h"

void init_ConsoleSystem()
{
  StringConstructorOptionValues[0] = "\n";
  StringConstructorOptionValues[1] = "\n\n";
  StringConstructorOptionValues[2] = "\t";
  StringConstructorOptionValues[3] = "";
}

StringConstructor* init_StringConstructor()
{
  StringConstructor* builder = malloc(sizeof(struct StringConstructor) + sizeof(char));
  builder->StringBuild = malloc(sizeof(char));
  builder->StringBuild = "\r";
  return(builder);
}

void addToStringConstructor(StringConstructor** constructor, const char* str, enum StringConstructorOption option)
{
  if((*constructor)->StringBuild != NULL)
  {
    char* new_string = concat_string((*constructor)->StringBuild, str);
    (*constructor)->StringBuild = concat_string(new_string, StringConstructorOptionValues[(int)option]);
  }
}

void AcquireStdOutHandle() { hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); }

HANDLE GET_hStdOut() { return(hStdOut); }

void Write_CommandLineHelpMenu()
{
    StringConstructor* constructor = init_StringConstructor();

    WriteToConsole("\n\033[1;35m");
    addToStringConstructor(&constructor, "  w = move forward", NEWLINE);
    addToStringConstructor(&constructor, "  a = move left", NEWLINE);
    addToStringConstructor(&constructor, "  s = move back", NEWLINE);
    addToStringConstructor(&constructor, "  d = move right", DOUBLENEWLINE);

    addToStringConstructor(&constructor, "  1 = select previous entity", NEWLINE);
    addToStringConstructor(&constructor, "  2 = select next entity", DOUBLENEWLINE);

    addToStringConstructor(&constructor, "  arrow-up = rotate upwards", NEWLINE);
    addToStringConstructor(&constructor, "  arrow-left = rotate left", NEWLINE);
    addToStringConstructor(&constructor, "  arrow-down = rotate down", NEWLINE);
    addToStringConstructor(&constructor, "  arrow-right = rotate right", DOUBLENEWLINE);

    addToStringConstructor(&constructor, "  r = reset all data of selected entity", NEWLINE);
    addToStringConstructor(&constructor, "  t = reset all data of worlds entities", NEWLINE);
    addToStringConstructor(&constructor, "  y = reset all data of player entity", DOUBLENEWLINE);

    addToStringConstructor(&constructor, "  q = decrement x-scale of current selected entity", NEWLINE);
    addToStringConstructor(&constructor, "  e = increment x-scale of current selected entity", DOUBLENEWLINE);

    addToStringConstructor(&constructor, "  - = decrement ambience of world by 0.1 (lower limit 0.6)[DEFAULT 1.0][stepping(0.1)]", NEWLINE);
    addToStringConstructor(&constructor, "  + = increment ambience of world by 0.1 (upper limit 2.0)[DEFAULT 1.0][stepping(0.1)]", DOUBLENEWLINE);

    addToStringConstructor(&constructor, "  F1 = decrement x-scale of all worlds entities", NEWLINE);
    addToStringConstructor(&constructor, "  F2 = increment x-scale of all worlds entities", NEWLINE);

    WriteToConsole(constructor->StringBuild);
    WriteToConsole("\033[0m\n");
}

DWORD WriteToConsole(const char* buffer)
{
  AcquireStdOutHandle();
  if (hStdOut != NULL && hStdOut != INVALID_HANDLE_VALUE)
  {
      FlushConsoleInputBuffer(hStdOut);
      DWORD written = 0;
      WriteConsoleA(hStdOut, buffer, (DWORD)get_cstrlen(buffer), &written, NULL);
      return(written);
  }
  return(0);
}
