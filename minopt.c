typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct _s_HandlerType _s_HandlerType, *P_s_HandlerType;

typedef struct _s_HandlerType HandlerType;

typedef struct TypeDescriptor TypeDescriptor, *PTypeDescriptor;

typedef int ptrdiff_t;

struct TypeDescriptor {
    void *pVFTable;
    void *spare;
    char name[0];
};

struct _s_HandlerType {
    uint adjectives;
    struct TypeDescriptor *pType;
    ptrdiff_t dispCatchObj;
    void *addressOfHandler;
};

typedef struct CLIENT_ID CLIENT_ID, *PCLIENT_ID;

struct CLIENT_ID {
    void *UniqueProcess;
    void *UniqueThread;
};

typedef struct _s_UnwindMapEntry _s_UnwindMapEntry, *P_s_UnwindMapEntry;

typedef struct _s_UnwindMapEntry UnwindMapEntry;

typedef int __ehstate_t;

struct _s_UnwindMapEntry {
    __ehstate_t toState;
    void (*action)(void);
};

typedef struct _s_TryBlockMapEntry _s_TryBlockMapEntry, *P_s_TryBlockMapEntry;

struct _s_TryBlockMapEntry {
    __ehstate_t tryLow;
    __ehstate_t tryHigh;
    __ehstate_t catchHigh;
    int nCatches;
    HandlerType *pHandlerArray;
};

typedef struct _s_FuncInfo _s_FuncInfo, *P_s_FuncInfo;

typedef struct _s_FuncInfo FuncInfo;

typedef struct _s_TryBlockMapEntry TryBlockMapEntry;

struct _s_FuncInfo {
    uint magicNumber_and_bbtFlags;
    __ehstate_t maxState;
    UnwindMapEntry *pUnwindMap;
    uint nTryBlocks;
    TryBlockMapEntry *pTryBlockMap;
    uint nIPMapEntries;
    void *pIPToStateMap;
};

typedef struct _cpinfo _cpinfo, *P_cpinfo;

typedef uint UINT;

typedef uchar BYTE;

struct _cpinfo {
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
};

typedef struct _cpinfo *LPCPINFO;

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME *LPFILETIME;

typedef ulong DWORD;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef int (*FARPROC)(void);

typedef DWORD *LPDWORD;

typedef ushort WORD;

typedef WORD *LPWORD;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

struct HINSTANCE__ {
    int unused;
};

typedef struct _FILETIME FILETIME;

typedef int BOOL;

typedef BOOL *LPBOOL;

typedef struct HINSTANCE__ *HINSTANCE;

typedef void *LPCVOID;

typedef void *LPVOID;

typedef HINSTANCE HMODULE;

typedef BYTE *LPBYTE;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef struct _iobuf FILE;

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef union _union_518 _union_518, *P_union_518;

typedef void *HANDLE;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void *PVOID;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _TIME_ZONE_INFORMATION _TIME_ZONE_INFORMATION, *P_TIME_ZONE_INFORMATION;

typedef struct _TIME_ZONE_INFORMATION *LPTIME_ZONE_INFORMATION;

typedef long LONG;

typedef wchar_t WCHAR;

typedef struct _SYSTEMTIME _SYSTEMTIME, *P_SYSTEMTIME;

typedef struct _SYSTEMTIME SYSTEMTIME;

struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};

typedef struct _WIN32_FIND_DATAA _WIN32_FIND_DATAA, *P_WIN32_FIND_DATAA;

typedef char CHAR;

struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[260];
    CHAR cAlternateFileName[14];
};

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef CHAR *LPSTR;

struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

typedef struct _WIN32_FIND_DATAA *LPWIN32_FIND_DATAA;

typedef struct _STARTUPINFOA *LPSTARTUPINFOA;

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef struct _LIST_ENTRY _LIST_ENTRY, *P_LIST_ENTRY;

typedef struct _LIST_ENTRY LIST_ENTRY;

struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
};

struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
};

struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD;
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef LONG (*PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT CONTEXT;

typedef CONTEXT *PCONTEXT;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct _SYSTEMTIME *LPSYSTEMTIME;

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

typedef CHAR *LPCSTR;

typedef LONG *PLONG;

typedef CHAR *LPCH;

typedef WCHAR *LPWSTR;

typedef WCHAR *PCNZWCH;

typedef WCHAR *LPWCH;

typedef WCHAR *LPCWSTR;

typedef DWORD LCID;

typedef CHAR *PCNZCH;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef uint UINT_PTR;

typedef ULONG_PTR SIZE_T;

typedef uint size_t;

typedef int errno_t;




int __cdecl FUN_00401000(undefined4 *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_c;
  
  iVar8 = (param_1[1] - (int)param_1 >> 2) + -3;
  if (iVar8 == 0) {
    FUN_0041b470((byte *)s_ERROR__cubelist_cc_partition__nu_0042d094);
    return 0;
  }
  puVar11 = param_1 + 2;
  puVar2 = (uint *)*puVar11;
  puVar9 = param_1 + 3;
  while (puVar2 != (uint *)0x0) {
    *puVar2 = *puVar2 & 0xfffff7ff;
    puVar2 = (uint *)*puVar9;
    puVar9 = puVar9 + 1;
  }
  *(uint *)*puVar11 = *(uint *)*puVar11 | 0x800;
  puVar2 = (uint *)*puVar11;
  iVar10 = 1;
  local_c = 1;
  puVar9 = puVar11;
  while (puVar2 != (uint *)0x0) {
    puVar9 = puVar9 + 1;
    if ((*puVar2 & 0x800) != 0) {
      puVar4 = (uint *)*puVar11;
      puVar7 = puVar11;
      iVar10 = local_c;
      while (local_c = iVar10, puVar4 != (uint *)0x0) {
        puVar7 = puVar7 + 1;
        if (((*puVar4 & 0x800) == 0) && (iVar1 = FUN_00418690((int)puVar2,puVar4), iVar1 != 0)) {
          local_c = iVar10 + 1;
          *puVar4 = *puVar4 | 0x800;
        }
        iVar10 = local_c;
        puVar4 = (uint *)*puVar7;
      }
    }
    puVar2 = (uint *)*puVar9;
  }
  if (param_4 != 0) {
    FUN_0041b470((byte *)s_COMPONENT_REDUCTION__split_into___0042d0c0);
  }
  if (iVar10 != iVar8) {
    iVar10 = iVar8 * 4 + 0xc;
    puVar2 = FUN_0040a880(1,iVar10);
    *param_2 = (int)puVar2;
    puVar2 = FUN_0040a880(1,iVar10);
    *param_3 = (int)puVar2;
    puVar2 = (uint *)*param_1;
    uVar3 = (*puVar2 & 0x3ff) * 0x20;
    if (uVar3 < 0x21) {
      iVar10 = 2;
    }
    else {
      iVar10 = (uVar3 - 1 >> 5) + 2;
    }
    iVar1 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar10 << 2);
    piVar5 = (int *)FUN_004171c0((int)puVar4,puVar2);
    uVar6 = FUN_00417140(piVar5,iVar1);
    *(undefined4 *)*param_2 = uVar6;
    puVar2 = (uint *)*param_1;
    uVar3 = (*puVar2 & 0x3ff) * 0x20;
    if (uVar3 < 0x21) {
      iVar10 = 2;
    }
    else {
      iVar10 = (uVar3 - 1 >> 5) + 2;
    }
    iVar1 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar10 << 2);
    piVar5 = (int *)FUN_004171c0((int)puVar4,puVar2);
    uVar6 = FUN_00417140(piVar5,iVar1);
    *(undefined4 *)*param_3 = uVar6;
    puVar9 = (undefined4 *)(*param_2 + 8);
    puVar7 = (undefined4 *)(*param_3 + 8);
    puVar2 = (uint *)*puVar11;
    while (puVar2 != (uint *)0x0) {
      puVar11 = puVar11 + 1;
      if ((*puVar2 & 0x800) == 0) {
        *puVar7 = puVar2;
        puVar7 = puVar7 + 1;
      }
      else {
        *puVar9 = puVar2;
        puVar9 = puVar9 + 1;
      }
      puVar2 = (uint *)*puVar11;
    }
    *puVar9 = 0;
    *(undefined4 **)(*param_2 + 4) = puVar9 + 1;
    *puVar7 = 0;
    *(undefined4 **)(*param_3 + 4) = puVar7 + 1;
    iVar10 = local_c;
  }
  return iVar8 - iVar10;
}



int __cdecl FUN_00401220(int *param_1)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  uint *local_4;
  
  iVar7 = 1;
  puVar2 = FUN_00402950((int)param_1);
  if ((int)(puVar2[1] - (int)puVar2) >> 2 == 3) {
    return 1;
  }
  do {
    uVar6 = 0xffffffff;
    pcVar9 = DAT_004354c0;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    puVar3 = FUN_0040a880(1,~uVar6 + 0x13);
    FUN_0041ec4a((undefined *)puVar3,(byte *)s__s___d_0042d0e8);
    DAT_00432d7c = (FILE *)FUN_0041ec37(puVar3,&DAT_0042d0f0);
    if (DAT_00432d7c == (FILE *)0x0) {
      FUN_0041b430((int *)&DAT_00431cb8,(byte *)s__espresso___Unable_to_open__s_0042d0f4);
      DAT_00432d7c = (FILE *)&DAT_00431c98;
    }
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
    iVar4 = FUN_00401000(puVar2,(int *)&param_1,(int *)&local_4,1);
    if (iVar4 == 0) {
      if ((int)(puVar2[1] - (int)puVar2) >> 2 == 3) {
        FUN_0041b470((byte *)s_ERROR__connected_comp__no_cubes_i_0042d114);
      }
      else {
        puVar5 = (undefined4 *)FUN_00406f70();
        FUN_00406fa0((int)puVar5);
        FUN_00408e40((int *)DAT_00432d7c,(int)puVar5,1);
        FUN_00406ff0(puVar5);
        FUN_0041b430((int *)DAT_00432d7c,(byte *)s___Component__d_0042d13c);
        puVar3 = puVar2 + 2;
        uVar6 = puVar2[2];
        while (uVar6 != 0) {
          puVar3 = puVar3 + 1;
          FUN_00409a60(uVar6);
          FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d14c);
          uVar6 = *puVar3;
        }
        FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d150);
        if (DAT_00432d7c != (FILE *)&DAT_00431c98) {
          FUN_0041ea29(DAT_00432d7c);
        }
      }
      if (*puVar2 != 0) {
        FUN_0041b8c0(*puVar2);
        *puVar2 = 0;
      }
      if (puVar2 == (uint *)0x0) {
        return iVar7;
      }
      FUN_0041b8c0((int)puVar2);
      return iVar7;
    }
    puVar5 = (undefined4 *)FUN_00406f70();
    FUN_00406fa0((int)puVar5);
    FUN_00408e40((int *)DAT_00432d7c,(int)puVar5,1);
    FUN_00406ff0(puVar5);
    iVar7 = iVar7 + 1;
    FUN_0041b430((int *)DAT_00432d7c,(byte *)s___Component__d_0042d154);
    piVar8 = param_1 + 2;
    iVar4 = param_1[2];
    while (iVar4 != 0) {
      piVar8 = piVar8 + 1;
      FUN_00409a60(iVar4);
      FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d164);
      iVar4 = *piVar8;
    }
    FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d168);
    if (DAT_00432d7c != (FILE *)&DAT_00431c98) {
      FUN_0041ea29(DAT_00432d7c);
    }
    puVar2 = local_4;
    if (*param_1 != 0) {
      FUN_0041b8c0(*param_1);
      *param_1 = 0;
    }
    if (param_1 != (int *)0x0) {
      FUN_0041b8c0((int)param_1);
      param_1 = (int *)0x0;
    }
    if ((int)(puVar2[1] - (int)puVar2) >> 2 == 3) {
      return iVar7;
    }
  } while( true );
}



int __cdecl FUN_00401920(int param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint unaff_EBP;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *local_4;
  
  puVar2 = param_2;
  iVar4 = param_1;
  uVar9 = *param_2;
  *param_2 = uVar9 + 1;
  if (*(int *)(param_1 + 0x10) < 2) {
    *param_2 = uVar9;
    return *(int *)(param_1 + 0x10);
  }
  uVar8 = *(int *)(param_1 + 0x10) / 2;
  uVar9 = uVar8;
  local_4 = FUN_00417930(uVar8,DAT_00435520,unaff_EBP);
  param_2 = FUN_00417930(uVar8,DAT_00435520,uVar9);
  puVar7 = *(uint **)(param_1 + 0x18);
  piVar1 = (int *)(param_1 + 0x10);
  param_1 = 0;
  if (0 < *piVar1) {
    do {
      if ((int)(uVar8 - 1) < param_1) {
        param_2 = (uint *)FUN_00417b00((int)param_2,puVar7);
      }
      else {
        local_4 = (uint *)FUN_00417b00((int)local_4,puVar7);
      }
      param_1 = param_1 + 1;
      puVar7 = puVar7 + *(int *)(iVar4 + 4);
    } while (param_1 < *(int *)(iVar4 + 0x10));
  }
  psVar3 = (short *)FUN_00419a60((int)local_4,(int)param_2);
  iVar4 = FUN_00401920((int)psVar3,puVar2);
  iVar5 = FUN_00401920((int)param_2,puVar2);
  iVar6 = FUN_00401920((int)local_4,puVar2);
  FUN_00417a40((short *)local_4);
  FUN_00417a40((short *)param_2);
  FUN_00417a40(psVar3);
  *puVar2 = *puVar2 - 1;
  return (iVar5 - iVar4) + iVar6;
}



void __cdecl FUN_00401a30(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = FUN_0040f770(param_1,param_2);
  puVar5 = param_1 + 2;
  puVar1 = (uint *)param_1[2];
  puVar4 = puVar5;
  while (puVar1 != (uint *)0x0) {
    puVar4 = puVar4 + 1;
    iVar3 = FUN_0040ef50(puVar2,puVar1);
    if (iVar3 == 0) {
      *puVar1 = *puVar1 & 0xffffdfff | 0x400;
    }
    else {
      *puVar1 = *puVar1 & 0xfffffbff | 0x2000;
    }
    if ((DAT_00435400 & 0x4000) != 0) {
      iVar3 = FUN_0041b360();
      FUN_004163a0(iVar3);
      FUN_0041b470((byte *)s_test_redundant__zr__d_ze__d_test_0042d198);
    }
    puVar1 = (uint *)*puVar4;
  }
  FUN_0040f840(param_1,param_2,(int *)puVar2);
  puVar1 = (uint *)*puVar5;
  puVar4 = puVar5;
  while (puVar1 != (uint *)0x0) {
    puVar4 = puVar4 + 1;
    if ((*puVar1 & 0x2000) != 0) {
      iVar3 = FUN_0040ef50(puVar2,puVar1);
      if (iVar3 != 0) {
        *puVar1 = *puVar1 & 0xffffdfff;
      }
      if ((DAT_00435400 & 0x4000) != 0) {
        iVar3 = FUN_0041b360();
        FUN_004163a0(iVar3);
        FUN_0041b470((byte *)s_test_totally_redundant__zr__d_zr_0042d1c8);
      }
    }
    puVar1 = (uint *)*puVar4;
  }
  if (DAT_0042d090 != 0) {
    puVar4 = (undefined4 *)FUN_00406f70();
    FUN_00406fa0((int)puVar4);
    FUN_00408e40((int *)DAT_00432d7c,(int)puVar4,1);
    FUN_00406ff0(puVar4);
    FUN_0041b430((int *)DAT_00432d7c,(byte *)s___Essential_primes_are_0042d1f8);
    puVar1 = (uint *)*puVar5;
    puVar4 = puVar5;
    while (puVar1 != (uint *)0x0) {
      puVar4 = puVar4 + 1;
      if ((*puVar1 & 0x400) != 0) {
        FUN_00409a60((int)puVar1);
        FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d210);
      }
      puVar1 = (uint *)*puVar4;
    }
    FUN_0041b430((int *)DAT_00432d7c,(byte *)s___Totally_redundant_primes_are_0042d214);
    puVar1 = (uint *)*puVar5;
    puVar4 = puVar5;
    while (puVar1 != (uint *)0x0) {
      puVar4 = puVar4 + 1;
      if ((*puVar1 & 0x2400) == 0) {
        FUN_00409a60((int)puVar1);
        FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d234);
      }
      puVar1 = (uint *)*puVar4;
    }
    FUN_0041b430((int *)DAT_00432d7c,(byte *)s___Partially_redundant_primes_are_0042d238);
    puVar1 = (uint *)*puVar5;
    while (puVar1 != (uint *)0x0) {
      puVar5 = puVar5 + 1;
      if (((*puVar1 & 0x2000) != 0) && ((*puVar1 & 0x400) == 0)) {
        FUN_00409a60((int)puVar1);
        FUN_0041b430((int *)DAT_00432d7c,&DAT_0042d25c);
      }
      puVar1 = (uint *)*puVar5;
    }
    if (DAT_00432d7c != (FILE *)&DAT_00431c98) {
      FUN_0041ea29(DAT_00432d7c);
    }
  }
  if (*puVar2 != 0) {
    FUN_0041b8c0(*puVar2);
    *puVar2 = 0;
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  if ((DAT_00435400 & 0x20) != 0) {
    FUN_0041b470((byte *)s___IRRED__F__d__E__d__R__d__Rt__d_0042d260);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_00401d00(int param_1,int param_2)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  if (DAT_0042d090 != 0) {
    iVar4 = 8;
    bVar8 = true;
    pcVar6 = DAT_004354c0;
    pcVar7 = s__stdin__0042d2a4;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      DAT_00432d7c = &DAT_00431c98;
      _DAT_00432d78 = &DAT_00431c98;
    }
    else {
      uVar5 = 0xffffffff;
      pcVar6 = DAT_004354c0;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      puVar2 = FUN_0040a880(1,~uVar5 + 0x13);
      FUN_0041ec4a((undefined *)puVar2,(byte *)s__s_cyclic_0042d2ac);
      DAT_00432d7c = (undefined *)FUN_0041ec37(puVar2,&DAT_0042d2b8);
      if (DAT_00432d7c == (undefined *)0x0) {
        FUN_0041b430((int *)&DAT_00431cb8,(byte *)s__espresso___Unable_to_open__s_0042d2bc);
        DAT_00432d7c = &DAT_00431c98;
      }
      FUN_0041ec4a((undefined *)puVar2,(byte *)s__s_cyclic_pi_0042d2dc);
      _DAT_00432d78 = (undefined *)FUN_0041ec37(puVar2,&DAT_0042d2ec);
      if (_DAT_00432d78 == (undefined *)0x0) {
        FUN_0041b430((int *)&DAT_00431cb8,(byte *)s__espresso___Unable_to_open__s_0042d2f0);
        _DAT_00432d78 = &DAT_00431c98;
      }
      if (puVar2 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar2);
      }
    }
  }
  do {
    iVar4 = *(int *)(param_1 + 0x10);
    puVar2 = FUN_00402950(param_1);
    puVar3 = FUN_00402950(param_2);
    FUN_00401a30(puVar2,(int)puVar3);
    if (*puVar2 != 0) {
      FUN_0041b8c0(*puVar2);
      *puVar2 = 0;
    }
    if (puVar2 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar2);
    }
    if (*puVar3 != 0) {
      FUN_0041b8c0(*puVar3);
      *puVar3 = 0;
    }
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
    FUN_004176e0(param_1);
    FUN_0041b470((byte *)s___Rp_level____d_F_>count____d_0042d310);
  } while (*(int *)(param_1 + 0x10) < iVar4);
  FUN_004176e0(param_1);
  return;
}



void __cdecl FUN_00402260(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  
  puVar8 = (uint *)*DAT_0043554c;
  puVar6 = param_1 + 2;
  uVar4 = *puVar6;
  puVar1 = puVar6;
  while (uVar4 != 0) {
    puVar1 = puVar1 + 1;
    uVar4 = *puVar1;
  }
  puVar1 = FUN_0040a880(1,((param_1[1] - (int)param_1 >> 2) + -3) * 4 + 0x18);
  if (DAT_00435520 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar2 = FUN_00417290(puVar8,DAT_00435550,(int)param_2);
  puVar8 = (uint *)*param_1;
  iVar7 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar5 * 4);
  puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar7);
  uVar4 = FUN_00417240(puVar3,puVar8,iVar2);
  *puVar1 = uVar4;
  puVar3 = puVar1 + 2;
  puVar8 = (uint *)*puVar6;
  while (puVar8 != (uint *)0x0) {
    puVar6 = puVar6 + 1;
    if ((puVar8 != param_2) && (iVar5 = FUN_00418690((int)puVar8,param_2), iVar5 != 0)) {
      *puVar3 = (uint)puVar8;
      puVar3 = puVar3 + 1;
    }
    puVar8 = (uint *)*puVar6;
  }
  *puVar3 = 0;
  puVar1[1] = (uint)(puVar3 + 1);
  return;
}



void __cdecl FUN_00402360(undefined4 *param_1,uint param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  
  iVar9 = param_3;
  puVar1 = *(uint **)(DAT_0043554c + 4);
  iVar2 = *(int *)(DAT_00435538 + param_3 * 4);
  iVar3 = *(int *)(DAT_0043553c + param_3 * 4);
  puVar4 = FUN_0040a880(1,((param_1[1] - (int)param_1 >> 2) + 2) * 4);
  if (DAT_00435520 < 0x21) {
    param_3 = 2;
  }
  else {
    param_3 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar5 = FUN_00417290(puVar1,DAT_00435550,param_2);
  puVar10 = (uint *)*param_1;
  iVar11 = DAT_00435520;
  puVar6 = FUN_0040a880(1,param_3 * 4);
  puVar6 = (uint *)FUN_00417140((int *)puVar6,iVar11);
  uVar7 = FUN_00417240(puVar6,puVar10,iVar5);
  *puVar4 = uVar7;
  puVar10 = puVar4 + 2;
  FUN_004171f0(puVar1,*(uint **)(DAT_00435548 + iVar9 * 4),param_2);
  uVar7 = param_1[2];
  puVar6 = param_1 + 3;
  do {
    if (uVar7 == 0) {
      *puVar10 = 0;
      puVar4[1] = (uint)(puVar10 + 1);
      return;
    }
    if (uVar7 != param_2) {
      puVar8 = puVar1 + iVar2;
      if ((*puVar8 & *(uint *)(uVar7 + iVar2 * 4)) == 0) {
        iVar9 = iVar2;
        do {
          iVar9 = iVar9 + 1;
          puVar8 = puVar8 + 1;
          if (iVar3 < iVar9) goto LAB_00402479;
        } while ((*puVar8 & *(uint *)((uVar7 - (int)puVar1) + (int)puVar8)) == 0);
      }
      *puVar10 = uVar7;
      puVar10 = puVar10 + 1;
    }
LAB_00402479:
    uVar7 = *puVar6;
    puVar6 = puVar6 + 1;
  } while( true );
}



void __cdecl FUN_004024a0(int *param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  piVar4 = DAT_00435580;
  if (-1 < DAT_00435520 + -1) {
    piVar9 = DAT_00435580 + DAT_00435520 + -1;
    iVar8 = DAT_00435520;
    do {
      *piVar9 = 0;
      piVar9 = piVar9 + -1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  iVar10 = DAT_00435550;
  iVar8 = *param_1;
  puVar2 = (uint *)param_1[2];
  piVar9 = param_1 + 3;
  while (puVar2 != (uint *)0x0) {
    uVar5 = *puVar2 & 0x3ff;
    if (uVar5 != 0) {
      puVar11 = (uint *)(iVar8 + uVar5 * 4);
      piVar7 = piVar4 + uVar5 * 0x20 + -2;
      do {
        uVar6 = ~(*(uint *)((int)puVar11 + ((int)puVar2 - iVar8)) | *puVar11) &
                *(uint *)((int)puVar11 + (iVar10 - iVar8));
        if (uVar6 != 0) {
          if ((uVar6 & 0xff000000) != 0) {
            if ((uVar6 & 0x80000000) != 0) {
              piVar7[1] = piVar7[1] + 1;
            }
            if ((uVar6 & 0x40000000) != 0) {
              *piVar7 = *piVar7 + 1;
            }
            if ((uVar6 & 0x20000000) != 0) {
              piVar7[-1] = piVar7[-1] + 1;
            }
            if ((uVar6 & 0x10000000) != 0) {
              piVar7[-2] = piVar7[-2] + 1;
            }
            if ((uVar6 & 0x8000000) != 0) {
              piVar7[-3] = piVar7[-3] + 1;
            }
            if ((uVar6 & 0x4000000) != 0) {
              piVar7[-4] = piVar7[-4] + 1;
            }
            if ((uVar6 & 0x2000000) != 0) {
              piVar7[-5] = piVar7[-5] + 1;
            }
            if ((uVar6 & 0x1000000) != 0) {
              piVar7[-6] = piVar7[-6] + 1;
            }
          }
          if ((uVar6 & 0xff0000) != 0) {
            if ((uVar6 & 0x800000) != 0) {
              piVar7[-7] = piVar7[-7] + 1;
            }
            if ((uVar6 & 0x400000) != 0) {
              piVar7[-8] = piVar7[-8] + 1;
            }
            if ((uVar6 & 0x200000) != 0) {
              piVar7[-9] = piVar7[-9] + 1;
            }
            if ((uVar6 & 0x100000) != 0) {
              piVar7[-10] = piVar7[-10] + 1;
            }
            if ((uVar6 & 0x80000) != 0) {
              piVar7[-0xb] = piVar7[-0xb] + 1;
            }
            if ((uVar6 & 0x40000) != 0) {
              piVar7[-0xc] = piVar7[-0xc] + 1;
            }
            if ((uVar6 & 0x20000) != 0) {
              piVar7[-0xd] = piVar7[-0xd] + 1;
            }
            if ((uVar6 & 0x10000) != 0) {
              piVar7[-0xe] = piVar7[-0xe] + 1;
            }
          }
          if ((char)(uVar6 >> 8) != '\0') {
            if ((uVar6 & 0x8000) != 0) {
              piVar7[-0xf] = piVar7[-0xf] + 1;
            }
            if ((uVar6 & 0x4000) != 0) {
              piVar7[-0x10] = piVar7[-0x10] + 1;
            }
            if ((uVar6 & 0x2000) != 0) {
              piVar7[-0x11] = piVar7[-0x11] + 1;
            }
            if ((uVar6 & 0x1000) != 0) {
              piVar7[-0x12] = piVar7[-0x12] + 1;
            }
            if ((uVar6 & 0x800) != 0) {
              piVar7[-0x13] = piVar7[-0x13] + 1;
            }
            if ((uVar6 & 0x400) != 0) {
              piVar7[-0x14] = piVar7[-0x14] + 1;
            }
            if ((uVar6 & 0x200) != 0) {
              piVar7[-0x15] = piVar7[-0x15] + 1;
            }
            if ((uVar6 & 0x100) != 0) {
              piVar7[-0x16] = piVar7[-0x16] + 1;
            }
          }
          if ((char)uVar6 != '\0') {
            if ((uVar6 & 0x80) != 0) {
              piVar7[-0x17] = piVar7[-0x17] + 1;
            }
            if ((uVar6 & 0x40) != 0) {
              piVar7[-0x18] = piVar7[-0x18] + 1;
            }
            if ((uVar6 & 0x20) != 0) {
              piVar7[-0x19] = piVar7[-0x19] + 1;
            }
            if ((uVar6 & 0x10) != 0) {
              piVar7[-0x1a] = piVar7[-0x1a] + 1;
            }
            if ((uVar6 & 8) != 0) {
              piVar7[-0x1b] = piVar7[-0x1b] + 1;
            }
            if ((uVar6 & 4) != 0) {
              piVar7[-0x1c] = piVar7[-0x1c] + 1;
            }
            if ((uVar6 & 2) != 0) {
              piVar7[-0x1d] = piVar7[-0x1d] + 1;
            }
            if ((uVar6 & 1) != 0) {
              piVar7[-0x1e] = piVar7[-0x1e] + 1;
            }
          }
        }
        puVar11 = puVar11 + -1;
        piVar7 = piVar7 + -0x20;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    puVar2 = (uint *)*piVar9;
    piVar9 = piVar9 + 1;
  }
  iVar8 = 0;
  local_14 = -1;
  local_c = (int *)0x0;
  local_10 = 0;
  param_1 = (int *)0x7d00;
  DAT_00435590 = 0;
  DAT_00435594 = 0;
  DAT_00435598 = -1;
  if (0 < DAT_00435524) {
    local_8 = piVar4;
    do {
      if (iVar8 < DAT_00435528) {
        piVar12 = (int *)local_8[1];
        piVar9 = (int *)*local_8;
        piVar7 = (int *)((uint)(0 < (int)piVar12) + (uint)(0 < (int)piVar9));
        *(int *)(DAT_00435584 + iVar8 * 4) = (int)piVar12 + (int)piVar9;
        if ((int)piVar9 <= (int)piVar12) {
          piVar9 = piVar12;
        }
      }
      else {
        piVar9 = (int *)0x0;
        *(undefined4 *)(DAT_00435584 + iVar8 * 4) = 0;
        piVar7 = (int *)0x0;
        iVar10 = *(int *)(DAT_00435530 + iVar8 * 4);
        iVar3 = *(int *)(DAT_0043552c + iVar8 * 4);
        if (iVar3 <= iVar10) {
          iVar10 = (iVar10 - iVar3) + 1;
          piVar12 = piVar4 + iVar3;
          do {
            piVar1 = (int *)(DAT_00435584 + iVar8 * 4);
            *piVar1 = *piVar1 + *piVar12;
            piVar7 = (int *)((int)piVar7 + (uint)(0 < *piVar12));
            if ((int)piVar9 < (int)piVar7) {
              piVar9 = piVar7;
            }
            piVar12 = piVar12 + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
      }
      if ((int)local_c < (int)piVar7) {
        iVar10 = *(int *)(DAT_00435584 + iVar8 * 4);
        local_c = piVar7;
LAB_0040278d:
        local_10 = iVar10;
        param_1 = piVar9;
        local_14 = iVar8;
      }
      else if (piVar7 == local_c) {
        iVar10 = *(int *)(DAT_00435584 + iVar8 * 4);
        if ((local_10 < iVar10) ||
           ((iVar10 == local_10 && (iVar10 = local_10, (int)piVar9 < (int)param_1))))
        goto LAB_0040278d;
      }
      *(int **)(DAT_00435588 + iVar8 * 4) = piVar7;
      *(uint *)(DAT_0043558c + iVar8 * 4) = (uint)(piVar7 == (int *)0x1);
      DAT_00435590 = DAT_00435590 + (uint)(0 < (int)piVar7);
      DAT_00435594 = DAT_00435594 + (uint)(piVar7 == (int *)0x1);
      iVar8 = iVar8 + 1;
      local_8 = local_8 + 2;
      DAT_00435598 = local_14;
    } while (iVar8 < DAT_00435524);
  }
  return;
}



int __cdecl FUN_00402800(int *param_1,uint *param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = DAT_00435598;
  iVar1 = *param_1;
  iVar6 = 0;
  iVar2 = *(int *)(DAT_00435530 + DAT_00435598 * 4);
  FUN_00417290(param_2,DAT_00435550,*(int *)(DAT_00435548 + DAT_00435598 * 4));
  FUN_00417290(param_3,DAT_00435550,*(int *)(DAT_00435548 + iVar3 * 4));
  iVar7 = *(int *)(DAT_0043552c + iVar3 * 4);
  for (iVar4 = iVar7; iVar4 <= iVar2; iVar4 = iVar4 + 1) {
    if ((*(uint *)(iVar1 + 4 + (iVar4 >> 5) * 4) & 1 << ((byte)iVar4 & 0x1f)) == 0) {
      iVar6 = iVar6 + 1;
    }
  }
  iVar6 = iVar6 / 2;
  while (0 < iVar6) {
    uVar5 = 1 << ((byte)iVar7 & 0x1f);
    if ((*(uint *)((iVar7 >> 5) * 4 + 4 + iVar1) & uVar5) == 0) {
      iVar6 = iVar6 + -1;
      param_2[(iVar7 >> 5) + 1] = param_2[(iVar7 >> 5) + 1] | uVar5;
    }
    iVar7 = iVar7 + 1;
  }
  for (; iVar7 <= iVar2; iVar7 = iVar7 + 1) {
    uVar5 = 1 << ((byte)iVar7 & 0x1f);
    if ((*(uint *)((iVar7 >> 5) * 4 + 4 + iVar1) & uVar5) == 0) {
      param_3[(iVar7 >> 5) + 1] = param_3[(iVar7 >> 5) + 1] | uVar5;
    }
  }
  if (((DAT_00435400 & param_4) != 0) &&
     (FUN_0041b470((byte *)s_BINATE_SPLIT_SELECT__split_again_0042d4a0), DAT_00435570 != 0)) {
    FUN_00409a80((int)param_3);
    FUN_00409a60((int)param_2);
    FUN_0041b470((byte *)s_cl__s_cr__s_0042d4c8);
  }
  return iVar3;
}



uint * __cdecl FUN_00402950(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar5 = uVar1 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10) * 4;
  if (uVar1 < uVar5) {
    do {
      uVar1 = uVar1 + *(int *)(param_1 + 4) * 4;
    } while (uVar1 < uVar5);
  }
  puVar2 = FUN_0040a880(1,*(int *)(param_1 + 0x10) * 4 + 0x10);
  if (DAT_00435520 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar6 = DAT_00435520;
  puVar4 = FUN_0040a880(1,iVar3 << 2);
  uVar5 = FUN_00417140((int *)puVar4,iVar6);
  *puVar2 = uVar5;
  uVar1 = *(uint *)(param_1 + 0x18);
  puVar4 = puVar2 + 2;
  uVar5 = uVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar1 < uVar5; uVar1 = uVar1 + *(int *)(param_1 + 4) * 4) {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  puVar2[1] = (uint)(puVar4 + 1);
  return puVar2;
}



uint * __cdecl FUN_00402a00(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar5 = uVar1 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10) * 4;
  if (uVar1 < uVar5) {
    do {
      uVar1 = uVar1 + *(int *)(param_1 + 4) * 4;
    } while (uVar1 < uVar5);
  }
  uVar1 = *(uint *)(param_2 + 0x18);
  uVar5 = uVar1 + *(int *)(param_2 + 4) * *(int *)(param_2 + 0x10) * 4;
  if (uVar1 < uVar5) {
    do {
      uVar1 = uVar1 + *(int *)(param_2 + 4) * 4;
    } while (uVar1 < uVar5);
  }
  puVar2 = FUN_0040a880(1,(*(int *)(param_1 + 0x10) + *(int *)(param_2 + 0x10)) * 4 + 0x10);
  if (DAT_00435520 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar6 = DAT_00435520;
  puVar4 = FUN_0040a880(1,iVar3 << 2);
  uVar5 = FUN_00417140((int *)puVar4,iVar6);
  *puVar2 = uVar5;
  uVar1 = *(uint *)(param_1 + 0x18);
  puVar4 = puVar2 + 2;
  uVar5 = uVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar1 < uVar5; uVar1 = uVar1 + *(int *)(param_1 + 4) * 4) {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  uVar1 = *(uint *)(param_2 + 0x18);
  uVar5 = uVar1 + *(int *)(param_2 + 4) * *(int *)(param_2 + 0x10) * 4;
  for (; uVar1 < uVar5; uVar1 = uVar1 + *(int *)(param_2 + 4) * 4) {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  puVar2[1] = (uint)(puVar4 + 1);
  return puVar2;
}



void __cdecl FUN_00402b00(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = FUN_0040a880(1,(*(int *)(param_3 + 0x10) + *(int *)(param_2 + 0x10) +
                          *(int *)(param_1 + 0x10)) * 4 + 0xc);
  if (DAT_00435520 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar6 = DAT_00435520;
  puVar4 = FUN_0040a880(1,iVar3 * 4);
  uVar5 = FUN_00417140((int *)puVar4,iVar6);
  *puVar2 = uVar5;
  uVar1 = *(uint *)(param_1 + 0x18);
  puVar4 = puVar2 + 2;
  uVar5 = uVar1 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10) * 4;
  for (; uVar1 < uVar5; uVar1 = uVar1 + *(int *)(param_1 + 4) * 4) {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  uVar1 = *(uint *)(param_2 + 0x18);
  uVar5 = uVar1 + *(int *)(param_2 + 4) * *(int *)(param_2 + 0x10) * 4;
  for (; uVar1 < uVar5; uVar1 = uVar1 + *(int *)(param_2 + 4) * 4) {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  uVar1 = *(uint *)(param_3 + 0x18);
  uVar5 = uVar1 + *(int *)(param_3 + 0x10) * *(int *)(param_3 + 4) * 4;
  for (; uVar1 < uVar5; uVar1 = uVar1 + *(int *)(param_3 + 4) * 4) {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  puVar2[1] = (uint)(puVar4 + 1);
  return;
}



uint * __cdecl FUN_00402bf0(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  uint unaff_ESI;
  int iVar5;
  
  iVar1 = *param_1;
  puVar2 = FUN_00417930((param_1[1] - (int)param_1 >> 2) + -3,DAT_00435520,unaff_ESI);
  piVar4 = param_1 + 2;
  puVar3 = (uint *)*piVar4;
  if (puVar3 != (uint *)0x0) {
    iVar5 = 0;
    do {
      FUN_00417240((uint *)(puVar2[6] + puVar2[1] * iVar5 * 4),puVar3,iVar1);
      puVar3 = (uint *)piVar4[1];
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (puVar3 != (uint *)0x0);
  }
  puVar2[4] = (param_1[1] - (int)param_1 >> 2) - 3;
  return puVar2;
}



void FUN_00402ce0(void)

{
  int iVar1;
  uint *puVar2;
  
  DAT_004330c0 = DAT_004330c0 + 1;
  if (DAT_004330c0 % 100 == 0) {
    DAT_004330c0 = 0;
    iVar1 = FUN_0041b360();
    if (DAT_0042fbb0 < iVar1 - DAT_004330c4) {
      FUN_0040f8b0(2);
    }
  }
  puVar2 = FUN_0040a880(1,0x20);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[4] = 0;
  puVar2[3] = 0;
  puVar2[6] = 0;
  puVar2[5] = 0;
  puVar2[2] = 0;
  puVar2[7] = 0;
  return;
}



void __cdecl FUN_00402d50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 8);
    if (iVar2 != 0) {
      FUN_0041b8c0(iVar2);
    }
  }
  if (param_1 != 0) {
    FUN_0041b8c0(param_1);
  }
  return;
}



uint * __cdecl FUN_00402dc0(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = FUN_0040a880(1,0x1c);
  puVar3[6] = 0;
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    *puVar3 = param_2;
    *(uint **)(param_1 + 0xc) = puVar3;
    *(uint **)(param_1 + 0x10) = puVar3;
    puVar3[2] = 0;
    puVar3[3] = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  if (**(int **)(param_1 + 0x10) < (int)param_2) {
    *puVar3 = param_2;
    *(uint **)(*(int *)(param_1 + 0x10) + 8) = puVar3;
    puVar3[3] = *(uint *)(param_1 + 0x10);
    *(uint **)(param_1 + 0x10) = puVar3;
    puVar3[2] = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  puVar1 = *(uint **)(param_1 + 0xc);
  uVar2 = *puVar1;
  if ((int)param_2 < (int)uVar2) {
    *puVar3 = param_2;
    *(uint **)(*(int *)(param_1 + 0xc) + 0xc) = puVar3;
    puVar3[2] = *(uint *)(param_1 + 0xc);
    *(uint **)(param_1 + 0xc) = puVar3;
    puVar3[3] = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  while ((int)uVar2 < (int)param_2) {
    puVar1 = (uint *)puVar1[2];
    uVar2 = *puVar1;
  }
  if ((int)param_2 < (int)*puVar1) {
    *puVar3 = param_2;
    uVar2 = puVar1[3];
    *(uint **)(*(int *)(uVar2 + 8) + 0xc) = puVar3;
    puVar3[2] = *(uint *)(uVar2 + 8);
    *(uint **)(uVar2 + 8) = puVar3;
    puVar3[3] = uVar2;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  if ((puVar3 != puVar1) && (puVar3 != (uint *)0x0)) {
    FUN_0041b8c0((int)puVar3);
  }
  return puVar1;
}



undefined4 __cdecl FUN_00402f40(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = DAT_004330c0 + 1;
  DAT_004330c0 = iVar2 % 100;
  if ((DAT_004330c0 == 0) &&
     (iVar3 = FUN_0041b360(), iVar2 = DAT_004330c0, DAT_0042fbb0 < iVar3 - DAT_004330c4)) {
    FUN_0040f8b0(2);
    iVar2 = DAT_004330c0;
  }
  DAT_004330c0 = iVar2;
  piVar4 = *(int **)(param_1 + 0xc);
  piVar1 = *(int **)(param_2 + 0xc);
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 1;
    }
    if ((piVar1 == (int *)0x0) || (*piVar4 < *piVar1)) break;
    if (*piVar4 == *piVar1) {
      piVar4 = (int *)piVar4[2];
    }
    piVar1 = (int *)piVar1[2];
  }
  return 0;
}



int __cdecl FUN_00403050(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  iVar3 = FUN_00402ce0();
  puVar5 = *(uint **)(param_2 + 0xc);
  puVar4 = *(uint **)(param_1 + 0xc);
  puVar1 = puVar5;
  if (puVar4 != (uint *)0x0) {
    while (puVar1 != (uint *)0x0) {
      while( true ) {
        uVar2 = *puVar4;
        if ((int)uVar2 < (int)*puVar5) break;
        if ((int)*puVar5 < (int)uVar2) {
          puVar5 = (uint *)puVar5[2];
        }
        else {
          FUN_00402dc0(iVar3,uVar2);
          puVar4 = (uint *)puVar4[2];
          if (puVar4 == (uint *)0x0) {
            return iVar3;
          }
          puVar5 = (uint *)puVar5[2];
        }
        if (puVar5 == (uint *)0x0) {
          return iVar3;
        }
      }
      puVar4 = (uint *)puVar4[2];
      puVar1 = puVar4;
    }
  }
  return iVar3;
}



void __cdecl FUN_004030e0(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0xc) == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 8);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0xc) + 8) = *(undefined4 *)(param_2 + 8);
  }
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0xc);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_2 + 0xc);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  if (param_2 != 0) {
    FUN_0041b8c0(param_2);
  }
  return;
}



uint * __cdecl FUN_00403160(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  
  puVar1 = param_1;
  iVar2 = DAT_00432d80;
  if (((byte)DAT_00435400 & 1) != 0) {
    DAT_00432d80 = DAT_00432d80 + 1;
    FUN_00409aa0((int *)param_1,s_COMPLEMENT_0042d4dc,iVar2);
  }
  iVar2 = FUN_00403300((int *)puVar1,(int *)&param_1);
  if (iVar2 == 2) {
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar9 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar2 * 4);
    puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar9);
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar9 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar2 * 4);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,iVar9);
    puVar5 = (uint *)FUN_00402800((int *)puVar1,puVar3,puVar4,1);
    puVar6 = (uint *)FUN_00402360(puVar1,(uint)puVar3,(int)puVar5);
    puVar6 = FUN_00403160(puVar6);
    puVar7 = (uint *)FUN_00402360(puVar1,(uint)puVar4,(int)puVar5);
    puVar8 = FUN_00403160(puVar7);
    iVar9 = (((int)(puVar1[1] - (int)puVar1) >> 2) + -3) * (puVar8[4] + puVar6[4]);
    iVar2 = puVar6[4] * puVar8[4];
    param_1 = FUN_00403540(puVar1,(int *)puVar6,(int)puVar8,(short *)puVar3,puVar4,puVar5,
                           (uint)(iVar2 - iVar9 != 0 && iVar9 <= iVar2),(int)puVar7);
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
    if (puVar4 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar4);
    }
    if (*puVar1 != 0) {
      FUN_0041b8c0(*puVar1);
      *puVar1 = 0;
    }
    if (puVar1 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar1);
    }
  }
  if (((byte)DAT_00435400 & 1) != 0) {
    DAT_00432d80 = DAT_00432d80 + -1;
    FUN_00409b90((int)param_1,s_exit_COMPLEMENT_0042d4e8,DAT_00432d80);
  }
  return param_1;
}



undefined4 __cdecl FUN_00403300(int *param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  short *psVar6;
  int *piVar7;
  uint unaff_EDI;
  int *piVar8;
  
  puVar3 = (uint *)*param_1;
  piVar8 = param_1 + 2;
  if (param_1[2] == 0) {
    puVar3 = DAT_00435550;
    puVar1 = FUN_00417930(1,DAT_00435520,(uint)DAT_00435550);
    iVar2 = FUN_00417b00((int)puVar1,puVar3);
    *param_2 = iVar2;
    iVar2 = *param_1;
  }
  else {
    if (param_1[3] == 0) {
      iVar2 = FUN_00417240(puVar3,puVar3,param_1[2]);
      puVar3 = FUN_00403b20(iVar2);
    }
    else {
      puVar1 = (uint *)*piVar8;
      piVar7 = piVar8;
      while (puVar1 != (uint *)0x0) {
        piVar7 = piVar7 + 1;
        iVar2 = FUN_00418630(puVar1,(int)puVar3);
        if (iVar2 != 0) {
          puVar3 = FUN_00417930(0,DAT_00435520,unaff_EDI);
          *param_2 = (int)puVar3;
          iVar2 = *param_1;
          if (iVar2 == 0) goto LAB_0040334f;
          goto LAB_00403340;
        }
        puVar1 = (uint *)*piVar7;
      }
      uVar4 = (*puVar3 & 0x3ff) * 0x20;
      if (uVar4 < 0x21) {
        iVar2 = 2;
      }
      else {
        iVar2 = (uVar4 - 1 >> 5) + 2;
      }
      puVar1 = puVar3;
      puVar5 = FUN_0040a880(1,iVar2 * 4);
      puVar1 = (uint *)FUN_004171c0((int)puVar5,puVar1);
      iVar2 = *piVar8;
      while (iVar2 != 0) {
        piVar8 = piVar8 + 1;
        FUN_00417240(puVar1,puVar1,iVar2);
        iVar2 = *piVar8;
      }
      iVar2 = FUN_004174c0(puVar1,(int)DAT_00435550);
      if (iVar2 == 0) {
        puVar5 = FUN_00403b20((int)puVar1);
        iVar2 = FUN_00417290(puVar1,DAT_00435550,(int)puVar1);
        FUN_00417240(puVar3,puVar3,iVar2);
        if (puVar1 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar1);
        }
        puVar3 = FUN_00403160((uint *)param_1);
        iVar2 = FUN_00417860((int)puVar3,(short *)puVar5);
        *param_2 = iVar2;
        return 1;
      }
      if (puVar1 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar1);
      }
      FUN_004024a0(param_1);
      if (DAT_00435590 != 1) {
        if (DAT_00435594 != DAT_00435590) {
          return 2;
        }
        puVar3 = FUN_0041a2e0((int)param_1);
        if (*param_1 != 0) {
          FUN_0041b8c0(*param_1);
          *param_1 = 0;
        }
        if (param_1 != (int *)0x0) {
          FUN_0041b8c0((int)param_1);
        }
        psVar6 = (short *)FUN_0041a5a0(puVar3);
        puVar3 = FUN_0041a420((int)psVar6);
        *param_2 = (int)puVar3;
        FUN_00417a40(psVar6);
        return 1;
      }
      puVar3 = FUN_00417930(0,DAT_00435520,unaff_EDI);
    }
    *param_2 = (int)puVar3;
    iVar2 = *param_1;
  }
  if (iVar2 != 0) {
LAB_00403340:
    FUN_0041b8c0(iVar2);
    *param_1 = 0;
  }
LAB_0040334f:
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return 1;
}



uint * __cdecl
FUN_00403540(undefined4 param_1,int *param_2,int param_3,short *param_4,uint *param_5,uint *param_6,
            int param_7,int param_8)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  uint unaff_EBX;
  uint uVar8;
  
  if (((byte)DAT_00435400 & 1) != 0) {
    FUN_0041b470((byte *)s_compl_merge__left__d__right__d_0042d4f8);
    FUN_00409a80((int)param_5);
    FUN_00409a60((int)param_4);
    FUN_0041b470((byte *)s__s__cl___s__cr__Left_is_0042d518);
    FUN_00409c20((int)param_2);
    FUN_0041b470((byte *)s_Right_is_0042d534);
    FUN_00409c20(param_3);
  }
  iVar2 = FUN_00403820(param_2[4]);
  iVar3 = FUN_00403820(*(uint *)(param_3 + 0x10));
  if (0x14 < iVar2 + iVar3) {
    FUN_0040f8b0(2);
  }
  puVar1 = (uint *)param_2[6];
  puVar6 = puVar1 + param_2[4] * param_2[1];
  for (; puVar1 < puVar6; puVar1 = puVar1 + param_2[1]) {
    FUN_004171f0(puVar1,puVar1,(int)param_5);
    *puVar1 = *puVar1 | 0x2000;
  }
  puVar1 = *(uint **)(param_3 + 0x18);
  puVar6 = puVar1 + *(int *)(param_3 + 0x10) * *(int *)(param_3 + 4);
  for (; puVar1 < puVar6; puVar1 = puVar1 + *(int *)(param_3 + 4)) {
    FUN_004171f0(puVar1,puVar1,(int)param_6);
    *puVar1 = *puVar1 | 0x2000;
  }
  FUN_004171c0(*DAT_0043554c,*(uint **)(DAT_00435548 + param_7 * 4));
  piVar4 = (int *)FUN_00404b40((int)param_2);
  FUN_0041ec9c(piVar4,(undefined4 *)param_2[4],4,FUN_00419320);
  piVar5 = (int *)FUN_00404b40(param_3);
  FUN_0041ec9c(piVar5,*(undefined4 **)(param_4 + 8),4,FUN_00419320);
  FUN_00403ab0(piVar4,piVar5);
  if (param_8 == 0) {
    FUN_00403840(piVar4,piVar5,param_6,param_7);
    FUN_00403840(piVar5,piVar4,param_5,param_7);
  }
  else if (param_8 == 1) {
    puVar6 = FUN_00402bf0(param_2);
    FUN_004038f0(piVar4,(int)puVar6,param_6,param_7);
    FUN_004038f0(piVar5,(int)puVar6,param_5,param_7);
    FUN_00417a40((short *)puVar6);
  }
  else if (param_8 == 2) {
    puVar6 = FUN_00402bf0(param_2);
    FUN_004039a0(piVar4,(int)puVar6,param_7);
    FUN_004039a0(piVar5,(int)puVar6,param_7);
    FUN_00417a40((short *)puVar6);
  }
  if (piVar4 != (int *)0x0) {
    FUN_0041b8c0((int)piVar4);
  }
  if (piVar5 != (int *)0x0) {
    FUN_0041b8c0((int)piVar5);
  }
  puVar7 = FUN_00417930(*(int *)(param_4 + 8) + param_2[4],DAT_00435520,unaff_EBX);
  puVar1 = (uint *)param_2[6];
  puVar6 = puVar1 + param_2[4] * param_2[1];
  uVar8 = puVar7[6];
  for (; puVar1 < puVar6; puVar1 = puVar1 + param_2[1]) {
    FUN_004171c0(uVar8,puVar1);
    puVar7[4] = puVar7[4] + 1;
    uVar8 = uVar8 + puVar7[1] * 4;
  }
  puVar1 = *(uint **)(param_4 + 0xc);
  puVar6 = puVar1 + *(int *)(param_4 + 8) * *(int *)(param_4 + 2);
  for (; puVar1 < puVar6; puVar1 = puVar1 + *(int *)(param_4 + 2)) {
    if ((*puVar1 & 0x2000) != 0) {
      FUN_004171c0(uVar8,puVar1);
      puVar7[4] = puVar7[4] + 1;
      uVar8 = uVar8 + puVar7[1] * 4;
    }
  }
  if ((((byte)DAT_00435400 & 1) != 0) &&
     (FUN_0041b470((byte *)s_Result__d_0042d540), DAT_00435570 != 0)) {
    FUN_00409c20((int)puVar7);
  }
  FUN_00417a40((short *)param_2);
  FUN_00417a40(param_4);
  return puVar7;
}



void __cdecl FUN_00403820(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1f;
  do {
    if ((param_1 & 1 << ((byte)iVar1 & 0x1f)) != 0) {
      return;
    }
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  return;
}



void __cdecl FUN_00403840(undefined4 *param_1,int *param_2,uint *param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  
  iVar1 = *(int *)(DAT_00435548 + param_4 * 4);
  puVar2 = *(uint **)(DAT_0043554c + 0x10);
  puVar3 = *(uint **)(DAT_0043554c + 0x14);
  FUN_004171f0(puVar3,param_3,iVar1);
  puVar4 = (uint *)*param_1;
  puVar5 = param_1 + 1;
  do {
    if (puVar4 == (uint *)0x0) {
      return;
    }
    if ((*puVar4 & 0x2000) != 0) {
      FUN_00417330(puVar2,param_3,(int)puVar4,iVar1);
      iVar6 = *param_2;
      piVar7 = param_2;
      while (iVar6 != 0) {
        piVar7 = piVar7 + 1;
        iVar6 = FUN_00417560(puVar2,iVar6);
        if (iVar6 != 0) {
          FUN_00417240(puVar4,puVar4,(int)puVar3);
          break;
        }
        iVar6 = *piVar7;
      }
    }
    puVar4 = (uint *)*puVar5;
    puVar5 = puVar5 + 1;
  } while( true );
}



void __cdecl FUN_004038f0(undefined4 *param_1,int param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  
  puVar2 = *(uint **)(DAT_0043554c + 0x10);
  iVar3 = *(int *)(DAT_00435548 + param_4 * 4);
  puVar4 = (uint *)*param_1;
  puVar6 = param_1 + 1;
  do {
    if (puVar4 == (uint *)0x0) {
      return;
    }
    if ((*puVar4 & 0x2000) != 0) {
      FUN_004171f0(puVar2,param_3,iVar3);
      FUN_00417240(puVar2,puVar4,(int)puVar2);
      uVar5 = *(uint *)(param_2 + 0x18);
      uVar1 = uVar5 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4) * 4;
      for (; uVar5 < uVar1; uVar5 = uVar5 + *(int *)(param_2 + 4) * 4) {
        iVar7 = FUN_00418690(uVar5,puVar2);
        if (iVar7 != 0) goto LAB_00403986;
      }
      FUN_004171c0((int)puVar4,puVar2);
      *puVar4 = *puVar4 | 0x2000;
    }
LAB_00403986:
    puVar4 = (uint *)*puVar6;
    puVar6 = puVar6 + 1;
  } while( true );
}



void __cdecl FUN_004039a0(undefined4 *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint unaff_ESI;
  int iVar7;
  
  if (DAT_00435520 < 0x21) {
    iVar4 = 2;
  }
  else {
    iVar4 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar7 = DAT_00435520;
  puVar5 = FUN_0040a880(1,iVar4 << 2);
  puVar6 = (uint *)FUN_00417140((int *)puVar5,iVar7);
  puVar5 = (uint *)*param_1;
  puVar3 = param_1 + 1;
  while (puVar5 != (uint *)0x0) {
    if ((*puVar5 & 0x2000) != 0) {
      FUN_00417140((int *)puVar6,DAT_00435520);
      puVar2 = *(uint **)(param_2 + 0x18);
      puVar1 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
      for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
        iVar4 = FUN_00418790((int)puVar2,puVar5);
        if (iVar4 < 2) {
          if (iVar4 == 0) {
            FUN_00408c40((int *)s_compl__ON_set_and_OFF_set_are_no_0042d54c,unaff_ESI);
          }
          else {
            FUN_00418b20((int)puVar6,puVar2,(int)puVar5);
          }
        }
      }
      FUN_00417290(puVar6,*(uint **)(DAT_00435548 + param_3 * 4),(int)puVar6);
      FUN_00417240(puVar5,puVar5,(int)puVar6);
      if (puVar6 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar6);
        puVar6 = (uint *)0x0;
      }
    }
    puVar5 = (uint *)*puVar3;
    puVar3 = puVar3 + 1;
  }
  return;
}



void __cdecl FUN_00403ab0(int *param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  
  puVar1 = (uint *)*param_1;
  puVar2 = (uint *)*param_2;
  while ((puVar1 != (uint *)0x0 && (puVar2 != (uint *)0x0))) {
    iVar3 = FUN_00419320(param_1,param_2);
    if (iVar3 == -1) {
      puVar1 = (uint *)param_1[1];
      param_1 = param_1 + 1;
    }
    else if (iVar3 == 0) {
      *puVar2 = *puVar2 & 0xffffdfff;
      FUN_00417240(puVar1,puVar1,(int)puVar2);
      puVar2 = (uint *)param_2[1];
      param_2 = param_2 + 1;
    }
    else if (iVar3 == 1) {
      puVar2 = (uint *)param_2[1];
      param_2 = param_2 + 1;
    }
  }
  return;
}



uint * __cdecl FUN_00403b20(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint unaff_EDI;
  
  puVar4 = DAT_00435550;
  puVar1 = *(uint **)(DAT_0043554c + 0x1c);
  puVar5 = FUN_00417930(DAT_00435524,DAT_00435520,unaff_EDI);
  FUN_00417290(puVar1,puVar4,param_1);
  param_1 = 0;
  if (DAT_00435524 < 1) {
    return puVar5;
  }
  do {
    iVar2 = *(int *)(DAT_00435548 + param_1 * 4);
    iVar6 = FUN_00417510(puVar1,iVar2);
    if (iVar6 == 0) {
      uVar3 = puVar5[4];
      puVar5[4] = uVar3 + 1;
      FUN_00417330((uint *)(puVar5[6] + puVar5[1] * uVar3 * 4),puVar1,(int)puVar4,iVar2);
    }
    param_1 = param_1 + 1;
  } while (param_1 < DAT_00435524);
  return puVar5;
}



void __cdecl FUN_00403bd0(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  int **ppiVar9;
  int **ppiVar10;
  int iVar11;
  int *local_c;
  int local_8;
  int *local_4;
  
  piVar1 = param_1;
  iVar2 = DAT_00432d84;
  if (((byte)DAT_00435400 & 1) != 0) {
    DAT_00432d84 = DAT_00432d84 + 1;
    FUN_00409aa0(param_1,s_SIMPCOMP_0042d57c,iVar2);
  }
  iVar2 = FUN_00403dc0(piVar1,param_2,param_3);
  if (iVar2 == 2) {
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar11 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar2 * 4);
    puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar11);
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar11 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar2 << 2);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,iVar11);
    puVar5 = (uint *)FUN_00402800(piVar1,puVar3,puVar4,1);
    ppiVar10 = &local_4;
    ppiVar9 = &local_c;
    piVar6 = (int *)FUN_00402360(piVar1,(uint)puVar3,(int)puVar5);
    FUN_00403bd0(piVar6,(int *)ppiVar9,(int *)ppiVar10);
    piVar6 = &local_8;
    ppiVar10 = &param_1;
    piVar7 = (int *)FUN_00402360(piVar1,(uint)puVar4,(int)puVar5);
    FUN_00403bd0(piVar7,(int *)ppiVar10,piVar6);
    piVar6 = piVar1;
    puVar8 = FUN_00403540(piVar1,local_c,(int)param_1,(short *)puVar3,puVar4,puVar5,0,(int)piVar7);
    *param_2 = (int)puVar8;
    puVar5 = FUN_00403540(piVar1,local_4,local_8,(short *)puVar3,puVar4,puVar5,0,(int)piVar6);
    piVar6 = param_2;
    *param_3 = (int)puVar5;
    if ((piVar1[1] - (int)piVar1 >> 2) + -3 < *(int *)((short *)*param_2 + 8)) {
      FUN_00417a40((short *)*param_2);
      puVar5 = FUN_00402bf0(piVar1);
      *piVar6 = (int)puVar5;
    }
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
    if (puVar4 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar4);
    }
    if (*piVar1 != 0) {
      FUN_0041b8c0(*piVar1);
      *piVar1 = 0;
    }
    if (piVar1 != (int *)0x0) {
      FUN_0041b8c0((int)piVar1);
    }
  }
  if (((byte)DAT_00435400 & 1) != 0) {
    FUN_00409b90(*param_2,s_exit_SIMPCOMP__new__0042d588,DAT_00432d84);
    FUN_00409b90(*param_3,s_exit_SIMPCOMP__compl__0042d59c,DAT_00432d84);
    DAT_00432d84 = DAT_00432d84 + -1;
  }
  return;
}



undefined4 __cdecl FUN_00403dc0(int *param_1,int *param_2,int *param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  short *psVar6;
  int *piVar7;
  uint unaff_EDI;
  int *piVar8;
  
  puVar1 = (uint *)*param_1;
  piVar7 = param_1 + 2;
  if (param_1[2] == 0) {
    puVar1 = FUN_00417930(1,DAT_00435520,unaff_EDI);
    *param_2 = (int)puVar1;
    puVar1 = DAT_00435550;
    puVar2 = FUN_00417930(1,DAT_00435520,(uint)DAT_00435550);
    iVar3 = FUN_00417b00((int)puVar2,puVar1);
    *param_3 = iVar3;
    iVar3 = *param_1;
  }
  else if (param_1[3] == 0) {
    FUN_00417240(puVar1,puVar1,param_1[2]);
    puVar2 = puVar1;
    puVar4 = FUN_00417930(1,DAT_00435520,(uint)puVar1);
    iVar3 = FUN_00417b00((int)puVar4,puVar2);
    *param_2 = iVar3;
    puVar1 = FUN_00403b20((int)puVar1);
    *param_3 = (int)puVar1;
    iVar3 = *param_1;
  }
  else {
    puVar2 = (uint *)*piVar7;
    piVar8 = piVar7;
    while (puVar2 != (uint *)0x0) {
      piVar8 = piVar8 + 1;
      iVar3 = FUN_00418630(puVar2,(int)puVar1);
      if (iVar3 != 0) {
        puVar1 = DAT_00435550;
        puVar2 = FUN_00417930(1,DAT_00435520,(uint)DAT_00435550);
        iVar3 = FUN_00417b00((int)puVar2,puVar1);
        *param_2 = iVar3;
        puVar1 = FUN_00417930(1,DAT_00435520,(uint)puVar2);
        *param_3 = (int)puVar1;
        iVar3 = *param_1;
        goto joined_r0x00403ef9;
      }
      puVar2 = (uint *)*piVar8;
    }
    uVar5 = (*puVar1 & 0x3ff) * 0x20;
    if (uVar5 < 0x21) {
      iVar3 = 2;
    }
    else {
      iVar3 = (uVar5 - 1 >> 5) + 2;
    }
    puVar2 = puVar1;
    puVar4 = FUN_0040a880(1,iVar3 * 4);
    puVar2 = (uint *)FUN_004171c0((int)puVar4,puVar2);
    iVar3 = *piVar7;
    while (iVar3 != 0) {
      piVar7 = piVar7 + 1;
      FUN_00417240(puVar2,puVar2,iVar3);
      iVar3 = *piVar7;
    }
    iVar3 = FUN_004174c0(puVar2,(int)DAT_00435550);
    if (iVar3 == 0) {
      if ((int)DAT_00435520 < 0x21) {
        iVar3 = 2;
      }
      else {
        iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
      }
      uVar5 = DAT_00435520;
      puVar4 = FUN_0040a880(1,iVar3 * 4);
      puVar4 = (uint *)FUN_00417140((int *)puVar4,uVar5);
      FUN_00417290(puVar4,DAT_00435550,(int)puVar2);
      FUN_00417240(puVar1,puVar1,(int)puVar4);
      if (puVar4 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar4);
      }
      FUN_00403bd0(param_1,param_2,param_3);
      iVar3 = *param_2;
      puVar4 = *(uint **)(iVar3 + 0x18);
      puVar1 = puVar4 + *(int *)(iVar3 + 0x10) * *(int *)(iVar3 + 4);
      for (; puVar4 < puVar1; puVar4 = puVar4 + *(int *)(iVar3 + 4)) {
        FUN_004171f0(puVar4,puVar4,(int)puVar2);
      }
      puVar1 = FUN_00403b20((int)puVar2);
      iVar3 = FUN_00417860(*param_3,(short *)puVar1);
      *param_3 = iVar3;
      if (puVar2 == (uint *)0x0) {
        return 1;
      }
      FUN_0041b8c0((int)puVar2);
      return 1;
    }
    if (puVar2 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar2);
    }
    FUN_004024a0(param_1);
    if (DAT_00435590 == 1) {
      puVar1 = DAT_00435550;
      puVar2 = FUN_00417930(1,DAT_00435520,(uint)DAT_00435550);
      iVar3 = FUN_00417b00((int)puVar2,puVar1);
      *param_2 = iVar3;
      puVar1 = FUN_00417930(1,DAT_00435520,(uint)puVar2);
      *param_3 = (int)puVar1;
      iVar3 = *param_1;
    }
    else {
      if (DAT_00435594 != DAT_00435590) {
        return 2;
      }
      puVar1 = FUN_00402bf0(param_1);
      puVar1 = FUN_004044e0((short *)puVar1);
      *param_2 = (int)puVar1;
      puVar1 = FUN_0041a2e0((int)param_1);
      psVar6 = (short *)FUN_0041a5a0(puVar1);
      puVar1 = FUN_0041a420((int)psVar6);
      *param_3 = (int)puVar1;
      FUN_00417a40(psVar6);
      iVar3 = *param_1;
    }
  }
joined_r0x00403ef9:
  if (iVar3 != 0) {
    FUN_0041b8c0(iVar3);
    *param_1 = 0;
  }
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return 1;
}



uint * __cdecl FUN_004040f0(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  
  puVar1 = param_1;
  iVar2 = DAT_00432d88;
  if (((byte)DAT_00435400 & 1) != 0) {
    DAT_00432d88 = DAT_00432d88 + 1;
    FUN_00409aa0((int *)param_1,s_SIMPLIFY_0042d5b4,iVar2);
  }
  iVar2 = FUN_00404280((int *)puVar1,(int *)&param_1);
  if (iVar2 == 2) {
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar9 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar2 * 4);
    puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar9);
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar9 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar2 * 4);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,iVar9);
    puVar5 = (uint *)FUN_00402800((int *)puVar1,puVar3,puVar4,1);
    puVar6 = (uint *)FUN_00402360(puVar1,(uint)puVar3,(int)puVar5);
    puVar6 = FUN_004040f0(puVar6);
    puVar7 = (uint *)FUN_00402360(puVar1,(uint)puVar4,(int)puVar5);
    puVar8 = FUN_004040f0(puVar7);
    param_1 = FUN_00403540(puVar1,(int *)puVar6,(int)puVar8,(short *)puVar3,puVar4,puVar5,0,
                           (int)puVar7);
    if (((int)(puVar1[1] - (int)puVar1) >> 2) + -3 < (int)param_1[4]) {
      FUN_00417a40((short *)param_1);
      param_1 = FUN_00402bf0((int *)puVar1);
    }
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
    if (puVar4 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar4);
    }
    if (*puVar1 != 0) {
      FUN_0041b8c0(*puVar1);
      *puVar1 = 0;
    }
    if (puVar1 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar1);
    }
  }
  if (((byte)DAT_00435400 & 1) != 0) {
    DAT_00432d88 = DAT_00432d88 + -1;
    FUN_00409b90((int)param_1,s_exit_SIMPLIFY_0042d5c0,DAT_00432d88);
  }
  return param_1;
}



undefined4 __cdecl FUN_00404280(int *param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  uint unaff_EDI;
  int *piVar8;
  
  puVar1 = (uint *)*param_1;
  piVar7 = param_1 + 2;
  if (param_1[2] == 0) {
    puVar1 = FUN_00417930(0,DAT_00435520,unaff_EDI);
    *param_2 = (int)puVar1;
    iVar3 = *param_1;
  }
  else {
    if (param_1[3] == 0) {
      puVar2 = (uint *)FUN_00417240(puVar1,puVar1,param_1[2]);
LAB_004042f0:
      puVar1 = FUN_00417930(1,DAT_00435520,(uint)puVar2);
      puVar1 = (uint *)FUN_00417b00((int)puVar1,puVar2);
    }
    else {
      puVar2 = (uint *)*piVar7;
      piVar8 = piVar7;
      while (puVar2 != (uint *)0x0) {
        piVar8 = piVar8 + 1;
        iVar3 = FUN_00418630(puVar2,(int)puVar1);
        puVar2 = DAT_00435550;
        if (iVar3 != 0) goto LAB_004042f0;
        puVar2 = (uint *)*piVar8;
      }
      uVar4 = (*puVar1 & 0x3ff) * 0x20;
      if (uVar4 < 0x21) {
        iVar3 = 2;
      }
      else {
        iVar3 = (uVar4 - 1 >> 5) + 2;
      }
      puVar2 = puVar1;
      puVar5 = FUN_0040a880(1,iVar3 * 4);
      puVar2 = (uint *)FUN_004171c0((int)puVar5,puVar2);
      iVar3 = *piVar7;
      while (iVar3 != 0) {
        piVar7 = piVar7 + 1;
        FUN_00417240(puVar2,puVar2,iVar3);
        iVar3 = *piVar7;
      }
      iVar3 = FUN_004174c0(puVar2,(int)DAT_00435550);
      if (iVar3 == 0) {
        if ((int)DAT_00435520 < 0x21) {
          iVar3 = 2;
        }
        else {
          iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
        }
        uVar4 = DAT_00435520;
        puVar5 = FUN_0040a880(1,iVar3 * 4);
        puVar5 = (uint *)FUN_00417140((int *)puVar5,uVar4);
        FUN_00417290(puVar5,DAT_00435550,(int)puVar2);
        FUN_00417240(puVar1,puVar1,(int)puVar5);
        if (puVar5 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar5);
        }
        puVar6 = FUN_004040f0((uint *)param_1);
        puVar5 = (uint *)puVar6[6];
        puVar1 = puVar5 + puVar6[4] * puVar6[1];
        for (; puVar5 < puVar1; puVar5 = puVar5 + puVar6[1]) {
          FUN_004171f0(puVar5,puVar5,(int)puVar2);
        }
        *param_2 = (int)puVar6;
        if (puVar2 == (uint *)0x0) {
          return 1;
        }
        FUN_0041b8c0((int)puVar2);
        return 1;
      }
      if (puVar2 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar2);
      }
      FUN_004024a0(param_1);
      if (DAT_00435590 == 1) {
        puVar1 = DAT_00435550;
        puVar2 = FUN_00417930(1,DAT_00435520,(uint)DAT_00435550);
        iVar3 = FUN_00417b00((int)puVar2,puVar1);
        *param_2 = iVar3;
        iVar3 = *param_1;
        goto joined_r0x004044ca;
      }
      if (DAT_00435594 != DAT_00435590) {
        return 2;
      }
      puVar1 = FUN_00402bf0(param_1);
      puVar1 = FUN_004044e0((short *)puVar1);
    }
    *param_2 = (int)puVar1;
    iVar3 = *param_1;
  }
joined_r0x004044ca:
  if (iVar3 != 0) {
    FUN_0041b8c0(iVar3);
    *param_1 = 0;
  }
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return 1;
}



uint * __cdecl FUN_004044e0(short *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (0xfff < *(uint *)(param_1 + 8)) {
    FUN_0040f8b0(2);
  }
  puVar1 = FUN_00404ab0((int)param_1,&LAB_004191c0);
  FUN_00404800((int *)puVar1,&LAB_004191c0);
  uVar2 = FUN_00404860((int *)puVar1);
  puVar1 = FUN_00404ba0(puVar1,uVar2,*(uint *)(param_1 + 4));
  FUN_00417a40(param_1);
  return puVar1;
}



uint * __cdecl FUN_00404540(short *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (0xfff < *(uint *)(param_1 + 8)) {
    FUN_0040f8b0(2);
  }
  puVar1 = FUN_00404ab0((int)param_1,&LAB_00419240);
  FUN_00404800((int *)puVar1,&LAB_00419240);
  uVar2 = FUN_004048f0(puVar1);
  puVar1 = FUN_00404ba0(puVar1,uVar2,*(uint *)(param_1 + 4));
  FUN_00417a40(param_1);
  return puVar1;
}



uint * __cdecl FUN_004045f0(short *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = FUN_00404ab0((int)param_1,&LAB_004191c0);
  uVar2 = FUN_00404800((int *)puVar1,&LAB_004191c0);
  puVar1 = FUN_00404ba0(puVar1,uVar2,*(uint *)(param_1 + 4));
  FUN_00417a40(param_1);
  return puVar1;
}



uint * __cdecl FUN_00404630(short *param_1,short *param_2)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = (int *)FUN_00404b40((int)param_1);
  piVar2 = (int *)FUN_00404b40((int)param_2);
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) <= *(int *)(param_2 + 8)) {
    iVar4 = *(int *)(param_2 + 8);
  }
  puVar3 = FUN_0040a880(1,iVar4 * 4 + 4);
  iVar4 = FUN_00404980(piVar1,piVar2,(int *)puVar3,&LAB_004191c0);
  iVar5 = FUN_00404a40(piVar1,piVar2);
  iVar6 = FUN_00404a40(piVar2,piVar1);
  puVar3 = FUN_00404cd0(piVar1,piVar2,(int *)puVar3,iVar6 + iVar4 + iVar5,*(uint *)(param_1 + 4));
  FUN_00417a40(param_1);
  FUN_00417a40(param_2);
  return puVar3;
}



uint * __cdecl FUN_004046d0(short *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  FUN_004171c0(*DAT_0043554c,param_2);
  puVar1 = FUN_00404ab0((int)param_1,FUN_00419320);
  uVar2 = FUN_00404740((int *)puVar1,FUN_00419320);
  puVar1 = FUN_00404ba0(puVar1,uVar2,*(uint *)(param_1 + 4));
  FUN_00417a40(param_1);
  return puVar1;
}



void __cdecl FUN_00404720(short *param_1,int param_2)

{
  FUN_004046d0(param_1,*(uint **)(DAT_00435548 + param_2 * 4));
  return;
}



int __cdecl FUN_00404740(int *param_1,undefined *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_c;
  int local_8;
  int local_4;
  
  piVar3 = param_1;
  local_c = 0;
  if (*param_1 == 0) {
    *param_1 = 0;
    return 0;
  }
  local_4 = 0;
  iVar6 = 1;
  iVar4 = 0;
  if (param_1[1] != 0) {
    local_8 = 0;
    piVar2 = param_1;
    do {
      piVar5 = piVar2 + 1;
      piVar1 = (int *)(local_8 + (int)piVar3);
      iVar4 = (*(code *)param_2)(piVar1,piVar5);
      if (iVar4 == 0) {
        FUN_00417240((uint *)*piVar1,(uint *)*piVar1,*piVar5);
      }
      else {
        local_c = local_c + 1;
        *param_1 = *piVar1;
        param_1 = param_1 + 1;
        local_8 = iVar6 * 4;
        local_4 = iVar6;
      }
      piVar1 = piVar2 + 2;
      iVar6 = iVar6 + 1;
      iVar4 = local_c;
      piVar2 = piVar5;
    } while (*piVar1 != 0);
  }
  piVar3[iVar4] = piVar3[local_4];
  piVar3[iVar4 + 1] = 0;
  return iVar4 + 1;
}



int __cdecl FUN_00404800(int *param_1,undefined *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar3 = param_1;
  if (*param_1 != 0) {
    piVar4 = param_1 + 1;
    iVar2 = param_1[1];
    piVar5 = param_1;
    while (iVar2 != 0) {
      iVar2 = (*(code *)param_2)(piVar4,piVar5);
      if (iVar2 != 0) {
        *piVar3 = *piVar5;
        piVar3 = piVar3 + 1;
      }
      piVar1 = piVar4 + 1;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
      iVar2 = *piVar1;
    }
    *piVar3 = piVar4[-1];
    piVar3 = piVar3 + 1;
    *piVar3 = 0;
  }
  return (int)piVar3 - (int)param_1 >> 2;
}



int __cdecl FUN_00404860(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *local_8;
  
  piVar2 = param_1;
  param_1 = (int *)0xffffffff;
  puVar1 = (uint *)*piVar2;
  piVar4 = piVar2 + 1;
  piVar5 = piVar2;
  do {
    if (puVar1 == (uint *)0x0) {
      *piVar5 = 0;
      return (int)piVar5 - (int)piVar2 >> 2;
    }
    if ((int *)(*puVar1 >> 0x10) != param_1) {
      param_1 = (int *)(*puVar1 >> 0x10);
      local_8 = piVar5;
    }
    piVar6 = piVar2;
    if (piVar2 != local_8) {
      do {
        iVar3 = *piVar6;
        piVar6 = piVar6 + 1;
        iVar3 = FUN_00417560(puVar1,iVar3);
        if (iVar3 != 0) goto LAB_004048c0;
      } while (piVar6 != local_8);
    }
    *piVar5 = (int)puVar1;
    piVar5 = piVar5 + 1;
LAB_004048c0:
    puVar1 = (uint *)*piVar4;
    piVar4 = piVar4 + 1;
  } while( true );
}



int __cdecl FUN_004048f0(undefined4 *param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  puVar3 = param_1;
  param_1 = (undefined4 *)0xffffffff;
  puVar1 = (uint *)*puVar3;
  puVar5 = puVar3 + 1;
  puVar6 = puVar3;
  do {
    if (puVar1 == (uint *)0x0) {
      *puVar6 = 0;
      return (int)puVar6 - (int)puVar3 >> 2;
    }
    if ((undefined4 *)(*puVar1 >> 0x10) != param_1) {
      param_1 = (undefined4 *)(*puVar1 >> 0x10);
      local_8 = puVar6;
    }
    puVar7 = puVar3;
    if (puVar3 != local_8) {
      do {
        puVar2 = (uint *)*puVar7;
        puVar7 = puVar7 + 1;
        iVar4 = FUN_00417560(puVar2,(int)puVar1);
        if (iVar4 != 0) goto LAB_00404950;
      } while (puVar7 != local_8);
    }
    *puVar6 = puVar1;
    puVar6 = puVar6 + 1;
LAB_00404950:
    puVar1 = (uint *)*puVar5;
    puVar5 = puVar5 + 1;
  } while( true );
}



int __cdecl FUN_00404980(int *param_1,int *param_2,int *param_3,undefined *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = *param_1;
  piVar2 = param_1;
  piVar3 = param_1;
  piVar4 = param_2;
  param_1 = param_3;
  while ((iVar1 != 0 && (*piVar4 != 0))) {
    iVar1 = (*(code *)param_4)(piVar3,piVar4);
    if (iVar1 == -1) {
      *piVar2 = *piVar3;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    else if (iVar1 == 0) {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *param_1 = iVar1;
      param_1 = param_1 + 1;
      piVar4 = piVar4 + 1;
    }
    else if (iVar1 == 1) {
      *param_2 = *piVar4;
      param_2 = param_2 + 1;
      piVar4 = piVar4 + 1;
    }
    iVar1 = *piVar3;
  }
  iVar1 = *piVar3;
  while (iVar1 != 0) {
    piVar3 = piVar3 + 1;
    *piVar2 = iVar1;
    piVar2 = piVar2 + 1;
    iVar1 = *piVar3;
  }
  iVar1 = *piVar4;
  while (iVar1 != 0) {
    piVar4 = piVar4 + 1;
    *param_2 = iVar1;
    param_2 = param_2 + 1;
    iVar1 = *piVar4;
  }
  *param_1 = 0;
  *param_2 = 0;
  *piVar2 = 0;
  return (int)param_1 - (int)param_3 >> 2;
}



int __cdecl FUN_00404a40(undefined4 *param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = (uint *)*param_1;
  puVar4 = param_1;
  puVar5 = param_1;
  do {
    if (puVar1 == (uint *)0x0) {
      *puVar4 = 0;
      return (int)puVar4 - (int)param_1 >> 2;
    }
    puVar5 = puVar5 + 1;
    puVar2 = (uint *)*param_2;
    puVar6 = param_2;
    while ((puVar2 != (uint *)0x0 &&
           (puVar6 = puVar6 + 1, (*puVar1 & 0xffff0000) < (*puVar2 & 0xffff0000)))) {
      iVar3 = FUN_00417560(puVar1,(int)puVar2);
      if (iVar3 != 0) goto LAB_00404a90;
      puVar2 = (uint *)*puVar6;
    }
    *puVar4 = puVar1;
    puVar4 = puVar4 + 1;
LAB_00404a90:
    puVar1 = (uint *)*puVar5;
  } while( true );
}



uint * __cdecl FUN_00404ab0(int param_1,undefined *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  
  puVar4 = FUN_0040a880(1,*(int *)(param_1 + 0x10) * 4 + 4);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  puVar3 = puVar4;
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    *puVar2 = *puVar2 & 0xffff;
    iVar5 = FUN_00417030(puVar2);
    *puVar2 = *puVar2 | iVar5 << 0x10;
    *puVar3 = (uint)puVar2;
    puVar3 = puVar3 + 1;
  }
  *puVar3 = 0;
  FUN_0041ec9c((int *)puVar4,*(undefined4 **)(param_1 + 0x10),4,param_2);
  return puVar4;
}



void __cdecl FUN_00404b40(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = FUN_0040a880(1,*(int *)(param_1 + 0x10) * 4 + 4);
  uVar3 = *(uint *)(param_1 + 0x18);
  uVar1 = uVar3 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  if (uVar1 <= uVar3) {
    *puVar2 = 0;
    return;
  }
  do {
    *puVar2 = uVar3;
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + *(int *)(param_1 + 4) * 4;
  } while (uVar3 < uVar1);
  *puVar2 = 0;
  return;
}



uint * __cdecl FUN_00404ba0(undefined4 *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint unaff_EDI;
  
  puVar3 = FUN_00417930(param_2,param_3,unaff_EDI);
  puVar3[4] = param_2;
  uVar2 = puVar3[6];
  puVar1 = (uint *)*param_1;
  puVar4 = param_1;
  while (puVar1 != (uint *)0x0) {
    puVar4 = puVar4 + 1;
    FUN_004171c0(uVar2,puVar1);
    uVar2 = uVar2 + puVar3[1] * 4;
    puVar1 = (uint *)*puVar4;
  }
  if (param_1 != (undefined4 *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return puVar3;
}



uint * __cdecl FUN_00404cd0(int *param_1,int *param_2,int *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  bool bVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int **ppiVar10;
  int *piVar11;
  uint unaff_EDI;
  int **ppiVar12;
  int *piVar13;
  int local_14;
  int *local_c [3];
  
  puVar5 = FUN_00417930(param_4,param_5,unaff_EDI);
  uVar1 = puVar5[6];
  local_c[1] = param_2;
  puVar5[4] = param_4;
  local_c[0] = param_1;
  local_c[2] = param_3;
  local_14 = 1;
  ppiVar12 = local_c;
  do {
    if (local_14 < 3) {
      param_4 = 3 - local_14;
      ppiVar10 = ppiVar12;
      do {
        ppiVar10 = ppiVar10 + 1;
        piVar11 = *ppiVar10;
        piVar13 = *ppiVar12;
        uVar6 = FUN_004193a0((uint *)*piVar13,(uint *)*piVar11);
        if (0 < (int)uVar6) {
          *ppiVar10 = piVar13;
          *ppiVar12 = piVar11;
        }
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
    ppiVar12 = ppiVar12 + 1;
    bVar4 = local_14 < 2;
    local_14 = local_14 + 1;
  } while (bVar4);
  iVar3 = *local_c[0];
  piVar11 = local_c[0];
  piVar13 = local_c[1];
  piVar9 = local_c[2];
  while (iVar3 != 0) {
    puVar2 = (uint *)*piVar11;
    piVar11 = piVar11 + 1;
    FUN_004171c0(uVar1,puVar2);
    uVar1 = uVar1 + puVar5[1] * 4;
    uVar6 = FUN_004193a0((uint *)*piVar11,(uint *)*piVar9);
    piVar7 = piVar9;
    piVar8 = piVar11;
    if ((0 < (int)uVar6) ||
       (uVar6 = FUN_004193a0((uint *)*piVar11,(uint *)*piVar13), piVar7 = piVar11, piVar8 = piVar9,
       0 < (int)uVar6)) {
      piVar9 = piVar8;
      piVar11 = piVar13;
      piVar13 = piVar7;
    }
    iVar3 = *piVar11;
  }
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  if (param_2 != (int *)0x0) {
    FUN_0041b8c0((int)param_2);
  }
  if (param_3 != (int *)0x0) {
    FUN_0041b8c0((int)param_3);
  }
  return puVar5;
}



void FUN_00404e20(void)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  uint unaff_ESI;
  int iVar9;
  
  iVar9 = 0;
  if ((DAT_00435528 < 0) || (DAT_00435524 < DAT_00435528)) {
    FUN_00408c40((int *)s_cube_size_is_silly__error_in__i__0042d5d0,unaff_ESI);
  }
  DAT_00435564 = DAT_00435524 - DAT_00435528;
  if (DAT_00435564 < 1) {
    DAT_00435568 = -1;
  }
  else {
    DAT_00435568 = DAT_00435524 + -1;
  }
  DAT_00435520 = 0;
  DAT_0043552c = FUN_0040a880(1,DAT_00435524 << 2);
  DAT_00435530 = FUN_0040a880(1,DAT_00435524 * 4);
  DAT_00435538 = FUN_0040a880(1,DAT_00435524 * 4);
  DAT_0043553c = FUN_0040a880(1,DAT_00435524 * 4);
  iVar2 = 0;
  if (0 < DAT_00435524) {
    do {
      if (iVar2 < DAT_00435528) {
        *(undefined4 *)(DAT_00435534 + iVar2 * 4) = 2;
      }
      DAT_0043552c[iVar2] = DAT_00435520;
      DAT_00435538[iVar2] = ((int)DAT_00435520 >> 5) + 1;
      iVar8 = *(int *)(DAT_00435534 + iVar2 * 4);
      if (iVar8 < 1) {
        iVar8 = -iVar8;
      }
      DAT_00435520 = DAT_00435520 + iVar8;
      DAT_00435530[iVar2] = DAT_00435520 - 1;
      DAT_0043553c[iVar2] = ((int)(DAT_00435520 - 1) >> 5) + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00435524);
  }
  DAT_00435548 = FUN_0040a880(1,DAT_00435524 * 4);
  DAT_00435560 = FUN_0040a880(1,DAT_00435524 * 4);
  if ((int)DAT_00435520 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar4 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar2 * 4);
  DAT_00435540 = (uint *)FUN_00417140((int *)puVar3,uVar4);
  if ((int)DAT_00435520 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar4 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar2 << 2);
  DAT_00435544 = (uint *)FUN_00417140((int *)puVar3,uVar4);
  if (0 < DAT_00435524) {
    do {
      if ((int)DAT_00435520 < 0x21) {
        iVar2 = 2;
      }
      else {
        iVar2 = ((int)(DAT_00435520 - 1) >> 5) + 2;
      }
      uVar4 = DAT_00435520;
      puVar3 = FUN_0040a880(1,iVar2 * 4);
      uVar4 = FUN_00417140((int *)puVar3,uVar4);
      DAT_00435548[iVar9] = uVar4;
      uVar4 = DAT_00435548[iVar9];
      uVar5 = DAT_0043552c[iVar9];
      if ((int)uVar5 <= (int)DAT_00435530[iVar9]) {
        do {
          puVar3 = (uint *)(uVar4 + 4 + ((int)uVar5 >> 5) * 4);
          bVar1 = (byte)uVar5;
          uVar5 = uVar5 + 1;
          *puVar3 = *puVar3 | 1 << (bVar1 & 0x1f);
        } while ((int)uVar5 <= (int)DAT_00435530[iVar9]);
      }
      if (iVar9 < DAT_00435528) {
        FUN_00417240(DAT_00435540,DAT_00435540,uVar4);
        DAT_00435560[iVar9] = 0;
      }
      else {
        FUN_00417240(DAT_00435544,DAT_00435544,uVar4);
        DAT_00435560[iVar9] = 1;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < DAT_00435524);
  }
  if (DAT_00435528 == 0) {
    DAT_0043555c = 0xffffffff;
  }
  else {
    DAT_0043555c = DAT_0043553c[DAT_00435528 + -1];
    DAT_00435558 = DAT_00435540[DAT_0043555c] & 0x55555555;
  }
  DAT_0043554c = FUN_0040a880(1,0x28);
  iVar9 = 0;
  do {
    if ((int)DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = ((int)(DAT_00435520 - 1) >> 5) + 2;
    }
    uVar4 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar2 << 2);
    uVar6 = FUN_00417140((int *)puVar3,uVar4);
    iVar2 = iVar9 + 4;
    *(undefined4 *)(iVar9 + (int)DAT_0043554c) = uVar6;
    iVar9 = iVar2;
  } while (iVar2 < 0x28);
  if ((int)DAT_00435520 < 0x21) {
    iVar9 = 2;
  }
  else {
    iVar9 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar4 = DAT_00435520;
  uVar5 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar9 * 4);
  piVar7 = (int *)FUN_00417140((int *)puVar3,uVar4);
  DAT_00435550 = FUN_00417170(piVar7,uVar5);
  if ((int)DAT_00435520 < 0x21) {
    iVar9 = 2;
  }
  else {
    iVar9 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar4 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar9 << 2);
  DAT_00435554 = FUN_00417140((int *)puVar3,uVar4);
  DAT_00435580 = FUN_0040a880(1,DAT_00435520 * 4);
  DAT_00435584 = FUN_0040a880(1,DAT_00435524 * 4);
  DAT_00435588 = FUN_0040a880(1,DAT_00435524 * 4);
  DAT_0043558c = FUN_0040a880(1,DAT_00435524 * 4);
  return;
}



void FUN_00405270(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0043552c != 0) {
    FUN_0041b8c0(DAT_0043552c);
    DAT_0043552c = 0;
  }
  if (DAT_00435530 != 0) {
    FUN_0041b8c0(DAT_00435530);
    DAT_00435530 = 0;
  }
  if (DAT_00435538 != 0) {
    FUN_0041b8c0(DAT_00435538);
    DAT_00435538 = 0;
  }
  if (DAT_0043553c != 0) {
    FUN_0041b8c0(DAT_0043553c);
    DAT_0043553c = 0;
  }
  if (DAT_00435560 != 0) {
    FUN_0041b8c0(DAT_00435560);
    DAT_00435560 = 0;
  }
  if (DAT_00435540 != 0) {
    FUN_0041b8c0(DAT_00435540);
    DAT_00435540 = 0;
  }
  if (DAT_00435544 != 0) {
    FUN_0041b8c0(DAT_00435544);
    DAT_00435544 = 0;
  }
  if (DAT_00435550 != 0) {
    FUN_0041b8c0(DAT_00435550);
    DAT_00435550 = 0;
  }
  if (DAT_00435554 != 0) {
    FUN_0041b8c0(DAT_00435554);
    DAT_00435554 = 0;
  }
  if (DAT_00435548 != 0) {
    iVar3 = 0;
    iVar2 = DAT_00435548;
    if (0 < DAT_00435524) {
      do {
        iVar1 = *(int *)(iVar2 + iVar3 * 4);
        if (iVar1 != 0) {
          FUN_0041b8c0(iVar1);
          *(undefined4 *)(DAT_00435548 + iVar3 * 4) = 0;
          iVar2 = DAT_00435548;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_00435524);
    }
    if (iVar2 != 0) {
      FUN_0041b8c0(iVar2);
      DAT_00435548 = 0;
    }
  }
  if (DAT_0043554c != 0) {
    iVar3 = 0;
    iVar2 = DAT_0043554c;
    do {
      if (*(int *)(iVar3 + iVar2) != 0) {
        FUN_0041b8c0(*(int *)(iVar3 + iVar2));
        *(undefined4 *)(iVar3 + DAT_0043554c) = 0;
        iVar2 = DAT_0043554c;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x28);
    if (iVar2 != 0) {
      FUN_0041b8c0(iVar2);
      DAT_0043554c = 0;
    }
  }
  if (DAT_00435580 != 0) {
    FUN_0041b8c0(DAT_00435580);
    DAT_00435580 = 0;
  }
  if (DAT_00435584 != 0) {
    FUN_0041b8c0(DAT_00435584);
    DAT_00435584 = 0;
  }
  if (DAT_00435588 != 0) {
    FUN_0041b8c0(DAT_00435588);
    DAT_00435588 = 0;
  }
  if (DAT_0043558c != 0) {
    FUN_0041b8c0(DAT_0043558c);
  }
  DAT_00435530 = 0;
  DAT_0043552c = 0;
  DAT_0043553c = 0;
  DAT_00435538 = 0;
  DAT_00435560 = 0;
  DAT_00435544 = 0;
  DAT_00435540 = 0;
  DAT_00435554 = 0;
  DAT_00435550 = 0;
  DAT_0043554c = 0;
  DAT_00435548 = 0;
  DAT_00435588 = 0;
  DAT_00435584 = 0;
  DAT_00435580 = 0;
  DAT_0043558c = 0;
  return;
}



void __cdecl FUN_00405550(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_0041ee9b(param_1);
  while ((iVar1 != -1 && (iVar1 != 10))) {
    if (param_3 != 0) {
      FUN_0041b3a0((char)iVar1,param_2);
    }
    iVar1 = FUN_0041ee9b(param_1);
  }
  if (param_3 != 0) {
    FUN_0041b3a0('\n',param_2);
  }
  DAT_00432d90 = DAT_00432d90 + 1;
  return;
}



undefined * __cdecl FUN_004055b0(undefined4 *param_1,undefined *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *extraout_ECX_01;
  void *extraout_ECX_02;
  int iVar4;
  
  iVar2 = FUN_0041ee9b(param_1);
  pvVar1 = extraout_ECX;
  while (iVar2 != -1) {
    if (DAT_00432104 < 2) {
      uVar3 = (byte)PTR_DAT_00431ef8[iVar2 * 2] & 8;
    }
    else {
      uVar3 = FUN_0041eea6(pvVar1,iVar2,8);
    }
    if (uVar3 == 0) break;
    iVar2 = FUN_0041ee9b(param_1);
    pvVar1 = extraout_ECX_00;
  }
  iVar4 = 1;
  *param_2 = (char)iVar2;
  iVar2 = FUN_0041ee9b(param_1);
  pvVar1 = extraout_ECX_01;
  while (iVar2 != -1) {
    if (DAT_00432104 < 2) {
      uVar3 = (byte)PTR_DAT_00431ef8[iVar2 * 2] & 8;
    }
    else {
      uVar3 = FUN_0041eea6(pvVar1,iVar2,8);
    }
    if (uVar3 != 0) break;
    param_2[iVar4] = (char)iVar2;
    iVar4 = iVar4 + 1;
    iVar2 = FUN_0041ee9b(param_1);
    pvVar1 = extraout_ECX_02;
  }
  param_2[iVar4] = 0;
  return param_2;
}



char * __cdecl FUN_00405660(undefined4 *param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  void *extraout_ECX_01;
  void *pvVar4;
  void *extraout_ECX_02;
  void *extraout_ECX_03;
  int iVar5;
  int iVar6;
  uint local_4;
  
  iVar5 = 0;
  local_4 = 0;
  do {
    bVar1 = false;
    cVar2 = FUN_0041ee9b(param_1);
    pvVar4 = extraout_ECX;
    while (cVar2 != -1) {
      if (DAT_00432104 < 2) {
        uVar3 = (byte)PTR_DAT_00431ef8[cVar2 * 2] & 8;
      }
      else {
        uVar3 = FUN_0041eea6(pvVar4,(int)cVar2,8);
      }
      if (uVar3 == 0) break;
      cVar2 = FUN_0041ee9b(param_1);
      pvVar4 = extraout_ECX_00;
    }
    do {
      iVar6 = iVar5;
      param_2[iVar6] = cVar2;
      iVar5 = iVar6 + 1;
      if (cVar2 == '\\') {
        local_4 = local_4 + 1;
      }
      cVar2 = FUN_0041ee9b(param_1);
      pvVar4 = this;
      if (cVar2 == -1) break;
      if (DAT_00432104 < 2) {
        pvVar4 = (void *)(int)cVar2;
        uVar3 = (byte)PTR_DAT_00431ef8[(int)pvVar4 * 2] & 8;
      }
      else {
        uVar3 = FUN_0041eea6(this,(int)cVar2,8);
        pvVar4 = extraout_ECX_01;
      }
    } while (uVar3 == 0);
    if (DAT_00432d98 == 2) {
      if (*param_2 == '\\') {
        if (DAT_00432104 < 2) {
          uVar3 = (byte)PTR_DAT_00431ef8[cVar2 * 2] & 8;
        }
        else {
          uVar3 = FUN_0041eea6(pvVar4,(int)cVar2,8);
        }
        if (uVar3 != 0) {
          param_2[iVar5] = cVar2;
          iVar5 = iVar6 + 2;
          cVar2 = FUN_0041ee9b(param_1);
          pvVar4 = extraout_ECX_02;
          while (cVar2 != -1) {
            if (DAT_00432104 < 2) {
              uVar3 = (byte)PTR_DAT_00431ef8[cVar2 * 2] & 8;
            }
            else {
              uVar3 = FUN_0041eea6(pvVar4,(int)cVar2,8);
            }
            if (uVar3 != 0) break;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = FUN_0041ee9b(param_1);
            pvVar4 = extraout_ECX_03;
          }
        }
      }
    }
    else if ((DAT_00432d98 == 1) && (*param_2 == '\\')) {
      if (DAT_00432104 < 2) {
        uVar3 = (byte)PTR_DAT_00431ef8[cVar2 * 2] & 8;
      }
      else {
        uVar3 = FUN_0041eea6(pvVar4,(int)cVar2,8);
      }
      if ((uVar3 != 0) && ((local_4 & 0xfffffffe) != local_4)) {
        param_2[iVar5] = cVar2;
        bVar1 = true;
        iVar5 = iVar6 + 2;
      }
    }
    param_2[iVar5] = '\0';
    if (!bVar1) {
      return param_2;
    }
  } while( true );
}



void __cdecl FUN_00405820(int *param_1,int param_2)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  undefined4 *puVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  uint *puVar14;
  bool bVar15;
  undefined4 *unaff_retaddr;
  uint *local_120;
  int local_118;
  uint *local_110;
  int local_108;
  byte local_100 [256];
  
  local_110 = (uint *)*DAT_0043554c;
  puVar2 = (uint *)DAT_0043554c[1];
  local_118 = DAT_0043554c[2];
  iVar13 = 0;
  FUN_00417140((int *)local_110,DAT_00435520);
  iVar8 = 0;
  if (0 < (int)DAT_00435528) {
    iVar11 = 1;
LAB_00405874:
    iVar3 = FUN_0041ee9b(param_1);
    if (iVar3 - 9U < 0x74) {
      iVar4 = iVar11 >> 5;
      switch(iVar3) {
      case 9:
      case 0x20:
      case 0x7c:
        goto switchD_00405898_caseD_9;
      case 10:
        if (DAT_00432d8c == 0) {
          FUN_0040aa50(1,1);
        }
        DAT_00432d8c = 1;
        DAT_00432d90 = DAT_00432d90 + 1;
        goto switchD_00405898_caseD_9;
      default:
        break;
      case 0x2d:
      case 0x32:
        local_110[iVar4 + 1] = local_110[iVar4 + 1] | 1 << ((byte)iVar11 & 0x1f);
      case 0x30:
        iVar4 = iVar13 >> 5;
        iVar3 = iVar13;
LAB_00405901:
        local_110[iVar4 + 1] = local_110[iVar4 + 1] | 1 << ((byte)iVar3 & 0x1f);
        goto switchD_00405898_caseD_3f;
      case 0x31:
        iVar3 = iVar11;
        goto LAB_00405901;
      case 0x3f:
        goto switchD_00405898_caseD_3f;
      }
    }
    goto switchD_00405c32_caseD_b;
  }
LAB_00405921:
  local_120 = DAT_00435528;
  iVar8 = DAT_00435524;
  puVar9 = local_110;
  puVar14 = DAT_00435528;
  if ((int)DAT_00435528 < DAT_00435524 + -1) {
    do {
      iVar8 = (int)local_120 * 4;
      if (-1 < *(int *)(DAT_00435534 + iVar8)) {
        iVar13 = *(int *)(DAT_0043552c + iVar8);
        if (iVar13 <= *(int *)(DAT_00435530 + iVar8)) {
          do {
            uVar7 = FUN_0041ee9b(param_1);
            switch(uVar7) {
            case 9:
            case 0x20:
            case 0x7c:
              goto switchD_00405b2d_caseD_9;
            case 10:
              if (DAT_00432d8c == 0) {
                FUN_0040aa50(1,1);
              }
              DAT_00432d8c = 1;
              DAT_00432d90 = DAT_00432d90 + 1;
switchD_00405b2d_caseD_9:
              iVar13 = iVar13 + -1;
              break;
            default:
              goto switchD_00405c32_caseD_b;
            case 0x30:
              break;
            case 0x31:
              local_110[(iVar13 >> 5) + 1] =
                   local_110[(iVar13 >> 5) + 1] | 1 << ((byte)iVar13 & 0x1f);
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 <= *(int *)(DAT_00435530 + iVar8));
        }
        goto LAB_00405aab;
      }
      FUN_0041f03b(param_1,&DAT_0042d5fc);
      iVar13 = 2;
      bVar15 = true;
      pbVar5 = local_100;
      pbVar12 = &DAT_0042d600;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        bVar15 = *pbVar5 == *pbVar12;
        pbVar5 = pbVar5 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar15);
      if (bVar15) {
LAB_00405ac5:
        if ((DAT_004353fc == 0) || (local_120 != (uint *)(DAT_00435524 + -2))) {
          FUN_00417240(local_110,local_110,*(int *)(DAT_00435548 + iVar8));
        }
      }
      else {
        iVar13 = 4;
        bVar15 = true;
        pbVar5 = local_100;
        pbVar12 = &DAT_0042d604;
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          bVar15 = *pbVar5 == *pbVar12;
          pbVar5 = pbVar5 + 1;
          pbVar12 = pbVar12 + 1;
        } while (bVar15);
        if (bVar15) goto LAB_00405ac5;
        iVar13 = 2;
        bVar15 = true;
        pbVar5 = local_100;
        pbVar12 = &DAT_0042d608;
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          bVar15 = *pbVar5 == *pbVar12;
          pbVar5 = pbVar5 + 1;
          pbVar12 = pbVar12 + 1;
        } while (bVar15);
        if (!bVar15) {
          if ((DAT_004353fc == 0) || (local_120 != (uint *)(DAT_00435524 + -2))) {
            puVar9 = (uint *)0x0;
            iVar13 = iVar8;
          }
          else {
            iVar13 = iVar8 + -4;
            puVar9 = *(uint **)(DAT_00435534 + -4 + iVar8);
            if ((int)puVar9 < 1) {
              puVar9 = (uint *)-(int)puVar9;
            }
          }
          local_108 = *(int *)(iVar13 + DAT_00435530);
          puVar14 = *(uint **)(iVar13 + DAT_0043552c);
          if ((int)puVar14 <= local_108) {
            puVar10 = (undefined4 *)(*(int *)(param_2 + 0x1c) + (int)puVar14 * 4);
            while (pbVar5 = (byte *)*puVar10, pbVar5 != (byte *)0x0) {
              pbVar12 = local_100;
              do {
                bVar1 = *pbVar5;
                bVar15 = bVar1 < *pbVar12;
                if (bVar1 != *pbVar12) {
LAB_00405a42:
                  iVar8 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                  goto LAB_00405a47;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar5[1];
                bVar15 = bVar1 < pbVar12[1];
                if (bVar1 != pbVar12[1]) goto LAB_00405a42;
                pbVar5 = pbVar5 + 2;
                pbVar12 = pbVar12 + 2;
              } while (bVar1 != 0);
              iVar8 = 0;
LAB_00405a47:
              if (iVar8 == 0) goto LAB_00405a77;
              puVar14 = (uint *)((int)puVar14 + 1);
              puVar10 = puVar10 + 1;
              if (local_108 < (int)puVar14) goto LAB_00405b8a;
            }
            puVar6 = FUN_0041a290((char *)local_100);
            *(uint **)(*(int *)(param_2 + 0x1c) + (int)puVar14 * 4) = puVar6;
LAB_00405a77:
            local_110[((int)puVar14 + (int)puVar9 >> 5) + 1] =
                 local_110[((int)puVar14 + (int)puVar9 >> 5) + 1] |
                 1 << ((byte)((int)puVar14 + (int)puVar9) & 0x1f);
            if ((int)puVar14 <= local_108) goto LAB_00405aab;
          }
LAB_00405b8a:
          FUN_0040aa50(0,2);
          iVar8 = FUN_0041ef48(0xffffffff);
          break;
        }
      }
LAB_00405aab:
      puVar14 = (uint *)((int)local_120 + 1);
      iVar8 = DAT_00435524;
      puVar9 = local_110;
      local_120 = puVar14;
    } while ((int)puVar14 < DAT_00435524 + -1);
  }
  if (DAT_004353fc == 0) {
    FUN_004171c0((int)local_120,puVar9);
  }
  else {
    local_110 = (uint *)0x1;
    local_118 = 1;
    FUN_004172e0(local_120,puVar9,*(int *)(DAT_00435548 + -8 + iVar8 * 4));
  }
  FUN_004171c0((int)puVar2,puVar9);
  iVar8 = *(int *)(DAT_0043552c + (int)puVar14 * 4);
  if (iVar8 <= *(int *)(DAT_00435530 + (int)puVar14 * 4)) {
    do {
      iVar13 = FUN_0041ee9b(unaff_retaddr);
      if (0x75 < iVar13 - 9U) {
switchD_00405c32_caseD_b:
        FUN_0040aa50(1,3);
        FUN_00405550(unaff_retaddr,DAT_00435368,1);
        return;
      }
      iVar11 = iVar8 >> 5;
      bVar1 = (byte)iVar8;
      switch(iVar13) {
      case 10:
        if (DAT_00432d8c == 0) {
          FUN_0040aa50(1,1);
        }
        DAT_00432d8c = 1;
        DAT_00432d90 = DAT_00432d90 + 1;
      case 9:
      case 0x20:
      case 0x7c:
        iVar8 = iVar8 + -1;
        break;
      default:
        goto switchD_00405c32_caseD_b;
      case 0x2d:
      case 0x32:
        if ((*(byte *)(param_1 + 4) & 2) != 0) {
          local_108 = 1;
          puVar2[iVar11 + 1] = puVar2[iVar11 + 1] | 1 << (bVar1 & 0x1f);
        }
        break;
      case 0x30:
      case 0x33:
        if ((*(byte *)(param_1 + 4) & 4) != 0) {
          local_118 = 1;
          local_120[iVar11 + 1] = local_120[iVar11 + 1] | 1 << (bVar1 & 0x1f);
        }
        break;
      case 0x31:
      case 0x34:
        if ((*(byte *)(param_1 + 4) & 1) != 0) {
          local_110 = (uint *)0x1;
          puVar9[iVar11 + 1] = puVar9[iVar11 + 1] | 1 << (bVar1 & 0x1f);
        }
        break;
      case 0x7e:
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 <= *(int *)(DAT_00435530 + (int)puVar14 * 4));
  }
  if (local_110 != (uint *)0x0) {
    iVar8 = FUN_00417b00(*param_1,puVar9);
    *param_1 = iVar8;
  }
  if (local_108 != 0) {
    iVar8 = FUN_00417b00(param_1[1],puVar2);
    param_1[1] = iVar8;
  }
  if (local_118 != 0) {
    iVar8 = FUN_00417b00(param_1[2],local_120);
    param_1[2] = iVar8;
  }
  return;
switchD_00405898_caseD_9:
  iVar8 = iVar8 + -1;
  iVar13 = iVar13 + -2;
  iVar11 = iVar11 + -2;
switchD_00405898_caseD_3f:
  iVar8 = iVar8 + 1;
  iVar13 = iVar13 + 2;
  iVar11 = iVar11 + 2;
  if ((int)DAT_00435528 <= iVar8) goto LAB_00405921;
  goto LAB_00405874;
}



void __cdecl FUN_00405f40(int *param_1,int *param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  undefined *puVar5;
  byte *pbVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  byte *pbVar12;
  uint unaff_EDI;
  undefined **ppuVar13;
  char *pcVar14;
  bool bVar15;
  uint uVar16;
  int iStack_814;
  int local_810;
  int local_80c;
  int iStack_808;
  char acStack_802 [2];
  undefined4 local_800;
  
  DAT_00432d90 = 1;
  DAT_00432d8c = 0;
  do {
    uVar3 = FUN_0041ee9b(param_1);
    switch(uVar3) {
    default:
      FUN_0041f068(uVar3,param_1);
      if (DAT_00435550 == (uint *)0x0) {
        iVar11 = DAT_0043540c;
        if (DAT_0043540c != 0) {
          FUN_0041b3a0('#',DAT_00435368);
          iVar11 = DAT_0043540c;
        }
LAB_00406913:
        FUN_00405550(param_1,DAT_00435368,iVar11);
      }
      else {
        if (*param_2 == 0) {
          uVar16 = 10;
          puVar10 = FUN_00417930(10,DAT_00435520,unaff_EDI);
          *param_2 = (int)puVar10;
          uVar3 = 10;
          puVar10 = FUN_00417930(10,DAT_00435520,uVar16);
          param_2[1] = (int)puVar10;
          puVar10 = FUN_00417930(10,DAT_00435520,uVar3);
          param_2[2] = (int)puVar10;
        }
        FUN_00405820(param_1,(int)param_2);
      }
    case 9:
    case 0xc:
    case 0xd:
    case 0x20:
      break;
    case 10:
      DAT_00432d90 = DAT_00432d90 + 1;
      break;
    case 0x23:
      FUN_0041f068(uVar3,param_1);
      FUN_00407480(param_1,DAT_00435368,DAT_0043540c);
      break;
    case 0x2e:
      pcVar4 = FUN_004055b0(param_1,(undefined *)&local_800);
      iVar11 = 2;
      bVar15 = true;
      pcVar14 = &DAT_0042d60c;
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        bVar15 = *pcVar4 == *pcVar14;
        pcVar4 = pcVar4 + 1;
        pcVar14 = pcVar14 + 1;
      } while (bVar15);
      if (!bVar15) {
        iVar11 = 2;
        bVar15 = true;
        pcVar4 = (char *)&local_800;
        pcVar14 = &DAT_0042d628;
        do {
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          bVar15 = *pcVar4 == *pcVar14;
          pcVar4 = pcVar4 + 1;
          pcVar14 = pcVar14 + 1;
        } while (bVar15);
        if (bVar15) {
          if (DAT_00435550 == (uint *)0x0) {
            if (DAT_00435534 == (uint *)0x0) {
              FUN_00408c40((int *)s__o_cannot_appear_before__i_0042d62c,unaff_EDI);
            }
            iVar11 = FUN_0041f03b(param_1,&DAT_0042d648);
            if (iVar11 != 1) {
              FUN_00408c40((int *)s_error_reading__o_0042d64c,unaff_EDI);
            }
LAB_0040609b:
            FUN_00404e20();
            FUN_00406fa0((int)param_2);
            break;
          }
          iVar11 = 5;
        }
        else {
          iVar11 = 3;
          bVar15 = true;
          pcVar4 = (char *)&local_800;
          pcVar14 = &DAT_0042d660;
          do {
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            bVar15 = *pcVar4 == *pcVar14;
            pcVar4 = pcVar4 + 1;
            pcVar14 = pcVar14 + 1;
          } while (bVar15);
          if (!bVar15) {
            iVar11 = 2;
            bVar15 = true;
            pcVar4 = (char *)&local_800;
            pcVar14 = &DAT_0042d738;
            do {
              if (iVar11 == 0) break;
              iVar11 = iVar11 + -1;
              bVar15 = *pcVar4 == *pcVar14;
              pcVar4 = pcVar4 + 1;
              pcVar14 = pcVar14 + 1;
            } while (bVar15);
            if (bVar15) {
              FUN_0041f03b(param_1,&DAT_0042d73c);
            }
            else {
              iVar11 = 2;
              bVar15 = true;
              pcVar4 = (char *)&local_800;
              pcVar14 = &DAT_0042d740;
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                bVar15 = *pcVar4 == *pcVar14;
                pcVar4 = pcVar4 + 1;
                pcVar14 = pcVar14 + 1;
              } while (bVar15);
              if (bVar15) {
                return;
              }
              iVar11 = 4;
              bVar15 = true;
              pcVar4 = (char *)&local_800;
              pcVar14 = &DAT_0042d744;
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                bVar15 = *pcVar4 == *pcVar14;
                pcVar4 = pcVar4 + 1;
                pcVar14 = pcVar14 + 1;
              } while (bVar15);
              if (bVar15) {
                return;
              }
              iVar11 = 5;
              bVar15 = true;
              pcVar4 = (char *)&local_800;
              pcVar14 = &DAT_0042d748;
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                bVar15 = *pcVar4 == *pcVar14;
                pcVar4 = pcVar4 + 1;
                pcVar14 = pcVar14 + 1;
              } while (bVar15);
              if (bVar15) {
                DAT_004353fc = 1;
              }
              else {
                iVar11 = 5;
                bVar15 = true;
                pcVar4 = (char *)&local_800;
                pcVar14 = &DAT_0042d750;
                do {
                  if (iVar11 == 0) break;
                  iVar11 = iVar11 + -1;
                  bVar15 = *pcVar4 == *pcVar14;
                  pcVar4 = pcVar4 + 1;
                  pcVar14 = pcVar14 + 1;
                } while (bVar15);
                if (bVar15) {
                  FUN_004055b0(param_1,(undefined *)&local_800);
                  iVar11 = 0;
                  if (PTR_DAT_0042ed08 != (undefined *)0x0) {
                    ppuVar13 = &PTR_DAT_0042ed08;
                    puVar5 = PTR_DAT_0042ed08;
                    do {
                      pbVar12 = (byte *)&local_800;
                      pbVar6 = puVar5 + 1;
                      do {
                        bVar2 = *pbVar6;
                        bVar15 = bVar2 < *pbVar12;
                        if (bVar2 != *pbVar12) {
LAB_004062c6:
                          iVar7 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                          goto LAB_004062cb;
                        }
                        if (bVar2 == 0) break;
                        bVar2 = pbVar6[1];
                        bVar15 = bVar2 < pbVar12[1];
                        if (bVar2 != pbVar12[1]) goto LAB_004062c6;
                        pbVar6 = pbVar6 + 2;
                        pbVar12 = pbVar12 + 2;
                      } while (bVar2 != 0);
                      iVar7 = 0;
LAB_004062cb:
                      if (iVar7 == 0) {
                        param_2[4] = (&DAT_0042ed0c)[iVar11 * 2];
                        break;
                      }
                      puVar5 = ppuVar13[2];
                      ppuVar13 = ppuVar13 + 2;
                      iVar11 = iVar11 + 1;
                    } while (puVar5 != (undefined *)0x0);
                  }
                  if ((&PTR_DAT_0042ed08)[iVar11 * 2] == (undefined *)0x0) {
                    FUN_00408c40((int *)s_unknown_type_in__type_command_0042d758,unaff_EDI);
                  }
                }
                else {
                  iVar11 = 4;
                  bVar15 = true;
                  pcVar4 = (char *)&local_800;
                  pcVar14 = &DAT_0042d778;
                  do {
                    if (iVar11 == 0) break;
                    iVar11 = iVar11 + -1;
                    bVar15 = *pcVar4 == *pcVar14;
                    pcVar4 = pcVar4 + 1;
                    pcVar14 = pcVar14 + 1;
                  } while (bVar15);
                  if (bVar15) {
                    if (DAT_00435550 == (uint *)0x0) {
                      FUN_00408c40((int *)s_PLA_size_must_be_declared_before_0042d77c,unaff_EDI);
                    }
                    if (param_2[7] == 0) {
                      FUN_00406fa0((int)param_2);
                    }
                    iStack_814 = 0;
                    if (0 < DAT_00435528) {
                      do {
                        FUN_00405660(param_1,(char *)&local_800);
                        iVar11 = *(int *)(DAT_0043552c + iStack_814 * 4);
                        puVar10 = FUN_0041a290((char *)&local_800);
                        *(uint **)(param_2[7] + 4 + iVar11 * 4) = puVar10;
                        uVar3 = 0xffffffff;
                        pcVar4 = (char *)&local_800;
                        do {
                          if (uVar3 == 0) break;
                          uVar3 = uVar3 - 1;
                          cVar1 = *pcVar4;
                          pcVar4 = pcVar4 + 1;
                        } while (cVar1 != '\0');
                        puVar10 = FUN_0040a880(1,~uVar3 + 5);
                        *(uint **)(param_2[7] + iVar11 * 4) = puVar10;
                        FUN_0041ec4a(*(undefined **)(param_2[7] + iVar11 * 4),
                                     (byte *)s__s_bar_0042d7ac);
                        iStack_814 = iStack_814 + 1;
                      } while (iStack_814 < DAT_00435528);
                    }
                  }
                  else {
                    iVar11 = 3;
                    bVar15 = true;
                    pcVar4 = (char *)&local_800;
                    pcVar14 = &DAT_0042d7b4;
                    do {
                      if (iVar11 == 0) break;
                      iVar11 = iVar11 + -1;
                      bVar15 = *pcVar4 == *pcVar14;
                      pcVar4 = pcVar4 + 1;
                      pcVar14 = pcVar14 + 1;
                    } while (bVar15);
                    if (bVar15) {
                      if (DAT_00435550 == (uint *)0x0) {
                        FUN_00408c40((int *)s_PLA_size_must_be_declared_before_0042d7b8,unaff_EDI);
                      }
                      if (param_2[7] == 0) {
                        FUN_00406fa0((int)param_2);
                      }
                      iStack_814 = DAT_00435524 + -1;
                      iVar11 = *(int *)(DAT_0043552c + iStack_814 * 4);
                      if (iVar11 <= *(int *)(DAT_00435530 + iStack_814 * 4)) {
                        do {
                          FUN_00405660(param_1,(char *)&local_800);
                          puVar10 = FUN_0041a290((char *)&local_800);
                          *(uint **)(param_2[7] + iVar11 * 4) = puVar10;
                          DAT_004330c8 = *(undefined4 *)(param_2[7] + iVar11 * 4);
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= *(int *)(DAT_00435530 + iStack_814 * 4));
                      }
                    }
                    else {
                      iVar11 = 6;
                      bVar15 = true;
                      pcVar4 = (char *)&local_800;
                      pcVar14 = s_label_0042d7e8;
                      do {
                        if (iVar11 == 0) break;
                        iVar11 = iVar11 + -1;
                        bVar15 = *pcVar4 == *pcVar14;
                        pcVar4 = pcVar4 + 1;
                        pcVar14 = pcVar14 + 1;
                      } while (bVar15);
                      if (bVar15) {
                        if (DAT_00435550 == (uint *)0x0) {
                          FUN_00408c40((int *)s_PLA_size_must_be_declared_before_0042d7f0,unaff_EDI)
                          ;
                        }
                        if (param_2[7] == 0) {
                          FUN_00406fa0((int)param_2);
                        }
                        iVar11 = FUN_0041f03b(param_1,(byte *)s_var__d_0042d818);
                        if (iVar11 != 1) {
                          FUN_00408c40((int *)s_Error_reading_labels_0042d820,unaff_EDI);
                        }
                        iVar11 = *(int *)(DAT_0043552c + iStack_814 * 4);
                        if (iVar11 <= *(int *)(DAT_00435530 + iStack_814 * 4)) {
                          do {
                            FUN_004055b0(param_1,(undefined *)&local_800);
                            puVar10 = FUN_0041a290((char *)&local_800);
                            *(uint **)(param_2[7] + iVar11 * 4) = puVar10;
                            iVar11 = iVar11 + 1;
                          } while (iVar11 <= *(int *)(DAT_00435530 + iStack_814 * 4));
                        }
                      }
                      else {
                        iVar11 = 9;
                        bVar15 = true;
                        pcVar4 = (char *)&local_800;
                        pcVar14 = s_symbolic_0042d838;
                        do {
                          if (iVar11 == 0) break;
                          iVar11 = iVar11 + -1;
                          bVar15 = *pcVar4 == *pcVar14;
                          pcVar4 = pcVar4 + 1;
                          pcVar14 = pcVar14 + 1;
                        } while (bVar15);
                        if (bVar15) {
                          iVar11 = FUN_00407170(param_1,(int)param_2,(byte *)&local_800,&local_80c);
                          if (iVar11 == 0) {
                            FUN_00408c40((int *)s_error_reading__symbolic_0042d844,unaff_EDI);
                          }
                          else {
                            iVar11 = param_2[8];
                            if (iVar11 == 0) {
                              param_2[8] = local_80c;
                            }
                            else {
                              for (iVar7 = *(int *)(iVar11 + 0x10); iVar7 != 0;
                                  iVar7 = *(int *)(iVar7 + 0x10)) {
                                iVar11 = iVar7;
                              }
                              *(int *)(iVar11 + 0x10) = local_80c;
                            }
                          }
                        }
                        else {
                          iVar11 = 0x10;
                          bVar15 = true;
                          pcVar4 = (char *)&local_800;
                          pcVar14 = s_symbolic_output_0042d85c;
                          do {
                            if (iVar11 == 0) break;
                            iVar11 = iVar11 + -1;
                            bVar15 = *pcVar4 == *pcVar14;
                            pcVar4 = pcVar4 + 1;
                            pcVar14 = pcVar14 + 1;
                          } while (bVar15);
                          if (bVar15) {
                            iVar11 = FUN_00407170(param_1,(int)param_2,(byte *)&local_800,&local_810
                                                 );
                            if (iVar11 == 0) {
                              FUN_00408c40((int *)s_error_reading__symbolic_output_0042d86c,
                                           unaff_EDI);
                            }
                            else {
                              iVar11 = param_2[9];
                              if (iVar11 == 0) {
                                param_2[9] = local_810;
                              }
                              else {
                                for (iVar7 = *(int *)(iVar11 + 0x10); iVar7 != 0;
                                    iVar7 = *(int *)(iVar7 + 0x10)) {
                                  iVar11 = iVar7;
                                }
                                *(int *)(iVar11 + 0x10) = local_810;
                              }
                            }
                          }
                          else {
                            iVar11 = 6;
                            bVar15 = true;
                            pcVar4 = (char *)&local_800;
                            pcVar14 = s_phase_0042d88c;
                            do {
                              if (iVar11 == 0) break;
                              iVar11 = iVar11 + -1;
                              bVar15 = *pcVar4 == *pcVar14;
                              pcVar4 = pcVar4 + 1;
                              pcVar14 = pcVar14 + 1;
                            } while (bVar15);
                            if (bVar15) {
                              if (DAT_00435550 == (uint *)0x0) {
                                FUN_00408c40((int *)s_PLA_size_must_be_declared_before_0042d894,
                                             unaff_EDI);
                              }
                              if (param_2[5] != 0) {
                                iVar11 = 7;
                                goto LAB_00406668;
                              }
                              do {
                                do {
                                  uVar3 = FUN_0041ee9b(param_1);
                                } while (uVar3 == 0x20);
                              } while (uVar3 == 9);
                              FUN_0041f068(uVar3,param_1);
                              uVar3 = (*DAT_00435550 & 0x3ff) * 0x20;
                              if (uVar3 < 0x21) {
                                iVar11 = 2;
                              }
                              else {
                                iVar11 = (uVar3 - 1 >> 5) + 2;
                              }
                              puVar10 = DAT_00435550;
                              puVar8 = FUN_0040a880(1,iVar11 * 4);
                              iVar11 = FUN_004171c0((int)puVar8,puVar10);
                              param_2[5] = iVar11;
                              iVar11 = *(int *)(DAT_00435530 + -4 + DAT_00435524 * 4);
                              for (iVar7 = *(int *)(DAT_0043552c + -4 + DAT_00435524 * 4);
                                  iVar7 <= iVar11; iVar7 = iVar7 + 1) {
                                iVar9 = FUN_0041ee9b(param_1);
                                if (iVar9 == 0x30) {
                                  puVar10 = (uint *)(param_2[5] + 4 + (iVar7 >> 5) * 4);
                                  *puVar10 = *puVar10 & ~(1 << ((byte)iVar7 & 0x1f));
                                }
                                else if (iVar9 != 0x31) {
                                  FUN_00408c40((int *)s_only_0_or_1_allowed_in_phase_des_0042d8bc,
                                               unaff_EDI);
                                }
                              }
                            }
                            else {
                              iVar11 = 5;
                              bVar15 = true;
                              pcVar4 = (char *)&local_800;
                              pcVar14 = &DAT_0042d8e8;
                              do {
                                if (iVar11 == 0) break;
                                iVar11 = iVar11 + -1;
                                bVar15 = *pcVar4 == *pcVar14;
                                pcVar4 = pcVar4 + 1;
                                pcVar14 = pcVar14 + 1;
                              } while (bVar15);
                              if (!bVar15) {
                                iVar11 = DAT_00435464;
                                if (DAT_00435464 != 0) {
                                  FUN_0041b470((byte *)s__c_s_0042d93c);
                                  iVar11 = DAT_00435464;
                                }
                                goto LAB_00406913;
                              }
                              if (param_2[6] == 0) {
                                puVar10 = FUN_0040a880(1,0xc);
                                param_2[6] = (int)puVar10;
                                iVar11 = FUN_0041f03b(param_1,&DAT_0042d8f0);
                                if (iVar11 != 1) {
                                  FUN_00408c40((int *)s_syntax_error_in__pair_0042d8f4,unaff_EDI);
                                }
                                puVar8 = FUN_0040a880(1,*puVar10 << 2);
                                puVar10[1] = (uint)puVar8;
                                puVar8 = FUN_0040a880(1,*puVar10 << 2);
                                puVar10[2] = (uint)puVar8;
                                iVar11 = 0;
                                if (0 < (int)*puVar10) {
                                  do {
                                    FUN_004055b0(param_1,(undefined *)&local_800);
                                    if ((byte)local_800 == 0x28) {
                                      uVar3 = 0xffffffff;
                                      pcVar4 = (char *)((int)&local_800 + 1);
                                      do {
                                        pcVar14 = pcVar4;
                                        if (uVar3 == 0) break;
                                        uVar3 = uVar3 - 1;
                                        pcVar14 = pcVar4 + 1;
                                        cVar1 = *pcVar4;
                                        pcVar4 = pcVar14;
                                      } while (cVar1 != '\0');
                                      uVar3 = ~uVar3;
                                      pcVar4 = pcVar14 + -uVar3;
                                      pcVar14 = (char *)&local_800;
                                      for (uVar16 = uVar3 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
                                        *(undefined4 *)pcVar14 = *(undefined4 *)pcVar4;
                                        pcVar4 = pcVar4 + 4;
                                        pcVar14 = pcVar14 + 4;
                                      }
                                      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                                        *pcVar14 = *pcVar4;
                                        pcVar4 = pcVar4 + 1;
                                        pcVar14 = pcVar14 + 1;
                                      }
                                    }
                                    iVar7 = FUN_004072d0((int)param_2,(byte *)&local_800,&iStack_814
                                                         ,&iStack_808);
                                    if (iVar7 == 0) {
                                      FUN_00408c40((int *)s_syntax_error_in__pair_0042d90c,unaff_EDI
                                                  );
                                    }
                                    else {
                                      *(int *)(puVar10[1] + iVar11 * 4) = iStack_814 + 1;
                                    }
                                    FUN_004055b0(param_1,(undefined *)&local_800);
                                    uVar3 = 0xffffffff;
                                    pcVar4 = (char *)&local_800;
                                    do {
                                      if (uVar3 == 0) break;
                                      uVar3 = uVar3 - 1;
                                      cVar1 = *pcVar4;
                                      pcVar4 = pcVar4 + 1;
                                    } while (cVar1 != '\0');
                                    if (acStack_802[~uVar3] == ')') {
                                      uVar3 = 0xffffffff;
                                      pcVar4 = (char *)&local_800;
                                      do {
                                        if (uVar3 == 0) break;
                                        uVar3 = uVar3 - 1;
                                        cVar1 = *pcVar4;
                                        pcVar4 = pcVar4 + 1;
                                      } while (cVar1 != '\0');
                                      acStack_802[~uVar3] = '\0';
                                    }
                                    iVar7 = FUN_004072d0((int)param_2,(byte *)&local_800,&iStack_814
                                                         ,&iStack_808);
                                    if (iVar7 == 0) {
                                      FUN_00408c40((int *)s_syntax_error_in__pair_0042d924,unaff_EDI
                                                  );
                                    }
                                    else {
                                      *(int *)(puVar10[2] + iVar11 * 4) = iStack_814 + 1;
                                    }
                                    iVar11 = iVar11 + 1;
                                  } while (iVar11 < (int)*puVar10);
                                }
                              }
                              else {
                                FUN_0040aa50(1,8);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            break;
          }
          if (DAT_00435550 == (uint *)0x0) {
            if (DAT_00435534 != (uint *)0x0) {
              FUN_00408c40((int *)s_cannot_mix__i_and__mv_0042d664,unaff_EDI);
            }
            iVar11 = FUN_0041f03b(param_1,(byte *)s__d__d_0042d67c);
            if (iVar11 != 2) {
              FUN_00408c40((int *)s_error_reading__mv_0042d684,unaff_EDI);
            }
            if (DAT_00435528 < 0) {
              FUN_00408c40((int *)s_num_binary_vars__second_field_of_0042d698,unaff_EDI);
            }
            if (DAT_00435524 < DAT_00435528) {
              FUN_00408c40((int *)s_num_vars__1st_field_of__mv__must_0042d6d4,unaff_EDI);
            }
            DAT_00435534 = FUN_0040a880(1,DAT_00435524 * 4);
            iStack_814 = DAT_00435528;
            if (DAT_00435528 < DAT_00435524) {
              do {
                iVar11 = FUN_0041f03b(param_1,&DAT_0042d720);
                if (iVar11 != 1) {
                  FUN_00408c40((int *)s_error_reading__mv_0042d724,unaff_EDI);
                }
                iStack_814 = iStack_814 + 1;
              } while (iStack_814 < DAT_00435524);
            }
            goto LAB_0040609b;
          }
          iVar11 = 6;
        }
        FUN_0040aa50(1,iVar11);
        FUN_00405550(param_1,DAT_00435368,0);
        break;
      }
      if (DAT_00435550 == (uint *)0x0) {
        iVar11 = FUN_0041f03b(param_1,&DAT_0042d610);
        if (iVar11 != 1) {
          FUN_00408c40((int *)s_error_reading__i_0042d614,unaff_EDI);
        }
        DAT_00435524 = DAT_00435528 + 1;
        DAT_00435534 = FUN_0040a880(1,DAT_00435524 * 4);
      }
      else {
        iVar11 = 4;
LAB_00406668:
        FUN_0040aa50(1,iVar11);
        FUN_00405550(param_1,DAT_00435368,0);
      }
      break;
    case 0xffffffff:
      return;
    }
  } while( true );
}



undefined4 __cdecl
FUN_00406a00(int *param_1,int param_2,int param_3,uint param_4,undefined4 *param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_18 [6];
  
  DAT_004330c8 = 0;
  puVar2 = (uint *)FUN_00406f70();
  *param_5 = puVar2;
  puVar2[4] = param_4;
  iVar3 = FUN_0041b360();
  FUN_00405f40(param_1,(int *)puVar2);
  if (*puVar2 == 0) {
    return 0xffffffff;
  }
  iVar7 = 0;
  if (0 < DAT_00435524) {
    do {
      iVar4 = *(int *)(DAT_00435534 + iVar7 * 4);
      if (iVar4 < 1) {
        iVar4 = -iVar4;
      }
      *(int *)(DAT_00435534 + iVar7 * 4) = iVar4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_00435524);
  }
  if (DAT_004353fc != 0) {
    iVar7 = DAT_00435524 * 4 + -8;
    iVar4 = DAT_00435524 * 4 + -0xc;
    if (*(int *)(DAT_00435534 + iVar4) != *(int *)(iVar7 + DAT_00435534)) {
      FUN_0040aa50(1,9);
      return 0xffffffff;
    }
    iVar9 = 0;
    if (0 < *(int *)(iVar7 + DAT_00435534)) {
      do {
        puVar5 = FUN_0041a290(*(char **)(puVar2[7] + (*(int *)(DAT_0043552c + iVar4) + iVar9) * 4));
        iVar8 = *(int *)(iVar7 + DAT_0043552c) + iVar9;
        iVar9 = iVar9 + 1;
        *(uint **)(puVar2[7] + iVar8 * 4) = puVar5;
      } while (iVar9 < *(int *)(iVar7 + DAT_00435534));
    }
    *(int *)(iVar7 + DAT_00435534) =
         *(int *)(iVar7 + DAT_00435534) + *(int *)(DAT_00435534 + -4 + DAT_00435524 * 4);
    DAT_00435524 = DAT_00435524 + -1;
    FUN_00405270();
    FUN_00404e20();
  }
  if (DAT_00435408 != 0) {
    FUN_00408bb0(iVar3,0,*puVar2,local_18);
  }
  iVar3 = FUN_0041b360();
  iVar7 = FUN_004073f0();
  if (iVar7 == 1) {
    return 1;
  }
  if (((DAT_00435410 == 0) && (puVar2[5] == 0)) && (puVar2[9] == 0)) {
    if (param_3 != 0) goto LAB_00406b72;
  }
  else {
    param_3 = 1;
LAB_00406b72:
    if ((puVar2[4] == 1) || (puVar2[4] == 3)) {
      FUN_00417a40((short *)puVar2[2]);
      puVar5 = FUN_00402a00(*puVar2,puVar2[1]);
      puVar5 = FUN_00403160(puVar5);
      puVar2[2] = (uint)puVar5;
      goto LAB_00406c25;
    }
  }
  if ((param_2 == 0) || (puVar2[4] != 5)) {
    if ((puVar2[4] == 4) || (puVar2[4] == 6)) {
      FUN_00417a40((short *)*puVar2);
      puVar5 = FUN_00402a00(puVar2[1],puVar2[2]);
      puVar5 = FUN_00403160(puVar5);
      *puVar2 = (uint)puVar5;
    }
  }
  else {
    FUN_00417a40((short *)puVar2[1]);
    iVar7 = DAT_00435524 + -1;
    puVar5 = FUN_004177d0(*puVar2,puVar2[2],iVar7);
    psVar6 = (short *)FUN_00404720((short *)puVar5,iVar7);
    puVar5 = FUN_00402950((int)psVar6);
    puVar5 = FUN_00403160(puVar5);
    puVar2[1] = (uint)puVar5;
    FUN_00417a40(psVar6);
  }
LAB_00406c25:
  if (DAT_00435408 != 0) {
    FUN_00408bb0(iVar3,1,puVar2[2],local_18);
  }
  if (DAT_00435410 == 0) {
    if (puVar2[5] != 0) {
      FUN_00414110((int *)puVar2);
    }
  }
  else {
    uVar1 = *puVar2;
    *puVar2 = puVar2[2];
    puVar2[2] = uVar1;
    if (DAT_00435520 < 0x21) {
      iVar3 = 2;
    }
    else {
      iVar3 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar7 = DAT_00435520;
    puVar5 = FUN_0040a880(1,iVar3 * 4);
    puVar5 = (uint *)FUN_00417140((int *)puVar5,iVar7);
    puVar2[5] = (uint)puVar5;
    FUN_00417290(puVar5,DAT_00435550,*(int *)(DAT_00435548 + -4 + DAT_00435524 * 4));
  }
  if (puVar2[6] != 0) {
    FUN_00414660(puVar2);
  }
  if (puVar2[8] != 0) {
    FUN_0041b360();
    FUN_0040daa0((int *)puVar2);
    if (DAT_00435408 != 0) {
      FUN_0041b360();
      FUN_00408b70(*puVar2);
    }
  }
  if (puVar2[9] != 0) {
    FUN_0041b360();
    FUN_0040d640(puVar2);
    if (DAT_00435408 != 0) {
      FUN_0041b360();
      FUN_00408b70(*puVar2);
    }
    if (param_3 != 0) {
      FUN_00417a40((short *)puVar2[2]);
      iVar3 = FUN_0041b360();
      puVar5 = FUN_00402a00(*puVar2,puVar2[1]);
      puVar5 = FUN_00403160(puVar5);
      puVar2[2] = (uint)puVar5;
      FUN_00408bb0(iVar3,1,(int)puVar5,local_18);
    }
  }
  return 1;
}



void __cdecl FUN_00406d90(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_0041b470((byte *)s___PLA_is__s_0042d95c);
  if (DAT_00435528 == DAT_00435524 + -1) {
    FUN_0041b470((byte *)s_with__d_inputs_and__d_outputs_0042d968);
  }
  else {
    FUN_0041b470((byte *)s_with__d_variables___d_binary__mv_0042d988);
    iVar2 = DAT_00435528;
    if (DAT_00435528 < DAT_00435524) {
      do {
        FUN_0041b470(&DAT_0042d9b0);
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_00435524);
    }
    FUN_0041b470(&DAT_0042d9b4);
  }
  FUN_00408af0(*param_1);
  FUN_0041b470((byte *)s___ON_set_cost_is__s_0042d9b8);
  FUN_00408af0(param_1[2]);
  FUN_0041b470((byte *)s___OFF_set_cost_is__s_0042d9d0);
  FUN_00408af0(param_1[1]);
  FUN_0041b470((byte *)s___DC_set_cost_is__s_0042d9e8);
  if (param_1[5] != 0) {
    FUN_00409a60(param_1[5]);
    FUN_0041b470((byte *)s___phase_is__s_0042da00);
  }
  if (param_1[6] != 0) {
    FUN_0041b470((byte *)s___two_bit_decoders__0042da10);
    iVar2 = 0;
    if (0 < *(int *)param_1[6]) {
      do {
        FUN_0041b470((byte *)s___d__d__0042da24);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)param_1[6]);
    }
    FUN_0041b470(&DAT_0042da30);
  }
  for (piVar1 = (int *)param_1[8]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    FUN_0041b470((byte *)s___symbolic__0042da34);
    for (iVar2 = *piVar1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      FUN_0041b470(&DAT_0042da44);
    }
    FUN_0041b470(&DAT_0042da48);
  }
  for (piVar1 = (int *)param_1[9]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    FUN_0041b470((byte *)s___output_symbolic__0042da4c);
    for (iVar2 = *piVar1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      FUN_0041b470(&DAT_0042da60);
    }
    FUN_0041b470(&DAT_0042da64);
  }
  FUN_0041f0ff(DAT_00435368);
  return;
}



void FUN_00406f70(void)

{
  uint *puVar1;
  
  puVar1 = FUN_0040a880(1,0x28);
  puVar1[2] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  return;
}



void __cdecl FUN_00406fa0(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = FUN_0040a880(1,DAT_00435520 * 4);
  *(uint **)(param_1 + 0x1c) = puVar1;
  iVar2 = 0;
  if (0 < DAT_00435520) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + -4 + iVar2 * 4) = 0;
    } while (iVar2 < DAT_00435520);
  }
  return;
}



void __cdecl FUN_00406ff0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if ((short *)*param_1 != (short *)0x0) {
    FUN_00417a40((short *)*param_1);
  }
  if ((short *)param_1[2] != (short *)0x0) {
    FUN_00417a40((short *)param_1[2]);
  }
  if ((short *)param_1[1] != (short *)0x0) {
    FUN_00417a40((short *)param_1[1]);
  }
  if (param_1[5] != 0) {
    FUN_0041b8c0(param_1[5]);
    param_1[5] = 0;
  }
  if (param_1[6] != 0) {
    iVar4 = *(int *)(param_1[6] + 4);
    if (iVar4 != 0) {
      FUN_0041b8c0(iVar4);
      *(undefined4 *)(param_1[6] + 4) = 0;
    }
    if (*(int *)(param_1[6] + 8) != 0) {
      FUN_0041b8c0(*(int *)(param_1[6] + 8));
      *(undefined4 *)(param_1[6] + 8) = 0;
    }
    if (param_1[6] != 0) {
      FUN_0041b8c0(param_1[6]);
      param_1[6] = 0;
    }
  }
  if (param_1[7] != 0) {
    iVar4 = 0;
    if (0 < DAT_00435520) {
      do {
        iVar1 = *(int *)(param_1[7] + iVar4 * 4);
        if (iVar1 != 0) {
          FUN_0041b8c0(iVar1);
          *(undefined4 *)(param_1[7] + iVar4 * 4) = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_00435520);
    }
    if (param_1[7] != 0) {
      FUN_0041b8c0(param_1[7]);
      param_1[7] = 0;
    }
  }
  if (param_1[3] != 0) {
    FUN_0041b8c0(param_1[3]);
    param_1[3] = 0;
  }
  piVar2 = (int *)param_1[8];
  while (piVar3 = piVar2, piVar3 != (int *)0x0) {
    iVar4 = *piVar3;
    while (iVar1 = iVar4, iVar1 != 0) {
      iVar4 = *(int *)(iVar1 + 8);
      if (iVar1 != 0) {
        FUN_0041b8c0(iVar1);
      }
    }
    piVar2 = (int *)piVar3[4];
    if (piVar3 != (int *)0x0) {
      FUN_0041b8c0((int)piVar3);
    }
  }
  param_1[8] = 0;
  piVar2 = (int *)param_1[9];
  while (piVar3 = piVar2, piVar3 != (int *)0x0) {
    iVar4 = *piVar3;
    while (iVar1 = iVar4, iVar1 != 0) {
      iVar4 = *(int *)(iVar1 + 8);
      if (iVar1 != 0) {
        FUN_0041b8c0(iVar1);
      }
    }
    piVar2 = (int *)piVar3[4];
    if (piVar3 != (int *)0x0) {
      FUN_0041b8c0((int)piVar3);
    }
  }
  param_1[9] = 0;
  if (param_1 != (undefined4 *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return;
}



undefined4 __cdecl FUN_00407170(undefined4 *param_1,int param_2,byte *param_3,undefined4 *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  uint *local_10;
  uint *local_c;
  uint local_8;
  uint local_4;
  
  puVar1 = FUN_0040a880(1,0x14);
  puVar1[4] = 0;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  local_10 = (uint *)0x0;
  local_c = (uint *)0x0;
  FUN_004055b0(param_1,param_3);
  iVar4 = 2;
  bVar7 = true;
  pbVar5 = param_3;
  pbVar6 = &DAT_0042da68;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar7);
joined_r0x004071bc:
  if (!bVar7) {
    iVar4 = FUN_004072d0(param_2,param_3,(int *)&local_8,(int *)&local_4);
    if (iVar4 == 0) {
      return 0;
    }
    puVar2 = FUN_0040a880(1,0xc);
    *puVar2 = local_8;
    puVar2[2] = 0;
    puVar2[1] = local_4;
    if (local_10 == (uint *)0x0) {
      *puVar1 = (uint)puVar2;
    }
    else {
      local_10[2] = (uint)puVar2;
    }
    puVar1[1] = puVar1[1] + 1;
    FUN_004055b0(param_1,param_3);
    iVar4 = 2;
    bVar7 = true;
    pbVar5 = param_3;
    pbVar6 = &DAT_0042da68;
    do {
      local_10 = puVar2;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar7);
    goto joined_r0x004071bc;
  }
  FUN_004055b0(param_1,param_3);
  iVar4 = 2;
  bVar7 = true;
  pbVar5 = param_3;
  pbVar6 = &DAT_0042da6c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar7);
  do {
    if (bVar7) {
      *param_4 = puVar1;
      return 1;
    }
    puVar2 = FUN_0040a880(1,8);
    puVar3 = FUN_0041a290((char *)param_3);
    *puVar2 = (uint)puVar3;
    puVar2[1] = 0;
    if (local_c == (uint *)0x0) {
      puVar1[2] = (uint)puVar2;
    }
    else {
      local_c[1] = (uint)puVar2;
    }
    puVar1[3] = puVar1[3] + 1;
    FUN_004055b0(param_1,param_3);
    iVar4 = 2;
    bVar7 = true;
    pbVar5 = param_3;
    pbVar6 = &DAT_0042da6c;
    do {
      local_c = puVar2;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar7);
  } while( true );
}



undefined4 __cdecl FUN_004072d0(int param_1,byte *param_2,int *param_3,int *param_4)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  bool bVar8;
  int *local_c;
  
  piVar2 = *(int **)(param_1 + 0x1c);
  if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {
    iVar5 = FUN_0041f265((char *)param_2,&DAT_0042da70);
    if (iVar5 == 1) {
      *param_4 = *param_3;
      return 1;
    }
  }
  else {
    param_1 = 0;
    if (0 < DAT_00435524) {
      local_c = DAT_00435534;
      do {
        iVar5 = 0;
        if (0 < *local_c) {
          piVar7 = piVar2 + *(int *)((DAT_0043552c - (int)DAT_00435534) + (int)local_c);
          do {
            pbVar3 = (byte *)*piVar7;
            pbVar6 = param_2;
            do {
              bVar1 = *pbVar3;
              bVar8 = bVar1 < *pbVar6;
              if (bVar1 != *pbVar6) {
LAB_00407357:
                iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_0040735c;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar8 = bVar1 < pbVar6[1];
              if (bVar1 != pbVar6[1]) goto LAB_00407357;
              pbVar3 = pbVar3 + 2;
              pbVar6 = pbVar6 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_0040735c:
            if (iVar4 == 0) {
              *param_3 = param_1;
              *param_4 = iVar5;
              return 1;
            }
            iVar5 = iVar5 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar5 < *local_c);
        }
        param_1 = param_1 + 1;
        local_c = local_c + 1;
      } while (param_1 < DAT_00435524);
    }
  }
  return 0;
}



undefined4 FUN_004073f0(void)

{
  return DAT_00432d94;
}



int __cdecl FUN_00407400(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int local_4;
  
  local_4 = 0;
  uVar2 = FUN_0041f299((int)*param_1);
  uVar3 = FUN_0041f299((int)*param_2);
  if (uVar2 == uVar3) {
    pcVar4 = param_1;
    do {
      cVar1 = *pcVar4;
      local_4 = local_4 + 1;
      pcVar4 = pcVar4 + 1;
      if (cVar1 == '\0') {
        return 0;
      }
      uVar2 = FUN_0041f299((int)pcVar4[(int)param_2 - (int)param_1]);
      uVar3 = FUN_0041f299((int)*pcVar4);
    } while (uVar3 == uVar2);
  }
  return (int)param_1[local_4] - (int)param_2[local_4];
}



void __cdecl FUN_00407480(int *param_1,int *param_2,int param_3)

{
  undefined **ppuVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  void *this;
  undefined **ppuVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  int local_804;
  byte local_800 [2048];
  
  cVar3 = FUN_0041ee9b(param_1);
  if (param_3 != 0) {
    FUN_0041b3a0(cVar3,param_2);
  }
  FUN_004055b0(param_1,local_800);
  iVar4 = FUN_00407400((char *)local_800,&DAT_0042da74);
  if (iVar4 != 0) {
    iVar4 = 2;
    bVar10 = true;
    pbVar8 = local_800;
    pbVar9 = &DAT_0042da78;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar10 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar10);
    if (!bVar10) goto LAB_0040791a;
  }
  if (param_3 != 0) {
    FUN_0041f46a((char *)local_800,param_2);
    FUN_0041b3a0(' ',param_2);
  }
  FUN_004055b0(param_1,local_800);
  iVar4 = FUN_00407400((char *)local_800,s_COMMAND_0042da7c);
  if (iVar4 != 0) {
LAB_0040791a:
    if (param_3 != 0) {
      FUN_0041f46a((char *)local_800,param_2);
      FUN_0041b3a0(' ',param_2);
    }
    FUN_00405550(param_1,param_2,param_3);
    return;
  }
  if (param_3 != 0) {
    FUN_0041f46a((char *)local_800,param_2);
    FUN_0041b3a0(' ',param_2);
  }
  FUN_004055b0(param_1,local_800);
  if (param_3 != 0) {
    FUN_0041f46a((char *)local_800,param_2);
    FUN_0041b3a0(' ',param_2);
  }
  iVar4 = FUN_00407400((char *)local_800,s_LANGUAGE_VHDL_0042da84);
  if (iVar4 == 0) {
    DAT_00432d98 = 1;
  }
  else {
    iVar4 = FUN_00407400((char *)local_800,s_LANGUAGE_VERILOG_0042da94);
    if (iVar4 == 0) {
      DAT_00432d98 = 2;
    }
    else {
      iVar4 = FUN_00407400((char *)local_800,s_USERCODE_0042daa8);
      if (iVar4 == 0) {
        FUN_004055b0(param_1,local_800);
joined_r0x004078dd:
        if (param_3 == 0) goto LAB_00407904;
        FUN_0041f46a((char *)local_800,param_2);
        FUN_0041b3a0(' ',param_2);
      }
      else {
        iVar4 = FUN_00407400((char *)local_800,s_PROPERTY_0042dab4);
        if (iVar4 == 0) {
          FUN_004055b0(param_1,local_800);
          if (param_3 != 0) {
            FUN_0041f46a((char *)local_800,param_2);
            FUN_0041b3a0(' ',param_2);
          }
          FUN_004055b0(param_1,local_800);
          if (local_800[0] != 0x23) goto joined_r0x004078dd;
          FUN_0041f068(0x20,param_1);
          uVar6 = 0xffffffff;
          pbVar8 = local_800;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            bVar2 = *pbVar8;
            pbVar8 = pbVar8 + 1;
          } while (bVar2 != 0);
          for (iVar4 = ~uVar6 - 2; (iVar4 != 0 && (local_800[iVar4] != 0x23)); iVar4 = iVar4 + -1) {
            FUN_0041f068((int)(char)local_800[iVar4],param_1);
          }
          FUN_0041f068(0x23,param_1);
        }
        else {
          iVar4 = FUN_00407400((char *)local_800,s_MERGE_PinNode_0042dac0);
          if ((iVar4 == 0) ||
             (iVar4 = FUN_00407400((char *)local_800,s_IREG_PinNode_0042dad0), iVar4 == 0)) {
            FUN_004055b0(param_1,local_800);
            if (param_3 != 0) {
              FUN_0041f46a((char *)local_800,param_2);
              FUN_0041b3a0(' ',param_2);
            }
            FUN_004055b0(param_1,local_800);
            if (param_3 != 0) {
              FUN_0041f46a((char *)local_800,param_2);
              FUN_0041b3a0(' ',param_2);
            }
            FUN_004055b0(param_1,local_800);
            goto joined_r0x004078dd;
          }
          iVar4 = FUN_00407400((char *)local_800,s_ESPRESSO_0042dae0);
          if (iVar4 == 0) {
            FUN_004055b0(param_1,local_800);
            local_804 = FUN_0041f45f(this,local_800);
            if (param_3 != 0) {
              FUN_0041f46a((char *)local_800,param_2);
              FUN_0041b3a0(' ',param_2);
            }
            if (local_804 == 0) {
              iVar4 = 0;
              if (PTR_DAT_0042fb08 != (undefined *)0x0) {
                ppuVar7 = &PTR_DAT_0042fb08;
                do {
                  iVar5 = FUN_00407400((char *)local_800,*ppuVar7);
                  if (iVar5 == 0) {
                    *(undefined4 *)(&PTR_DAT_0042fb0c)[iVar4 * 3] = (&DAT_0042fb10)[iVar4 * 3];
                    break;
                  }
                  ppuVar1 = ppuVar7 + 3;
                  ppuVar7 = ppuVar7 + 3;
                  iVar4 = iVar4 + 1;
                } while (*ppuVar1 != (undefined *)0x0);
              }
              if ((&PTR_DAT_0042fb08)[iVar4 * 3] == (undefined *)0x0) {
                FUN_0040aa50(2,3);
                FUN_0040a940();
                FUN_0040aa50(2,4);
                FUN_0040a950();
                FUN_0040aa50(2,0x11);
                FUN_0040aa50(2,7);
                FUN_0040aa50(4,0xe);
              }
            }
            if (0 < local_804) {
              do {
                FUN_004055b0(param_1,local_800);
                if (param_3 != 0) {
                  FUN_0041f46a((char *)local_800,param_2);
                  FUN_0041b3a0(' ',param_2);
                }
                iVar4 = 8;
                bVar10 = true;
                pbVar8 = local_800;
                pbVar9 = (byte *)s__Dcheck_0042daec;
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar10 = *pbVar8 == *pbVar9;
                  pbVar8 = pbVar8 + 1;
                  pbVar9 = pbVar9 + 1;
                } while (bVar10);
                if (bVar10) {
                  DAT_00432d94 = 1;
                }
                else {
                  iVar4 = 10;
                  bVar10 = true;
                  pbVar8 = local_800;
                  pbVar9 = (byte *)s__Dso_both_0042daf4;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar10 = *pbVar8 == *pbVar9;
                    pbVar8 = pbVar8 + 1;
                    pbVar9 = pbVar9 + 1;
                  } while (bVar10);
                  if (bVar10) {
                    DAT_00432d94 = 2;
                  }
                  else {
                    iVar4 = 5;
                    bVar10 = true;
                    pbVar8 = local_800;
                    pbVar9 = &DAT_0042db00;
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar10 = *pbVar8 == *pbVar9;
                      pbVar8 = pbVar8 + 1;
                      pbVar9 = pbVar9 + 1;
                    } while (bVar10);
                    if (bVar10) {
                      DAT_00432d94 = 0;
                    }
                  }
                }
                local_804 = local_804 + -1;
              } while (local_804 != 0);
            }
          }
        }
      }
    }
  }
  if (param_3 != 0) {
    FUN_0041b3a0('\n',param_2);
  }
LAB_00407904:
  DAT_00432d90 = DAT_00432d90 + 1;
  return;
}



uint * __cdecl FUN_00407950(short *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint unaff_EDI;
  int iVar7;
  int local_8;
  
  puVar2 = *(uint **)(DAT_0043554c + 4);
  FUN_004171c0((int)puVar2,DAT_00435554);
  iVar6 = 0;
  if (0 < param_2) {
    do {
      FUN_00417240(puVar2,puVar2,*(int *)(DAT_00435548 + iVar6 * 4));
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_2);
  }
  iVar6 = param_3 + 1;
  if (iVar6 < DAT_00435524) {
    do {
      FUN_00417240(puVar2,puVar2,*(int *)(DAT_00435548 + iVar6 * 4));
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_00435524);
  }
  local_8 = 0;
  puVar3 = *(uint **)(param_1 + 0xc);
  puVar1 = puVar3 + *(int *)(param_1 + 2) * *(int *)(param_1 + 8);
  for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_1 + 2)) {
    iVar7 = 1;
    iVar6 = param_2;
    if (param_2 <= param_3) {
      do {
        iVar4 = FUN_004170b0(puVar3,*(int *)(DAT_00435548 + iVar6 * 4));
        if ((1 < iVar4) && (iVar7 = iVar4 * iVar7, 0xffff < iVar7)) {
          FUN_00408c40((int *)s_unreasonable_expansion_in_unrave_0042db08,unaff_EDI);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= param_3);
    }
    local_8 = local_8 + iVar7;
  }
  puVar5 = FUN_00417930(local_8,DAT_00435520,unaff_EDI);
  puVar3 = *(uint **)(param_1 + 0xc);
  puVar1 = puVar3 + *(int *)(param_1 + 2) * *(int *)(param_1 + 8);
  for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_1 + 2)) {
    FUN_00407ac0(puVar3,param_2,param_3,puVar2,(int)puVar5);
  }
  FUN_00417a40(param_1);
  return puVar5;
}



void __cdecl FUN_00407ac0(uint *param_1,int param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_14;
  int local_10;
  
  puVar3 = (uint *)*DAT_0043554c;
  iVar10 = 1;
  local_14 = 1;
  FUN_004171c0((int)puVar3,param_4);
  iVar9 = param_2;
  if (param_2 <= param_3) {
    do {
      iVar5 = FUN_004170b0(param_1,*(int *)(DAT_00435548 + iVar9 * 4));
      if (iVar5 < 2) {
        FUN_00417240(puVar3,puVar3,*(int *)(DAT_00435548 + iVar9 * 4));
      }
      else {
        iVar10 = iVar5 * iVar10;
        local_14 = iVar10;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 <= param_3);
  }
  FUN_004171f0(puVar3,param_1,(int)puVar3);
  iVar9 = *(int *)(param_5 + 0x10);
  iVar5 = *(int *)(param_5 + 4);
  iVar6 = *(int *)(param_5 + 0x18);
  *(int *)(param_5 + 0x10) = iVar9 + iVar10;
  for (uVar8 = iVar6 + iVar5 * iVar9 * 4; uVar8 < (uint)(iVar6 + iVar5 * (iVar9 + iVar10) * 4);
      uVar8 = uVar8 + *(int *)(param_5 + 4) * 4) {
    FUN_004171c0(uVar8,puVar3);
  }
  local_10 = param_2;
  iVar10 = local_14;
  if (param_2 <= param_3) {
    do {
      iVar6 = FUN_004170b0(param_1,*(int *)(DAT_00435548 + local_10 * 4));
      iVar5 = iVar10;
      if (1 < iVar6) {
        iVar5 = iVar10 / iVar6;
        param_2 = 0;
        iVar6 = *(int *)(DAT_0043552c + local_10 * 4);
        if (iVar6 <= *(int *)(DAT_00435530 + local_10 * 4)) {
          do {
            uVar8 = 1 << ((byte)iVar6 & 0x1f);
            iVar1 = (iVar6 >> 5) * 4 + 4;
            iVar4 = param_2;
            if ((param_1[(iVar6 >> 5) + 1] & uVar8) != 0) {
              for (; iVar4 < local_14; iVar4 = iVar4 + iVar10) {
                if (0 < iVar5) {
                  iVar7 = iVar4 + iVar9;
                  iVar11 = iVar5;
                  do {
                    iVar2 = *(int *)(param_5 + 0x18) + *(int *)(param_5 + 4) * iVar7 * 4;
                    iVar7 = iVar7 + 1;
                    iVar11 = iVar11 + -1;
                    *(uint *)(iVar1 + iVar2) = *(uint *)(iVar1 + iVar2) | uVar8;
                  } while (iVar11 != 0);
                }
              }
              param_2 = param_2 + iVar5;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 <= *(int *)(DAT_00435530 + local_10 * 4));
        }
      }
      local_10 = local_10 + 1;
      iVar10 = iVar5;
    } while (local_10 <= param_3);
  }
  return;
}



void __cdecl FUN_00407ca0(short *param_1,int param_2)

{
  FUN_00407950(param_1,param_2,DAT_00435524 + -1);
  return;
}



uint * __cdecl FUN_00407cc0(short *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  puVar1 = FUN_00404ab0((int)param_1,&LAB_004192c0);
  puVar1 = FUN_00404ba0(puVar1,uVar2,uVar3);
  FUN_00417a40(param_1);
  return puVar1;
}



uint * __cdecl FUN_00407d40(short *param_1,undefined *param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = DAT_00435520;
  piVar3 = (int *)FUN_00418060((int)param_1);
  puVar1 = *(uint **)(param_1 + 0xc);
  puVar5 = puVar1 + *(int *)(param_1 + 8) * *(int *)(param_1 + 2);
  for (; puVar1 < puVar5; puVar1 = puVar1 + *(int *)(param_1 + 2)) {
    iVar7 = 0;
    iVar6 = 0;
    piVar4 = piVar3;
    if (0 < iVar2) {
      do {
        if ((puVar1[(iVar6 >> 5) + 1] & 1 << ((byte)iVar6 & 0x1f)) != 0) {
          iVar7 = iVar7 + *piVar4;
        }
        iVar6 = iVar6 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar6 < iVar2);
    }
    *puVar1 = *puVar1 & 0xffff | iVar7 << 0x10;
  }
  if (piVar3 != (int *)0x0) {
    FUN_0041b8c0((int)piVar3);
  }
  piVar3 = (int *)FUN_00404b40((int)param_1);
  FUN_0041ec9c(piVar3,*(undefined4 **)(param_1 + 8),4,param_2);
  puVar5 = FUN_00404ba0(piVar3,*(uint *)(param_1 + 8),*(uint *)(param_1 + 4));
  FUN_00417a40(param_1);
  return puVar5;
}



uint * __cdecl FUN_00407e10(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  uint *local_8;
  
  iVar2 = DAT_00435524;
  iVar6 = -1;
  local_8 = (uint *)0x0;
  if (param_1[4] != 0) {
    puVar1 = (uint *)param_1[6];
    puVar5 = puVar1 + param_1[1] * param_1[4];
    for (; puVar1 < puVar5; puVar1 = puVar1 + param_1[1]) {
      iVar3 = FUN_00417030(puVar1);
      if (iVar6 < iVar3) {
        iVar6 = iVar3;
        local_8 = puVar1;
      }
    }
    puVar1 = (uint *)param_1[6];
    puVar5 = puVar1 + param_1[1] * param_1[4];
    for (; puVar1 < puVar5; puVar1 = puVar1 + param_1[1]) {
      *puVar1 = *puVar1 & 0xffff;
      iVar6 = FUN_00417030(puVar1);
      if (iVar6 < 0x7f) {
        iVar6 = FUN_00417030(puVar1);
      }
      else {
        iVar6 = 0x7f;
      }
      iVar3 = FUN_00418980((int)local_8,puVar1);
      *puVar1 = *puVar1 | ((iVar3 * 0x1ff + iVar2) * 0x80 + iVar6) * 0x10000;
    }
    piVar4 = (int *)FUN_00404b40((int)param_1);
    FUN_0041ec9c(piVar4,(undefined4 *)param_1[4],4,&LAB_004191c0);
    puVar5 = FUN_00404ba0(piVar4,param_1[4],param_1[2]);
    FUN_00417a40((short *)param_1);
    return puVar5;
  }
  return param_1;
}



int __cdecl FUN_00407f20(int param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = (iVar3 + -1 >> 5) + 2;
  }
  puVar2 = FUN_0040a880(1,iVar1 << 2);
  puVar2 = (uint *)FUN_00417140((int *)puVar2,iVar3);
  iVar3 = *(int *)(param_1 + 0x10) + -1;
  if (0 < iVar3) {
    iVar1 = iVar3 * 0x17 + 0x3e5;
    do {
      FUN_004171c0((int)puVar2,
                   (uint *)(*(int *)(param_1 + 0x18) + (iVar1 % iVar3) * *(int *)(param_1 + 4) * 4))
      ;
      FUN_004171c0(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * (iVar1 % iVar3) * 4,
                   (uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * iVar3 * 4));
      FUN_004171c0(*(int *)(param_1 + 0x18) + iVar3 * *(int *)(param_1 + 4) * 4,puVar2);
      iVar3 = iVar3 + -1;
      iVar1 = iVar1 + -0x17;
    } while (0 < iVar3);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  return param_1;
}



int __cdecl FUN_00407ff0(undefined4 *param_1,int *param_2,int *param_3,int param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  uint *puVar11;
  int *piVar12;
  int local_10;
  
  piVar12 = param_1 + 2;
  iVar3 = (param_1[1] - (int)param_1 >> 2) + -3;
  puVar7 = (uint *)*piVar12;
  puVar2 = param_1 + 3;
  while (puVar7 != (uint *)0x0) {
    *puVar7 = *puVar7 & 0xfffff7ff;
    puVar7 = (uint *)*puVar2;
    puVar2 = puVar2 + 1;
  }
  puVar7 = (uint *)*piVar12;
  uVar4 = (*puVar7 & 0x3ff) * 0x20;
  if (uVar4 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (uVar4 - 1 >> 5) + 2;
  }
  puVar6 = FUN_0040a880(1,iVar5 << 2);
  puVar6 = (uint *)FUN_004171c0((int)puVar6,puVar7);
  puVar7 = (uint *)*param_1;
  local_10 = 1;
  *(uint *)*piVar12 = *(uint *)*piVar12 | 0x800;
  do {
    puVar11 = (uint *)*piVar12;
    bVar1 = false;
    piVar10 = piVar12;
    if (puVar11 == (uint *)0x0) break;
    do {
      piVar10 = piVar10 + 1;
      if (((*puVar11 & 0x800) == 0) &&
         (iVar5 = FUN_00419020((int)puVar11,(int)puVar6,puVar7), iVar5 != 0)) {
        FUN_004171f0(puVar6,puVar6,(int)puVar11);
        local_10 = local_10 + 1;
        *puVar11 = *puVar11 | 0x800;
        bVar1 = true;
      }
      puVar11 = (uint *)*piVar10;
    } while (puVar11 != (uint *)0x0);
  } while (bVar1);
  if (puVar6 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar6);
  }
  if (param_4 != 0) {
    FUN_0041b470((byte *)s_COMPONENT_REDUCTION__split_into___0042db30);
  }
  if (local_10 != iVar3) {
    iVar5 = iVar3 * 4 + 0xc;
    puVar7 = FUN_0040a880(1,iVar5);
    *param_2 = (int)puVar7;
    puVar7 = FUN_0040a880(1,iVar5);
    *param_3 = (int)puVar7;
    puVar7 = (uint *)*param_1;
    uVar4 = (*puVar7 & 0x3ff) * 0x20;
    if (uVar4 < 0x21) {
      iVar5 = 2;
    }
    else {
      iVar5 = (uVar4 - 1 >> 5) + 2;
    }
    puVar6 = FUN_0040a880(1,iVar5 * 4);
    uVar8 = FUN_004171c0((int)puVar6,puVar7);
    *(undefined4 *)*param_2 = uVar8;
    puVar7 = (uint *)*param_1;
    uVar4 = (*puVar7 & 0x3ff) * 0x20;
    if (uVar4 < 0x21) {
      iVar5 = 2;
    }
    else {
      iVar5 = (uVar4 - 1 >> 5) + 2;
    }
    puVar6 = FUN_0040a880(1,iVar5 * 4);
    uVar8 = FUN_004171c0((int)puVar6,puVar7);
    *(undefined4 *)*param_3 = uVar8;
    piVar10 = (int *)(*param_2 + 8);
    piVar9 = (int *)(*param_3 + 8);
    iVar5 = *piVar12;
    while (iVar5 != 0) {
      piVar12 = piVar12 + 1;
      if ((*(byte *)(iVar5 + 1) & 8) == 0) {
        *piVar9 = iVar5;
        piVar9 = piVar9 + 1;
      }
      else {
        *piVar10 = iVar5;
        piVar10 = piVar10 + 1;
      }
      iVar5 = *piVar12;
    }
    *piVar10 = 0;
    *(int **)(*param_2 + 4) = piVar10 + 1;
    *piVar9 = 0;
    *(int **)(*param_3 + 4) = piVar9 + 1;
  }
  return iVar3 - local_10;
}



uint * __cdecl FUN_00408220(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint unaff_ESI;
  uint *puVar6;
  
  iVar3 = *(int *)(DAT_00435548 + DAT_00435568 * 4);
  puVar5 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),DAT_00435520,unaff_ESI);
  puVar6 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar6 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10);
  if (puVar6 < puVar1) {
    do {
      if ((puVar6[(param_2 >> 5) + 1] & 1 << ((byte)param_2 & 0x1f)) != 0) {
        uVar4 = puVar5[4];
        puVar5[4] = uVar4 + 1;
        puVar2 = (uint *)(puVar5[6] + puVar5[1] * uVar4 * 4);
        FUN_00417240(puVar2,puVar6,iVar3);
        *puVar2 = *puVar2 & 0xffff7fff;
      }
      puVar6 = puVar6 + *(int *)(param_1 + 4);
    } while (puVar6 < puVar1);
    return puVar5;
  }
  return puVar5;
}



int __cdecl FUN_004082e0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(DAT_00435548 + DAT_00435568 * 4);
    puVar3 = *(uint **)(param_1 + 0x18);
    puVar1 = puVar3 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
    if (puVar3 < puVar1) {
      do {
        FUN_00417290(puVar3,puVar3,iVar2);
        puVar3[(param_2 >> 5) + 1] = puVar3[(param_2 >> 5) + 1] | 1 << ((byte)param_2 & 0x1f);
        puVar3 = puVar3 + *(int *)(param_1 + 4);
      } while (puVar3 < puVar1);
    }
    return param_1;
  }
  return 0;
}



void __cdecl FUN_00408360(int *param_1,undefined *param_2,undefined *param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(DAT_00435534 + DAT_00435568 * 4)) {
    while( true ) {
      piVar1 = (int *)FUN_00406f70();
      puVar2 = FUN_00408220(*param_1,*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar4);
      *piVar1 = (int)puVar2;
      puVar2 = FUN_00408220(param_1[2],*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar4);
      piVar1[2] = (int)puVar2;
      puVar2 = FUN_00408220(param_1[1],*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar4);
      piVar1[1] = (int)puVar2;
      iVar3 = (*(code *)param_2)(piVar1,iVar4);
      if (iVar3 == 0) break;
      iVar3 = FUN_004082e0(*piVar1,*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar4);
      *piVar1 = iVar3;
      iVar3 = FUN_004082e0(piVar1[2],*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar4);
      piVar1[2] = iVar3;
      iVar3 = FUN_004082e0(piVar1[1],*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar4);
      piVar1[1] = iVar3;
      piVar1[4] = param_1[4];
      iVar3 = (*(code *)param_3)(piVar1,iVar4);
      if (iVar3 == 0) break;
      FUN_00406ff0(piVar1);
      iVar4 = iVar4 + 1;
      if (*(int *)(DAT_00435534 + DAT_00435568 * 4) <= iVar4) {
        return;
      }
    }
    FUN_00406ff0(piVar1);
  }
  return;
}



void __cdecl FUN_00408490(int *param_1,int param_2)

{
  uint unaff_ESI;
  undefined *puVar1;
  
  DAT_00432da4 = FUN_00417930(*(undefined4 *)(*param_1 + 0x10),DAT_00435520,unaff_ESI);
  if (param_2 == 0) {
    puVar1 = &LAB_00408590;
  }
  else {
    puVar1 = &LAB_00408600;
  }
  FUN_00408360(param_1,puVar1,&LAB_00408680);
  FUN_00417a40((short *)*param_1);
  *param_1 = (int)DAT_00432da4;
  return;
}



void __cdecl FUN_004084f0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined *puVar4;
  uint *puVar5;
  
  uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
  if (uVar1 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = (uVar1 - 1 >> 5) + 2;
  }
  puVar5 = DAT_00435550;
  puVar3 = FUN_0040a880(1,iVar2 << 2);
  DAT_00432da0 = FUN_004171c0((int)puVar3,puVar5);
  DAT_00432da4 = FUN_00417930(*(undefined4 *)(*param_1 + 0x10),DAT_00435520,(uint)puVar3);
  if (param_2 == 0) {
    puVar4 = &LAB_004086b0;
  }
  else {
    puVar4 = &LAB_00408780;
  }
  FUN_00408360(param_1,puVar4,FUN_00408850);
  FUN_00417a40((short *)*param_1);
  *param_1 = (int)DAT_00432da4;
  param_1[5] = DAT_00432da0;
  return;
}



undefined4 __cdecl FUN_00408850(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)((short *)param_1[2] + 8) < *(int *)((short *)*param_1 + 8)) {
    FUN_00417a40((short *)*param_1);
    *param_1 = param_1[2];
    param_1[2] = 0;
    iVar2 = param_2 + *(int *)(DAT_0043552c + DAT_00435568 * 4);
    if ((*(byte *)(param_1 + 4) & 4) == 0) goto LAB_004088dc;
    puVar1 = (uint *)(DAT_00432da0 + 4 + (iVar2 >> 5) * 4);
    uVar3 = *puVar1 | 1 << ((byte)iVar2 & 0x1f);
  }
  else {
    FUN_00417a40((short *)param_1[2]);
    param_1[2] = 0;
    if ((*(byte *)(param_1 + 4) & 4) == 0) goto LAB_004088fd;
    iVar2 = param_2 + *(int *)(DAT_0043552c + DAT_00435568 * 4);
LAB_004088dc:
    puVar1 = (uint *)(DAT_00432da0 + 4 + (iVar2 >> 5) * 4);
    uVar3 = *puVar1 & ~(1 << ((byte)iVar2 & 0x1f));
  }
  *puVar1 = uVar3;
LAB_004088fd:
  DAT_00432da4 = FUN_00417860(DAT_00432da4,(short *)*param_1);
  *param_1 = 0;
  return 1;
}



void __cdecl FUN_00408930(int param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = FUN_00402950(param_1);
  FUN_004024a0((int *)puVar2);
  if (*puVar2 != 0) {
    FUN_0041b8c0(*puVar2);
    *puVar2 = 0;
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  iVar3 = 0;
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  param_2[5] = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  param_2[4] = 0;
  if (0 < DAT_00435528) {
    do {
      iVar4 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      param_2[1] = param_2[1] + *(int *)(DAT_00435584 + iVar4);
    } while (iVar3 < DAT_00435528);
  }
  iVar3 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524 + -1) {
    do {
      if (*(int *)(DAT_00435560 + iVar3 * 4) == 0) {
        iVar4 = *(int *)(DAT_00435584 + iVar3 * 4);
      }
      else {
        iVar4 = *(int *)(DAT_00435534 + iVar3 * 4) * *(int *)(param_1 + 0x10) -
                *(int *)(DAT_00435584 + iVar3 * 4);
      }
      iVar3 = iVar3 + 1;
      param_2[3] = param_2[3] + iVar4;
    } while (iVar3 < DAT_00435524 + -1);
  }
  if (DAT_00435528 != DAT_00435524) {
    param_2[2] = *(int *)(DAT_00435534 + -4 + DAT_00435524 * 4) * *(int *)(param_1 + 0x10) -
                 *(int *)(DAT_00435584 + -4 + DAT_00435524 * 4);
  }
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar2 = puVar1 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10);
  for (; puVar1 < puVar2; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    param_2[5] = param_2[5] + (*puVar1 >> 0xf & 1);
  }
  param_2[4] = param_2[1] + param_2[3] + param_2[2];
  return;
}



undefined * FUN_00408a70(undefined4 param_1)

{
  if (DAT_00435528 == DAT_00435524 + -1) {
    FUN_0041ec4a(&DAT_00432da8,(byte *)s_c__d__d__in__d_out__d_tot__d_0042dbc4);
    return &DAT_00432da8;
  }
  FUN_0041ec4a(&DAT_00432da8,(byte *)s_c__d__d__in__d_mv__d_out__d_0042dbe4);
  return &DAT_00432da8;
}



void __cdecl FUN_00408af0(int param_1)

{
  undefined4 local_18 [6];
  
  FUN_00408930(param_1,local_18);
  FUN_00408a70(local_18);
  return;
}



void __cdecl FUN_00408b10(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  return;
}



void __cdecl FUN_00408b40(int param_1)

{
  FUN_00408af0(param_1);
  FUN_0041b470((byte *)s____s_Cost_is__s_0042dc00);
  FUN_0041f0ff((int *)&DAT_00431c98);
  return;
}



void __cdecl FUN_00408b70(int param_1)

{
  undefined4 in_stack_0000000c;
  
  FUN_00408af0(param_1);
  FUN_004163a0(in_stack_0000000c);
  FUN_0041b470((byte *)s____s_Time_was__s__cost_is__s_0042dc14);
  FUN_0041f0ff((int *)&DAT_00431c98);
  return;
}



void __cdecl FUN_00408bb0(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_0041b360();
  (&DAT_004354e0)[param_2] = (&DAT_004354e0)[param_2] + (iVar1 - param_1);
  (&DAT_00435480)[param_2] = (&DAT_00435480)[param_2] + 1;
  FUN_00408930(param_3,param_4);
  if (DAT_00435408 != 0) {
    FUN_00408a70(param_4);
    FUN_004163a0(iVar1 - param_1);
    FUN_0041b470((byte *)s____s_Time_was__s__cost_is__s_0042dc34);
    FUN_0041f0ff((int *)&DAT_00431c98);
  }
  return;
}



void FUN_00408c40(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *unaff_ESI;
  undefined4 unaff_EDI;
  int *unaff_retaddr;
  
  FUN_0040aa50(4,10);
  FUN_0041ef48(1);
  if ((param_2 & 0x100) != 0) {
    FUN_00409f50(unaff_retaddr,(uint *)param_1,0);
    param_2 = param_2 & 0xfffffeff;
    if (param_2 == 0) {
      return;
    }
  }
  if ((param_2 & 0x200) != 0) {
    FUN_00409f50(unaff_retaddr,(uint *)param_1,1);
    param_2 = param_2 & 0xfffffdff;
    if (param_2 == 0) {
      return;
    }
  }
  if (param_2 == 8) {
    FUN_004091d0(param_1);
    return;
  }
  if (param_2 == 0x10) {
    FUN_00409430(param_1,unaff_EDI,unaff_ESI);
    return;
  }
  if (param_2 != 0x80) {
    FUN_00408e40(unaff_retaddr,(int)param_1,param_2);
    FUN_0041b430(unaff_retaddr,(byte *)s__p__d_0042dc54);
    if (param_2 != 1) {
      if ((param_2 & 1) != 0) {
        iVar2 = *param_1;
        uVar3 = *(uint *)(iVar2 + 0x18);
        uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
        for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(*param_1 + 4) * 4) {
          FUN_004097b0(unaff_retaddr,uVar3,0x42dc64);
        }
      }
      if ((param_2 & 2) != 0) {
        iVar2 = param_1[1];
        uVar3 = *(uint *)(iVar2 + 0x18);
        uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
        for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(param_1[1] + 4) * 4) {
          FUN_004097b0(unaff_retaddr,uVar3,0x42dc68);
        }
      }
      if ((param_2 & 4) != 0) {
        iVar2 = param_1[2];
        uVar3 = *(uint *)(iVar2 + 0x18);
        uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
        for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(param_1[2] + 4) * 4) {
          FUN_004097b0(unaff_retaddr,uVar3,0x42dc6c);
        }
      }
      FUN_0041b430(unaff_retaddr,(byte *)s__end_0042dc70);
      return;
    }
    iVar2 = *param_1;
    uVar3 = *(uint *)(iVar2 + 0x18);
    uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
    for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(*param_1 + 4) * 4) {
      FUN_004097b0(unaff_retaddr,uVar3,0x42dc5c);
    }
    FUN_0041b430(unaff_retaddr,&DAT_0042dc60);
    return;
  }
  FUN_00409d40(unaff_retaddr,param_1);
  return;
}



void __cdecl FUN_00408c60(int *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int *unaff_ESI;
  undefined4 unaff_EDI;
  
  if ((param_3 & 0x100) != 0) {
    FUN_00409f50(param_1,param_2,0);
    param_3 = param_3 & 0xfffffeff;
    if (param_3 == 0) {
      return;
    }
  }
  if ((param_3 & 0x200) != 0) {
    FUN_00409f50(param_1,param_2,1);
    param_3 = param_3 & 0xfffffdff;
    if (param_3 == 0) {
      return;
    }
  }
  if (param_3 == 8) {
    FUN_004091d0((int *)param_2);
    return;
  }
  if (param_3 == 0x10) {
    FUN_00409430(param_2,unaff_EDI,unaff_ESI);
    return;
  }
  if (param_3 != 0x80) {
    FUN_00408e40(param_1,(int)param_2,param_3);
    FUN_0041b430(param_1,(byte *)s__p__d_0042dc54);
    if (param_3 != 1) {
      if ((param_3 & 1) != 0) {
        uVar1 = *param_2;
        uVar2 = *(uint *)(uVar1 + 0x18);
        uVar1 = uVar2 + *(int *)(uVar1 + 0x10) * *(int *)(uVar1 + 4) * 4;
        for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(*param_2 + 4) * 4) {
          FUN_004097b0(param_1,uVar2,0x42dc64);
        }
      }
      if ((param_3 & 2) != 0) {
        uVar1 = param_2[1];
        uVar2 = *(uint *)(uVar1 + 0x18);
        uVar1 = uVar2 + *(int *)(uVar1 + 0x10) * *(int *)(uVar1 + 4) * 4;
        for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(param_2[1] + 4) * 4) {
          FUN_004097b0(param_1,uVar2,0x42dc68);
        }
      }
      if ((param_3 & 4) != 0) {
        uVar1 = param_2[2];
        uVar2 = *(uint *)(uVar1 + 0x18);
        uVar1 = uVar2 + *(int *)(uVar1 + 0x10) * *(int *)(uVar1 + 4) * 4;
        for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(param_2[2] + 4) * 4) {
          FUN_004097b0(param_1,uVar2,0x42dc6c);
        }
      }
      FUN_0041b430(param_1,(byte *)s__end_0042dc70);
      return;
    }
    uVar1 = *param_2;
    uVar2 = *(uint *)(uVar1 + 0x18);
    uVar1 = uVar2 + *(int *)(uVar1 + 0x10) * *(int *)(uVar1 + 4) * 4;
    for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(*param_2 + 4) * 4) {
      FUN_004097b0(param_1,uVar2,0x42dc5c);
    }
    FUN_0041b430(param_1,&DAT_0042dc60);
    return;
  }
  FUN_00409d40(param_1,(int *)param_2);
  return;
}



void __cdecl FUN_00408e40(int *param_1,int param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_3 != 1) {
    FUN_0041b430(param_1,(byte *)s__type_0042dc78);
    if ((param_3 & 1) != 0) {
      FUN_0041b3a0('f',param_1);
    }
    if ((param_3 & 2) != 0) {
      FUN_0041b3a0('d',param_1);
    }
    if ((param_3 & 4) != 0) {
      FUN_0041b3a0('r',param_1);
    }
    FUN_0041b3a0('\n',param_1);
  }
  if (DAT_00435564 < 2) {
    FUN_0041b430(param_1,(byte *)s__i__d_0042dc80);
    if (DAT_00435568 != -1) {
      FUN_0041b430(param_1,(byte *)s__o__d_0042dc88);
    }
  }
  else {
    FUN_0041b430(param_1,(byte *)s__mv__d__d_0042dc90);
    iVar4 = DAT_00435528;
    if (DAT_00435528 < DAT_00435524) {
      do {
        FUN_0041b430(param_1,&DAT_0042dc9c);
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_00435524);
    }
    FUN_0041b430(param_1,&DAT_0042dca0);
  }
  if (((*(int *)(param_2 + 0x1c) != 0) && (*(int *)(*(int *)(param_2 + 0x1c) + 4) != 0)) &&
     (0 < DAT_00435528)) {
    FUN_0041b430(param_1,&DAT_0042dca4);
    iVar4 = 4;
    param_3 = 0;
    if (0 < DAT_00435528) {
      do {
        FUN_0041b430(param_1,&DAT_0042dcac);
        uVar3 = 0xffffffff;
        pcVar5 = *(char **)(*(int *)(param_2 + 0x1c) + 4 + *(int *)(DAT_0043552c + param_3 * 4) * 4)
        ;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = iVar4 + ~uVar3;
        if (0x46 < iVar4) {
          FUN_0041b3a0('\n',param_1);
          iVar4 = 0;
        }
        param_3 = param_3 + 1;
      } while ((int)param_3 < DAT_00435528);
    }
    FUN_0041b3a0('\n',param_1);
  }
  if (((*(int *)(param_2 + 0x1c) != 0) &&
      (*(int *)(*(int *)(param_2 + 0x1c) + *(int *)(DAT_0043552c + DAT_00435568 * 4) * 4) != 0)) &&
     (DAT_00435568 != -1)) {
    FUN_0041b430(param_1,&DAT_0042dcb0);
    iVar4 = 3;
    param_3 = 0;
    if (0 < *(int *)(DAT_00435568 * 4 + DAT_00435534)) {
      do {
        FUN_0041b430(param_1,&DAT_0042dcb4);
        uVar3 = 0xffffffff;
        pcVar5 = *(char **)(*(int *)(param_2 + 0x1c) +
                           (*(int *)(DAT_0043552c + DAT_00435568 * 4) + param_3) * 4);
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = iVar4 + ~uVar3;
        if (0x46 < iVar4) {
          FUN_0041b3a0('\n',param_1);
          iVar4 = 0;
        }
        param_3 = param_3 + 1;
      } while ((int)param_3 < *(int *)(DAT_00435568 * 4 + DAT_00435534));
    }
    FUN_0041b3a0('\n',param_1);
  }
  iVar4 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524 + -1) {
    do {
      iVar2 = *(int *)(DAT_00435530 + iVar4 * 4);
      iVar6 = *(int *)(DAT_0043552c + iVar4 * 4);
      if ((*(int *)(param_2 + 0x1c) != 0) && (*(int *)(*(int *)(param_2 + 0x1c) + iVar6 * 4) != 0))
      {
        FUN_0041b430(param_1,(byte *)s__label_var__d_0042dcb8);
        for (; iVar6 <= iVar2; iVar6 = iVar6 + 1) {
          FUN_0041b430(param_1,&DAT_0042dcc8);
        }
        FUN_0041b3a0('\n',param_1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00435524 + -1);
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    iVar4 = *(int *)(DAT_0043552c + DAT_00435568 * 4);
    iVar2 = *(int *)(DAT_00435530 + DAT_00435568 * 4);
    FUN_0041b430(param_1,(byte *)s__phase_0042dccc);
    for (; iVar4 <= iVar2; iVar4 = iVar4 + 1) {
      FUN_0041b3a0(((1 << ((byte)iVar4 & 0x1f) &
                    *(uint *)(*(int *)(param_2 + 0x14) + 4 + (iVar4 >> 5) * 4)) != 0) + '0',param_1)
      ;
    }
    FUN_0041b430(param_1,&DAT_0042dcd4);
  }
  return;
}



void __cdecl FUN_004091d0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  FUN_0041b470((byte *)s__option_unmerged_0042dcd8);
  FUN_00409c60((int)param_1);
  FUN_00409360((int)param_1,(int *)&DAT_00431c98);
  FUN_00409260((int)param_1,(int *)&DAT_00431c98);
  FUN_0041b470((byte *)s__p__d_0042dcec);
  iVar2 = *param_1;
  uVar3 = *(uint *)(iVar2 + 0x18);
  uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
  for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(*param_1 + 4) * 4) {
    FUN_004098e0((int *)&DAT_00431c98,uVar3,param_1[5]);
  }
  FUN_0041b470((byte *)s__end_0042dcf4);
  return;
}



void __cdecl FUN_00409260(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  piVar2 = param_2;
  FUN_0041b430(param_2,(byte *)s__group_0042dcfc);
  iVar4 = 6;
  param_2 = (int *)0x0;
  if (DAT_00435524 != 1 && -1 < DAT_00435524 + -1) {
    do {
      FUN_0041b430(piVar2,&DAT_0042dd04);
      iVar4 = iVar4 + 2;
      iVar5 = *(int *)(DAT_0043552c + (int)param_2 * 4);
      if (iVar5 <= *(int *)(DAT_00435530 + (int)param_2 * 4)) {
        do {
          uVar3 = 0xffffffff;
          pcVar6 = *(char **)(*(int *)(param_1 + 0x1c) + iVar5 * 4);
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          if ((int)((~uVar3 - 1) + iVar4) < 0x4c) {
            if (iVar5 != 0) {
              FUN_0041b3a0(' ',piVar2);
              iVar4 = iVar4 + 1;
            }
          }
          else {
            FUN_0041b430(piVar2,&DAT_0042dd08);
            iVar4 = 0;
          }
          FUN_0041b430(piVar2,&DAT_0042dd0c);
          iVar4 = iVar4 + (~uVar3 - 1);
          iVar5 = iVar5 + 1;
        } while (iVar5 <= *(int *)(DAT_00435530 + (int)param_2 * 4));
      }
      FUN_0041b430(piVar2,&DAT_0042dd10);
      iVar4 = iVar4 + 1;
      param_2 = (int *)((int)param_2 + 1);
    } while ((int)param_2 < DAT_00435524 + -1);
  }
  FUN_0041b430(piVar2,&DAT_0042dd14);
  return;
}



void __cdecl FUN_00409360(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  piVar2 = param_2;
  FUN_0041b430(param_2,(byte *)s__label_0042dd18);
  iVar5 = 6;
  param_2 = (int *)0x0;
  iVar3 = DAT_00435530;
  if (0 < DAT_00435524) {
    do {
      iVar6 = *(int *)(DAT_0043552c + (int)param_2 * 4);
      if (iVar6 <= *(int *)(iVar3 + (int)param_2 * 4)) {
        do {
          uVar4 = 0xffffffff;
          pcVar7 = *(char **)(*(int *)(param_1 + 0x1c) + iVar6 * 4);
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          if ((int)((~uVar4 - 1) + iVar5) < 0x4c) {
            FUN_0041b3a0(' ',piVar2);
            iVar5 = iVar5 + 1;
          }
          else {
            FUN_0041b430(piVar2,&DAT_0042dd20);
            iVar5 = 0;
          }
          FUN_0041b430(piVar2,&DAT_0042dd24);
          iVar5 = iVar5 + (~uVar4 - 1);
          iVar6 = iVar6 + 1;
          iVar3 = DAT_00435530;
        } while (iVar6 <= *(int *)(DAT_00435530 + (int)param_2 * 4));
      }
      param_2 = (int *)((int)param_2 + 1);
    } while ((int)param_2 < DAT_00435524);
  }
  return;
}



void __cdecl FUN_00409430(undefined4 param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  uint in_stack_ffffffe8;
  uint in_stack_fffffff0;
  uint uVar12;
  int iStack_4;
  
  if (DAT_00435568 == -1) {
    FUN_00408c40((int *)s_Cannot_have_no_output_function_f_0042dd28,in_stack_ffffffe8);
  }
  if (DAT_00435564 != 1) {
    FUN_00408c40((int *)s_Must_have_binary_valued_function_0042dd60,in_stack_fffffff0);
  }
  FUN_00409c60((int)param_3);
  iVar11 = 0;
  if (0 < *(int *)(DAT_00435568 * 4 + DAT_00435534)) {
    do {
      FUN_0041b470((byte *)s__s___0042dd9c);
      bVar2 = true;
      uVar4 = 0xffffffff;
      pcVar9 = *(char **)(param_3[7] + (*(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar11) * 4);
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      iVar7 = *param_3;
      uVar10 = *(uint *)(iVar7 + 0x18);
      iVar8 = ~uVar4 + 2;
      uVar4 = uVar10 + *(int *)(iVar7 + 0x10) * *(int *)(iVar7 + 4) * 4;
      for (; uVar10 < uVar4; uVar10 = uVar10 + *(int *)(*param_3 + 4) * 4) {
        iVar7 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar11;
        if ((*(uint *)(uVar10 + 4 + (iVar7 >> 5) * 4) & 1 << ((byte)iVar7 & 0x1f)) != 0) {
          iVar7 = 0;
          uVar12 = uVar10;
          if (bVar2) {
            FUN_0041b470(&DAT_0042dda4);
            iVar8 = iVar8 + 1;
          }
          else {
            FUN_0041b470(&DAT_0042dda8);
            iVar8 = iVar8 + 4;
          }
          bVar2 = false;
          bVar3 = true;
          if (0 < DAT_00435528) {
            iStack_4 = 0;
            do {
              uVar6 = *(uint *)(uVar10 + 4 + (iStack_4 >> 5) * 4) >> ((byte)iStack_4 & 0x1f) & 3;
              if (uVar6 != 3) {
                uVar5 = 0xffffffff;
                pcVar9 = *(char **)(param_3[7] + 4 + *(int *)(DAT_0043552c + iVar7 * 4) * 4);
                do {
                  if (uVar5 == 0) break;
                  uVar5 = uVar5 - 1;
                  cVar1 = *pcVar9;
                  pcVar9 = pcVar9 + 1;
                } while (cVar1 != '\0');
                uVar10 = uVar12;
                if (0x48 < (int)((~uVar5 - 1) + iVar8)) {
                  FUN_0041b470((byte *)s__0042ddb0);
                  iVar8 = 4;
                  uVar10 = uVar12;
                }
                if (!bVar3) {
                  FUN_0041b470(&DAT_0042ddb8);
                  iVar8 = iVar8 + 1;
                }
                bVar3 = false;
                if (uVar6 == 1) {
                  FUN_0041b470(&DAT_0042ddbc);
                  iVar8 = iVar8 + 1;
                }
                FUN_0041b470(&DAT_0042ddc0);
                iVar8 = iVar8 + (~uVar5 - 1);
                uVar12 = uVar10;
              }
              iVar7 = iVar7 + 1;
              iStack_4 = iStack_4 + 2;
            } while (iVar7 < DAT_00435528);
          }
          FUN_0041b470(&DAT_0042ddc4);
          iVar8 = iVar8 + 1;
        }
      }
      FUN_0041b470(&DAT_0042ddc8);
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(DAT_00435568 * 4 + DAT_00435534));
  }
  return;
}



void __cdecl FUN_004096a0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = 0;
  if (0 < DAT_00435528) {
    iVar3 = 0;
    iVar6 = 0;
    do {
      iVar5 = iVar3 >> 5;
      bVar1 = (byte)iVar3;
      iVar3 = iVar3 + 2;
      iVar2 = iVar2 + 1;
      iVar4 = iVar6 + 1;
      *(undefined *)(iVar6 + param_3) =
           (&DAT_0042ddcc)[*(uint *)(param_1 + 4 + iVar5 * 4) >> (bVar1 & 0x1f) & 3];
      iVar6 = iVar4;
    } while (iVar4 < DAT_00435528);
  }
  iVar6 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524 + -1) {
    do {
      *(undefined *)(iVar2 + param_3) = 0x20;
      iVar2 = iVar2 + 1;
      iVar3 = *(int *)(DAT_0043552c + iVar6 * 4);
      iVar4 = iVar2;
      if (iVar3 <= *(int *)(DAT_00435530 + iVar6 * 4)) {
        do {
          bVar1 = (byte)iVar3;
          iVar5 = iVar3 >> 5;
          iVar2 = iVar4 + 1;
          iVar3 = iVar3 + 1;
          *(undefined *)(iVar4 + param_3) =
               (&DAT_0042ddd4)[(1 << (bVar1 & 0x1f) & *(uint *)(param_1 + 4 + iVar5 * 4)) != 0];
          iVar4 = iVar2;
        } while (iVar3 <= *(int *)(DAT_00435530 + iVar6 * 4));
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_00435524 + -1);
  }
  if (DAT_00435568 != -1) {
    iVar6 = *(int *)(DAT_00435530 + DAT_00435568 * 4);
    *(undefined *)(iVar2 + param_3) = 0x20;
    for (iVar3 = *(int *)(DAT_0043552c + DAT_00435568 * 4); iVar2 = iVar2 + 1, iVar3 <= iVar6;
        iVar3 = iVar3 + 1) {
      *(undefined *)(iVar2 + param_3) =
           *(undefined *)
            (param_2 +
            (uint)((1 << ((byte)iVar3 & 0x1f) & *(uint *)(param_1 + 4 + (iVar3 >> 5) * 4)) != 0));
    }
  }
  *(undefined *)(iVar2 + param_3) = 0;
  return;
}



void __cdecl FUN_004097b0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < DAT_00435528) {
    iVar2 = 0;
    do {
      FUN_0041b3a0((&DAT_0042ddd8)
                   [*(uint *)(param_2 + 4 + (iVar2 >> 5) * 4) >> ((byte)iVar2 & 0x1f) & 3],param_1);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 2;
    } while (iVar1 < DAT_00435528);
  }
  iVar1 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524 + -1) {
    do {
      FUN_0041b3a0(' ',param_1);
      iVar2 = *(int *)(DAT_0043552c + iVar1 * 4);
      if (iVar2 <= *(int *)(DAT_00435530 + iVar1 * 4)) {
        do {
          FUN_0041b3a0((&DAT_0042dde0)
                       [(1 << ((byte)iVar2 & 0x1f) & *(uint *)(param_2 + 4 + (iVar2 >> 5) * 4)) != 0
                       ],param_1);
          iVar2 = iVar2 + 1;
        } while (iVar2 <= *(int *)(DAT_00435530 + iVar1 * 4));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00435524 + -1);
  }
  if (DAT_00435568 != -1) {
    iVar1 = *(int *)(DAT_00435530 + DAT_00435568 * 4);
    FUN_0041b3a0(' ',param_1);
    for (iVar2 = *(int *)(DAT_0043552c + DAT_00435568 * 4); iVar2 <= iVar1; iVar2 = iVar2 + 1) {
      FUN_0041b3a0(*(char *)((uint)((1 << ((byte)iVar2 & 0x1f) &
                                    *(uint *)(param_2 + 4 + (iVar2 >> 5) * 4)) != 0) + param_3),
                   param_1);
    }
  }
  FUN_0041b3a0('\n',param_1);
  return;
}



void __cdecl FUN_004098e0(int *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = 0;
  iVar4 = DAT_00435530;
  iVar5 = DAT_00435528;
  if (0 < DAT_00435528) {
    do {
      iVar3 = *(int *)(DAT_0043552c + iVar2 * 4);
      if (iVar3 <= *(int *)(iVar4 + iVar2 * 4)) {
        do {
          FUN_0041b3a0((&DAT_0042dde4)
                       [(1 << ((byte)iVar3 & 0x1f) & *(uint *)(param_2 + 4 + (iVar3 >> 5) * 4)) != 0
                       ],param_1);
          iVar3 = iVar3 + 1;
          iVar4 = DAT_00435530;
          iVar5 = DAT_00435528;
        } while (iVar3 <= *(int *)(DAT_00435530 + iVar2 * 4));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  iVar2 = DAT_00435524;
  if (iVar5 < DAT_00435524 + -1) {
    do {
      iVar3 = *(int *)(DAT_0043552c + iVar5 * 4);
      if (iVar3 <= *(int *)(iVar4 + iVar5 * 4)) {
        do {
          FUN_0041b3a0((&DAT_0042dde8)
                       [(1 << ((byte)iVar3 & 0x1f) & *(uint *)(param_2 + 4 + (iVar3 >> 5) * 4)) != 0
                       ],param_1);
          iVar3 = iVar3 + 1;
          iVar4 = DAT_00435530;
          iVar2 = DAT_00435524;
        } while (iVar3 <= *(int *)(DAT_00435530 + iVar5 * 4));
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2 + -1);
  }
  if (DAT_00435568 != -1) {
    iVar2 = iVar2 + -1;
    FUN_0041b3a0(' ',param_1);
    iVar4 = *(int *)(DAT_0043552c + iVar2 * 4);
    if (iVar4 <= *(int *)(DAT_00435530 + iVar2 * 4)) {
      do {
        if ((param_3 == 0) ||
           (puVar1 = &DAT_0042ddf0,
           (*(uint *)(param_3 + 4 + (iVar4 >> 5) * 4) & 1 << ((byte)iVar4 & 0x1f)) != 0)) {
          puVar1 = &DAT_0042ddec;
        }
        FUN_0041b3a0(puVar1[(1 << ((byte)iVar4 & 0x1f) & *(uint *)(param_2 + 4 + (iVar4 >> 5) * 4))
                            != 0],param_1);
        iVar4 = iVar4 + 1;
      } while (iVar4 <= *(int *)(DAT_00435530 + iVar2 * 4));
    }
  }
  FUN_0041b3a0('\n',param_1);
  return;
}



void __cdecl FUN_00409a60(int param_1)

{
  FUN_004096a0(param_1,0x42ddf4,0x432e70);
  return;
}



void __cdecl FUN_00409a80(int param_1)

{
  FUN_004096a0(param_1,0x42ddf8,0x432f70);
  return;
}



void __cdecl FUN_00409aa0(int *param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  
  if (DAT_00435520 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar5 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar2 << 2);
  puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar5);
  if ((DAT_00435570 != 0) && (param_3 == 0)) {
    FUN_0041b470(&DAT_0042ddfc);
  }
  FUN_0041b470((byte *)s__s__d___ord_T___d_0042de00);
  if (DAT_00435570 != 0) {
    FUN_00409a60(*param_1);
    FUN_0041b470((byte *)s_cofactor__s_0042de14);
    piVar4 = param_1 + 2;
    puVar1 = (uint *)param_1[2];
    while (puVar1 != (uint *)0x0) {
      piVar4 = piVar4 + 1;
      iVar2 = FUN_00417240(puVar3,puVar1,*param_1);
      FUN_00409a60(iVar2);
      FUN_0041b470((byte *)s__4d___s_0042de24);
      puVar1 = (uint *)*piVar4;
    }
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return;
}



void __cdecl FUN_00409b90(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_00435570 != 0) && (param_3 == 0)) {
    FUN_0041b470(&DAT_0042de30);
  }
  FUN_0041b470((byte *)s__s__d___ord_T___d_0042de34);
  if (DAT_00435570 != 0) {
    uVar2 = *(uint *)(param_1 + 0x18);
    uVar1 = uVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
    for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(param_1 + 4) * 4) {
      FUN_00409a60(uVar2);
      FUN_0041b470((byte *)s__4d___s_0042de48);
    }
  }
  return;
}



void __cdecl FUN_00409c20(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar1 = uVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(param_1 + 4) * 4) {
    FUN_00409a60(uVar2);
    FUN_0041b470(&DAT_0042de54);
  }
  return;
}



void __cdecl FUN_00409c60(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    FUN_00406fa0(param_1);
  }
  iVar5 = 0;
  if (0 < DAT_00435524) {
    do {
      uVar3 = 0;
      if (0 < *(int *)(DAT_00435534 + iVar5 * 4)) {
        do {
          iVar4 = *(int *)(DAT_0043552c + iVar5 * 4) + uVar3;
          if (*(int *)(*(int *)(param_1 + 0x1c) + iVar4 * 4) == 0) {
            puVar1 = FUN_0040a880(1,0xf);
            *(uint **)(*(int *)(param_1 + 0x1c) + iVar4 * 4) = puVar1;
            if (iVar5 < DAT_00435528) {
              uVar2 = uVar3 & 0x80000001;
              bVar6 = uVar2 == 0;
              if ((int)uVar2 < 0) {
                bVar6 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
              }
              if (bVar6) {
                FUN_0041ec4a(*(undefined **)(*(int *)(param_1 + 0x1c) + iVar4 * 4),
                             (byte *)s_v_d_bar_0042de58);
              }
              else {
                FUN_0041ec4a(*(undefined **)(*(int *)(param_1 + 0x1c) + iVar4 * 4),&DAT_0042de60);
              }
            }
            else {
              FUN_0041ec4a(*(undefined **)(*(int *)(param_1 + 0x1c) + iVar4 * 4),
                           (byte *)s_v_d__d_0042de64);
            }
          }
          uVar3 = uVar3 + 1;
        } while ((int)uVar3 < *(int *)(DAT_00435534 + iVar5 * 4));
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00435524);
  }
  return;
}



void __cdecl FUN_00409d40(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_2;
  uVar3 = *(uint *)(iVar2 + 0x18);
  uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
  for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(*param_2 + 4) * 4) {
    FUN_00409dc0(param_1,(int)param_2,uVar3,0x42de6c);
  }
  iVar2 = param_2[1];
  uVar3 = *(uint *)(iVar2 + 0x18);
  uVar1 = uVar3 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4) * 4;
  for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(param_2[1] + 4) * 4) {
    FUN_00409dc0(param_1,(int)param_2,uVar3,0x42de70);
  }
  return;
}



void __cdecl FUN_00409dc0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint unaff_EDI;
  int iVar3;
  bool bVar4;
  
  iVar3 = 0;
  if (0 < DAT_00435528) {
    iVar2 = 0;
    do {
      FUN_0041b3a0((&DAT_0042de74)
                   [*(uint *)(param_3 + 4 + (iVar2 >> 5) * 4) >> ((byte)iVar2 & 0x1f) & 3],param_1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 2;
    } while (iVar3 < DAT_00435528);
  }
  iVar3 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524 + -1) {
    do {
      FUN_0041b3a0(' ',param_1);
      iVar2 = FUN_00417560(*(uint **)(DAT_00435548 + iVar3 * 4),param_3);
      if (iVar2 == 0) {
        iVar1 = -1;
        iVar2 = *(int *)(DAT_0043552c + iVar3 * 4);
        if (iVar2 <= *(int *)(DAT_00435530 + iVar3 * 4)) {
          do {
            if (((*(uint *)(param_3 + 4 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0) &&
               (bVar4 = iVar1 != -1, iVar1 = iVar2, bVar4)) {
              FUN_00408c40((int *)s_more_than_1_part_in_a_symbolic_v_0042de7c,unaff_EDI);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 <= *(int *)(DAT_00435530 + iVar3 * 4));
          if (iVar1 != -1) {
            FUN_0041f46a(*(char **)(*(int *)(param_2 + 0x1c) + iVar1 * 4),param_1);
            goto LAB_00409eb7;
          }
        }
        FUN_0041b3a0('~',param_1);
      }
      else {
        FUN_0041b3a0('-',param_1);
      }
LAB_00409eb7:
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00435524 + -1);
  }
  iVar3 = DAT_00435568;
  if (DAT_00435568 != -1) {
    FUN_0041b3a0(' ',param_1);
    iVar2 = *(int *)(DAT_0043552c + iVar3 * 4);
    if (iVar2 <= *(int *)(DAT_00435530 + iVar3 * 4)) {
      do {
        FUN_0041b3a0(*(char *)((uint)((1 << ((byte)iVar2 & 0x1f) &
                                      *(uint *)(param_3 + 4 + (iVar2 >> 5) * 4)) != 0) + param_4),
                     param_1);
        iVar2 = iVar2 + 1;
      } while (iVar2 <= *(int *)(DAT_00435530 + iVar3 * 4));
    }
  }
  FUN_0041b3a0('\n',param_1);
  return;
}



void __cdecl FUN_00409f50(int *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  short *psVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int local_10;
  int local_c;
  uint *local_8;
  
  if (1 < DAT_00435524 - DAT_00435528) {
    FUN_00409c60((int)param_2);
    local_c = DAT_00435528;
    if (DAT_00435528 < DAT_00435524 + -1) {
      do {
        uVar5 = *(uint *)(DAT_00435534 + local_c * 4);
        puVar1 = FUN_0040a880(1,uVar5 * 4);
        iVar2 = 0;
        puVar4 = puVar1;
        if (0 < (int)uVar5) {
          do {
            uVar7 = *(int *)(DAT_0043552c + local_c * 4) + iVar2;
            iVar2 = iVar2 + 1;
            *puVar4 = uVar7;
            puVar4 = puVar4 + 1;
          } while (iVar2 < (int)uVar5);
        }
        puVar4 = puVar1;
        psVar3 = (short *)FUN_00417a20(*param_2);
        puVar4 = FUN_00418550(psVar3,(int *)puVar4,uVar5);
        if (puVar1 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar1);
        }
        iVar2 = 0;
        if (0 < (int)puVar4[4]) {
          do {
            uVar5 = FUN_00417030((uint *)(puVar4[6] + puVar4[1] * iVar2 * 4));
            if ((uVar5 == 1) || (iVar8 = iVar2, uVar5 == puVar4[2])) {
              iVar8 = iVar2 + -1;
              FUN_00417b90((int)puVar4,iVar2);
            }
            iVar2 = iVar8 + 1;
          } while (iVar2 < (int)puVar4[4]);
        }
        puVar1 = FUN_0040a880(1,puVar4[4] << 2);
        iVar2 = 0;
        if (0 < (int)puVar4[4]) {
          do {
            iVar8 = puVar4[1] * iVar2;
            iVar2 = iVar2 + 1;
            *(uint *)(puVar4[6] + iVar8 * 4) = *(uint *)(puVar4[6] + iVar8 * 4) & 0xfffff7ff;
          } while (iVar2 < (int)puVar4[4]);
        }
        iVar2 = 0;
        puVar9 = puVar1;
        if (0 < (int)puVar4[4]) {
          do {
            *puVar9 = 0;
            if ((*(uint *)(puVar4[6] + puVar4[1] * iVar2 * 4) & 0x800) == 0) {
              *puVar9 = 1;
              iVar8 = iVar2 + 1;
              if (iVar8 < (int)puVar4[4]) {
                do {
                  iVar6 = FUN_004174c0((uint *)(puVar4[6] + puVar4[1] * iVar2 * 4),
                                       puVar4[6] + puVar4[1] * iVar8 * 4);
                  if (iVar6 != 0) {
                    *puVar9 = *puVar9 + 1;
                    *(uint *)(puVar4[6] + puVar4[1] * iVar8 * 4) =
                         *(uint *)(puVar4[6] + puVar4[1] * iVar8 * 4) | 0x800;
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < (int)puVar4[4]);
              }
            }
            iVar2 = iVar2 + 1;
            puVar9 = puVar9 + 1;
          } while (iVar2 < (int)puVar4[4]);
        }
        local_8 = puVar1;
        if (param_3 == 0) {
          FUN_0041b430(param_1,(byte *)s___Symbolic_constraints_for_varia_0042dea8);
          FUN_0041b430(param_1,(byte *)s___unconstrained_weight____d_0042dee0);
          FUN_0041b430(param_1,(byte *)s_num_codes__d_0042df00);
          local_10 = 0;
          if (0 < (int)puVar4[4]) {
            do {
              if (0 < (int)*local_8) {
                FUN_0041b430(param_1,(byte *)s_weight__d__0042df10);
                iVar2 = 0;
                if (0 < (int)puVar4[2]) {
                  do {
                    if ((*(uint *)(puVar4[6] + 4 + (puVar4[1] * local_10 + (iVar2 >> 5)) * 4) &
                        1 << ((byte)iVar2 & 0x1f)) != 0) {
                      FUN_0041b430(param_1,&DAT_0042df1c);
                    }
                    iVar2 = iVar2 + 1;
                  } while (iVar2 < (int)puVar4[2]);
                }
                FUN_0041b430(param_1,&DAT_0042df20);
              }
              local_10 = local_10 + 1;
              local_8 = local_8 + 1;
            } while (local_10 < (int)puVar4[4]);
          }
        }
        else {
          FUN_0041b430(param_1,(byte *)s___Symbolic_constraints_for_varia_0042df24);
          local_10 = 0;
          if (0 < (int)puVar4[4]) {
            do {
              if (0 < (int)*local_8) {
                FUN_0041b430(param_1,(byte *)s___w__d____0042df5c);
                iVar2 = 0;
                if (0 < (int)puVar4[2]) {
                  do {
                    if ((*(uint *)(puVar4[6] + 4 + (puVar4[1] * local_10 + (iVar2 >> 5)) * 4) &
                        1 << ((byte)iVar2 & 0x1f)) != 0) {
                      FUN_0041b430(param_1,&DAT_0042df68);
                    }
                    iVar2 = iVar2 + 1;
                  } while (iVar2 < (int)puVar4[2]);
                }
                FUN_0041b430(param_1,&DAT_0042df6c);
              }
              local_10 = local_10 + 1;
              local_8 = local_8 + 1;
            } while (local_10 < (int)puVar4[4]);
          }
          if (puVar1 != (uint *)0x0) {
            FUN_0041b8c0((int)puVar1);
          }
        }
        local_c = local_c + 1;
      } while (local_c < DAT_00435524 + -1);
    }
  }
  return;
}



int __cdecl FUN_0040a300(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar2 = param_1[6];
  for (piVar1 = (int *)param_1[4]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[5]) {
    iVar7 = *(int *)(piVar1[3] + 4);
    if ((iVar7 < 0) || (param_1[3] <= iVar7)) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(param_1[2] + iVar7 * 4);
    }
    for (iVar3 = *(int *)(piVar1[3] + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {
      iVar6 = *(int *)(iVar3 + 4);
      if ((iVar6 < 0) || (param_1[3] <= iVar6)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1[2] + iVar6 * 4);
      }
      if (*(int *)(iVar6 + 4) < *(int *)(iVar7 + 4)) {
        iVar7 = iVar6;
      }
    }
    piVar5 = *(int **)(iVar7 + 0xc);
    while (piVar5 != (int *)0x0) {
      piVar4 = (int *)piVar5[2];
      iVar7 = *piVar5;
      if ((iVar7 < 0) || (param_1[1] <= iVar7)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = *(int **)(*param_1 + iVar7 * 4);
      }
      piVar5 = piVar4;
      if (((piVar1[1] < piVar8[1]) || ((piVar8[1] == piVar1[1] && (*piVar1 < *piVar8)))) &&
         (iVar7 = FUN_00416df0((int)piVar1,(int)piVar8), iVar7 != 0)) {
        FUN_00412460(param_1,*piVar8);
      }
    }
  }
  return iVar2 - param_1[6];
}



int __cdecl FUN_0040a3d0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = param_1[9];
  piVar2 = (int *)param_1[7];
  do {
    piVar3 = piVar2;
    if (piVar3 == (int *)0x0) {
      return iVar1 - param_1[9];
    }
    piVar2 = (int *)piVar3[5];
    iVar6 = *(int *)piVar3[3];
    if ((iVar6 < 0) || (param_1[1] <= iVar6)) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(*param_1 + iVar6 * 4);
    }
    for (piVar4 = (int *)((int *)piVar3[3])[2]; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[2]) {
      iVar5 = *piVar4;
      if ((iVar5 < 0) || (param_1[1] <= iVar5)) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*param_1 + iVar5 * 4);
      }
      if (*(int *)(iVar5 + 4) < *(int *)(iVar6 + 4)) {
        iVar6 = iVar5;
      }
    }
    for (iVar6 = *(int *)(iVar6 + 0xc); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x10)) {
      iVar5 = *(int *)(iVar6 + 4);
      if ((iVar5 < 0) || (param_1[3] <= iVar5)) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = *(int **)(param_1[2] + iVar5 * 4);
      }
      if ((((param_2 == 0) || (*(int *)(param_2 + *piVar4 * 4) <= *(int *)(param_2 + *piVar3 * 4)))
          && ((piVar3[1] < piVar4[1] || ((piVar4[1] == piVar3[1] && (*piVar3 < *piVar4)))))) &&
         (iVar5 = FUN_00402f40((int)piVar3,(int)piVar4), iVar5 != 0)) {
        FUN_00412520(param_1,*piVar3);
        break;
      }
    }
  } while( true );
}



void __cdecl FUN_0040a4c0(int param_1)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  char *pcVar11;
  uint *local_20;
  uint *local_1c;
  
  iVar8 = 0;
  bVar1 = false;
  FUN_00409c60(param_1);
  puVar2 = FUN_0040a880(1,*(int *)(DAT_00435534 + DAT_00435568 * 4) << 2);
  puVar3 = FUN_0040a880(1,*(int *)(DAT_00435534 + DAT_00435568 * 4) << 2);
  iVar10 = DAT_00435568 * 4;
  if (0 < *(int *)(iVar10 + DAT_00435534)) {
    puVar9 = puVar2;
    do {
      puVar4 = FUN_00408220(*(int *)(param_1 + 8),*(int *)(iVar10 + DAT_0043552c) + iVar8);
      *(uint **)((int)puVar9 + ((int)puVar3 - (int)puVar2)) = puVar4;
      puVar4 = FUN_00402950((int)puVar4);
      puVar4 = FUN_00403160(puVar4);
      *puVar9 = (uint)puVar4;
      iVar10 = DAT_00435568 * 4;
      iVar8 = iVar8 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar8 < *(int *)(iVar10 + DAT_00435534));
  }
  iVar10 = 0;
  iVar8 = *(int *)(DAT_00435568 * 4 + DAT_00435534);
  if (iVar8 != 1 && -1 < iVar8 + -1) {
    iVar7 = (int)puVar2 - (int)puVar3;
    iVar5 = DAT_00435568;
    iVar6 = DAT_00435534;
    local_1c = puVar3;
    do {
      iVar10 = iVar10 + 1;
      if (iVar10 < iVar8) {
        iVar8 = iVar10;
        local_20 = local_1c;
        do {
          local_20 = local_20 + 1;
          iVar5 = FUN_0040a7a0(*(int *)(iVar7 + (int)local_1c),*(int *)(iVar7 + (int)local_20));
          if (iVar5 == 0) {
            iVar5 = FUN_0040a7a0(*(int *)(iVar7 + (int)local_1c),*local_20);
            if (iVar5 != 0) {
              pcVar11 = s___Outputs__d_and_NOT__d___s_and___0042dfa0;
              goto LAB_0040a6b1;
            }
            iVar5 = FUN_0040a7a0(*local_1c,*(int *)(iVar7 + (int)local_20));
            if (iVar5 != 0) {
              pcVar11 = s___Outputs_NOT__d_and__d___s_and___0042dfd4;
              goto LAB_0040a6b1;
            }
            iVar5 = FUN_0040a7a0(*local_1c,*local_20);
            if (iVar5 != 0) {
              pcVar11 = s___Outputs_NOT__d_and_NOT__d___s_a_0042e008;
              goto LAB_0040a6b1;
            }
          }
          else {
            pcVar11 = s___Outputs__d_and__d___s_and__s__a_0042df70;
LAB_0040a6b1:
            FUN_0041b470((byte *)pcVar11);
            bVar1 = true;
          }
          iVar8 = iVar8 + 1;
          iVar5 = DAT_00435568;
          iVar6 = DAT_00435534;
        } while (iVar8 < *(int *)(DAT_00435568 * 4 + DAT_00435534));
      }
      local_1c = local_1c + 1;
      iVar8 = *(int *)(iVar5 * 4 + iVar6);
    } while (iVar10 < iVar8 + -1);
    if (bVar1) goto LAB_0040a734;
  }
  FUN_0041b470((byte *)s___No_outputs_are_equivalent_0042e040);
  iVar5 = DAT_00435568;
  iVar6 = DAT_00435534;
LAB_0040a734:
  iVar10 = 0;
  if (0 < *(int *)(iVar6 + iVar5 * 4)) {
    puVar9 = puVar3;
    do {
      FUN_00417a40(*(short **)((int)puVar9 + ((int)puVar2 - (int)puVar3)));
      FUN_00417a40((short *)*puVar9);
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar10 < *(int *)(DAT_00435534 + DAT_00435568 * 4));
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return;
}



undefined4 __cdecl FUN_0040a7a0(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = FUN_00402950(param_1);
  puVar2 = *(uint **)(param_2 + 0x18);
  puVar1 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
    iVar4 = FUN_0040ef50(puVar3,puVar2);
    if (iVar4 == 0) {
      return 0;
    }
  }
  if (*puVar3 != 0) {
    FUN_0041b8c0(*puVar3);
    *puVar3 = 0;
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  puVar3 = FUN_00402950(param_2);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  while( true ) {
    if (puVar1 <= puVar2) {
      if (*puVar3 != 0) {
        FUN_0041b8c0(*puVar3);
        *puVar3 = 0;
      }
      if (puVar3 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar3);
      }
      return 1;
    }
    iVar4 = FUN_0040ef50(puVar3,puVar2);
    if (iVar4 == 0) break;
    puVar2 = puVar2 + *(int *)(param_1 + 4);
  }
  return 0;
}



uint * __cdecl FUN_0040a880(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *extraout_EDX;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = param_1 * param_2;
  puVar1 = FUN_0041b590(uVar3);
  if (puVar1 == (uint *)0x0) {
    if (DAT_004330b8 != 0) {
      FUN_0040aa50(4,4);
      FUN_0041ef48(1);
    }
    FUN_0040aa50(1,0xb);
    FUN_0041ef48(DAT_0042fbac);
    puVar1 = extraout_EDX;
  }
  puVar4 = puVar1;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined *)puVar4 = 0;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  return puVar1;
}



void __cdecl FUN_0040a8f0(uint *param_1,int param_2)

{
  uint *puVar1;
  
  if (param_2 != 0) {
    puVar1 = FUN_0041ba30(param_1,param_2);
    if (puVar1 == (uint *)0x0) {
      if (DAT_004330b8 != 0) {
        FUN_0040aa50(4,4);
        FUN_0041ef48(1);
      }
      FUN_0040aa50(1,0xb);
      FUN_0041ef48(DAT_0042fbac);
      return;
    }
  }
  return;
}



void FUN_0040a940(void)

{
  return;
}



undefined * FUN_0040a950(void)

{
  int *piVar1;
  int local_4;
  
  local_4 = FUN_0041feca(&local_4);
  piVar1 = FUN_0041fd6a(&local_4);
  FUN_0041f4b8(&DAT_00433070,10,&DAT_0042e9a0,piVar1);
  return &DAT_00433070;
}



void __cdecl FUN_0040a9d0(undefined4 param_1)

{
  DAT_00435da0 = (undefined *)FUN_0041ec37(param_1,&DAT_0042e9a8);
  if (DAT_00435da0 == (undefined *)0x0) {
    FUN_0040aa50(0,0x1d);
    DAT_00435da0 = &DAT_00431c98;
  }
  return;
}



void FUN_0040aa10(void)

{
  FUN_0041ea29(DAT_00435da0);
  return;
}



undefined4 FUN_0040aa20(void)

{
  return DAT_00433090;
}



int FUN_0040aa30(void)

{
  return DAT_0043308c + DAT_00433088 + DAT_00433090;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_0040aa50(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  int unaff_EDI;
  char *pcVar7;
  char *pcVar8;
  
  switch(param_1) {
  case 0:
    _DAT_00435dc0 = s_Error__0042e9ac._0_4_;
    DAT_00433090 = DAT_00433090 + 1;
    _DAT_00435dc4 = s_Error__0042e9ac._4_4_;
    pbVar5 = (&PTR_DAT_0042e120)[param_2];
    _DAT_00435dc8 = s_Error__0042e9ac._8_2_;
    break;
  case 1:
    _DAT_00435dc0 = s_Warning__0042e9c4._0_4_;
    DAT_0043308c = DAT_0043308c + 1;
    _DAT_00435dc4 = s_Warning__0042e9c4._4_4_;
    pbVar5 = (&PTR_DAT_0042e0b8)[param_2];
    _DAT_00435dc8 = s_Warning__0042e9c4._8_4_;
    break;
  case 2:
    DAT_00433088 = DAT_00433088 + 1;
    DAT_00435dc0 = DAT_00433098;
    FUN_0041ffa6(&DAT_00435dc0,(&PTR_s__s_s_s_0042e064)[param_2],(undefined4 *)&stack0x0000000c);
    goto switchD_0040aa69_caseD_5;
  case 3:
    FUN_0041ec4a(&DAT_00435dc0,(byte *)s_Summary__Error_Count____d_Warnin_0042e9d0);
    goto switchD_0040aa69_caseD_5;
  case 4:
    _DAT_00435dc0 = s_Error__0042e9b8._0_4_;
    DAT_00433090 = DAT_00433090 + 1;
    _DAT_00435dc4 = s_Error__0042e9b8._4_4_;
    pbVar5 = (&PTR_DAT_0042e120)[param_2];
    _DAT_00435dc8 = s_Error__0042e9b8._8_2_;
    break;
  default:
    goto switchD_0040aa69_caseD_5;
  }
  FUN_0041ffa6(&DAT_004355a0,pbVar5,(undefined4 *)&stack0x0000000c);
  uVar2 = 0xffffffff;
  pcVar6 = &DAT_004355a0;
  do {
    pcVar8 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar6 = &DAT_00435dc0;
  do {
    pcVar7 = pcVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  pcVar6 = pcVar8 + -uVar2;
  pcVar8 = pcVar7 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar8 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  }
switchD_0040aa69_caseD_5:
  FUN_0041b430(DAT_00435da0,(byte *)&DAT_00435dc0);
  if (DAT_0042e060 != 0) {
    FUN_0041b470((byte *)&DAT_00435dc0);
  }
  if (param_1 != 4) {
    if ((param_1 == 1) && (param_2 == 0xb)) {
      FUN_0040aa50(3,unaff_EDI);
      FUN_0040aa50(2,6);
      FUN_0040aa10();
      FUN_0041ef48(DAT_0042fbac);
    }
    return;
  }
  FUN_0040aa50(3,unaff_EDI);
  FUN_0040aa50(2,6);
  FUN_0040aa10();
  if (param_2 != 6) {
    FUN_0041ef48(1);
    return;
  }
  FUN_0041ef48(0xffffffff);
  return;
}



uint * __cdecl FUN_0040ac70(uint *param_1,uint param_2,short *param_3)

{
  uint *puVar1;
  short *psVar2;
  uint *puVar3;
  uint *puVar4;
  short *psVar5;
  int iVar6;
  uint unaff_EDI;
  int local_30 [2];
  int local_28;
  int local_20;
  int local_18 [4];
  int local_8;
  
  psVar2 = param_3;
  do {
    puVar3 = (uint *)FUN_00417a20((uint)param_1);
    param_3 = (short *)FUN_00417a20(param_2);
    if (DAT_00435460 != 0) {
      FUN_0041b360();
      puVar4 = FUN_00402950((int)param_1);
      puVar4 = FUN_004040f0(puVar4);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)puVar4);
      }
      FUN_00417a40((short *)param_1);
      param_1 = puVar4;
    }
    FUN_00408930((int)param_1,local_30);
    if ((((DAT_00435370 != 0) && (iVar6 = *(int *)(DAT_00435534 + -4 + DAT_00435524 * 4), 1 < iVar6)
         ) && (local_28 != iVar6 * local_30[0])) && (local_28 < 5000)) {
      FUN_0041b360();
      psVar5 = (short *)FUN_00407ca0((short *)param_1,DAT_00435524 + -1);
      param_1 = FUN_004044e0(psVar5);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)param_1);
      }
    }
    puVar1 = (uint *)param_1[6];
    puVar4 = puVar1 + param_1[4] * param_1[1];
    for (; puVar1 < puVar4; puVar1 = puVar1 + param_1[1]) {
      *puVar1 = *puVar1 & 0xffff7fff;
    }
    iVar6 = FUN_0041b360();
    param_1 = FUN_0040b8a0((short *)param_1,(int)psVar2,0);
    FUN_00408bb0(iVar6,4,(int)param_1,local_30);
    iVar6 = FUN_0041b360();
    param_1 = (uint *)FUN_0040e9b0((int *)param_1,param_3);
    FUN_00408bb0(iVar6,5,(int)param_1,local_30);
    if (DAT_00435574 == 0) {
      if (DAT_004354c8 == 0) {
        puVar4 = FUN_00417930(0,DAT_00435520,unaff_EDI);
      }
      else {
        iVar6 = FUN_0041b360();
        puVar4 = FUN_0040b020((uint *)&param_1,&param_3);
        FUN_00408bb0(iVar6,3,(int)puVar4,local_30);
      }
      FUN_00408930((int)param_1,local_30);
      do {
        while( true ) {
          do {
            FUN_00408b10(local_30,local_18);
            iVar6 = FUN_0041b360();
            param_1 = (uint *)FUN_004163f0(param_1,(int)param_3);
            FUN_00408bb0(iVar6,6,(int)param_1,local_30);
            iVar6 = FUN_0041b360();
            param_1 = FUN_0040b8a0((short *)param_1,(int)psVar2,0);
            FUN_00408bb0(iVar6,4,(int)param_1,local_30);
            iVar6 = FUN_0041b360();
            param_1 = (uint *)FUN_0040e9b0((int *)param_1,param_3);
            FUN_00408bb0(iVar6,5,(int)param_1,local_30);
          } while (local_30[0] < local_18[0]);
          FUN_00408b10(local_30,local_18);
          if (DAT_004353cc != 0) break;
          param_1 = (uint *)FUN_0040cc50((uint)param_1,param_3,(int)psVar2,local_30);
          if ((local_18[0] <= local_30[0]) &&
             ((local_30[0] != local_18[0] || (local_8 <= local_20)))) goto LAB_0040af87;
        }
        param_1 = (uint *)FUN_0040cdf0((int)param_1,param_3,(int)psVar2,local_30);
      } while (local_30[0] < local_18[0]);
LAB_0040af87:
      param_1 = (uint *)FUN_00417860((int)param_1,(short *)puVar4);
      if (DAT_00435408 != 0) {
        FUN_00408b40((int)param_1);
      }
    }
    FUN_00417a40(param_3);
    if (DAT_0043536c == 0) {
      param_1 = FUN_00419e50((int)param_1,param_2,(int)psVar2);
    }
    if ((int)param_1[4] <= (int)puVar3[4]) {
      FUN_00417a40((short *)puVar3);
      return param_1;
    }
    FUN_00417a40((short *)param_1);
    DAT_00435370 = 0;
    param_1 = puVar3;
  } while( true );
}



uint * __cdecl FUN_0040b020(uint *param_1,undefined4 *param_2)

{
  short *psVar1;
  uint *puVar2;
  bool bVar3;
  uint *puVar4;
  undefined3 extraout_var;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  psVar1 = (short *)*param_2;
  uVar7 = *param_1;
  uVar5 = uVar7;
  FUN_004176a0(uVar7);
  puVar4 = FUN_00417930(10,DAT_00435520,uVar5);
  puVar2 = *(uint **)(uVar7 + 0x18);
  puVar6 = puVar2 + *(int *)(uVar7 + 0x10) * *(int *)(uVar7 + 4);
  for (; puVar2 < puVar6; puVar2 = puVar2 + *(int *)(uVar7 + 4)) {
    if ((((*puVar2 & 0x4000) == 0) && ((*puVar2 & 0x400) != 0)) &&
       (bVar3 = FUN_0040b0f0(uVar7,(int)psVar1,puVar2), CONCAT31(extraout_var,bVar3) != 0)) {
      if (((byte)DAT_00435400 & 2) != 0) {
        FUN_00409a60((int)puVar2);
        FUN_0041b470((byte *)s_ESSENTIAL___s_0042ea3c);
      }
      puVar4 = (uint *)FUN_00417b00((int)puVar4,puVar2);
      *puVar2 = *puVar2 & 0xffffdfff;
      *(int *)(uVar7 + 0x14) = *(int *)(uVar7 + 0x14) + -1;
    }
  }
  uVar5 = FUN_004176e0(uVar7);
  *param_1 = uVar5;
  puVar6 = FUN_004177d0((int)psVar1,(int)puVar4,uVar7);
  *param_2 = puVar6;
  FUN_00417a40(psVar1);
  return puVar4;
}



bool __cdecl FUN_0040b0f0(int param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int unaff_EDI;
  
  puVar1 = FUN_004177d0(param_1,param_2,unaff_EDI);
  puVar2 = FUN_0040b170((int)puVar1,param_3);
  FUN_00417a40((short *)puVar1);
  puVar1 = FUN_00402a00((int)puVar2,param_2);
  iVar3 = FUN_0040ef50(puVar1,param_3);
  if (*puVar1 != 0) {
    FUN_0041b8c0(*puVar1);
    *puVar1 = 0;
  }
  if (puVar1 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar1);
  }
  FUN_00417a40((short *)puVar2);
  return (bool)('\x01' - (iVar3 != 0));
}



uint * __cdecl FUN_0040b170(int param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint unaff_EBP;
  uint uVar6;
  
  puVar2 = FUN_00417930(*(int *)(param_1 + 0x10) << 1,DAT_00435520,unaff_EBP);
  if ((int)DAT_00435520 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar6 = DAT_00435520;
  puVar4 = FUN_0040a880(1,iVar3 * 4);
  puVar5 = (uint *)FUN_00417140((int *)puVar4,uVar6);
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar4 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar1 < puVar4; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    if (puVar1 != param_2) {
      iVar3 = FUN_00418790((int)puVar1,param_2);
      if (iVar3 == 0) {
        puVar2 = (uint *)FUN_0040b250((int)puVar2,puVar1,param_2);
      }
      else if (iVar3 == 1) {
        FUN_00418c70((int *)puVar5,(int)puVar1,param_2);
        puVar2 = (uint *)FUN_00417b00((int)puVar2,puVar5);
      }
    }
  }
  if (puVar5 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar5);
  }
  return puVar2;
}



int __cdecl FUN_0040b250(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = (uint *)*DAT_0043554c;
  puVar2 = (uint *)DAT_0043554c[1];
  iVar4 = FUN_00417560(param_2,(int)param_3);
  if (iVar4 != 0) {
    return param_1;
  }
  if (DAT_00435520 < 0x21) {
    iVar4 = 2;
  }
  else {
    iVar4 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar7 = DAT_00435520;
  puVar5 = FUN_0040a880(1,iVar4 * 4);
  puVar5 = (uint *)FUN_00417140((int *)puVar5,iVar7);
  bVar3 = false;
  FUN_00417290(puVar1,param_2,(int)param_3);
  FUN_004171f0(puVar2,param_2,(int)param_3);
  iVar4 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524) {
    do {
      iVar7 = *(int *)(DAT_00435548 + iVar4 * 4);
      iVar6 = FUN_00417510(puVar1,iVar7);
      if (iVar6 == 0) {
        FUN_00417330(puVar5,param_3,(int)puVar2,iVar7);
        param_1 = FUN_00417b00(param_1,puVar5);
        bVar3 = true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00435524);
    if (bVar3) goto LAB_0040b368;
  }
  if (0 < DAT_00435528) {
    FUN_004171f0(puVar5,param_2,(int)param_3);
    param_1 = FUN_00417b00(param_1,puVar5);
  }
LAB_0040b368:
  if (puVar5 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar5);
  }
  return param_1;
}



void __cdecl FUN_0040b380(int param_1,int param_2,int param_3,short *param_4)

{
  FUN_0040b3c0(param_1,param_2,param_3,param_4,0);
  return;
}



uint * __cdecl FUN_0040b3c0(int param_1,int param_2,int param_3,short *param_4,int param_5)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  uint unaff_EDI;
  int *local_14;
  uint local_10;
  short *local_c;
  uint local_8;
  uint local_4;
  
  local_10 = DAT_00435400;
  if ((DAT_00435400 & 0x400) != 0) {
    DAT_00435400 = DAT_00435400 | 0x820;
  }
  local_8 = DAT_00435400 >> 9 & 4;
  local_4 = (uint)(param_4 == (short *)0x0);
  FUN_0041b360();
  puVar3 = FUN_00402a00(param_1,param_2);
  piVar4 = FUN_00415e80((int *)puVar3);
  if (DAT_00435408 != 0) {
    FUN_0041b360();
    FUN_00408b70((int)piVar4);
  }
  FUN_0041b360();
  FUN_0040eb60((int)piVar4,param_2,(int *)&param_4,(int *)&local_c,(int *)&local_14);
  if (DAT_00435408 != 0) {
    FUN_0041b360();
    FUN_00408b70((int)param_4);
  }
  FUN_0041b360();
  piVar5 = FUN_0040edb0(param_2,(int)param_4,(int)local_14);
  if (DAT_00435408 != 0) {
    FUN_0041b360();
    FUN_00408b70((int)local_14);
  }
  if (param_5 == 0) {
    puVar3 = (uint *)0x0;
  }
  else {
    puVar3 = FUN_0040a880(1,piVar4[4] << 2);
    puVar7 = (uint *)local_14[6];
    puVar1 = puVar7 + local_14[4] * local_14[1];
    for (; puVar7 < puVar1; puVar7 = puVar7 + local_14[1]) {
      iVar6 = FUN_00417030(puVar7);
      puVar3[*puVar7 >> 0x10] = DAT_00435520 - iVar6;
    }
  }
  FUN_0041b360();
  param_5 = FUN_00412a50((int)piVar5,(int *)puVar3,local_4,local_8);
  if (DAT_00435408 != 0) {
    FUN_0041b360();
    FUN_00408b70((int)piVar4);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  if ((DAT_00435400 & 0x400) != 0) {
    FUN_0040b6a0((int)param_4,(int)local_c,(int)local_14,(int)piVar5);
  }
  puVar7 = FUN_00417930(100,DAT_00435520,unaff_EDI);
  puVar1 = *(uint **)(param_4 + 0xc);
  puVar3 = puVar1 + *(int *)(param_4 + 8) * *(int *)(param_4 + 2);
  iVar6 = param_5;
  for (; param_5 = iVar6, puVar1 < puVar3; puVar1 = puVar1 + *(int *)(param_4 + 2)) {
    puVar7 = (uint *)FUN_00417b00((int)puVar7,puVar1);
    iVar6 = param_5;
  }
  for (iVar2 = *(int *)(iVar6 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
    puVar7 = (uint *)FUN_00417b00((int)puVar7,
                                  (uint *)(piVar4[6] + *(int *)(iVar2 + 4) * piVar4[1] * 4));
  }
  FUN_00417a40(param_4);
  FUN_00417a40(local_c);
  FUN_00417a40((short *)local_14);
  FUN_00411db0(piVar5,local_14);
  FUN_00416c00(iVar6);
  FUN_00417a40((short *)piVar4);
  DAT_00435400 = DAT_00435400 & 0xffffd7df;
  if (DAT_0043536c != 0) {
    DAT_00435400 = local_10;
    return puVar7;
  }
  if (param_3 == 0) {
    DAT_00435400 = local_10;
    return puVar7;
  }
  puVar3 = FUN_00419e50((int)puVar7,param_2,param_3);
  DAT_00435400 = local_10;
  return puVar3;
}



void __cdecl FUN_0040b6a0(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  FILE *pFVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  FILE *local_4;
  
  if (DAT_004354c0 != (char *)0x0) {
    iVar6 = 8;
    bVar10 = true;
    pcVar8 = DAT_004354c0;
    pcVar9 = s__stdin__0042ea7c;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (!bVar10) {
      uVar7 = 0xffffffff;
      pcVar8 = DAT_004354c0;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      puVar3 = FUN_0040a880(1,~uVar7 + 0x13);
      FUN_0041ec4a((undefined *)puVar3,(byte *)s__s_primes_0042ea84);
      pFVar4 = (FILE *)FUN_0041ec37(puVar3,&DAT_0042ea90);
      if (pFVar4 == (FILE *)0x0) {
        FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_espresso__Unable_to_open__s_0042ea94);
        pFVar4 = (FILE *)&DAT_00431c98;
      }
      FUN_0041ec4a((undefined *)puVar3,(byte *)s__s_pi_0042eab4);
      local_4 = (FILE *)FUN_0041ec37(puVar3,&DAT_0042eabc);
      if (local_4 == (FILE *)0x0) {
        FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_espresso__Unable_to_open__s_0042eac0);
        local_4 = (FILE *)&DAT_00431c98;
      }
      if (puVar3 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar3);
      }
      goto LAB_0040b776;
    }
  }
  pFVar4 = (FILE *)&DAT_00431c98;
  local_4 = (FILE *)&DAT_00431c98;
LAB_0040b776:
  puVar5 = (undefined4 *)FUN_00406f70();
  FUN_00406fa0((int)puVar5);
  FUN_00408e40((int *)pFVar4,(int)puVar5,1);
  FUN_00406ff0(puVar5);
  FUN_0041b430((int *)pFVar4,(byte *)s___Essential_primes_are_0042eae0);
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar7 = uVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar2 < uVar7; uVar2 = uVar2 + *(int *)(param_1 + 4) * 4) {
    FUN_00409a60(uVar2);
    FUN_0041b430((int *)pFVar4,&DAT_0042eaf8);
  }
  FUN_0041b430((int *)pFVar4,(byte *)s___Totally_redundant_primes_are_0042eafc);
  uVar2 = *(uint *)(param_2 + 0x18);
  uVar7 = uVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4) * 4;
  for (; uVar2 < uVar7; uVar2 = uVar2 + *(int *)(param_2 + 4) * 4) {
    FUN_00409a60(uVar2);
    FUN_0041b430((int *)pFVar4,&DAT_0042eb1c);
  }
  FUN_0041b430((int *)pFVar4,(byte *)s___Partially_redundant_primes_are_0042eb20);
  uVar2 = *(uint *)(param_3 + 0x18);
  uVar7 = uVar2 + *(int *)(param_3 + 0x10) * *(int *)(param_3 + 4) * 4;
  for (; uVar2 < uVar7; uVar2 = uVar2 + *(int *)(param_3 + 4) * 4) {
    FUN_00409a60(uVar2);
    FUN_0041b430((int *)pFVar4,&DAT_0042eb44);
  }
  if (pFVar4 != (FILE *)&DAT_00431c98) {
    FUN_0041ea29(pFVar4);
  }
  FUN_00412830((int *)local_4,param_4);
  if (local_4 != (FILE *)&DAT_00431c98) {
    FUN_0041ea29(local_4);
  }
  return;
}



uint * __cdecl FUN_0040b8a0(short *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  int local_10;
  uint *local_c;
  uint *local_8;
  uint *local_4;
  
  if (DAT_00435404 == 0) {
    puVar4 = FUN_00407d40(param_1,&LAB_00419240);
  }
  else {
    puVar4 = (uint *)FUN_00407f20((int)param_1);
  }
  if (DAT_00435520 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar10 = DAT_00435520;
  puVar6 = FUN_0040a880(1,iVar5 * 4);
  puVar6 = (uint *)FUN_00417140((int *)puVar6,iVar10);
  if (DAT_00435520 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar10 = DAT_00435520;
  puVar7 = FUN_0040a880(1,iVar5 << 2);
  local_8 = (uint *)FUN_00417140((int *)puVar7,iVar10);
  if (DAT_00435520 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar10 = DAT_00435520;
  puVar7 = FUN_0040a880(1,iVar5 * 4);
  puVar7 = (uint *)FUN_00417140((int *)puVar7,iVar10);
  if (DAT_00435520 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar10 = DAT_00435520;
  local_c = puVar7;
  puVar8 = FUN_0040a880(1,iVar5 * 4);
  local_4 = (uint *)FUN_00417140((int *)puVar8,iVar10);
  if (DAT_00435520 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar10 = DAT_00435520;
  puVar8 = FUN_0040a880(1,iVar5 << 2);
  puVar8 = (uint *)FUN_00417140((int *)puVar8,iVar10);
  if ((param_3 != 0) && (iVar5 = 0, 0 < DAT_00435524)) {
    do {
      if (*(int *)(DAT_00435560 + iVar5 * 4) != 0) {
        FUN_00417240(puVar7,puVar7,*(int *)(DAT_00435548 + iVar5 * 4));
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00435524);
  }
  puVar9 = (uint *)puVar4[6];
  puVar1 = puVar9 + puVar4[1] * puVar4[4];
  for (; puVar9 < puVar1; puVar9 = puVar9 + puVar4[1]) {
    *puVar9 = *puVar9 & 0xffffb7ff;
  }
  puVar9 = (uint *)puVar4[6];
  puVar1 = puVar9 + puVar4[1] * puVar4[4];
  for (; puVar9 < puVar1; puVar9 = puVar9 + puVar4[1]) {
    if ((*puVar9 & 0x8800) == 0) {
      FUN_0040bbd0(param_2,(int)puVar4,puVar6,local_8,puVar8,local_4,local_c,&local_10,puVar9);
      if (((byte)DAT_00435400 & 4) != 0) {
        FUN_00409a60((int)puVar9);
        FUN_0041b470((byte *)s_EXPAND___s__covered__d__0042eb48);
      }
      FUN_004171c0((int)puVar9,puVar6);
      *puVar9 = *puVar9 & 0xfffff7ff | 0x8000;
      if ((local_10 == 0) && (iVar5 = FUN_004174c0(puVar9,(int)puVar8), iVar5 == 0)) {
        *puVar9 = *puVar9 | 0x4000;
      }
    }
    puVar7 = local_c;
  }
  puVar9 = (uint *)puVar4[6];
  bVar3 = false;
  puVar1 = puVar9 + puVar4[1] * puVar4[4];
  puVar4[5] = 0;
  if (puVar9 < puVar1) {
    do {
      uVar2 = *puVar9;
      if ((uVar2 & 0x800) == 0) {
        *puVar9 = uVar2 | 0x2000;
        puVar4[5] = puVar4[5] + 1;
      }
      else {
        bVar3 = true;
        *puVar9 = uVar2 & 0xffffdfff;
      }
      puVar9 = puVar9 + puVar4[1];
    } while (puVar9 < puVar1);
    if (bVar3) {
      puVar4 = (uint *)FUN_004176e0((int)puVar4);
    }
  }
  if (puVar6 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar6);
  }
  if (local_8 != (uint *)0x0) {
    FUN_0041b8c0((int)local_8);
  }
  if (puVar7 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar7);
  }
  if (local_4 != (uint *)0x0) {
    FUN_0041b8c0((int)local_4);
  }
  if (puVar8 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar8);
  }
  return puVar4;
}



void __cdecl
FUN_0040bbd0(int param_1,int param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6,
            uint *param_7,int *param_8,uint *param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (((byte)DAT_00435400 & 8) != 0) {
    FUN_00409a60((int)param_9);
    FUN_0041b470((byte *)s_EXPAND1___s_0042eb64);
  }
  *param_9 = *param_9 | 0x8000;
  FUN_0040c050(param_1,param_2);
  *param_8 = 0;
  FUN_004171c0((int)param_6,param_9);
  FUN_004171c0((int)param_3,param_9);
  FUN_00417290(param_4,DAT_00435550,(int)param_3);
  iVar1 = FUN_00417440(param_7);
  if (iVar1 == 0) {
    FUN_00417290(param_4,param_4,(int)param_7);
    FUN_0040be90(param_1,param_2,param_3,(int)param_4);
  }
  FUN_0040bd10(param_1,param_2,param_3,param_4);
  FUN_00417240(param_5,param_3,(int)param_4);
  if (0 < *(int *)(param_2 + 0x14)) {
    FUN_0040c0d0(param_1,param_2,param_3,param_4,param_6,param_8);
    iVar1 = *(int *)(param_2 + 0x14);
    while (0 < iVar1) {
      iVar1 = FUN_0040bf40(param_2,(int)param_4);
      iVar2 = iVar1 >> 5;
      uVar3 = 1 << ((byte)iVar1 & 0x1f);
      param_3[iVar2 + 1] = param_3[iVar2 + 1] | uVar3;
      param_4[iVar2 + 1] = param_4[iVar2 + 1] & ~uVar3;
      FUN_0040bd10(param_1,param_2,param_3,param_4);
      iVar1 = *(int *)(param_2 + 0x14);
    }
  }
  iVar1 = *(int *)(param_1 + 0x14);
  while (0 < iVar1) {
    FUN_0040c440(param_1,param_3,param_4);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  FUN_00417240(param_3,param_3,(int)param_4);
  return;
}



void __cdecl FUN_0040bd10(int param_1,int param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint unaff_EDI;
  
  puVar2 = (uint *)*DAT_0043554c;
  FUN_004171c0((int)puVar2,DAT_00435554);
  puVar3 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar3 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_1 + 4)) {
    if (((*puVar3 & 0x2000) != 0) && (iVar4 = FUN_00418790((int)puVar3,param_3), iVar4 < 2)) {
      if (iVar4 == 0) {
        FUN_00408c40((int *)s_ON_set_and_OFF_set_are_not_ortho_0042eb78,unaff_EDI);
      }
      else {
        FUN_00418b20((int)puVar2,puVar3,(int)param_3);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
        *puVar3 = *puVar3 & 0xffffdfff;
      }
    }
  }
  iVar4 = FUN_00417440(puVar2);
  if (iVar4 == 0) {
    FUN_00417290(param_4,param_4,(int)puVar2);
    FUN_0040be90(param_1,param_2,param_3,(int)param_4);
  }
  if (((byte)DAT_00435400 & 8) != 0) {
    FUN_00409a80((int)param_4);
    FUN_00409a60((int)param_3);
    FUN_0041b470((byte *)s_ESSEN_PARTS__RAISE__s_FREESET__s_0042eba0);
  }
  return;
}



void __cdecl FUN_0040bdf0(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)*DAT_0043554c;
  FUN_004171c0((int)puVar2,DAT_00435554);
  puVar3 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar3 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_1 + 4)) {
    if ((*puVar3 & 0x2000) != 0) {
      FUN_00417240(puVar2,puVar2,(int)puVar3);
    }
  }
  FUN_00417290(puVar2,param_3,(int)puVar2);
  FUN_00417240(param_2,param_2,(int)puVar2);
  FUN_00417290(param_3,param_3,(int)puVar2);
  if (((byte)DAT_00435400 & 8) != 0) {
    FUN_00409a80((int)param_3);
    FUN_00409a60((int)param_2);
    FUN_0041b470((byte *)s_ESSEN_RAISING__RAISE__s_FREESET__0042ebc4);
  }
  return;
}



void __cdecl FUN_0040be90(int param_1,int param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = (uint *)FUN_00417240((uint *)*DAT_0043554c,param_3,param_4);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    if (((*puVar2 & 0x2000) != 0) && (iVar4 = FUN_00418690((int)puVar2,puVar3), iVar4 == 0)) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      *puVar2 = *puVar2 & 0xffffdfff;
    }
  }
  if (param_2 != 0) {
    puVar2 = *(uint **)(param_2 + 0x18);
    puVar1 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
    for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
      if (((*puVar2 & 0x2000) != 0) && (iVar4 = FUN_00417560(puVar2,(int)puVar3), iVar4 == 0)) {
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
        *puVar2 = *puVar2 & 0xffffdfff;
      }
    }
  }
  return;
}



int __cdecl FUN_0040bf40(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  
  puVar2 = FUN_0040a880(1,DAT_00435520 * 4);
  iVar3 = 0;
  puVar5 = puVar2;
  if (0 < DAT_00435520) {
    do {
      *puVar5 = 0;
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar3 < DAT_00435520);
  }
  iVar3 = DAT_00435520;
  if (param_1 != 0) {
    puVar1 = *(uint **)(param_1 + 0x18);
    puVar5 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
    for (; puVar1 < puVar5; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
      if ((*puVar1 & 0x2000) != 0) {
        FUN_00418010(puVar1,(int)puVar2,1);
        iVar3 = DAT_00435520;
      }
    }
  }
  uVar6 = 0xffffffff;
  iVar4 = 0;
  param_1 = -1;
  iVar7 = -1;
  puVar5 = puVar2;
  if (0 < iVar3) {
    do {
      if (((*(uint *)(param_2 + 4 + (iVar4 >> 5) * 4) & 1 << ((byte)iVar4 & 0x1f)) != 0) &&
         ((int)uVar6 < (int)*puVar5)) {
        uVar6 = *puVar5;
        param_1 = iVar4;
      }
      iVar4 = iVar4 + 1;
      iVar7 = param_1;
      puVar5 = puVar5 + 1;
    } while (iVar4 < iVar3);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  if (((byte)DAT_00435400 & 8) != 0) {
    FUN_00409a80(param_2);
    FUN_0041b470((byte *)s_MOST_FREQUENT__best__d_FREESET___0042ebe8);
  }
  return iVar7;
}



void __cdecl FUN_0040c050(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(param_1 + 0x18);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x10);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    *puVar2 = *puVar2 | 0x2000;
  }
  if (param_2 != 0) {
    puVar2 = *(uint **)(param_2 + 0x18);
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x10);
    puVar1 = puVar2 + *(int *)(param_2 + 4) * *(int *)(param_2 + 0x10);
    for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
      if ((*puVar2 & 0x8800) == 0) {
        uVar3 = *puVar2 | 0x2000;
      }
      else {
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
        uVar3 = *puVar2 & 0xffffdfff;
      }
      *puVar2 = uVar3;
    }
  }
  return;
}



void __cdecl
FUN_0040c0d0(int param_1,int param_2,uint *param_3,uint *param_4,uint *param_5,int *param_6)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int local_28;
  uint *local_20;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar1 = FUN_0040a880(1,*(int *)(param_2 + 0x14) << 2);
  puVar2 = *(uint **)(param_2 + 0x18);
  local_14 = 0;
  puVar6 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
  puVar3 = puVar1;
  for (; puVar2 < puVar6; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
    if ((*puVar2 & 0x2000) != 0) {
      *puVar3 = (uint)puVar2;
      local_14 = local_14 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  uVar9 = 1;
  puVar2 = FUN_0040a880(1,*(int *)(param_2 + 0x14) << 2);
  puVar3 = FUN_00417930(local_14,DAT_00435520,uVar9);
  iVar4 = 0;
  puVar6 = puVar2;
  if (0 < local_14) {
    do {
      iVar7 = puVar3[1] * iVar4;
      iVar4 = iVar4 + 1;
      *puVar6 = puVar3[6] + iVar7 * 4;
      puVar6 = puVar6 + 1;
    } while (iVar4 < local_14);
  }
  while( true ) {
    FUN_0040bdf0(param_1,param_3,param_4);
    local_28 = 0;
    if (0 < local_14) {
      puVar6 = puVar1;
      local_20 = puVar1;
      do {
        puVar8 = (uint *)*local_20;
        if ((*puVar8 & 0x2000) != 0) {
          iVar4 = FUN_00417560(puVar8,(int)param_3);
          if (iVar4 == 0) {
            iVar4 = FUN_0040c3b0(param_1,(int)puVar8,param_3,
                                 *(int *)(((int)puVar2 - (int)puVar1) + (int)puVar6));
            if (iVar4 != 0) {
              *puVar6 = (uint)puVar8;
              local_28 = local_28 + 1;
              puVar6 = puVar6 + 1;
            }
          }
          else {
            *param_6 = *param_6 + 1;
            FUN_00417240(param_5,param_5,(int)puVar8);
            *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
            *puVar8 = *puVar8 & 0xffffdfff | 0x800;
          }
        }
        local_20 = local_20 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
    if (((byte)DAT_00435400 & 8) != 0) {
      FUN_0041b470((byte *)s_SELECT_FEASIBLE__started_with__d_0042ec0c);
    }
    if (local_28 == 0) break;
    local_10 = 0;
    local_20 = (uint *)0x270f;
    if (0 < local_28) {
      local_c = local_28;
      puVar6 = puVar1;
      do {
        iVar4 = FUN_004170b0((uint *)*puVar6,(int)param_4);
        iVar7 = 0;
        local_14 = local_28;
        puVar8 = puVar1;
        do {
          iVar5 = FUN_00417510(*(uint **)((int)puVar6 + ((int)puVar2 - (int)puVar1)),*puVar8);
          if (iVar5 != 0) {
            iVar7 = iVar7 + 1;
          }
          puVar8 = puVar8 + 1;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
        if (local_10 < iVar7) {
          local_8 = *puVar6;
          local_20 = (uint *)iVar4;
          local_10 = iVar7;
        }
        else if ((iVar7 == local_10) && (iVar4 < (int)local_20)) {
          local_8 = *puVar6;
          local_20 = (uint *)iVar4;
        }
        puVar6 = puVar6 + 1;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    FUN_00417240(param_3,param_3,local_8);
    FUN_00417290(param_4,param_4,(int)param_3);
    if (((byte)DAT_00435400 & 8) != 0) {
      FUN_00409a80((int)param_4);
      FUN_00409a60((int)param_3);
      FUN_0041b470((byte *)s_FEASIBLE__RAISE__s_FREESET__s_0042ec48);
    }
    FUN_0040bd10(param_1,param_2,param_3,param_4);
    local_14 = local_28;
  }
  if (puVar1 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar1);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  FUN_00417a40((short *)puVar3);
  return;
}



undefined4 __cdecl FUN_0040c3b0(int param_1,int param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = (uint *)FUN_00417240((uint *)*DAT_0043554c,param_3,param_2);
  FUN_004171c0(param_4,DAT_00435554);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  do {
    if (puVar1 <= puVar2) {
      return 1;
    }
    if (((*puVar2 & 0x2000) != 0) && (iVar4 = FUN_00418790((int)puVar2,puVar3), iVar4 < 2)) {
      if (iVar4 == 0) {
        return 0;
      }
      FUN_00418b20(param_4,puVar2,(int)puVar3);
    }
    puVar2 = puVar2 + *(int *)(param_1 + 4);
  } while( true );
}



void __cdecl FUN_0040c440(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  uint unaff_EDI;
  int iVar9;
  int local_c;
  
  puVar2 = (uint *)*DAT_0043554c;
  puVar5 = FUN_00417930(*(undefined4 *)(param_1 + 0x14),DAT_00435520,unaff_EDI);
  puVar3 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar3 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_1 + 4)) {
    if ((*puVar3 & 0x2000) != 0) {
      uVar4 = puVar5[4];
      puVar5[4] = uVar4 + 1;
      iVar6 = FUN_004171c0(puVar5[6] + puVar5[1] * uVar4 * 4,DAT_00435554);
      FUN_00418b20(iVar6,puVar3,(int)param_2);
    }
  }
  puVar3 = (uint *)puVar5[6];
  local_c = 0;
  puVar1 = puVar3 + puVar5[4] * puVar5[1];
  iVar6 = DAT_00435524;
  iVar9 = DAT_00435528;
  while( true ) {
    DAT_00435528 = iVar9;
    if (puVar1 <= puVar3) {
      psVar7 = (short *)FUN_00407ca0((short *)puVar5,iVar9);
      iVar6 = FUN_00419b90((int)psVar7);
      iVar9 = FUN_00417290(puVar2,param_3,iVar6);
      FUN_00417240(param_2,param_2,iVar9);
      FUN_004171c0((int)param_3,DAT_00435554);
      *(undefined4 *)(param_1 + 0x14) = 0;
      if (((byte)DAT_00435400 & 8) != 0) {
        FUN_00409a80((int)param_3);
        FUN_00409a60((int)param_2);
        FUN_0041b470((byte *)s_MINCOV__RAISE__s_FREESET__s_0042ec6c);
      }
      FUN_00417a40(psVar7);
      if (iVar6 != 0) {
        FUN_0041b8c0(iVar6);
      }
      return;
    }
    iVar8 = 1;
    if (iVar9 < iVar6) {
      do {
        iVar6 = FUN_004170b0(puVar3,*(int *)(DAT_00435548 + iVar9 * 4));
        if ((1 < iVar6) && (iVar8 = iVar6 * iVar8, 500 < iVar8)) goto LAB_0040c5e0;
        iVar9 = iVar9 + 1;
        iVar6 = DAT_00435524;
      } while (iVar9 < DAT_00435524);
    }
    local_c = local_c + iVar8;
    if (500 < local_c) break;
    puVar3 = puVar3 + puVar5[1];
    iVar9 = DAT_00435528;
  }
LAB_0040c5e0:
  FUN_00417a40((short *)puVar5);
  iVar6 = FUN_0040bf40(0,(int)param_3);
  iVar9 = FUN_0040bf40(0,(int)param_3);
  param_2[(iVar6 >> 5) + 1] = param_2[(iVar6 >> 5) + 1] | 1 << ((byte)iVar9 & 0x1f);
  FUN_00417290(param_3,param_3,(int)param_2);
  FUN_0040bd10(param_1,0,param_2,param_3);
  return;
}



uint * __cdecl FUN_0040c640(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  short *psVar6;
  uint *puVar7;
  uint unaff_EBP;
  uint unaff_EDI;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    puVar4 = FUN_00417930(*(int *)(param_1 + 0x14),DAT_00435520,unaff_EBP);
    puVar3 = *(uint **)(param_1 + 0x18);
    puVar1 = puVar3 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
    for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_1 + 4)) {
      if ((*puVar3 & 0x2000) != 0) {
        uVar2 = puVar4[4];
        puVar4[4] = uVar2 + 1;
        iVar5 = FUN_004171c0(puVar4[6] + puVar4[1] * uVar2 * 4,DAT_00435554);
        FUN_00418b20(iVar5,puVar3,(int)param_2);
      }
    }
    psVar6 = (short *)FUN_00407ca0((short *)puVar4,DAT_00435528);
    puVar4 = FUN_00404540(psVar6);
    puVar7 = FUN_0041a8b0((uint)puVar4);
    puVar3 = (uint *)puVar7[6];
    puVar1 = puVar3 + puVar7[4] * puVar7[1];
    for (; puVar3 < puVar1; puVar3 = puVar3 + puVar7[1]) {
      FUN_00417290(puVar3,param_3,(int)puVar3);
      FUN_00417240(puVar3,puVar3,(int)param_2);
      *puVar3 = *puVar3 | 0x8000;
    }
    FUN_00417a40((short *)puVar4);
    return puVar7;
  }
  puVar3 = FUN_00417930(1,DAT_00435520,unaff_EDI);
  uVar2 = puVar3[4];
  puVar3[4] = uVar2 + 1;
  puVar1 = (uint *)(puVar3[6] + puVar3[1] * uVar2 * 4);
  FUN_004171c0((int)puVar1,param_2);
  *puVar1 = *puVar1 | 0x8000;
  return puVar3;
}



uint * __cdecl FUN_0040c770(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  
  if ((int)DAT_00435520 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar8 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar2 << 2);
  puVar3 = (uint *)FUN_00417140((int *)puVar3,uVar8);
  if ((int)DAT_00435520 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar8 = DAT_00435520;
  puVar4 = FUN_0040a880(1,iVar2 * 4);
  puVar5 = (uint *)FUN_00417140((int *)puVar4,uVar8);
  puVar6 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),DAT_00435520,(uint)puVar4);
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar4 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar1 < puVar4; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    if ((*puVar1 & 0x8000) == 0) {
      FUN_004171c0((int)puVar5,puVar1);
      FUN_00417290(puVar3,DAT_00435550,(int)puVar5);
      FUN_0040c050(param_2,0);
      FUN_0040bd10(param_2,0,puVar5,puVar3);
      puVar7 = FUN_0040c640(param_2,puVar5,puVar3);
      puVar6 = (uint *)FUN_00417860((int)puVar6,(short *)puVar7);
    }
    else {
      puVar6 = (uint *)FUN_00417b00((int)puVar6,puVar1);
    }
  }
  if (puVar5 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar5);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return puVar6;
}



void __cdecl FUN_0040c8a0(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_EDI;
  uint *local_4;
  
  local_4 = FUN_00417930(10,DAT_00435520,unaff_EDI);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      FUN_0040c910(param_1,param_2,param_3,param_4,iVar1,(int *)&local_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  local_4 = FUN_004045f0((short *)local_4);
  FUN_0040b8a0((short *)local_4,param_3,0);
  return;
}



void __cdecl FUN_0040c910(int param_1,int param_2,int param_3,uint param_4,int param_5,int *param_6)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  short *psVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  int local_c;
  
  if (((byte)DAT_00435400 & 8) != 0) {
    FUN_00409a60(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * param_5 * 4);
    FUN_0041b470((byte *)s_EXPAND1_GASP___s_0042ec90);
  }
  if (DAT_00435520 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar8 = DAT_00435520;
  puVar2 = FUN_0040a880(1,iVar1 << 2);
  puVar2 = (uint *)FUN_00417140((int *)puVar2,iVar8);
  if (DAT_00435520 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar8 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar1 * 4);
  puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar8);
  if (DAT_00435520 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar8 = DAT_00435520;
  puVar4 = FUN_0040a880(1,iVar1 * 4);
  puVar5 = (uint *)FUN_00417140((int *)puVar4,iVar8);
  puVar7 = *(uint **)(param_3 + 0x18);
  *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x10);
  puVar4 = puVar7 + *(int *)(param_3 + 4) * *(int *)(param_3 + 0x10);
  for (; puVar7 < puVar4; puVar7 = puVar7 + *(int *)(param_3 + 4)) {
    *puVar7 = *puVar7 | 0x2000;
  }
  puVar4 = *(uint **)(param_1 + 0x18);
  iVar1 = 0;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x10);
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if ((param_5 == iVar1) || ((*puVar4 & 0x8000) != 0)) {
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
        uVar9 = *puVar4 & 0xffffdfff;
      }
      else {
        uVar9 = *puVar4 | 0x2000;
      }
      *puVar4 = uVar9;
      iVar1 = iVar1 + 1;
      puVar4 = puVar4 + *(int *)(param_1 + 4);
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  FUN_004171c0((int)puVar2,(uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * param_5 * 4))
  ;
  FUN_00417290(puVar3,DAT_00435550,(int)puVar2);
  FUN_0040bd10(param_3,param_1,puVar2,puVar3);
  FUN_0040bdf0(param_3,puVar2,puVar3);
  puVar4 = *(uint **)(param_1 + 0x18);
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if (((*puVar4 & 0x2000) != 0) &&
         ((iVar1 = FUN_00417560(puVar4,(int)puVar2), iVar1 != 0 ||
          (iVar1 = FUN_0040c3b0(param_3,(int)puVar4,puVar2,(int)puVar5), iVar1 != 0)))) {
        psVar6 = (short *)FUN_00417a20(param_4);
        FUN_004171c0(*(int *)(psVar6 + 0xc) + *(int *)(psVar6 + 2) * param_5 * 4,
                     (uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * param_5 * 4));
        puVar7 = FUN_00402a00((int)psVar6,param_2);
        iVar1 = FUN_00416550(puVar7,(uint *)(*(int *)(psVar6 + 0xc) +
                                            *(int *)(psVar6 + 2) * local_c * 4));
        if (*puVar7 != 0) {
          FUN_0041b8c0(*puVar7);
          *puVar7 = 0;
        }
        if (puVar7 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar7);
        }
        FUN_00417a40(psVar6);
        iVar8 = FUN_0040c3b0(param_3,iVar1,puVar2,(int)puVar5);
        if (iVar8 != 0) {
          FUN_00417240(puVar5,puVar2,iVar1);
          *puVar5 = *puVar5 & 0xffff7fff;
          iVar8 = FUN_00417b00(*param_6,puVar5);
          *param_6 = iVar8;
        }
        if (iVar1 != 0) {
          FUN_0041b8c0(iVar1);
        }
      }
      local_c = local_c + 1;
      puVar4 = puVar4 + *(int *)(param_1 + 4);
    } while (local_c < *(int *)(param_1 + 0x10));
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  if (puVar5 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar5);
  }
  return;
}



int __cdecl FUN_0040cc10(int param_1,short *param_2,short *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_3 + 8) != 0) {
    piVar1 = (int *)FUN_00417860(param_1,param_3);
    iVar2 = FUN_0040e9b0(piVar1,param_2);
    return iVar2;
  }
  FUN_00417a40(param_3);
  return param_1;
}



int __cdecl FUN_0040cc50(uint param_1,short *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  short *psVar3;
  int iVar4;
  
  iVar1 = FUN_0041b360();
  puVar2 = FUN_0040cce0(param_1,(int)param_2);
  FUN_00408bb0(iVar1,9,(int)puVar2,param_4);
  iVar1 = FUN_0041b360();
  psVar3 = (short *)FUN_0040c8a0((int)puVar2,(int)param_2,param_3,param_1);
  FUN_00408bb0(iVar1,7,(int)psVar3,param_4);
  FUN_00417a40((short *)puVar2);
  iVar1 = FUN_0041b360();
  iVar4 = FUN_0040cc10(param_1,param_2,psVar3);
  FUN_00408bb0(iVar1,8,iVar4,param_4);
  return iVar4;
}



uint * __cdecl FUN_0040cce0(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint unaff_EDI;
  uint *puVar7;
  
  puVar3 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),DAT_00435520,unaff_EDI);
  puVar4 = FUN_00402a00(param_1,param_2);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    puVar5 = (uint *)FUN_00416550(puVar4,puVar2);
    iVar6 = FUN_00417440(puVar5);
    if (iVar6 == 0) {
      iVar6 = FUN_004174c0(puVar5,(int)puVar2);
      if (iVar6 == 0) {
        *puVar5 = *puVar5 & 0xffff7fff;
        puVar7 = puVar5;
      }
      else {
        *puVar5 = *puVar5 | 0x8000;
        puVar7 = puVar2;
      }
      puVar3 = (uint *)FUN_00417b00((int)puVar3,puVar7);
    }
    else {
      FUN_00408c40((int *)s_empty_reduction_in_reduce_gasp__s_0042eca8,unaff_EDI);
    }
    if (((byte)DAT_00435400 & 0x10) != 0) {
      FUN_00409a80((int)puVar5);
      FUN_00409a60((int)puVar2);
      FUN_0041b470((byte *)s_REDUCE_GASP___s_reduced_to__s_0042ecdc);
    }
    if (puVar5 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar5);
    }
  }
  if (*puVar4 != 0) {
    FUN_0041b8c0(*puVar4);
    *puVar4 = 0;
  }
  if (puVar4 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar4);
  }
  return puVar3;
}



int __cdecl FUN_0040cdf0(int param_1,short *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  short *psVar4;
  int iVar5;
  
  iVar1 = FUN_0041b360();
  puVar2 = FUN_0040cce0(param_1,(int)param_2);
  FUN_00408bb0(iVar1,9,(int)puVar2,param_4);
  iVar1 = FUN_0041b360();
  puVar3 = FUN_0040c770((int)puVar2,param_3);
  FUN_00408bb0(iVar1,7,(int)puVar3,param_4);
  FUN_00417a40((short *)puVar2);
  FUN_0041b360();
  psVar4 = (short *)FUN_00417860(param_1,(short *)puVar3);
  puVar2 = FUN_004045f0(psVar4);
  if (DAT_00435408 != 0) {
    FUN_0041b360();
    FUN_00408b70((int)puVar2);
  }
  iVar1 = FUN_0041b360();
  iVar5 = FUN_0040e9b0((int *)puVar2,param_2);
  FUN_00408bb0(iVar1,5,iVar5,param_4);
  return iVar5;
}



int __cdecl FUN_0040ceb0(int param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  int _Val;
  
  DAT_0043559c = (char *)0x0;
  if ((DAT_004330a0 == (char *)0x0) || (pcVar2 = DAT_004330a0, *DAT_004330a0 == '\0')) {
    if (DAT_0043309c == 0) {
      DAT_0043309c = 1;
    }
    if ((((param_1 <= DAT_0043309c) ||
         (pcVar1 = *(char **)(param_2 + DAT_0043309c * 4), *pcVar1 != '-')) ||
        (pcVar2 = pcVar1 + 1, pcVar1[1] == '\0')) ||
       ((DAT_0043309c = DAT_0043309c + 1, *pcVar2 == '-' && (pcVar1[2] == '\0')))) {
      return -1;
    }
  }
  _Val = (int)*pcVar2;
  DAT_004330a0 = pcVar2 + 1;
  pcVar2 = _strchr(param_3,_Val);
  if ((pcVar2 != (char *)0x0) && (_Val != 0x3a)) {
    if (pcVar2[1] == ':') {
      if (*DAT_004330a0 != '\0') {
        DAT_0043559c = DAT_004330a0;
        DAT_004330a0 = (char *)0x0;
        return _Val;
      }
      DAT_0043559c = *(char **)(param_2 + DAT_0043309c * 4);
      DAT_0043309c = DAT_0043309c + 1;
    }
    return _Val;
  }
  FUN_0040aa50(0,0xb);
  return 0x3f;
}



undefined4 __cdecl
FUN_0040cfa0(int *param_1,int *param_2,int param_3,int param_4,int param_5,uint *param_6,int param_7
            ,int *param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  
  puVar4 = (uint *)param_1[4];
  do {
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    if (puVar4[1] == 2) {
      iVar3 = *(int *)(puVar4[3] + 4);
      if ((iVar3 < 0) || (param_1[3] <= iVar3)) {
        puVar6 = (uint *)0x0;
      }
      else {
        puVar6 = *(uint **)(param_1[2] + iVar3 * 4);
      }
      iVar3 = *(int *)(puVar4[4] + 4);
      if ((iVar3 < 0) || (param_1[3] <= iVar3)) {
        puVar8 = (uint *)0x0;
      }
      else {
        puVar8 = *(uint **)(param_1[2] + iVar3 * 4);
      }
      if (puVar6[1] == 2) {
LAB_0040d03a:
        uVar1 = *puVar4;
        uVar7 = *(uint *)puVar6[3];
        if (uVar7 == uVar1) {
          uVar7 = *(uint *)puVar6[4];
        }
        uVar10 = *puVar6;
        uVar2 = *puVar8;
        if (((int)uVar7 < 0) || (param_1[1] <= (int)uVar7)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*param_1 + uVar7 * 4);
        }
        iVar3 = FUN_00416c40(iVar3);
        FUN_00416d40(iVar3,uVar10);
        for (puVar4 = (uint *)puVar8[3]; puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[2]) {
          if (*puVar4 != uVar1) {
            for (iVar5 = *(int *)(iVar3 + 0xc); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {
              FUN_00411f90(param_1,*puVar4,*(uint *)(iVar5 + 4));
            }
          }
        }
        FUN_00412520(param_1,uVar10);
        FUN_00412520(param_1,uVar2);
        FUN_00412460(param_1,uVar1);
        FUN_00412460(param_1,uVar7);
        *(int *)(param_7 + 0x18) = *(int *)(param_7 + 0x18) + 1;
        *(int *)(param_7 + 0x1c) = *(int *)(param_7 + 0x1c) + 1;
        puVar4 = FUN_00412c80(param_1,param_2,(int *)param_3,param_4 - 1,param_5 - 1,param_6,
                              (uint *)param_7);
        *param_8 = (int)puVar4;
        *(int *)(param_7 + 0x1c) = *(int *)(param_7 + 0x1c) + -1;
        if ((int *)*param_8 != (int *)0x0) {
          iVar5 = FUN_00416e70(iVar3,*(int *)*param_8);
          if (iVar5 == 0) {
            piVar9 = (int *)*param_8;
          }
          else {
            piVar9 = (int *)*param_8;
            uVar10 = uVar2;
          }
          FUN_00419d40(piVar9,param_3,uVar10);
        }
        FUN_00416c00(iVar3);
        return 1;
      }
      if (puVar8[1] == 2) {
        iVar3 = *(int *)(puVar4[4] + 4);
        if ((iVar3 < 0) || (param_1[3] <= iVar3)) {
          puVar6 = (uint *)0x0;
        }
        else {
          puVar6 = *(uint **)(param_1[2] + iVar3 * 4);
        }
        iVar3 = *(int *)(puVar4[3] + 4);
        if ((iVar3 < 0) || (param_1[3] <= iVar3)) {
          puVar8 = (uint *)0x0;
        }
        else {
          puVar8 = *(uint **)(param_1[2] + iVar3 * 4);
        }
        goto LAB_0040d03a;
      }
    }
    puVar4 = (uint *)puVar4[5];
  } while( true );
}



undefined4 __cdecl FUN_0040d180(int param_1)

{
  return *(undefined4 *)(&DAT_0042edb0 + param_1 * 4);
}



void __cdecl FUN_0040d190(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  short *psVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  int **ppiVar12;
  short **ppsVar13;
  short **ppsVar14;
  short *local_28;
  short *local_24;
  short *local_20;
  short *local_1c;
  int *local_18;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  int local_4;
  
  piVar1 = param_1;
  if ((((int *)param_1[7] != (int *)0x0) && (*(int *)param_1[7] != 0)) &&
     (iVar11 = 0, 0 < DAT_00435528 * 2)) {
    while (((iVar2 = _strncmp(*(char **)(piVar1[7] + iVar11 * 4),s_DONT_CARE_0042f234,9), iVar2 != 0
            && (iVar2 = _strncmp(*(char **)(piVar1[7] + iVar11 * 4),s_DONTCARE_0042f240,8),
               iVar2 != 0)) &&
           ((iVar2 = _strncmp(*(char **)(piVar1[7] + iVar11 * 4),s_dont_care_0042f24c,9), iVar2 != 0
            && (iVar2 = _strncmp(*(char **)(piVar1[7] + iVar11 * 4),s_dontcare_0042f258,8),
               iVar2 != 0))))) {
      iVar11 = iVar11 + 1;
      if (DAT_00435528 * 2 <= iVar11) {
        return;
      }
    }
    iVar11 = iVar11 / 2;
    if (iVar11 != -1) {
      uVar3 = (*DAT_00435550 & 0x3ff) * 0x20;
      if (uVar3 < 0x21) {
        iVar2 = 2;
      }
      else {
        iVar2 = (uVar3 - 1 >> 5) + 2;
      }
      puVar5 = DAT_00435550;
      local_4 = iVar11;
      puVar4 = FUN_0040a880(1,iVar2 << 2);
      puVar5 = (uint *)FUN_004171c0((int)puVar4,puVar5);
      uVar3 = (*DAT_00435550 & 0x3ff) * 0x20;
      if (uVar3 < 0x21) {
        iVar2 = 2;
      }
      else {
        iVar2 = (uVar3 - 1 >> 5) + 2;
      }
      puVar4 = DAT_00435550;
      puVar6 = FUN_0040a880(1,iVar2 * 4);
      puVar4 = (uint *)FUN_004171c0((int)puVar6,puVar4);
      iVar11 = iVar11 * 2;
      local_14 = 1 << ((byte)iVar11 & 0x1f);
      iVar2 = iVar11 >> 5;
      local_10 = iVar2 * 4 + 4;
      puVar5[iVar2 + 1] = puVar5[iVar2 + 1] & ~local_14;
      local_c = 1 << ((byte)(iVar11 + 1) & 0x1f);
      iVar2 = iVar11 + 1 >> 5;
      local_8 = iVar2 * 4 + 4;
      puVar4[iVar2 + 1] = puVar4[iVar2 + 1] & ~local_c;
      local_18 = (int *)FUN_0041b360();
      ppsVar14 = &local_24;
      ppiVar12 = &param_1;
      puVar6 = FUN_00402950(*piVar1);
      piVar7 = (int *)FUN_00402260(puVar6,puVar5);
      FUN_00403bd0(piVar7,(int *)ppiVar12,(int *)ppsVar14);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)param_1);
      }
      FUN_0041b360();
      ppsVar14 = &local_20;
      ppsVar13 = &local_28;
      puVar5 = FUN_00402950(*piVar1);
      piVar7 = (int *)FUN_00402260(puVar5,puVar4);
      FUN_00403bd0(piVar7,(int *)ppsVar13,(int *)ppsVar14);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)local_28);
      }
      FUN_0041b360();
      psVar8 = (short *)FUN_00419a60((int)param_1,(int)local_20);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)psVar8);
      }
      local_18 = (int *)FUN_0041b360();
      psVar9 = (short *)FUN_00419a60((int)local_28,(int)local_24);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)psVar9);
      }
      local_18 = (int *)FUN_0041b360();
      puVar5 = FUN_00404630(psVar8,psVar9);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70((int)puVar5);
      }
      FUN_0041b360();
      ppsVar14 = &local_1c;
      piVar7 = piVar1 + 1;
      local_18 = piVar7;
      puVar5 = FUN_00402950((int)puVar5);
      FUN_00403bd0((int *)puVar5,piVar7,(int *)ppsVar14);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70(*local_18);
      }
      FUN_0041b360();
      iVar2 = FUN_00419a60(*piVar1,(int)local_1c);
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70(*piVar1);
      }
      FUN_00417a40((short *)*piVar1);
      *piVar1 = iVar2;
      FUN_00417a40((short *)param_1);
      FUN_00417a40(local_28);
      FUN_00417a40(local_24);
      FUN_00417a40(local_20);
      FUN_00417a40(local_1c);
      FUN_004176a0(*piVar1);
      iVar2 = *piVar1;
      puVar4 = *(uint **)(iVar2 + 0x18);
      puVar5 = puVar4 + *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 4);
      for (; puVar4 < puVar5; puVar4 = puVar4 + *(int *)(*piVar1 + 4)) {
        if (((*(uint *)(local_10 + (int)puVar4) & local_14) == 0) ||
           ((*(uint *)(local_8 + (int)puVar4) & local_c) == 0)) {
          *puVar4 = *puVar4 & 0xffffdfff;
        }
      }
      iVar2 = FUN_004176e0(*piVar1);
      *piVar1 = iVar2;
      FUN_00405270();
      iVar2 = local_4 + 1;
      iVar10 = iVar2 * 2;
      if (iVar10 < DAT_00435520) {
        do {
          iVar10 = iVar10 + 1;
          *(undefined4 *)(piVar1[7] + -0xc + iVar10 * 4) =
               *(undefined4 *)(piVar1[7] + -4 + iVar10 * 4);
        } while (iVar10 < DAT_00435520);
      }
      if (iVar2 < DAT_00435524) {
        do {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(DAT_00435534 + -8 + iVar2 * 4) =
               *(undefined4 *)(DAT_00435534 + -4 + iVar2 * 4);
        } while (iVar2 < DAT_00435524);
      }
      DAT_00435528 = DAT_00435528 + -1;
      DAT_00435524 = DAT_00435524 + -1;
      FUN_00404e20();
      iVar2 = FUN_004181e0((short *)*piVar1,iVar11,iVar11 + 1);
      piVar7 = local_18;
      *piVar1 = iVar2;
      iVar11 = FUN_004181e0((short *)*local_18,iVar11,iVar11 + 1);
      *piVar7 = iVar11;
    }
  }
  return;
}



void __cdecl FUN_0040d640(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint unaff_EDI;
  short *psVar9;
  uint *puStack_c;
  int local_8;
  uint uStack_4;
  
  puVar2 = param_1;
  if (0 < *(int *)(param_1[1] + 0x10)) {
    FUN_00417a40((short *)*param_1);
    puVar3 = FUN_00402a00(puVar2[1],puVar2[2]);
    puVar3 = FUN_00403160(puVar3);
    *puVar2 = (uint)puVar3;
  }
  piVar1 = (int *)puVar2[9];
  iVar8 = 0;
  local_8 = 0;
  for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    for (iVar7 = *piVar1; iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
      if ((*(int *)(iVar7 + 4) < 0) ||
         (*(int *)(DAT_00435534 + DAT_00435568 * 4) <= *(int *)(iVar7 + 4))) {
        FUN_00408c40((int *)s_symbolic_output_index_out_of_ran_0042f2b8,unaff_EDI);
      }
    }
    iVar8 = iVar8 + (1 << ((byte)piVar1[1] & 0x1f));
  }
  uStack_4 = DAT_00435520;
  for (piVar1 = (int *)puVar2[9]; DAT_00435520 = uStack_4, piVar1 != (int *)0x0;
      piVar1 = (int *)piVar1[4]) {
    for (iVar7 = *piVar1; iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
      *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + iVar8;
    }
    uStack_4 = DAT_00435520;
  }
  piVar1 = (int *)(DAT_00435534 + DAT_00435568 * 4);
  *piVar1 = *piVar1 + iVar8;
  local_8 = iVar8;
  FUN_00405270();
  FUN_00404e20();
  iVar7 = *(int *)(DAT_0043552c + DAT_00435568 * 4);
  uVar4 = FUN_00418200((short *)*puVar2,iVar7,iVar8);
  *puVar2 = uVar4;
  uVar4 = FUN_00418200((short *)puVar2[1],iVar7,iVar8);
  puVar2[1] = uVar4;
  uVar4 = FUN_00418200((short *)puVar2[2],iVar7,iVar8);
  piVar1 = (int *)puVar2[9];
  puVar2[2] = uVar4;
  for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    uVar4 = 100;
    param_1 = FUN_00417930(100,DAT_00435520,unaff_EDI);
    puStack_c = FUN_00417930(100,DAT_00435520,uVar4);
    FUN_0040d950(0,(int *)puVar2,*piVar1,iVar7,0,(int *)&param_1,&puStack_c);
    FUN_00417a40((short *)*puVar2);
    *puVar2 = (uint)param_1;
    FUN_00417a40((short *)puStack_c);
    iVar7 = iVar7 + (1 << ((byte)piVar1[1] & 0x1f));
  }
  uVar4 = param_1[2];
  if ((int)uVar4 < 0x21) {
    iVar7 = 2;
  }
  else {
    iVar7 = ((int)(uVar4 - 1) >> 5) + 2;
  }
  puVar3 = FUN_0040a880(1,iVar7 * 4);
  puVar3 = (uint *)FUN_00417170((int *)puVar3,uVar4);
  for (piVar1 = (int *)puVar2[9]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    for (iVar7 = *piVar1; iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
      iVar8 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + *(int *)(iVar7 + 4);
      iVar6 = iVar8 >> 5;
      puVar3[iVar6 + 1] = puVar3[iVar6 + 1] & ~(1 << ((byte)iVar8 & 0x1f));
      iVar8 = local_8;
    }
  }
  piVar1 = (int *)(DAT_00435534 + DAT_00435568 * 4);
  iVar7 = FUN_00417030(puVar3);
  *piVar1 = *piVar1 + (iVar7 - param_1[2]);
  FUN_00405270();
  FUN_00404e20();
  puVar5 = FUN_004183e0((short *)*puVar2,puVar3);
  *puVar2 = (uint)puVar5;
  puVar5 = FUN_004183e0((short *)puVar2[1],puVar3);
  puVar2[1] = (uint)puVar5;
  if (DAT_00435520 != *(uint *)(*puVar2 + 8)) {
    FUN_00408c40((int *)s_error_0042f2dc,unaff_EDI);
  }
  puVar5 = FUN_004044e0((short *)*puVar2);
  *puVar2 = (uint)puVar5;
  puVar5 = FUN_004044e0((short *)puVar2[1]);
  puVar2[1] = (uint)puVar5;
  iVar7 = 0;
  if (0 < DAT_00435524) {
    do {
      uVar4 = FUN_00404720((short *)*puVar2,iVar7);
      *puVar2 = uVar4;
      uVar4 = FUN_00404720((short *)puVar2[1],iVar7);
      puVar2[1] = uVar4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_00435524);
  }
  puVar5 = FUN_004044e0((short *)*puVar2);
  *puVar2 = (uint)puVar5;
  puVar5 = FUN_004044e0((short *)puVar2[1]);
  psVar9 = (short *)puVar2[2];
  puVar2[1] = (uint)puVar5;
  FUN_00417a40(psVar9);
  puVar5 = FUN_00417930(0,DAT_00435520,(uint)psVar9);
  puVar2[2] = (uint)puVar5;
  FUN_0040dea0((int)puVar2,puVar2[9],(int)puVar3,DAT_00435520,uStack_4,iVar8);
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return;
}



void __cdecl
FUN_0040d950(int param_1,int *param_2,int param_3,int param_4,int param_5,int *param_6,
            undefined4 param_7)

{
  uint uVar1;
  short *psVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  if (param_3 == 0) {
    psVar2 = (short *)FUN_00419a60(param_1,*param_2);
    uVar6 = *(uint *)(psVar2 + 0xc);
    uVar1 = uVar6 + *(int *)(psVar2 + 8) * *(int *)(psVar2 + 2) * 4;
    if (uVar6 < uVar1) {
      iVar3 = (param_4 + param_5 >> 5) * 4 + 4;
      do {
        *(uint *)(iVar3 + uVar6) =
             *(uint *)(iVar3 + uVar6) | 1 << ((byte)(param_4 + param_5) & 0x1f);
        uVar6 = uVar6 + *(int *)(psVar2 + 2) * 4;
      } while (uVar6 < uVar1);
    }
    iVar3 = FUN_00417860(*param_6,psVar2);
    *param_6 = iVar3;
    return;
  }
  puVar4 = FUN_00408220(param_2[2],*(int *)(DAT_0043552c + DAT_00435568 * 4) + *(int *)(param_3 + 4)
                       );
  puVar5 = puVar4;
  if (param_1 != 0) {
    puVar5 = (uint *)FUN_00419a60(param_1,(int)puVar4);
    FUN_00417a40((short *)puVar4);
  }
  FUN_0040d950((int)puVar5,param_2,*(int *)(param_3 + 8),param_4,param_5 * 2,param_6,param_7);
  FUN_00417a40((short *)puVar5);
  puVar4 = FUN_00408220(*param_2,*(int *)(DAT_0043552c + DAT_00435568 * 4) + *(int *)(param_3 + 4));
  puVar5 = puVar4;
  if (param_1 != 0) {
    puVar5 = (uint *)FUN_00419a60(param_1,(int)puVar4);
    FUN_00417a40((short *)puVar4);
  }
  FUN_0040d950((int)puVar5,param_2,*(int *)(param_3 + 8),param_4,param_5 * 2 + 1,param_6,param_7);
  FUN_00417a40((short *)puVar5);
  return;
}



void __cdecl FUN_0040daa0(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint unaff_EDI;
  int iVar12;
  undefined4 *puVar13;
  uint *puStack_10;
  
  for (puVar13 = (undefined4 *)param_1[8]; puVar13 != (undefined4 *)0x0;
      puVar13 = (undefined4 *)puVar13[4]) {
    for (piVar1 = (int *)*puVar13; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if ((*piVar1 < 0) || (DAT_00435528 <= *piVar1)) {
        FUN_00408c40((int *)s__symbolic_requires_binary_variab_0042f2e4,unaff_EDI);
      }
    }
  }
  iVar11 = 0;
  iVar10 = 0;
  for (iVar8 = param_1[8]; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x10)) {
    iVar11 = iVar11 + (1 << ((byte)*(undefined4 *)(iVar8 + 4) & 0x1f));
    iVar10 = iVar10 + 1;
  }
  iVar8 = *(int *)(*param_1 + 8) + iVar11;
  if (iVar8 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = (iVar8 + -1 >> 5) + 2;
  }
  puVar3 = FUN_0040a880(1,iVar2 * 4);
  puVar3 = (uint *)FUN_00417170((int *)puVar3,iVar8);
  for (puVar13 = (undefined4 *)param_1[8]; puVar13 != (undefined4 *)0x0;
      puVar13 = (undefined4 *)puVar13[4]) {
    for (piVar1 = (int *)*puVar13; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      iVar8 = (*piVar1 << 1) >> 5;
      puVar3[iVar8 + 1] = puVar3[iVar8 + 1] & ~(1 << ((byte)(*piVar1 << 1) & 0x1f));
      iVar8 = *piVar1 * 2 + 1;
      iVar2 = iVar8 >> 5;
      puVar3[iVar2 + 1] = puVar3[iVar2 + 1] & ~(1 << ((byte)iVar8 & 0x1f));
    }
  }
  iVar8 = FUN_00417030(puVar3);
  iVar12 = (iVar11 + (*(int *)(*param_1 + 8) - iVar8)) / 2;
  iVar10 = (DAT_00435524 - iVar12) + iVar10;
  iVar8 = DAT_00435528 - iVar12;
  iVar2 = DAT_00435520 + iVar12 * -2;
  puVar4 = FUN_0040a880(1,iVar10 * 4);
  puVar4[iVar10 + -1] = *(uint *)((int)DAT_00435534 + -4 + DAT_00435524 * 4);
  if (DAT_00435528 < DAT_00435524 + -1) {
    iVar5 = DAT_00435528 * 4;
    iVar9 = DAT_00435528;
    do {
      iVar9 = iVar9 + 1;
      *(undefined4 *)(iVar5 + iVar12 * -4 + (int)puVar4) =
           *(undefined4 *)(iVar5 + (int)DAT_00435534);
      iVar5 = iVar5 + 4;
    } while (iVar9 < DAT_00435524 + -1);
  }
  iVar5 = *(int *)(DAT_0043552c + DAT_00435568 * 4);
  iVar9 = FUN_00418200((short *)*param_1,iVar5,iVar11);
  *param_1 = iVar9;
  iVar9 = FUN_00418200((short *)param_1[1],iVar5,iVar11);
  param_1[1] = iVar9;
  iVar9 = FUN_00418200((short *)param_1[2],iVar5,iVar11);
  param_1[2] = iVar9;
  puVar13 = (undefined4 *)param_1[8];
  if (puVar13 != (undefined4 *)0x0) {
    puStack_10 = puVar4 + (DAT_00435524 - iVar12) + -1;
    do {
      iVar12 = FUN_0040ddb0(*param_1,(int *)*puVar13,iVar5);
      *param_1 = iVar12;
      iVar12 = FUN_0040ddb0(param_1[1],(int *)*puVar13,iVar5);
      param_1[1] = iVar12;
      iVar12 = FUN_0040ddb0(param_1[2],(int *)*puVar13,iVar5);
      param_1[2] = iVar12;
      uVar6 = 1 << ((byte)puVar13[1] & 0x1f);
      *puStack_10 = uVar6;
      puVar13 = (undefined4 *)puVar13[4];
      iVar5 = iVar5 + uVar6;
      puStack_10 = puStack_10 + 1;
    } while (puVar13 != (undefined4 *)0x0);
  }
  puVar7 = FUN_004183e0((short *)*param_1,puVar3);
  *param_1 = (int)puVar7;
  puVar7 = FUN_004183e0((short *)param_1[1],puVar3);
  param_1[1] = (int)puVar7;
  puVar7 = FUN_004183e0((short *)param_1[2],puVar3);
  param_1[2] = (int)puVar7;
  FUN_0040dea0((int)param_1,param_1[8],(int)puVar3,iVar2 + iVar11,DAT_00435520,iVar11);
  FUN_00405270();
  if (DAT_00435534 != (uint *)0x0) {
    FUN_0041b8c0((int)DAT_00435534);
  }
  DAT_00435524 = iVar10;
  DAT_00435528 = iVar8;
  DAT_00435534 = puVar4;
  FUN_00404e20();
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return;
}



int __cdecl FUN_0040ddb0(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar1 = uVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  if (uVar1 <= uVar2) {
    return param_1;
  }
  do {
    FUN_0040de00(uVar2,param_3,0,param_2);
    uVar2 = uVar2 + *(int *)(param_1 + 4) * 4;
  } while (uVar2 < uVar1);
  return param_1;
}



void __cdecl FUN_0040de00(int param_1,int param_2,int param_3,int *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint unaff_EDI;
  
  if (param_4 != (int *)0x0) {
    do {
      uVar2 = *(uint *)(param_1 + 4 + ((*param_4 << 1) >> 5) * 4) >> ((byte)(*param_4 << 1) & 0x1f)
              & 3;
      if (uVar2 == 1) {
        param_4 = (int *)param_4[2];
        param_3 = param_3 * 2;
      }
      else if (uVar2 == 2) {
        param_4 = (int *)param_4[2];
        param_3 = param_3 * 2 + 1;
      }
      else {
        if (uVar2 != 3) {
          FUN_00408c40((int *)s_bad_cube_in_form_bitvector_0042f308,unaff_EDI);
          return;
        }
        FUN_0040de00(param_1,param_2,param_3 * 2,(int *)param_4[2]);
        param_4 = (int *)param_4[2];
        param_3 = param_3 * 2 + 1;
      }
    } while (param_4 != (int *)0x0);
  }
  puVar1 = (uint *)(param_1 + 4 + (param_3 + param_2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)(param_3 + param_2) & 0x1f);
  return;
}



void __cdecl FUN_0040dea0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar7 = 0;
  if (piVar1 != (int *)0x0) {
    puVar2 = FUN_0040a880(1,param_4 * 4);
    *(uint **)(param_1 + 0x1c) = puVar2;
    iVar3 = 0;
    if (0 < param_4) {
      do {
        iVar3 = iVar3 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + -4 + iVar3 * 4) = 0;
      } while (iVar3 < param_4);
    }
    param_4 = 0;
    piVar6 = piVar1;
    if (0 < *(int *)(DAT_0043552c + DAT_00435568 * 4)) {
      do {
        if ((*(uint *)(param_3 + 4 + (iVar7 >> 5) * 4) & 1 << ((byte)iVar7 & 0x1f)) == 0) {
          if (*piVar6 != 0) {
            FUN_0041b8c0(*piVar6);
            *piVar6 = 0;
          }
        }
        else {
          *(int *)(*(int *)(param_1 + 0x1c) + param_4 * 4) = *piVar6;
          param_4 = param_4 + 1;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar7 < *(int *)(DAT_0043552c + DAT_00435568 * 4));
    }
    if (param_2 != 0) {
      do {
        puVar5 = *(undefined4 **)(param_2 + 8);
        iVar7 = 0;
        if (0 < 1 << ((byte)*(undefined4 *)(param_2 + 4) & 0x1f)) {
          iVar3 = param_4 * 4;
          do {
            if (puVar5 == (undefined4 *)0x0) {
              puVar2 = FUN_0040a880(1,10);
              *(uint **)(iVar3 + *(int *)(param_1 + 0x1c)) = puVar2;
              FUN_0041ec4a(*(undefined **)(iVar3 + *(int *)(param_1 + 0x1c)),&DAT_0042f324);
            }
            else {
              *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x1c)) = *puVar5;
              puVar5 = (undefined4 *)puVar5[1];
            }
            iVar7 = iVar7 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar7 < 1 << ((byte)*(undefined4 *)(param_2 + 4) & 0x1f));
        }
        puVar5 = (undefined4 *)(param_2 + 4);
        param_2 = *(int *)(param_2 + 0x10);
        param_4 = param_4 + (1 << ((byte)*puVar5 & 0x1f));
      } while (param_2 != 0);
    }
    iVar7 = *(int *)(DAT_0043552c + DAT_00435568 * 4);
    if (iVar7 < param_5) {
      iVar4 = param_5 - iVar7;
      piVar6 = piVar1 + iVar7;
      iVar3 = param_4 * 4;
      iVar7 = iVar7 + param_6;
      do {
        if ((*(uint *)(param_3 + 4 + (iVar7 >> 5) * 4) & 1 << ((byte)iVar7 & 0x1f)) == 0) {
          if (*piVar6 != 0) {
            FUN_0041b8c0(*piVar6);
            *piVar6 = 0;
          }
        }
        else {
          *(int *)(iVar3 + *(int *)(param_1 + 0x1c)) = *piVar6;
          iVar3 = iVar3 + 4;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    FUN_0041b8c0((int)piVar1);
  }
  return;
}



void __cdecl
FUN_0040e080(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int *param_5,int param_6)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  uint unaff_EBP;
  int iVar14;
  int iVar15;
  undefined *puVar16;
  uint *puVar17;
  short *psVar18;
  int iStack_30;
  uint *puStack_2c;
  uint uStack_28;
  uint *puStack_1c;
  int iStack_18;
  
  if (DAT_00435524 - DAT_00435528 != 2) {
    FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_use__symbolic_and__symbolic_outp_0042f328);
    puVar16 = &DAT_00431cb8;
    FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_the_present_state_and_next_state_0042f358);
    FUN_00408c40((int *)s_disassemble_pla__need_two_multip_0042f38c,(uint)puVar16);
  }
  iVar5 = *(int *)((int)DAT_00435534 + DAT_00435528 * 4);
  if (*(int *)((int)DAT_00435534 + -4 + DAT_00435524 * 4) < iVar5) {
    FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_use__symbolic_and__symbolic_outp_0042f3c4);
    puVar16 = &DAT_00431cb8;
    FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_the_present_state_and_next_state_0042f3f4);
    FUN_00408c40((int *)s_disassemble_pla____outputs_<___s_0042f428,(uint)puVar16);
  }
  iVar13 = *(int *)(DAT_0043552c + DAT_00435528 * 4);
  if ((int)DAT_00435520 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar8 = DAT_00435520;
  puVar2 = FUN_0040a880(1,iVar1 * 4);
  puVar2 = (uint *)FUN_00417140((int *)puVar2,uVar8);
  iVar1 = iVar13;
  iVar14 = iVar5;
  if (0 < iVar5) {
    do {
      iVar14 = iVar14 + -1;
      puVar2[(iVar1 >> 5) + 1] = puVar2[(iVar1 >> 5) + 1] | 1 << ((byte)iVar1 & 0x1f);
      iVar1 = iVar1 + 1;
    } while (iVar14 != 0);
  }
  iVar1 = *(int *)(DAT_0043552c + 4 + DAT_00435528 * 4);
  if ((int)DAT_00435520 < 0x21) {
    iVar14 = 2;
  }
  else {
    iVar14 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar8 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar14 * 4);
  puVar3 = (uint *)FUN_00417140((int *)puVar3,uVar8);
  iVar14 = iVar1;
  iVar15 = iVar5;
  if (0 < iVar5) {
    do {
      iVar15 = iVar15 + -1;
      puVar3[(iVar14 >> 5) + 1] = puVar3[(iVar14 >> 5) + 1] | 1 << ((byte)iVar14 & 0x1f);
      iVar14 = iVar14 + 1;
    } while (iVar15 != 0);
  }
  if ((int)DAT_00435520 < 0x21) {
    iVar14 = 2;
  }
  else {
    iVar14 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar8 = DAT_00435520;
  puVar6 = puVar3;
  puVar17 = puVar2;
  puVar4 = FUN_0040a880(1,iVar14 << 2);
  puVar4 = (uint *)FUN_00417140((int *)puVar4,uVar8);
  iVar15 = FUN_00417240(puVar4,puVar6,(int)puVar17);
  puStack_2c = FUN_00417930(10,DAT_00435520,(uint)puVar4);
  iStack_30 = 0;
  iVar14 = iVar1;
  if (0 < iVar5) {
    do {
      puVar4 = FUN_00417930(10,DAT_00435520,unaff_EBP);
      iVar5 = *param_5;
      puVar17 = *(uint **)(iVar5 + 0x18);
      puVar6 = puVar17 + *(int *)(iVar5 + 0x10) * *(int *)(iVar5 + 4);
      for (; puVar17 < puVar6; puVar17 = puVar17 + *(int *)(*param_5 + 4)) {
        iVar5 = FUN_00417560(puVar2,(int)puVar17);
        if ((iVar5 != 0) && ((puVar17[(iVar14 >> 5) + 1] & 1 << ((byte)iVar14 & 0x1f)) != 0)) {
          puVar4 = (uint *)FUN_00417b00((int)puVar4,puVar17);
        }
      }
      if (0 < (int)puVar4[4]) {
        puVar6 = FUN_0040e750(puVar4);
        uVar9 = puVar6[6];
        uVar8 = uVar9 + puVar6[4] * puVar6[1] * 4;
        if (uVar9 < uVar8) {
          iVar5 = (iVar14 >> 5) * 4 + 4;
          do {
            *(uint *)(iVar5 + uVar9) = *(uint *)(iVar5 + uVar9) | 1 << ((byte)iVar14 & 0x1f);
            uVar9 = uVar9 + puVar6[1] * 4;
          } while (uVar9 < uVar8);
        }
        puStack_2c = (uint *)FUN_00417860((int)puStack_2c,(short *)puVar6);
        if (param_6 != 0) {
          FUN_0041b470((byte *)s___state_EVERY_to__d__before__d_a_0042f450);
        }
      }
      iStack_30 = iStack_30 + 1;
      iVar14 = iVar14 + 1;
    } while (iStack_30 < (int)uStack_28);
  }
  puVar4 = FUN_00417930(10,DAT_00435520,unaff_EBP);
  iVar5 = *param_5;
  puVar17 = *(uint **)(iVar5 + 0x18);
  puVar6 = puVar17 + *(int *)(iVar5 + 0x10) * *(int *)(iVar5 + 4);
  for (; puVar17 < puVar6; puVar17 = puVar17 + *(int *)(*param_5 + 4)) {
    iVar5 = FUN_00417510(puVar17,(int)puVar3);
    if (iVar5 != 0) {
      puVar4 = (uint *)FUN_00417b00((int)puVar4,puVar17);
    }
  }
  puVar6 = FUN_00407950((short *)puVar4,DAT_00435528,DAT_00435528);
  puStack_2c = (uint *)FUN_00417860((int)puStack_2c,(short *)puVar6);
  if (param_6 != 0) {
    FUN_0041b470((byte *)s___state_ANY_to_NOWHERE__before___0042f47c);
  }
  iStack_30 = 0;
  if (0 < (int)uStack_28) {
    do {
      iStack_18 = 0;
      iVar5 = iVar1;
      do {
        puStack_1c = FUN_00417930(10,DAT_00435520,unaff_EBP);
        iVar14 = *param_5;
        puVar17 = *(uint **)(iVar14 + 0x18);
        puVar6 = puVar17 + *(int *)(iVar14 + 0x10) * *(int *)(iVar14 + 4);
        iVar14 = iVar5 >> 5;
        for (; puVar17 < puVar6; puVar17 = puVar17 + *(int *)(*param_5 + 4)) {
          iVar7 = FUN_00417560(puVar2,(int)puVar17);
          if (iVar7 == 0) {
            iVar7 = iVar13 >> 5;
            uVar8 = 1 << ((byte)iVar13 & 0x1f);
            if (((uVar8 & puVar17[iVar7 + 1]) != 0) &&
               (uVar9 = 1 << ((byte)iVar5 & 0x1f), (puVar17[iVar14 + 1] & uVar9) != 0)) {
              uVar10 = (*puVar17 & 0x3ff) * 0x20;
              if (uVar10 < 0x21) {
                iVar11 = 2;
              }
              else {
                iVar11 = (uVar10 - 1 >> 5) + 2;
              }
              puVar4 = puVar17;
              puVar12 = FUN_0040a880(1,iVar11 * 4);
              puVar4 = (uint *)FUN_004171c0((int)puVar12,puVar4);
              FUN_00417290(puVar4,puVar4,iVar15);
              puVar4[iVar7 + 1] = puVar4[iVar7 + 1] | uVar8;
              puVar4[iVar14 + 1] = puVar4[iVar14 + 1] | uVar9;
              puStack_1c = (uint *)FUN_00417b00((int)puStack_1c,puVar4);
              if (puVar4 != (uint *)0x0) {
                FUN_0041b8c0((int)puVar4);
              }
            }
          }
        }
        if (0 < (int)puStack_1c[4]) {
          puVar6 = FUN_0040e750(puStack_1c);
          uVar9 = puVar6[6];
          uVar8 = uVar9 + puVar6[4] * puVar6[1] * 4;
          if (uVar9 < uVar8) {
            iVar14 = iVar14 * 4 + 4;
            do {
              *(uint *)(iVar14 + uVar9) = *(uint *)(iVar14 + uVar9) | 1 << ((byte)iVar5 & 0x1f);
              uVar9 = uVar9 + puVar6[1] * 4;
            } while (uVar9 < uVar8);
          }
          puStack_2c = (uint *)FUN_00417860((int)puStack_2c,(short *)puVar6);
          if (param_6 != 0) {
            FUN_0041b470((byte *)s___state__d_to__d__before__d_afte_0042f4a8);
          }
        }
        iStack_18 = iStack_18 + 1;
        iVar5 = iVar5 + 1;
      } while (iStack_18 < (int)uStack_28);
      iStack_30 = iStack_30 + 1;
      iVar13 = iVar13 + 1;
    } while (iStack_30 < (int)uStack_28);
  }
  if (iVar15 != 0) {
    FUN_0041b8c0(iVar15);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  FUN_00417a40((short *)*param_5);
  psVar18 = (short *)param_5[1];
  *param_5 = (int)puStack_2c;
  FUN_00417a40(psVar18);
  puVar2 = FUN_00417930(0,DAT_00435520,(uint)psVar18);
  param_5[1] = (int)puVar2;
  FUN_00405270();
  if (DAT_00435534 != (uint *)0x0) {
    FUN_0041b8c0((int)DAT_00435534);
    DAT_00435534 = (uint *)0x0;
  }
  DAT_00435528 = param_2;
  DAT_00435524 = param_2 + 3;
  DAT_00435534 = FUN_0040a880(1,DAT_00435524 * 4);
  DAT_00435534[DAT_00435528] = uStack_28;
  DAT_00435534[DAT_00435528 + 1] = uStack_28;
  DAT_00435534[DAT_00435528 + 2] = param_3 - uStack_28;
  FUN_00404e20();
  iVar5 = *param_5;
  uVar9 = *(uint *)(iVar5 + 0x18);
  uVar8 = uVar9 + *(int *)(iVar5 + 0x10) * *(int *)(iVar5 + 4) * 4;
  for (; uVar9 < uVar8; uVar9 = uVar9 + *(int *)(*param_5 + 4) * 4) {
    FUN_00409dc0((int *)&DAT_00431c98,(int)param_5,uVar9,0x42f4d0);
  }
  return;
}



uint * __cdecl FUN_0040e750(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint unaff_EDI;
  
  puVar1 = FUN_00417930(0,DAT_00435520,unaff_EDI);
  puVar2 = FUN_00402950((int)param_1);
  puVar2 = FUN_00403160(puVar2);
  puVar3 = FUN_0040ac70(param_1,(uint)puVar1,(short *)puVar2);
  FUN_00417a40((short *)puVar1);
  FUN_00417a40((short *)puVar2);
  return puVar3;
}



uint * __cdecl FUN_0040e7a0(int *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int *unaff_EDI;
  
  puVar4 = FUN_00419cc0();
  piVar5 = FUN_0040e8b0(param_1);
  iVar6 = piVar5[6];
  while (0 < iVar6) {
    puVar8 = (uint *)piVar5[4];
    for (puVar1 = (uint *)puVar8[5]; puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[5]) {
      if ((int)puVar1[1] < (int)puVar8[1]) {
        puVar8 = puVar1;
      }
    }
    if (param_2 == 0) {
      iVar7 = 1;
    }
    else {
      uVar2 = *puVar8;
      if (((int)uVar2 < 0) || (param_1[1] <= (int)uVar2)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(*param_1 + uVar2 * 4);
      }
      iVar7 = *(int *)(param_2 + *(int *)(*(int *)(iVar6 + 0xc) + 4) * 4);
      for (iVar6 = *(int *)(*(int *)(iVar6 + 0xc) + 0x10); iVar6 != 0;
          iVar6 = *(int *)(iVar6 + 0x10)) {
        iVar3 = *(int *)(param_2 + *(int *)(iVar6 + 4) * 4);
        if (iVar3 < iVar7) {
          iVar7 = iVar3;
        }
      }
    }
    puVar4[1] = puVar4[1] + iVar7;
    FUN_00416c70(*puVar4,*puVar8);
    iVar7 = FUN_00416c40((int)puVar8);
    for (iVar6 = *(int *)(iVar7 + 0xc); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x10)) {
      FUN_00412460(piVar5,*(int *)(iVar6 + 4));
      FUN_00412520(piVar5,*(int *)(iVar6 + 4));
    }
    FUN_00416c00(iVar7);
    iVar6 = piVar5[6];
  }
  FUN_00411db0(piVar5,unaff_EDI);
  return puVar4;
}



int * __cdecl FUN_0040e8b0(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  
  piVar4 = (int *)FUN_00411d20();
  for (puVar1 = (uint *)param_1[4]; puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[5]) {
    for (uVar2 = puVar1[3]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x10)) {
      iVar5 = *(int *)(uVar2 + 4);
      if ((iVar5 < 0) || (param_1[3] <= iVar5)) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1[2] + iVar5 * 4);
      }
      for (piVar3 = *(int **)(iVar5 + 0xc); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
        iVar5 = *piVar3;
        if ((iVar5 < 0) || (param_1[1] <= iVar5)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(*param_1 + iVar5 * 4);
        }
        *(undefined4 *)(iVar5 + 8) = 0;
      }
    }
    for (uVar2 = puVar1[3]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x10)) {
      iVar5 = *(int *)(uVar2 + 4);
      if ((iVar5 < 0) || (param_1[3] <= iVar5)) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1[2] + iVar5 * 4);
      }
      for (piVar3 = *(int **)(iVar5 + 0xc); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
        iVar5 = *piVar3;
        if ((iVar5 < 0) || (param_1[1] <= iVar5)) {
          puVar6 = (uint *)0x0;
        }
        else {
          puVar6 = *(uint **)(*param_1 + iVar5 * 4);
        }
        if (puVar6[2] == 0) {
          puVar6[2] = 1;
          FUN_00411f90(piVar4,*puVar1,*puVar6);
        }
      }
    }
  }
  return piVar4;
}



void __cdecl FUN_0040e9b0(int *param_1,short *param_2)

{
  FUN_0040e9d0(param_1,param_2);
  FUN_004176e0((int)param_1);
  return;
}



void __cdecl FUN_0040e9d0(int *param_1,short *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int *piVar7;
  short *local_c;
  int local_8;
  int *local_4;
  
  psVar5 = param_2;
  piVar7 = param_1;
  FUN_0040eb60((int)param_1,(int)param_2,(int *)&param_2,(int *)&local_c,(int *)&param_1);
  local_4 = FUN_0040edb0((int)psVar5,(int)param_2,(int)param_1);
  iVar6 = FUN_00412a50((int)local_4,(int *)0x0,1,0);
  puVar3 = (uint *)piVar7[6];
  puVar2 = puVar3 + piVar7[4] * piVar7[1];
  for (; puVar3 < puVar2; puVar3 = puVar3 + piVar7[1]) {
    *puVar3 = *puVar3 & 0xffffdbff;
  }
  puVar3 = *(uint **)(param_2 + 0xc);
  puVar2 = puVar3 + *(int *)(param_2 + 8) * *(int *)(param_2 + 2);
  while( true ) {
    local_8 = iVar6;
    if (puVar2 <= puVar3) {
      for (iVar4 = *(int *)(iVar6 + 0xc); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
        puVar2 = (uint *)(piVar7[6] + *(int *)(iVar4 + 4) * piVar7[1] * 4);
        *puVar2 = *puVar2 | 0x2000;
      }
      if (((byte)DAT_00435400 & 0x20) != 0) {
        FUN_0041b470((byte *)s___IRRED__F__d_E__d_R__d_Rt__d_Rp_0042f500);
      }
      FUN_00417a40(param_2);
      FUN_00417a40(local_c);
      piVar7 = param_1;
      FUN_00417a40((short *)param_1);
      FUN_00411db0(local_4,piVar7);
      FUN_00416c00(iVar6);
      return;
    }
    puVar1 = (uint *)(piVar7[6] + (*puVar3 >> 0x10) * piVar7[1] * 4);
    iVar6 = FUN_004174c0(puVar1,(int)puVar3);
    if (iVar6 == 0) break;
    *puVar1 = *puVar1 | 0x2400;
    puVar3 = puVar3 + *(int *)(param_2 + 2);
    iVar6 = local_8;
  }
  FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_Assertion_failed__file__s__line___0042f4dc);
  FUN_0041f0ff((int *)&DAT_00431c98);
  FUN_00420108();
  return;
}



void __cdecl FUN_0040eb60(int param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint unaff_EBP;
  uint uVar7;
  
  iVar5 = 0;
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar2 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar1 < puVar2; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    uVar6 = iVar5 << 0x10;
    iVar5 = iVar5 + 1;
    *puVar1 = *puVar1 & 0xffff | uVar6;
  }
  uVar6 = 10;
  puVar2 = FUN_00417930(10,DAT_00435520,unaff_EBP);
  *param_3 = (int)puVar2;
  uVar7 = 10;
  puVar2 = FUN_00417930(10,DAT_00435520,uVar6);
  *param_4 = (int)puVar2;
  uVar6 = 10;
  puVar2 = FUN_00417930(10,DAT_00435520,uVar7);
  *param_5 = (int)puVar2;
  puVar3 = FUN_00417930(10,DAT_00435520,uVar6);
  puVar4 = FUN_00402a00(param_1,param_2);
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar2 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar1 < puVar2; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    iVar5 = FUN_0040ef50(puVar4,puVar1);
    if (iVar5 == 0) {
      iVar5 = FUN_00417b00(*param_3,puVar1);
      *param_3 = iVar5;
    }
    else {
      puVar3 = (uint *)FUN_00417b00((int)puVar3,puVar1);
    }
    if ((DAT_00435400 & 0x4000) != 0) {
      iVar5 = FUN_0041b360();
      FUN_004163a0(iVar5);
      FUN_0041b470((byte *)s_IRRED1__zr__d_ze__d_to_go__d_tim_0042f540);
    }
  }
  if (*puVar4 != 0) {
    FUN_0041b8c0(*puVar4);
    *puVar4 = 0;
  }
  if (puVar4 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar4);
  }
  puVar4 = FUN_00402a00(*param_3,param_2);
  puVar1 = (uint *)puVar3[6];
  puVar2 = puVar1 + puVar3[4] * puVar3[1];
  for (; puVar1 < puVar2; puVar1 = puVar1 + puVar3[1]) {
    iVar5 = FUN_0040ef50(puVar4,puVar1);
    if (iVar5 == 0) {
      iVar5 = FUN_00417b00(*param_5,puVar1);
      *param_5 = iVar5;
    }
    else {
      iVar5 = FUN_00417b00(*param_4,puVar1);
      *param_4 = iVar5;
    }
    if ((DAT_00435400 & 0x4000) != 0) {
      iVar5 = FUN_0041b360();
      FUN_004163a0(iVar5);
      FUN_0041b470((byte *)s_IRRED1__zr__d_zrt__d_to_go__d_ti_0042f568);
    }
  }
  if (*puVar4 != 0) {
    FUN_0041b8c0(*puVar4);
    *puVar4 = 0;
  }
  if (puVar4 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar4);
  }
  FUN_00417a40((short *)puVar3);
  return;
}



int * __cdecl FUN_0040edb0(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    *puVar2 = *puVar2 & 0xffffefff;
  }
  puVar2 = *(uint **)(param_2 + 0x18);
  puVar1 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
    *puVar2 = *puVar2 & 0xffffefff;
  }
  puVar2 = *(uint **)(param_3 + 0x18);
  puVar1 = puVar2 + *(int *)(param_3 + 4) * *(int *)(param_3 + 0x10);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_3 + 4)) {
    *puVar2 = *puVar2 | 0x1000;
  }
  piVar3 = (int *)FUN_00402b00(param_1,param_2,param_3);
  piVar4 = (int *)FUN_00411d20();
  puVar2 = *(uint **)(param_3 + 0x18);
  param_1 = 0;
  puVar1 = puVar2 + *(int *)(param_3 + 4) * *(int *)(param_3 + 0x10);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_3 + 4)) {
    DAT_004330a4 = *puVar2 >> 0x10;
    FUN_0040f3b0(piVar3,puVar2,piVar4);
    *puVar2 = *puVar2 & 0xffffefff;
    if ((DAT_00435400 & 0x4000) != 0) {
      iVar5 = FUN_0041b360();
      FUN_004163a0(iVar5);
      FUN_0041b470((byte *)s_IRRED1___d_of__d_to_go__d__table_0042f590);
    }
    if (1000 < piVar4[6] - param_1) {
      FUN_0040a300(piVar4);
      param_1 = piVar4[6];
      if ((DAT_00435400 & 0x4000) != 0) {
        FUN_0041b470((byte *)s_IRRED1__delete_redundant_rows__n_0042f5c0);
      }
    }
  }
  if (*piVar3 != 0) {
    FUN_0041b8c0(*piVar3);
    *piVar3 = 0;
  }
  if (piVar3 != (int *)0x0) {
    FUN_0041b8c0((int)piVar3);
  }
  return piVar4;
}



void __cdecl FUN_0040ef50(undefined4 *param_1,uint *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00402260(param_1,param_2);
  FUN_0040ef70(piVar1);
  return;
}



int __cdecl FUN_0040ef70(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = DAT_004330a8;
  if ((DAT_00435400 & 0x200) != 0) {
    DAT_004330a8 = DAT_004330a8 + 1;
    FUN_00409aa0(param_1,s_TAUTOLOGY_0042f5ec,iVar1);
  }
  iVar1 = FUN_0040f0e0(param_1);
  if (iVar1 != 2) goto LAB_0040f097;
  if (DAT_00435520 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar5 = DAT_00435520;
  puVar2 = FUN_0040a880(1,iVar1 << 2);
  puVar2 = (uint *)FUN_00417140((int *)puVar2,iVar5);
  if (DAT_00435520 < 0x21) {
    iVar1 = 2;
  }
  else {
    iVar1 = (DAT_00435520 + -1 >> 5) + 2;
  }
  iVar5 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar1 * 4);
  puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar5);
  iVar1 = FUN_00402800(param_1,puVar2,puVar3,0x200);
  piVar4 = (int *)FUN_00402360(param_1,(uint)puVar2,iVar1);
  iVar5 = FUN_0040ef70(piVar4);
  if (iVar5 == 0) {
LAB_0040f058:
    iVar1 = 0;
  }
  else {
    piVar4 = (int *)FUN_00402360(param_1,(uint)puVar3,iVar1);
    iVar1 = FUN_0040ef70(piVar4);
    if (iVar1 == 0) goto LAB_0040f058;
    iVar1 = 1;
  }
  if (*param_1 != 0) {
    FUN_0041b8c0(*param_1);
    *param_1 = 0;
  }
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
LAB_0040f097:
  if ((DAT_00435400 & 0x200) != 0) {
    DAT_004330a8 = DAT_004330a8 + -1;
    FUN_0041b470((byte *)s_exit_TAUTOLOGY__d____s_0042f610);
  }
  return iVar1;
}



undefined4 __cdecl FUN_0040f0e0(int *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *local_c;
  int *local_4;
  
  piVar4 = param_1;
  puVar1 = (uint *)*DAT_0043554c;
  puVar2 = (uint *)DAT_0043554c[1];
  piVar6 = param_1 + 2;
  puVar3 = (uint *)*piVar6;
  while (puVar3 != (uint *)0x0) {
    piVar6 = piVar6 + 1;
    iVar5 = FUN_00418630(puVar3,*piVar4);
    if (iVar5 != 0) {
      iVar5 = *piVar4;
      goto joined_r0x0040f265;
    }
    puVar3 = (uint *)*piVar6;
  }
  while( true ) {
    FUN_004171c0((int)puVar1,(uint *)*piVar4);
    iVar5 = piVar4[2];
    piVar6 = piVar4 + 3;
    while (iVar5 != 0) {
      FUN_00417240(puVar1,puVar1,iVar5);
      iVar5 = *piVar6;
      piVar6 = piVar6 + 1;
    }
    iVar5 = FUN_004174c0(puVar1,DAT_00435550);
    if (iVar5 == 0) break;
    FUN_004024a0(piVar4);
    if (DAT_00435594 == DAT_00435590) {
      iVar5 = *piVar4;
      goto joined_r0x0040f26e;
    }
    if (DAT_00435590 == 1) {
      iVar5 = *piVar4;
      DAT_00435590 = 1;
joined_r0x0040f265:
      if (iVar5 != 0) {
        FUN_0041b8c0(iVar5);
        *piVar4 = 0;
      }
      if (piVar4 != (int *)0x0) {
        FUN_0041b8c0((int)piVar4);
        return 1;
      }
      return 1;
    }
    if (DAT_00435594 == 0) {
      if ((((piVar4[1] - (int)piVar4 >> 2) + -3) / 2 <= *(int *)(DAT_00435584 + DAT_00435598 * 4))
         || (iVar5 = FUN_00407ff0(piVar4,(int *)&local_4,(int *)&param_1,DAT_00435400 & 0x200),
            iVar5 == 0)) {
        return 2;
      }
      if (*piVar4 != 0) {
        FUN_0041b8c0(*piVar4);
        *piVar4 = 0;
      }
      if (piVar4 != (int *)0x0) {
        FUN_0041b8c0((int)piVar4);
      }
      iVar5 = FUN_0040ef70(local_4);
      if (iVar5 == 0) {
        iVar5 = FUN_0040ef70(param_1);
        return iVar5;
      }
      if (*param_1 != 0) {
        FUN_0041b8c0(*param_1);
        *param_1 = 0;
      }
      if (param_1 != (int *)0x0) {
        FUN_0041b8c0((int)param_1);
      }
      return 1;
    }
    FUN_004171c0((int)puVar1,DAT_00435554);
    iVar5 = 0;
    if (0 < DAT_00435524) {
      do {
        if (*(int *)(DAT_0043558c + iVar5 * 4) != 0) {
          FUN_00417240(puVar1,puVar1,*(int *)(DAT_00435548 + iVar5 * 4));
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_00435524);
    }
    piVar6 = piVar4 + 2;
    puVar3 = (uint *)piVar4[2];
    local_c = piVar6;
    while (puVar3 != (uint *)0x0) {
      piVar6 = piVar6 + 1;
      iVar5 = FUN_00417240(puVar2,puVar3,*piVar4);
      iVar5 = FUN_00417560(puVar1,iVar5);
      if (iVar5 != 0) {
        *local_c = (int)puVar3;
        local_c = local_c + 1;
      }
      puVar3 = (uint *)*piVar6;
    }
    *local_c = 0;
    piVar4[1] = (int)(local_c + 1);
    if ((DAT_00435400 & 0x200) != 0) {
      FUN_0041b470((byte *)s_UNATE_REDUCTION___d_unate_variab_0042f628);
    }
  }
  iVar5 = *piVar4;
joined_r0x0040f26e:
  if (iVar5 != 0) {
    FUN_0041b8c0(iVar5);
    *piVar4 = 0;
  }
  if (piVar4 != (int *)0x0) {
    FUN_0041b8c0((int)piVar4);
  }
  return 0;
}



void __cdecl FUN_0040f3b0(undefined4 *param_1,uint *param_2,int *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00402260(param_1,param_2);
  FUN_0040f3e0(piVar1,param_3);
  return;
}



void __cdecl FUN_0040f3e0(int *param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = DAT_004330ac;
  if ((DAT_00435400 & 0x200) != 0) {
    DAT_004330ac = DAT_004330ac + 1;
    FUN_00409aa0(param_1,s_FIND_TAUTOLOGY_0042f65c,iVar1);
  }
  iVar1 = FUN_0040f550(param_1,param_2);
  if (iVar1 == 2) {
    if (DAT_00435520 < 0x21) {
      iVar1 = 2;
    }
    else {
      iVar1 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar6 = DAT_00435520;
    puVar2 = FUN_0040a880(1,iVar1 * 4);
    puVar2 = (uint *)FUN_00417140((int *)puVar2,iVar6);
    if (DAT_00435520 < 0x21) {
      iVar1 = 2;
    }
    else {
      iVar1 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar6 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar1 * 4);
    puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar6);
    iVar1 = FUN_00402800(param_1,puVar2,puVar3,0x200);
    piVar5 = param_2;
    piVar4 = (int *)FUN_00402360(param_1,(uint)puVar2,iVar1);
    FUN_0040f3e0(piVar4,piVar5);
    piVar5 = (int *)FUN_00402360(param_1,(uint)puVar3,iVar1);
    FUN_0040f3e0(piVar5,param_2);
    if (*param_1 != 0) {
      FUN_0041b8c0(*param_1);
      *param_1 = 0;
    }
    if (param_1 != (int *)0x0) {
      FUN_0041b8c0((int)param_1);
    }
    if (puVar2 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar2);
    }
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
  }
  if ((DAT_00435400 & 0x200) != 0) {
    DAT_004330ac = DAT_004330ac + -1;
    FUN_0041b470((byte *)s_exit_FIND_TAUTOLOGY__d___table_i_0042f66c);
  }
  return;
}



undefined4 __cdecl FUN_0040f550(int *param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  puVar1 = (uint *)*DAT_0043554c;
  puVar2 = (uint *)DAT_0043554c[1];
  puVar3 = (uint *)param_1[2];
  piVar6 = param_1 + 3;
  while( true ) {
    if (puVar3 == (uint *)0x0) {
      FUN_004024a0(param_1);
      if (DAT_00435594 != DAT_00435590) {
        do {
          if (DAT_00435594 == 0) {
            return 2;
          }
          FUN_004171c0((int)puVar2,DAT_00435554);
          iVar5 = 0;
          if (0 < DAT_00435524) {
            do {
              if (*(int *)(DAT_0043558c + iVar5 * 4) != 0) {
                FUN_00417240(puVar2,puVar2,*(int *)(DAT_00435548 + iVar5 * 4));
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < DAT_00435524);
          }
          piVar6 = param_1 + 2;
          puVar3 = (uint *)param_1[2];
          piVar4 = param_1 + 3;
          while (puVar3 != (uint *)0x0) {
            iVar5 = FUN_00417240(puVar1,puVar3,*param_1);
            iVar5 = FUN_00417560(puVar2,iVar5);
            if (iVar5 != 0) {
              *piVar6 = (int)puVar3;
              piVar6 = piVar6 + 1;
            }
            puVar3 = (uint *)*piVar4;
            piVar4 = piVar4 + 1;
          }
          *piVar6 = 0;
          param_1[1] = (int)(piVar6 + 1);
          if ((DAT_00435400 & 0x200) != 0) {
            FUN_0041b470((byte *)s_UNATE_REDUCTION___d_unate_variab_0042f698);
          }
          FUN_004024a0(param_1);
        } while (DAT_00435594 != DAT_00435590);
      }
      if ((int *)param_2[5] == (int *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(int *)param_2[5] + 1;
      }
      FUN_00411f90(param_2,uVar7,DAT_004330a4);
      puVar1 = (uint *)param_1[2];
      piVar6 = param_1 + 3;
      while (puVar1 != (uint *)0x0) {
        if (((*puVar1 & 0x1000) != 0) && (iVar5 = FUN_00418630(puVar1,*param_1), iVar5 != 0)) {
          FUN_00411f90(param_2,uVar7,*puVar1 >> 0x10);
        }
        puVar1 = (uint *)*piVar6;
        piVar6 = piVar6 + 1;
      }
      if (*param_1 != 0) {
        FUN_0041b8c0(*param_1);
        *param_1 = 0;
      }
      if (param_1 != (int *)0x0) {
        FUN_0041b8c0((int)param_1);
      }
      return 1;
    }
    if (((*puVar3 & 0x1000) == 0) && (iVar5 = FUN_00418630(puVar3,*param_1), iVar5 != 0)) break;
    puVar3 = (uint *)*piVar6;
    piVar6 = piVar6 + 1;
  }
  if (*param_1 != 0) {
    FUN_0041b8c0(*param_1);
    *param_1 = 0;
  }
  if (param_1 == (int *)0x0) {
    return 1;
  }
  FUN_0041b8c0((int)param_1);
  return 1;
}



uint * __cdecl FUN_0040f770(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  puVar1 = FUN_0040a880(1,((param_1[1] - (int)param_1 >> 2) + -3 +
                          (*(int *)(param_2 + 4) - param_2 >> 2)) * 4);
  if (DAT_00435520 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = (DAT_00435520 + -1 >> 5) + 2;
  }
  puVar6 = (uint *)*param_1;
  iVar5 = DAT_00435520;
  puVar3 = FUN_0040a880(1,iVar2 << 2);
  iVar2 = FUN_00417140((int *)puVar3,iVar5);
  uVar4 = FUN_004171c0(iVar2,puVar6);
  puVar6 = param_1 + 2;
  *puVar1 = uVar4;
  puVar3 = puVar1 + 2;
  uVar4 = *puVar6;
  while (uVar4 != 0) {
    puVar6 = puVar6 + 1;
    *puVar3 = uVar4;
    puVar3 = puVar3 + 1;
    uVar4 = *puVar6;
  }
  puVar6 = (uint *)(param_2 + 8);
  uVar4 = *(uint *)(param_2 + 8);
  while (uVar4 != 0) {
    puVar6 = puVar6 + 1;
    *puVar3 = uVar4;
    puVar3 = puVar3 + 1;
    uVar4 = *puVar6;
  }
  *puVar3 = 0;
  puVar1[1] = (uint)(puVar3 + 1);
  return puVar1;
}



void __cdecl FUN_0040f840(undefined4 *param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  FUN_004171c0(*param_3,(uint *)*param_1);
  puVar5 = param_1 + 2;
  piVar4 = param_3 + 2;
  puVar1 = (uint *)param_1[2];
  while (puVar1 != (uint *)0x0) {
    puVar5 = puVar5 + 1;
    if ((*puVar1 & 0x400) != 0) {
      *piVar4 = (int)puVar1;
      piVar4 = piVar4 + 1;
    }
    puVar1 = (uint *)*puVar5;
  }
  iVar2 = *(int *)(param_2 + 8);
  piVar3 = (int *)(param_2 + 0xc);
  while (iVar2 != 0) {
    *piVar4 = iVar2;
    piVar4 = piVar4 + 1;
    iVar2 = *piVar3;
    piVar3 = piVar3 + 1;
  }
  *piVar4 = 0;
  param_3[1] = (int)(piVar4 + 1);
  return;
}



void FUN_0040f8b0(int param_1)

{
  if (DAT_004330c8 != 0) {
    FUN_0040aa50(2,0x14);
  }
                    // WARNING: Subroutine does not return
  _longjmp((int *)&DAT_00435320,param_1);
}



void __cdecl FUN_0040f8e0(int param_1,undefined **param_2)

{
  undefined **ppuVar1;
  byte *pbVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  short *psVar8;
  int *piVar9;
  undefined **ppuVar10;
  char *pcVar11;
  void *this;
  uint uVar12;
  uint uVar13;
  void *this_00;
  uint extraout_ECX;
  uint *puVar14;
  uint uVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  int *unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  char *pcVar19;
  undefined **ppuVar20;
  uint *puVar21;
  bool bVar22;
  byte bVar23;
  undefined8 uVar24;
  byte in_stack_007e0045;
  int *in_stack_ffffffa4;
  int *in_stack_ffffffa8;
  int in_stack_ffffffac;
  uint local_44;
  uint *local_40;
  undefined8 local_3c;
  uint local_34;
  short *local_30;
  int local_2c;
  uint *local_28;
  int local_24;
  undefined **local_20;
  int local_1c;
  int *local_18;
  undefined *local_14;
  uint local_10;
  short *local_c;
  uint *local_8;
  
  pbVar2 = (byte *)FUN_00420199((uchar *)s_ESPTIMEOUT_0042fe34);
  if ((pbVar2 != (byte *)0x0) && (iVar3 = FUN_0041f45f(this,pbVar2), 0 < iVar3)) {
    DAT_0042fbb0 = iVar3 * 1000;
  }
  local_40 = (uint *)FUN_0041b360();
  local_28 = (uint *)0x0;
  FUN_004110a0();
  local_1c = 0;
  local_10 = 1;
  DAT_00435400 = 0;
  DAT_00435570 = 0;
  DAT_004354c4 = (uint *)0x1;
  DAT_004353d0 = 0;
  DAT_00435408 = 0;
  local_c = (short *)0x0;
  local_20 = (undefined **)0xffffffff;
  local_14 = (undefined *)0xffffffff;
  DAT_004354c8 = 1;
  DAT_0043556c = 1;
  DAT_00435370 = 1;
  DAT_00435574 = 0;
  DAT_00435410 = 0;
  DAT_00435460 = 0;
  DAT_004353cc = 0;
  DAT_00435404 = 0;
  DAT_004353fc = 0;
  DAT_0043540c = 1;
  DAT_00435464 = 1;
  local_30 = (short *)0x0;
  DAT_004330b4 = FUN_0040a880(1,0x5b);
  puVar4 = (uint *)s_MINOPT_EXE_01_NOV_1999__v4_02___0042fe40;
  puVar21 = DAT_004330b4;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar21 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar21 = puVar21 + 1;
  }
  *(undefined2 *)puVar21 = *(undefined2 *)puVar4;
  uVar12 = 0xffffffff;
  pcVar11 = PTR_s_6_3_IR_35_0042fba0;
  do {
    pcVar19 = pcVar11;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar19 = pcVar11 + 1;
    cVar16 = *pcVar11;
    pcVar11 = pcVar19;
  } while (cVar16 != '\0');
  uVar12 = ~uVar12;
  iVar3 = -1;
  puVar4 = DAT_004330b4;
  do {
    puVar21 = puVar4;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    puVar21 = (uint *)((int)puVar4 + 1);
    cVar16 = *(char *)puVar4;
    puVar4 = puVar21;
  } while (cVar16 != '\0');
  pcVar11 = pcVar19 + -uVar12;
  ppuVar20 = (undefined **)((int)puVar21 + -1);
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *ppuVar20 = *(undefined **)pcVar11;
    pcVar11 = pcVar11 + 4;
    ppuVar20 = ppuVar20 + 1;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(char *)ppuVar20 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    ppuVar20 = (undefined **)((int)ppuVar20 + 1);
  }
  if (param_1 < 3) {
    FUN_0040a9d0(s__MOCHA__RPT_0042fe68);
    FUN_00411230(unaff_EDI,unaff_ESI);
  }
  ppuVar10 = param_2;
  puVar4 = FUN_00411910(&param_1,param_2,(byte *)s__rr_esp_0042fe74,(uint *)0x0);
  if (puVar4 != (uint *)0x0) {
    DAT_0042fbac = FUN_0041f45f(this_00,(byte *)puVar4);
  }
  DAT_00435360 = (char *)FUN_00411910(&param_1,ppuVar10,&DAT_0042fe7c,(uint *)DAT_00435360);
  if ((uint *)DAT_00435360 == (uint *)0x0) {
    DAT_00435360 = s__MOCHA__RPT_0042fe84;
  }
  DAT_00435364 = (char *)FUN_00411910(&param_1,ppuVar10,&DAT_0042fe90,(uint *)DAT_00435364);
  if ((uint *)DAT_00435364 == (uint *)0x0) {
    DAT_00435364 = s__MOCHA__PLX_0042fe98;
  }
  FUN_0040a9d0(DAT_00435360);
  DAT_00435368 = (FILE *)FUN_0041ec37(DAT_00435364,&DAT_0042fea4);
  if (DAT_00435368 == (FILE *)0x0) {
    FUN_0040aa50(4,0x1e);
  }
  FUN_00411550(&param_1,(int *)ppuVar10,&local_1c);
  iVar3 = FUN_0040ceb0(param_1,(int)ppuVar10,s_D_S_de_o_r_stv_x_q_0042fea8);
  while (iVar3 != -1) {
    switch(iVar3) {
    case 0x44:
      iVar7 = 0;
      ppuVar10 = (undefined **)PTR_s_OPTIMIZE_0042f6d0;
      iVar3 = local_1c;
      if ((undefined **)PTR_s_OPTIMIZE_0042f6d0 != (undefined **)0x0) {
        ppuVar20 = &PTR_s_OPTIMIZE_0042f6d0;
        pbVar2 = DAT_0043559c;
LAB_0040fb33:
        do {
          bVar23 = *pbVar2;
          bVar22 = bVar23 < *(byte *)ppuVar10;
          if (bVar23 == *(byte *)ppuVar10) {
            if (bVar23 != 0) {
              bVar23 = pbVar2[1];
              bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
              if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fb57;
              ppuVar10 = (undefined **)((int)ppuVar10 + 2);
              pbVar2 = pbVar2 + 2;
              if (bVar23 != 0) goto LAB_0040fb33;
            }
            iVar5 = 0;
          }
          else {
LAB_0040fb57:
            iVar5 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          iVar3 = iVar7;
          if (iVar5 == 0) break;
          ppuVar10 = (undefined **)ppuVar20[5];
          ppuVar20 = ppuVar20 + 5;
          iVar7 = iVar7 + 1;
          pbVar2 = DAT_0043559c;
          iVar3 = local_1c;
        } while (ppuVar10 != (undefined **)0x0);
      }
      local_1c = iVar3;
      if ((&PTR_s_OPTIMIZE_0042f6d0)[iVar7 * 5] == (undefined *)0x0) {
        FUN_0040aa50(4,0xc);
        FUN_0041ef48(1);
LAB_0040fe83:
        FUN_0040aa50(4,0xd);
        FUN_0041ef48(1);
LAB_0040fea1:
        FUN_0040aa50(4,0xe);
        FUN_0041ef48(1);
LAB_0040febe:
        FUN_0040aa50(4,0xf);
        FUN_0041ef48(1);
LAB_0040fedc:
        FUN_0040aa50(4,0x10);
        unaff_EBX = (int *)0x1;
        FUN_0041ef48(1);
        goto switchD_0040fb07_caseD_45;
      }
      break;
    default:
switchD_0040fb07_caseD_45:
      FUN_00411230(unaff_EBX,in_stack_ffffffa4);
      unaff_EBX = (int *)0x40ff05;
      FUN_0041ef48(0x40ff05);
      goto LAB_0040ff05;
    case 0x53:
      local_c = (short *)FUN_0041f45f(DAT_0043559c,DAT_0043559c);
      break;
    case 100:
      DAT_00435408 = 1;
      DAT_00435400 = DAT_0042fa84;
    case 0x73:
      DAT_004353d0 = 1;
      break;
    case 0x65:
      iVar3 = 0;
      ppuVar10 = (undefined **)PTR_DAT_0042fb08;
      if ((undefined **)PTR_DAT_0042fb08 != (undefined **)0x0) {
        ppuVar20 = &PTR_DAT_0042fb08;
        pbVar2 = DAT_0043559c;
LAB_0040fc17:
        do {
          bVar23 = *pbVar2;
          bVar22 = bVar23 < *(byte *)ppuVar10;
          if (bVar23 == *(byte *)ppuVar10) {
            if (bVar23 != 0) {
              bVar23 = pbVar2[1];
              bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
              if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fc3b;
              ppuVar10 = (undefined **)((int)ppuVar10 + 2);
              pbVar2 = pbVar2 + 2;
              if (bVar23 != 0) goto LAB_0040fc17;
            }
            iVar7 = 0;
          }
          else {
LAB_0040fc3b:
            iVar7 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          if (iVar7 == 0) {
            *(undefined4 *)(&PTR_DAT_0042fb0c)[iVar3 * 3] = (&DAT_0042fb10)[iVar3 * 3];
            break;
          }
          ppuVar10 = (undefined **)ppuVar20[3];
          ppuVar20 = ppuVar20 + 3;
          iVar3 = iVar3 + 1;
          pbVar2 = DAT_0043559c;
        } while (ppuVar10 != (undefined **)0x0);
      }
      if ((&PTR_DAT_0042fb08)[iVar3 * 3] == (undefined *)0x0) goto LAB_0040fea1;
      break;
    case 0x6f:
      iVar3 = 0;
      if (PTR_DAT_0042ed08 != (undefined *)0x0) {
        ppuVar20 = &PTR_DAT_0042ed08;
        puVar6 = PTR_DAT_0042ed08;
        do {
          ppuVar10 = (undefined **)(puVar6 + 1);
          pbVar2 = DAT_0043559c;
          do {
            bVar23 = *pbVar2;
            bVar22 = bVar23 < *(byte *)ppuVar10;
            if (bVar23 != *(byte *)ppuVar10) {
LAB_0040fbc8:
              iVar7 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
              goto LAB_0040fbcd;
            }
            if (bVar23 == 0) break;
            bVar23 = pbVar2[1];
            bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
            if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fbc8;
            pbVar2 = pbVar2 + 2;
            ppuVar10 = (undefined **)((int)ppuVar10 + 2);
          } while (bVar23 != 0);
          iVar7 = 0;
LAB_0040fbcd:
          if (iVar7 == 0) {
            local_10 = (&DAT_0042ed0c)[iVar3 * 2];
            break;
          }
          puVar6 = ppuVar20[2];
          ppuVar20 = ppuVar20 + 2;
          iVar3 = iVar3 + 1;
        } while (puVar6 != (undefined *)0x0);
      }
      if ((&PTR_DAT_0042ed08)[iVar3 * 2] == (undefined *)0x0) goto LAB_0040fe83;
      break;
    case 0x71:
      DAT_0042e060 = 0;
      break;
    case 0x72:
      iVar3 = FUN_0041f265((char *)DAT_0043559c,(byte *)s__d__d_0042febc);
      if (iVar3 < 2) goto LAB_0040fedc;
      break;
    case 0x74:
      DAT_00435408 = 1;
      break;
    case 0x76:
      iVar3 = 0;
      DAT_00435570 = 1;
      ppuVar10 = (undefined **)PTR_DAT_0042fa80;
      if ((undefined **)PTR_DAT_0042fa80 != (undefined **)0x0) {
        ppuVar20 = &PTR_DAT_0042fa80;
        pbVar2 = DAT_0043559c;
LAB_0040fcba:
        do {
          bVar23 = *pbVar2;
          bVar22 = bVar23 < *(byte *)ppuVar10;
          if (bVar23 == *(byte *)ppuVar10) {
            if (bVar23 != 0) {
              bVar23 = pbVar2[1];
              bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
              if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fcde;
              ppuVar10 = (undefined **)((int)ppuVar10 + 2);
              pbVar2 = pbVar2 + 2;
              if (bVar23 != 0) goto LAB_0040fcba;
            }
            iVar7 = 0;
          }
          else {
LAB_0040fcde:
            iVar7 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          if (iVar7 == 0) {
            DAT_00435400 = DAT_00435400 | (&DAT_0042fa84)[iVar3 * 2];
            break;
          }
          ppuVar10 = (undefined **)ppuVar20[2];
          ppuVar20 = ppuVar20 + 2;
          iVar3 = iVar3 + 1;
          pbVar2 = DAT_0043559c;
        } while (ppuVar10 != (undefined **)0x0);
      }
      if ((&PTR_DAT_0042fa80)[iVar3 * 2] == (undefined *)0x0) goto LAB_0040febe;
      break;
    case 0x78:
      DAT_004354c4 = (uint *)0x0;
    }
    iVar3 = FUN_0040ceb0(param_1,(int)param_2,s_D_S_de_o_r_stv_x_q_0042fea8);
  }
  if ((DAT_004353d0 != 0) || (DAT_00435408 != 0)) {
    FUN_0041b470(&DAT_0042fec4);
    iVar3 = 0;
    ppuVar20 = param_2;
    if (0 < param_1) {
      do {
        FUN_0041b470(&DAT_0042fec8);
        iVar3 = iVar3 + 1;
        ppuVar10 = ppuVar20 + 1;
        ppuVar20 = ppuVar10;
      } while (iVar3 < param_1);
    }
    FUN_0041b470(&DAT_0042fecc);
    FUN_0041b470((byte *)s____s_0042ff0c);
  }
  FUN_0040aa50(2,3);
  FUN_0040a940();
  FUN_0040aa50(2,4);
  FUN_0040a950();
  FUN_0040aa50(2,0x11);
  FUN_0040aa50(2,7);
  ppuVar20 = (undefined **)0x0;
  if (PTR_DAT_0042fb08 != (undefined *)0x0) {
    ppuVar10 = &PTR_DAT_0042fb08;
    do {
      iVar3 = FUN_00407400(&DAT_0042ff14,*ppuVar10);
      if (iVar3 == 0) goto LAB_0040ff05;
      ppuVar1 = ppuVar10 + 3;
      ppuVar10 = ppuVar10 + 3;
      ppuVar20 = (undefined **)((int)ppuVar20 + 1);
    } while (*ppuVar1 != (undefined *)0x0);
  }
LAB_0040ff23:
  puVar4 = (uint *)0x1;
  puVar21 = (uint *)0x0;
  if (DAT_004330b8 != 0) {
    FUN_0040aa50(2,0x13);
  }
  local_18 = (int *)0x0;
  local_8 = (uint *)0x0;
  if (*(int *)(&DAT_0042f6d8 + local_1c * 0x14) == 1) {
    if (DAT_0043309c + 1 < param_1) {
      FUN_00408c40((int *)s_trailing_arguments_on_command_li_0042ff40,(uint)unaff_EBX);
    }
    iVar3 = DAT_0043309c;
    DAT_0043309c = DAT_0043309c + 1;
    FUN_00410ee0(iVar3,param_1,(int)param_2,local_1c,(int *)&local_8,local_10);
  }
  else if (*(int *)(&DAT_0042f6d8 + local_1c * 0x14) == 2) {
    if (DAT_0043309c + 2 < param_1) {
      FUN_00408c40((int *)s_trailing_arguments_on_command_li_0042ff1c,(uint)unaff_EBX);
    }
    ppuVar10 = param_2;
    iVar3 = DAT_0043309c;
    DAT_0043309c = DAT_0043309c + 1;
    FUN_00410ee0(iVar3,param_1,(int)param_2,local_1c,(int *)&local_8,local_10);
    iVar3 = DAT_0043309c;
    DAT_0043309c = DAT_0043309c + 1;
    FUN_00410ee0(iVar3,param_1,(int)ppuVar10,local_1c,(int *)&local_18,local_10);
  }
  if (DAT_0043309c < param_1) {
    FUN_00408c40((int *)s_trailing_arguments_on_command_li_0042ff64,(uint)unaff_EBX);
  }
  if ((DAT_004353d0 != 0) || (DAT_00435408 != 0)) {
    if (local_8 != (uint *)0x0) {
      FUN_00406d90((int *)local_8);
    }
    if (local_18 != (int *)0x0) {
      FUN_00406d90(local_18);
    }
  }
  ppuVar20 = DAT_00435534;
  piVar9 = local_18;
  switch(*(undefined4 *)(&DAT_0042f6d4 + local_1c * 0x14)) {
  case 0:
    do {
      DAT_004330c4 = FUN_0041b360();
      local_24 = 1;
      if (DAT_004330bc == 0) {
        iVar3 = __setjmp3((undefined4 *)&DAT_00435320,0,unaff_EBX,in_stack_ffffffa4);
        if (iVar3 == 0) {
          iVar3 = 1;
          if (DAT_004330bc == 0) {
            iVar3 = FUN_004073f0();
          }
          if (iVar3 == 0) {
            FUN_0041b200((int *)local_8);
            local_24 = 0;
            if (((int)local_c < 0) || (1 < (int)local_c)) {
              local_c = (short *)0x0;
            }
            FUN_00408490((int *)local_8,(int)local_c);
          }
          else if (iVar3 == 2) {
            FUN_0041b200((int *)local_8);
            local_24 = 0;
            if (((int)local_c < 0) || (1 < (int)local_c)) {
              local_c = (short *)0x0;
            }
            FUN_004084f0((int *)local_8,(int)local_c);
          }
        }
        else if (((DAT_004330bc == 0) && (local_24 == 0)) && (DAT_00435574 == 0)) {
          DAT_00435574 = 1;
          DAT_004330c4 = FUN_0041b360();
          iVar3 = __setjmp3((undefined4 *)&DAT_00435320,0,unaff_EBX,in_stack_ffffffa4);
          if (iVar3 == 0) {
            iVar3 = FUN_004073f0();
            if (iVar3 == 0) {
              if (((int)local_c < 0) || (1 < (int)local_c)) {
                local_c = (short *)0x0;
              }
              FUN_00408490((int *)local_8,(int)local_c);
            }
            else if (iVar3 == 2) {
              if (((int)local_c < 0) || (1 < (int)local_c)) {
                local_c = (short *)0x0;
              }
              FUN_004084f0((int *)local_8,(int)local_c);
            }
          }
          DAT_00435574 = 0;
        }
      }
      if (DAT_004354c4 != (uint *)0x0) {
        FUN_00408c60((int *)DAT_00435368,local_8,local_10);
        FUN_0041f0ff((int *)DAT_00435368);
      }
      local_34 = local_8[4];
      FUN_00406ff0(local_8);
      FUN_00405270();
      if (DAT_00435534 != (undefined **)0x0) {
        FUN_0041b8c0((int)DAT_00435534);
        DAT_00435534 = (undefined **)0x0;
      }
      DAT_00432d94 = 0;
      local_2c = 1;
      DAT_004330bc = 0;
      DAT_004330c4 = FUN_0041b360();
      iVar3 = __setjmp3((undefined4 *)&DAT_00435320,0,unaff_EBX,in_stack_ffffffa4);
      if (iVar3 == 0) {
        local_2c = FUN_00406a00(DAT_004330b0,1,1,local_34,&local_8);
      }
      else {
        DAT_004330bc = 1;
      }
    } while (local_2c != -1);
    if (DAT_00435368 != (FILE *)0x0) {
      FUN_0041ea29(DAT_00435368);
    }
    iVar3 = FUN_0040aa30();
    if (iVar3 == 0) {
      FUN_0040aa50(2,0xc);
    }
    FUN_0040aa50(3,(int)unaff_EBX);
    iVar3 = FUN_0040aa20();
    if (iVar3 == 0) {
      iVar3 = 5;
    }
    else {
      iVar3 = 6;
    }
    FUN_0040aa50(2,iVar3);
    FUN_0040aa10();
    return;
  case 1:
    ppuVar10 = (undefined **)FUN_00417a20(*local_8);
    puVar4 = FUN_0040ac70((uint *)*local_8,local_8[1],(short *)local_8[2]);
    *local_8 = (uint)puVar4;
    puVar21 = (uint *)FUN_0041b360();
    puVar4 = (uint *)FUN_0041ae90(*local_8,(int)ppuVar10,local_8[1]);
    local_28 = puVar4;
    FUN_00408bb0((int)puVar21,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (puVar4 != (uint *)0x0) {
      DAT_004354c4 = (uint *)0x0;
      *local_8 = (uint)ppuVar10;
      FUN_0041b200((int *)local_8);
      break;
    }
    goto LAB_0041065f;
  case 2:
    iVar3 = FUN_0041b360();
    iVar7 = FUN_0041afd0((int *)local_8,local_18);
    FUN_00408bb0(iVar3,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (iVar7 != 0) {
      FUN_0041b470((byte *)s_PLA_comparison_failed__the_PLA_s_0042ffd0);
      FUN_0041ef48(1);
    }
    FUN_0041b470((byte *)s_PLA_s_compared_equal_00430008);
    piVar9 = (int *)FUN_0041ef48(0);
  case 0x27:
    puVar4 = (uint *)*piVar9;
    uVar12 = *local_8;
    puVar21 = (uint *)local_8[1];
    local_34 = FUN_0041b360();
    ppuVar10 = (undefined **)FUN_0041ae90((int)puVar4,uVar12,(int)puVar21);
    FUN_00408bb0(local_34,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (ppuVar10 != (undefined **)0x0) {
      FUN_0041b470((byte *)s_PLA_comparison_failed__the_PLA_s_00430020);
      FUN_0041ef48(1);
    }
    FUN_0041b470((byte *)s_PLA_s_compared_equal_00430058);
    unaff_EBX = (int *)0x0;
    FUN_0041ef48(0);
switchD_00410077_caseD_3:
    FUN_0041b200((int *)local_8);
    DAT_004354c4 = puVar21;
    break;
  case 3:
    goto switchD_00410077_caseD_3;
  case 4:
    puVar14 = FUN_004044e0((short *)*local_8);
    *local_8 = (uint)puVar14;
    break;
  case 5:
    if (((int)local_20 < 0) || (DAT_00435524 <= (int)local_20)) {
      local_20 = (undefined **)0x0;
    }
    if (((int)local_14 < 0) || (DAT_00435524 <= (int)local_14)) {
      local_14 = (undefined *)(DAT_00435524 + -1);
    }
    ppuVar10 = local_20;
    if ((int)local_20 <= (int)local_14) {
      do {
        uVar12 = FUN_00404720((short *)*local_8,(int)ppuVar10);
        ppuVar10 = (undefined **)((int)ppuVar10 + 1);
        *local_8 = uVar12;
      } while ((int)ppuVar10 <= (int)local_14);
    }
    break;
  case 6:
    puVar14 = FUN_004196b0(*local_8);
    *local_8 = (uint)puVar14;
    break;
  case 7:
    puVar14 = FUN_00419700(*local_8,*local_18);
    *local_8 = (uint)puVar14;
    break;
  case 8:
    FUN_0040aa50(2,0x12);
    break;
  case 9:
    uVar12 = *local_8;
    puVar14 = *(uint **)(uVar12 + 0x18);
    puVar21 = puVar14 + *(int *)(uVar12 + 0x10) * *(int *)(uVar12 + 4);
    for (; puVar14 < puVar21; puVar14 = puVar14 + *(int *)(*local_8 + 4)) {
      *puVar14 = *puVar14 & 0xffffbfff | 0x400;
    }
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar21 = FUN_0040b020(local_8,local_8 + 1);
    FUN_00408bb0((int)ppuVar10,3,*local_8,(undefined4 *)&stack0xffffffa4);
    FUN_00417a40((short *)puVar21);
    break;
  case 10:
    local_30 = (short *)0x1;
  case 0x1b:
    ppuVar10 = (undefined **)FUN_00417a20(*local_8);
    uVar12 = FUN_0040b380(*local_8,local_8[1],local_8[2],local_30);
    *local_8 = uVar12;
    puVar21 = (uint *)FUN_0041b360();
    puVar4 = (uint *)FUN_0041ae90(*local_8,(int)ppuVar10,local_8[1]);
    local_28 = puVar4;
    FUN_00408bb0((int)puVar21,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (puVar4 != (uint *)0x0) {
      DAT_004354c4 = (uint *)0x0;
      *local_8 = (uint)ppuVar10;
      FUN_0041b200((int *)local_8);
    }
LAB_0041065f:
    FUN_00417a40((short *)ppuVar10);
    break;
  case 0xb:
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar14 = FUN_0040b8a0((short *)*local_8,local_8[2],0);
    *local_8 = (uint)puVar14;
    FUN_00408bb0((int)ppuVar10,4,*local_8,(undefined4 *)&stack0xffffffa4);
    break;
  case 0xc:
    uVar12 = FUN_0040cc50(*local_8,(short *)local_8[1],local_8[2],(undefined4 *)&stack0xffffffa4);
    *local_8 = uVar12;
    break;
  case 0xd:
    uVar12 = FUN_00419a60(*local_8,*local_18);
    *local_8 = uVar12;
    break;
  case 0xe:
    ppuVar10 = (undefined **)FUN_0041b360();
    uVar12 = FUN_0040e9b0((int *)*local_8,(short *)local_8[1]);
    *local_8 = uVar12;
    FUN_00408bb0((int)ppuVar10,5,*local_8,(undefined4 *)&stack0xffffffa4);
    break;
  case 0xf:
    puVar14 = FUN_00407cc0((short *)*local_8);
    *local_8 = (uint)puVar14;
    break;
  case 0x10:
    puVar14 = FUN_00419e50(*local_8,local_8[1],local_8[2]);
    *local_8 = (uint)puVar14;
    break;
  case 0x11:
    FUN_00411b30(*local_8);
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x12:
    FUN_0040d190((int *)local_8);
    local_10 = 3;
    break;
  case 0x13:
    local_3c = (double)((ulonglong)local_3c & 0xffffffff);
    FUN_00401920(*local_8,(uint *)((int)&local_3c + 4));
    FUN_0041b470((byte *)s_Euler_Poincaire_Characteristic_M_00430070);
    break;
  case 0x14:
    uVar12 = FUN_00401d00(*local_8,local_8[1]);
    *local_8 = uVar12;
    ppuVar10 = (undefined **)FUN_00401920(*local_8,&local_44);
    local_3c._4_4_ = ppuVar10;
    FUN_00401220((int *)*local_8);
    local_34 = *(uint *)(*local_8 + 0x10);
    if (local_34 == 0) {
      local_3c = -99999.0;
    }
    else {
      local_3c = (double)(int)local_3c._4_4_ / (double)(int)local_34;
    }
    FUN_0041b470((byte *)s___EULER__Cubes___d_Components____004300a4);
    break;
  case 0x15:
    if (((int)local_20 < 0) || (DAT_00435524 <= (int)local_20)) {
      local_20 = (undefined **)0x0;
    }
    if (((int)local_14 < 0) || (DAT_00435524 <= (int)local_14)) {
      local_14 = (undefined *)(DAT_00435524 + -1);
    }
    puVar14 = FUN_00407950((short *)*local_8,(int)local_20,(int)local_14);
    puVar14 = FUN_004045f0((short *)puVar14);
    *local_8 = (uint)puVar14;
    break;
  case 0x16:
    FUN_00413310(local_8,(uint)local_c);
    break;
  case 0x17:
    if (((int)local_20 < 0) || ((int)DAT_00435534[DAT_00435568] <= (int)local_20)) {
      local_20 = (undefined **)0x0;
    }
    if (((int)local_14 < 0) || ((int)DAT_00435534[DAT_00435568] <= (int)local_14)) {
      local_14 = DAT_00435534[DAT_00435568] + -1;
    }
    FUN_00414330(local_8,(int)local_20,(int)local_14,local_c);
    ppuVar10 = ppuVar20;
    break;
  case 0x18:
    FUN_00414d10(local_8,(uint)local_c);
    break;
  case 0x19:
    FUN_00415540((int *)local_8,local_c);
    break;
  case 0x1a:
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar14 = FUN_00402a00(*local_8,local_8[1]);
    piVar9 = FUN_00415e80((int *)puVar14);
    *local_8 = (uint)piVar9;
    if (DAT_00435408 == 0) goto LAB_00410cbb;
    FUN_0041b360();
    FUN_00408b70(*local_8);
    break;
  case 0x1c:
    ppuVar10 = (undefined **)FUN_0041b360();
    uVar12 = FUN_004163f0((uint *)*local_8,local_8[1]);
    *local_8 = uVar12;
    FUN_00408bb0((int)ppuVar10,6,*local_8,(undefined4 *)&stack0xffffffa4);
    break;
  case 0x1d:
    puVar14 = FUN_00419430(*local_8,*local_18);
    *local_8 = (uint)puVar14;
    break;
  case 0x1e:
    goto switchD_00410077_caseD_1e;
  case 0x1f:
    if (((int)local_c < 0) || (psVar8 = local_c, 1 < (int)local_c)) {
      psVar8 = (short *)0x0;
    }
    FUN_00408490((int *)local_8,(int)psVar8);
    break;
  case 0x20:
    if (((int)local_c < 0) || (psVar8 = local_c, 1 < (int)local_c)) {
      psVar8 = (short *)0x0;
    }
    FUN_004084f0((int *)local_8,(int)psVar8);
    break;
  case 0x21:
    if (DAT_004353d0 == 0) {
      FUN_00406d90((int *)local_8);
    }
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x22:
    uVar12 = FUN_0040cdf0(*local_8,(short *)local_8[1],local_8[2],(undefined4 *)&stack0xffffffa4);
    *local_8 = uVar12;
    break;
  case 0x23:
    puVar14 = FUN_00402950(*local_8);
    FUN_0040ef70((int *)puVar14);
    FUN_0041b470((byte *)s_ON_set_is_sa_tautology_0042ffb8);
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x24:
    uVar12 = local_8[1];
    puVar4 = FUN_004177d0(uVar12,local_8[2],(int)unaff_EBX);
    puVar21 = FUN_00417930(10,DAT_00435520,uVar12);
    FUN_00417a40((short *)*local_8);
    iVar3 = FUN_0041b360();
    puVar14 = FUN_00402950((int)puVar4);
    puVar14 = FUN_00403160(puVar14);
    *local_8 = (uint)puVar14;
    FUN_00408bb0(iVar3,1,*local_8,(undefined4 *)&stack0xffffffa4);
    iVar3 = FUN_0041b360();
    puVar14 = FUN_0040b8a0((short *)*local_8,(int)puVar4,0);
    *local_8 = (uint)puVar14;
    FUN_00408bb0(iVar3,4,*local_8,(undefined4 *)&stack0xffffffa4);
    iVar3 = FUN_0041b360();
    uVar12 = FUN_0040e9b0((int *)*local_8,(short *)puVar21);
    *local_8 = uVar12;
    FUN_00408bb0(iVar3,5,*local_8,(undefined4 *)&stack0xffffffa4);
    FUN_00417a40((short *)puVar4);
    ppuVar10 = (undefined **)FUN_004177d0(*local_8,local_8[2],(int)puVar4);
    iVar3 = FUN_0041b360();
    puVar4 = FUN_0040b8a0((short *)local_8[1],(int)ppuVar10,0);
    local_8[1] = (uint)puVar4;
    FUN_00408bb0(iVar3,4,local_8[1],(undefined4 *)&stack0xffffffa4);
    puVar4 = (uint *)FUN_0041b360();
    uVar12 = FUN_0040e9b0((int *)local_8[1],(short *)puVar21);
    local_8[1] = uVar12;
    FUN_00408bb0((int)puVar4,5,local_8[1],(undefined4 *)&stack0xffffffa4);
    FUN_00417a40((short *)ppuVar10);
    FUN_00417a40((short *)puVar21);
    break;
  case 0x25:
    FUN_0040a4c0((int)local_8);
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x26:
    puVar14 = FUN_00404630((short *)*local_8,(short *)*local_18);
    *local_8 = (uint)puVar14;
    break;
  case 0x28:
    do {
      FUN_0041b360();
      puVar21 = FUN_0040ac70((uint *)*local_8,local_8[1],(short *)local_8[2]);
      *local_8 = (uint)puVar21;
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70(*local_8);
      }
      if (DAT_004354c4 != (uint *)0x0) {
        FUN_00408c60((int *)&DAT_00431c98,local_8,local_10);
        FUN_0041f0ff((int *)&DAT_00431c98);
      }
      uVar12 = local_8[4];
      FUN_00406ff0(local_8);
      FUN_00405270();
      if (DAT_00435534 != (undefined **)0x0) {
        FUN_0041b8c0((int)DAT_00435534);
        DAT_00435534 = (undefined **)0x0;
      }
      iVar3 = FUN_00406a00(DAT_004330b0,1,1,uVar12,&local_8);
    } while (iVar3 != -1);
    FUN_0041ef48(0);
switchD_00410077_caseD_1e:
    puVar21 = (uint *)0x0;
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar14 = FUN_00402950(*local_8);
    puVar14 = FUN_004040f0(puVar14);
    *local_8 = (uint)puVar14;
    if (DAT_00435408 == 0) goto LAB_00410cbb;
    FUN_0041b360();
    FUN_00408b70(*local_8);
    break;
  case 0x29:
    puVar14 = FUN_00402a00(local_8[1],local_8[2]);
    puVar14 = FUN_00403160(puVar14);
    *local_8 = (uint)puVar14;
    break;
  case 0x2a:
    ppuVar10 = (undefined **)FUN_00419a60(*local_8,local_18[2]);
    puVar21 = (uint *)FUN_00419a60(*local_18,local_8[2]);
    psVar8 = (short *)*local_8;
    FUN_00417a40(psVar8);
    puVar14 = FUN_004177d0((int)ppuVar10,(int)puVar21,(int)psVar8);
    puVar14 = FUN_004044e0((short *)puVar14);
    *local_8 = (uint)puVar14;
    FUN_00417a40((short *)ppuVar10);
    FUN_00417a40((short *)puVar21);
    break;
  case 0x2b:
    ppuVar10 = (undefined **)0x0;
    if (0 < DAT_00435528) {
      do {
        uVar12 = FUN_00404720((short *)*local_8,(int)ppuVar10);
        ppuVar10 = (undefined **)((int)ppuVar10 + 1);
        *local_8 = uVar12;
      } while ((int)ppuVar10 < DAT_00435528);
    }
    break;
  case 0x2c:
    FUN_0040e080(local_8,DAT_004353d0,(int)unaff_EBX,in_stack_ffffffa4,in_stack_ffffffa8,
                 in_stack_ffffffac);
    DAT_004354c4 = (uint *)0x0;
  }
  if (DAT_00435408 != 0) {
    FUN_00411020();
  }
LAB_00410cbb:
  if ((DAT_004353d0 != 0) || (DAT_00435408 != 0)) {
    FUN_0041b360();
    puVar21 = local_40;
    FUN_00408b70(*local_8);
  }
  if (DAT_004354c4 != (uint *)0x0) {
    ppuVar10 = (undefined **)FUN_0041b360();
    FUN_00408c60((int *)DAT_00435368,local_8,local_10);
    FUN_00408bb0((int)ppuVar10,0xf,*local_8,(undefined4 *)&stack0xffffffa4);
    if (DAT_00435368 != (FILE *)0x0) {
      FUN_0041ea29(DAT_00435368);
    }
    FUN_0040aa50(3,(int)unaff_EBX);
    iVar3 = FUN_0040aa20();
    if (iVar3 == 0) {
      iVar3 = 5;
    }
    else {
      iVar3 = 6;
    }
    FUN_0040aa50(2,iVar3);
    FUN_0040aa10();
  }
  if (local_28 != (uint *)0x0) {
    FUN_00408c40((int *)s_cover_verification_failed_004300f4,(uint)unaff_EBX);
  }
  FUN_00406ff0(local_8);
  bVar23 = false;
  if (DAT_00435534 != (undefined **)0x0) {
    FUN_0041b8c0((int)DAT_00435534);
    bVar23 = (undefined *)0xfffffffb < &stack0xffffff9c;
    DAT_00435534 = (undefined **)0x0;
  }
  FUN_00405270();
  FUN_00417ac0();
  FUN_00412a40();
  uVar24 = FUN_0041ef48(0);
  iVar3 = ((int)uVar24 + -0x330040fb) - (uint)bVar23;
  cVar16 = (char)iVar3;
  *(char *)(extraout_ECX + 0x10040fc) = *(char *)(extraout_ECX + 0x10040fc) + cVar16 + '\x01';
  *(char *)(puVar4 + (int)puVar21 * 2 + -0x13c7ff0) =
       *(char *)(puVar4 + (int)puVar21 * 2 + -0x13c7ff0) + (char)extraout_ECX;
  *(char *)((int)puVar21 + -3) = *(char *)((int)puVar21 + -3) + cVar16 + '\x03';
  cVar16 = (char)((ulonglong)uVar24 >> 0x20);
  *(char *)(puVar4 + 0x7c0103f) = *(char *)(puVar4 + 0x7c0103f) + cVar16;
  *(byte *)(ppuVar10 + 0x9c0103f) = *(byte *)(ppuVar10 + 0x9c0103f) + (char)puVar4;
  pcVar11 = (char *)(iVar3 + 6);
  cVar18 = (char)((uint)puVar4 >> 8);
  cVar16 = cVar16 + cVar18;
  iVar7 = CONCAT31((int3)((ulonglong)uVar24 >> 0x28),cVar16);
  *pcVar11 = *pcVar11 + '\x01';
  *(char *)puVar4 = *(char *)puVar4 + (char)extraout_ECX;
  puVar14 = (uint *)(extraout_ECX | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4);
  uVar12 = (uint)pcVar11 | *puVar14;
  uVar15 = (uint)puVar14 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 |
           *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4;
  uVar12 = CONCAT31((int3)(uVar12 >> 8),(char)uVar12 + *(char *)puVar4) |
           *(uint *)((int)puVar4 + uVar15);
  uVar13 = uVar12 + 0xb080706;
  *puVar4 = *puVar4 | uVar15;
  iVar3 = CONCAT31((int3)(uVar15 >> 8),(byte)uVar15 | in_stack_007e0045);
  puVar14 = (uint *)(iVar3 + 1);
  pcVar11 = (char *)(iVar7 + 0x45004102);
  cVar17 = (char)((ulonglong)uVar24 >> 0x28);
  *pcVar11 = *pcVar11 + cVar17;
  *puVar14 = *puVar14 | uVar13;
  *puVar14 = *puVar14 | uVar13;
  *(byte *)puVar14 = *(byte *)puVar14 | (byte)uVar13;
  *(byte *)ppuVar10 = *(byte *)ppuVar10 + cVar16;
  *(char *)(puVar4 + 1) = *(char *)(puVar4 + 1) + cVar18;
  *(char *)((int)puVar21 + -0x3effbefb) = *(char *)((int)puVar21 + -0x3effbefb) + (char)puVar4;
  pbVar2 = (byte *)(iVar3 + 6);
  pcVar11 = (char *)(iVar7 + 0x45004104);
  *pcVar11 = *pcVar11 + cVar17;
  *pbVar2 = *pbVar2 | (char)uVar12 + 0x47U;
  return;
LAB_0040ff05:
  if (*(int *)(&PTR_DAT_0042fb0c)[(int)ppuVar20 * 3] == (&DAT_0042fb10)[(int)ppuVar20 * 3]) {
    DAT_004330b8 = 1;
  }
  goto LAB_0040ff23;
}



void __cdecl FUN_00410ee0(int param_1,int param_2,int param_3,int param_4,int *param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  char *pcVar4;
  undefined4 unaff_EDI;
  char *pcVar5;
  bool bVar6;
  undefined *in_stack_ffffffdc;
  char *local_14;
  uint local_10;
  undefined **local_8;
  
  if (param_1 < param_2) {
    bVar6 = true;
    local_14 = *(char **)(param_3 + param_1 * 4);
    iVar1 = 2;
    pcVar4 = local_14;
    pcVar5 = &DAT_00430118;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      local_8 = &PTR_DAT_00431c78;
      goto LAB_00410f01;
    }
    in_stack_ffffffdc = &DAT_0043011c;
    local_8 = (undefined **)FUN_0041ec37(local_14,&DAT_0043011c);
    if (local_8 != (undefined **)0x0) goto LAB_00410f01;
    FUN_0040aa50(4,0x11);
    in_stack_ffffffdc = (undefined *)0x1;
    iVar1 = FUN_0041ef48(1);
LAB_00410f7c:
    local_10 = *(uint *)(&DAT_0042f6e0 + iVar1);
    uVar2 = *(uint *)(&DAT_0042f6dc + iVar1);
  }
  else {
    local_8 = &PTR_DAT_00431c78;
    local_14 = s__stdin__00430110;
LAB_00410f01:
    iVar1 = param_4 * 0x14;
    if (*(int *)(&DAT_0042f6d4 + iVar1) != 8) goto LAB_00410f7c;
    local_10 = param_6 >> 1 & 1;
    uVar2 = param_6 >> 2 & 1;
  }
  DAT_004330c4 = FUN_0041b360();
  iVar1 = __setjmp3((undefined4 *)&DAT_00435320,0,in_stack_ffffffdc,unaff_EDI);
  if (iVar1 == 0) {
    iVar1 = FUN_00406a00((int *)local_8,local_10,uVar2,DAT_0042fba8,param_5);
    if (iVar1 != -1) goto LAB_00410ff6;
    FUN_0040aa50(4,0x12);
    FUN_0041ef48(1);
  }
  DAT_004330bc = 1;
LAB_00410ff6:
  puVar3 = FUN_0041a290(local_14);
  *(uint **)(*param_5 + 0xc) = puVar3;
  DAT_004330b0 = local_8;
  DAT_004354c0 = *(undefined4 *)(*param_5 + 0xc);
  return;
}



void FUN_00411020(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_004354e0;
  do {
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x435520);
  iVar2 = 0;
  do {
    if (*(int *)((int)&DAT_00435480 + iVar2) != 0) {
      FUN_004163a0(*(undefined4 *)((int)&DAT_004354e0 + iVar2));
      FUN_0041b470((byte *)s____s__2d_call_s__for__s___2ld__0_00430120);
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x40);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_004110a0(void)

{
  DAT_00435420 = s_READ_00430148;
  _DAT_0043545c = s_WRITE_00430154;
  _DAT_00435424 = s_COMPL_00430160;
  _DAT_00435438 = s_REDUCE_0043016c;
  _DAT_00435430 = s_EXPAND_00430178;
  _DAT_0043542c = s_ESSEN_00430184;
  _DAT_00435434 = s_IRRED_00430190;
  _DAT_00435444 = s_REDUCE_GASP_0043019c;
  _DAT_0043543c = s_EXPAND_GASP_004301a8;
  _DAT_00435440 = s_IRRED_GASP_004301b4;
  _DAT_00435450 = s_MV_REDUCE_004301c0;
  _DAT_00435454 = s_RAISE_IN_004301cc;
  _DAT_00435458 = s_VERIFY_004301d8;
  _DAT_00435448 = s_PRIMES_004301e4;
  _DAT_0043544c = s_MINCOV_004301f0;
  return;
}



void FUN_00411140(void)

{
  undefined **ppuVar1;
  char cVar2;
  uint uVar3;
  undefined **ppuVar4;
  int iVar5;
  char *pcVar6;
  
  FUN_0040aa50(2,0);
  iVar5 = 0x10;
  if (PTR_s_OPTIMIZE_0042f6d0 != (undefined *)0x0) {
    ppuVar4 = &PTR_s_OPTIMIZE_0042f6d0;
    do {
      uVar3 = 0xffffffff;
      pcVar6 = *ppuVar4;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      if ((int)(~uVar3 + iVar5) < 0x4d) {
        if (ppuVar4 != &PTR_s_OPTIMIZE_0042f6d0) {
          FUN_0040aa50(2,0);
        }
      }
      else {
        FUN_0040aa50(2,0);
        iVar5 = 0x10;
      }
      FUN_0040aa50(2,0);
      uVar3 = 0xffffffff;
      pcVar6 = *ppuVar4;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      ppuVar1 = ppuVar4 + 5;
      ppuVar4 = ppuVar4 + 5;
      iVar5 = iVar5 + ~uVar3 + 1;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  FUN_0040aa50(2,0);
  return;
}



void FUN_00411230(int *param_1,int *param_2)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined **ppuVar9;
  char *pcVar10;
  byte *pbVar11;
  char *pcVar12;
  bool bVar13;
  int *unaff_retaddr;
  int *piVar14;
  
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_00411140();
  DAT_0042e060 = 0;
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  DAT_0042e060 = 1;
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,0);
  FUN_0040aa50(2,6);
  piVar14 = (int *)0x1;
  FUN_0041ef48(1);
  *param_2 = 0;
  iVar8 = 1;
  piVar7 = param_1;
  if (1 < *unaff_retaddr + -1) {
    do {
      iVar6 = 4;
      bVar13 = true;
      pcVar10 = (char *)piVar7[1];
      pcVar12 = &DAT_00430784;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pcVar10 == *pcVar12;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      } while (bVar13);
      if (bVar13) {
        iVar6 = 0;
        if (PTR_s_OPTIMIZE_0042f6d0 == (undefined *)0x0) goto LAB_00411651;
        ppuVar9 = &PTR_s_OPTIMIZE_0042f6d0;
        pbVar3 = (byte *)param_1[iVar8 + 1];
        pbVar11 = PTR_s_OPTIMIZE_0042f6d0;
        goto LAB_004115f3;
      }
      iVar8 = iVar8 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar8 < *unaff_retaddr + -1);
  }
  goto LAB_00411594;
  while( true ) {
    if (iVar5 == 0) {
      *param_2 = iVar6;
      FUN_00411860(unaff_retaddr,(int)param_1,iVar8 + 1);
      FUN_00411860(unaff_retaddr,(int)param_1,iVar8);
      break;
    }
    pbVar11 = ppuVar9[5];
    ppuVar9 = ppuVar9 + 5;
    iVar6 = iVar6 + 1;
    pbVar3 = (byte *)param_1[iVar8 + 1];
    if (pbVar11 == (byte *)0x0) break;
LAB_004115f3:
    bVar1 = *pbVar3;
    bVar13 = bVar1 < *pbVar11;
    if (bVar1 == *pbVar11) {
      if (bVar1 != 0) {
        bVar1 = pbVar3[1];
        bVar13 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_00411617;
        pbVar3 = pbVar3 + 2;
        pbVar11 = pbVar11 + 2;
        if (bVar1 != 0) goto LAB_004115f3;
      }
      iVar5 = 0;
    }
    else {
LAB_00411617:
      iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
    }
  }
LAB_00411651:
  if ((&PTR_s_OPTIMIZE_0042f6d0)[iVar6 * 5] == (undefined *)0x0) {
    FUN_0040aa50(4,0x14);
    FUN_0041ef48(1);
LAB_0041167f:
    iVar6 = 0;
    if (PTR_DAT_0042ed08 != (undefined *)0x0) {
      ppuVar9 = &PTR_DAT_0042ed08;
      puVar2 = PTR_DAT_0042ed08;
      do {
        pbVar3 = puVar2 + 1;
        pbVar11 = (byte *)unaff_retaddr[iVar8 + 1];
        do {
          bVar1 = *pbVar3;
          bVar13 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_004116c6:
            iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            goto LAB_004116cb;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar13 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_004116c6;
          pbVar3 = pbVar3 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004116cb:
        if (iVar5 == 0) {
          *param_2 = (&DAT_0042ed0c)[iVar6 * 2];
          piVar7 = piVar14;
          FUN_00411860(piVar14,(int)unaff_retaddr,iVar8 + 1);
          FUN_00411860(piVar14,(int)unaff_retaddr,iVar8);
          piVar14 = piVar7;
          break;
        }
        puVar2 = ppuVar9[2];
        ppuVar9 = ppuVar9 + 2;
        iVar6 = iVar6 + 1;
      } while (puVar2 != (undefined *)0x0);
    }
    piVar7 = piVar14;
    if ((&PTR_DAT_0042ed08)[iVar6 * 2] == (undefined *)0x0) {
      FUN_0040aa50(4,0x15);
      FUN_0041ef48(1);
      piVar7 = piVar14;
    }
    goto LAB_00411732;
  }
LAB_00411594:
  iVar8 = 1;
  piVar7 = unaff_retaddr;
  if (1 < *unaff_retaddr + -1) {
    do {
      param_1 = param_1 + 1;
      iVar6 = 5;
      bVar13 = true;
      pcVar10 = (char *)*param_1;
      pcVar12 = &DAT_00430788;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pcVar10 == *pcVar12;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      } while (bVar13);
      if (bVar13) goto LAB_0041167f;
      iVar8 = iVar8 + 1;
      piVar7 = piVar14;
    } while (iVar8 < *unaff_retaddr + -1);
  }
LAB_00411732:
  iVar8 = 1;
  if (1 < *piVar7) {
    param_1 = unaff_retaddr + 1;
    do {
      if ((*(char *)*param_1 == '-') && (iVar6 = 0, PTR_DAT_0042fb08 != (undefined *)0x0)) {
        pbVar4 = (byte *)((char *)*param_1 + 1);
        ppuVar9 = &PTR_DAT_0042fb08;
        pbVar3 = pbVar4;
        pbVar11 = PTR_DAT_0042fb08;
LAB_00411775:
        do {
          bVar1 = *pbVar3;
          bVar13 = bVar1 < *pbVar11;
          if (bVar1 == *pbVar11) {
            if (bVar1 != 0) {
              bVar1 = pbVar3[1];
              bVar13 = bVar1 < pbVar11[1];
              if (bVar1 != pbVar11[1]) goto LAB_00411799;
              pbVar3 = pbVar3 + 2;
              pbVar11 = pbVar11 + 2;
              if (bVar1 != 0) goto LAB_00411775;
            }
            iVar5 = 0;
          }
          else {
LAB_00411799:
            iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          }
          if (iVar5 == 0) {
            FUN_00411860(piVar7,(int)unaff_retaddr,iVar8);
            *(undefined4 *)(&PTR_DAT_0042fb0c)[iVar6 * 3] = (&DAT_0042fb10)[iVar6 * 3];
            break;
          }
          pbVar11 = ppuVar9[3];
          ppuVar9 = ppuVar9 + 3;
          iVar6 = iVar6 + 1;
          pbVar3 = pbVar4;
        } while (pbVar11 != (byte *)0x0);
      }
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 < *piVar7);
  }
  iVar8 = FUN_00411890(piVar7,unaff_retaddr,&DAT_00430790);
  if (iVar8 != 0) {
    DAT_0042fba8 = 7;
  }
  iVar8 = FUN_00411890(piVar7,unaff_retaddr,&DAT_00430798);
  if (iVar8 != 0) {
    DAT_0042fba8 = 5;
  }
  iVar8 = FUN_00411890(piVar7,unaff_retaddr,&DAT_0043079c);
  if (iVar8 != 0) {
    DAT_0042fba8 = 1;
  }
  return;
}



void __cdecl FUN_00411550(int *param_1,int *param_2,int *param_3)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined **ppuVar9;
  char *pcVar10;
  byte *pbVar11;
  char *pcVar12;
  bool bVar13;
  int *unaff_retaddr;
  
  *param_3 = 0;
  iVar8 = 1;
  piVar7 = param_2;
  if (1 < *param_1 + -1) {
    do {
      iVar6 = 4;
      bVar13 = true;
      pcVar10 = (char *)piVar7[1];
      pcVar12 = &DAT_00430784;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pcVar10 == *pcVar12;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      } while (bVar13);
      if (bVar13) {
        iVar6 = 0;
        if (PTR_s_OPTIMIZE_0042f6d0 == (undefined *)0x0) goto LAB_00411651;
        ppuVar9 = &PTR_s_OPTIMIZE_0042f6d0;
        pbVar3 = (byte *)param_2[iVar8 + 1];
        pbVar11 = PTR_s_OPTIMIZE_0042f6d0;
        goto LAB_004115f3;
      }
      iVar8 = iVar8 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar8 < *param_1 + -1);
  }
  goto LAB_00411594;
  while( true ) {
    if (iVar5 == 0) {
      *param_3 = iVar6;
      FUN_00411860(param_1,(int)param_2,iVar8 + 1);
      FUN_00411860(param_1,(int)param_2,iVar8);
      break;
    }
    pbVar11 = ppuVar9[5];
    ppuVar9 = ppuVar9 + 5;
    iVar6 = iVar6 + 1;
    pbVar3 = (byte *)param_2[iVar8 + 1];
    if (pbVar11 == (byte *)0x0) break;
LAB_004115f3:
    bVar1 = *pbVar3;
    bVar13 = bVar1 < *pbVar11;
    if (bVar1 == *pbVar11) {
      if (bVar1 != 0) {
        bVar1 = pbVar3[1];
        bVar13 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_00411617;
        pbVar3 = pbVar3 + 2;
        pbVar11 = pbVar11 + 2;
        if (bVar1 != 0) goto LAB_004115f3;
      }
      iVar5 = 0;
    }
    else {
LAB_00411617:
      iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
    }
  }
LAB_00411651:
  if ((&PTR_s_OPTIMIZE_0042f6d0)[iVar6 * 5] == (undefined *)0x0) {
    FUN_0040aa50(4,0x14);
    FUN_0041ef48(1);
LAB_0041167f:
    iVar6 = 0;
    if (PTR_DAT_0042ed08 != (undefined *)0x0) {
      ppuVar9 = &PTR_DAT_0042ed08;
      puVar2 = PTR_DAT_0042ed08;
      do {
        pbVar3 = puVar2 + 1;
        pbVar11 = (byte *)param_1[iVar8 + 1];
        do {
          bVar1 = *pbVar3;
          bVar13 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_004116c6:
            iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            goto LAB_004116cb;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar13 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_004116c6;
          pbVar3 = pbVar3 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004116cb:
        if (iVar5 == 0) {
          *param_3 = (&DAT_0042ed0c)[iVar6 * 2];
          FUN_00411860(unaff_retaddr,(int)param_1,iVar8 + 1);
          FUN_00411860(unaff_retaddr,(int)param_1,iVar8);
          break;
        }
        puVar2 = ppuVar9[2];
        ppuVar9 = ppuVar9 + 2;
        iVar6 = iVar6 + 1;
      } while (puVar2 != (undefined *)0x0);
    }
    piVar7 = unaff_retaddr;
    if ((&PTR_DAT_0042ed08)[iVar6 * 2] == (undefined *)0x0) {
      FUN_0040aa50(4,0x15);
      FUN_0041ef48(1);
    }
    goto LAB_00411732;
  }
LAB_00411594:
  iVar8 = 1;
  piVar7 = param_1;
  if (1 < *param_1 + -1) {
    do {
      param_2 = param_2 + 1;
      iVar6 = 5;
      bVar13 = true;
      pcVar10 = (char *)*param_2;
      pcVar12 = &DAT_00430788;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pcVar10 == *pcVar12;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      } while (bVar13);
      if (bVar13) goto LAB_0041167f;
      iVar8 = iVar8 + 1;
      piVar7 = unaff_retaddr;
    } while (iVar8 < *param_1 + -1);
  }
LAB_00411732:
  iVar8 = 1;
  if (1 < *piVar7) {
    param_2 = param_1 + 1;
    do {
      if ((*(char *)*param_2 == '-') && (iVar6 = 0, PTR_DAT_0042fb08 != (undefined *)0x0)) {
        pbVar4 = (byte *)((char *)*param_2 + 1);
        ppuVar9 = &PTR_DAT_0042fb08;
        pbVar3 = pbVar4;
        pbVar11 = PTR_DAT_0042fb08;
LAB_00411775:
        do {
          bVar1 = *pbVar3;
          bVar13 = bVar1 < *pbVar11;
          if (bVar1 == *pbVar11) {
            if (bVar1 != 0) {
              bVar1 = pbVar3[1];
              bVar13 = bVar1 < pbVar11[1];
              if (bVar1 != pbVar11[1]) goto LAB_00411799;
              pbVar3 = pbVar3 + 2;
              pbVar11 = pbVar11 + 2;
              if (bVar1 != 0) goto LAB_00411775;
            }
            iVar5 = 0;
          }
          else {
LAB_00411799:
            iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          }
          if (iVar5 == 0) {
            FUN_00411860(piVar7,(int)param_1,iVar8);
            *(undefined4 *)(&PTR_DAT_0042fb0c)[iVar6 * 3] = (&DAT_0042fb10)[iVar6 * 3];
            break;
          }
          pbVar11 = ppuVar9[3];
          ppuVar9 = ppuVar9 + 3;
          iVar6 = iVar6 + 1;
          pbVar3 = pbVar4;
        } while (pbVar11 != (byte *)0x0);
      }
      iVar8 = iVar8 + 1;
      param_2 = param_2 + 1;
    } while (iVar8 < *piVar7);
  }
  iVar8 = FUN_00411890(piVar7,param_1,&DAT_00430790);
  if (iVar8 != 0) {
    DAT_0042fba8 = 7;
  }
  iVar8 = FUN_00411890(piVar7,param_1,&DAT_00430798);
  if (iVar8 != 0) {
    DAT_0042fba8 = 5;
  }
  iVar8 = FUN_00411890(piVar7,param_1,&DAT_0043079c);
  if (iVar8 != 0) {
    DAT_0042fba8 = 1;
  }
  return;
}



void __cdecl FUN_00411860(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (param_3 < iVar1 + -1) {
    puVar2 = (undefined4 *)(param_2 + param_3 * 4);
    do {
      param_3 = param_3 + 1;
      *puVar2 = puVar2[1];
      puVar2 = puVar2 + 1;
    } while (param_3 < *param_1);
  }
  return;
}



undefined4 __cdecl FUN_00411890(int *param_1,undefined4 *param_2,byte *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = 1;
  puVar2 = param_2;
  if (1 < *param_1) {
    do {
      pbVar3 = (byte *)puVar2[1];
      pbVar5 = param_3;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_004118d5:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_004118da;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_004118d5;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_004118da:
      if (iVar4 == 0) {
        FUN_00411860(param_1,(int)param_2,iVar6);
        return 1;
      }
      iVar6 = iVar6 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar6 < *param_1);
  }
  return 0;
}



uint * __cdecl FUN_00411910(int *param_1,undefined4 *param_2,byte *param_3,uint *param_4)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint *puVar10;
  char *pcVar11;
  char *pcVar12;
  uint *puVar13;
  bool bVar14;
  
  iVar8 = 1;
  puVar3 = param_2;
  if (1 < *param_1) {
    do {
      pbVar4 = (byte *)puVar3[1];
      pbVar9 = param_3;
      do {
        bVar2 = *pbVar4;
        bVar14 = bVar2 < *pbVar9;
        if (bVar2 != *pbVar9) {
LAB_00411959:
          iVar5 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_0041195e;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar14 = bVar2 < pbVar9[1];
        if (bVar2 != pbVar9[1]) goto LAB_00411959;
        pbVar4 = pbVar4 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_0041195e:
      if (iVar5 == 0) {
        iVar5 = iVar8 + 1;
        if ((char *)param_2[iVar5] == (char *)0x0) goto LAB_004119d8;
        uVar6 = 0xffffffff;
        pcVar11 = (char *)param_2[iVar5];
        goto code_r0x0041198d;
      }
      iVar8 = iVar8 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar8 < *param_1);
  }
  return (uint *)0x0;
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    if (cVar1 == '\0') break;
code_r0x0041198d:
    if (uVar6 == 0) break;
  }
  param_4 = FUN_0040a880(1,~uVar6);
  uVar6 = 0xffffffff;
  pcVar11 = (char *)param_2[iVar5];
  do {
    pcVar12 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  puVar10 = (uint *)(pcVar12 + -uVar6);
  puVar13 = param_4;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar13 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar13 = puVar13 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)puVar13 = *(char *)puVar10;
    puVar10 = (uint *)((int)puVar10 + 1);
    puVar13 = (uint *)((int)puVar13 + 1);
  }
  FUN_00411860(param_1,(int)param_2,iVar5);
LAB_004119d8:
  FUN_00411860(param_1,(int)param_2,iVar8);
  return param_4;
}



undefined4 __cdecl FUN_00411a00(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = 1;
  piVar4 = DAT_00435534;
  iVar5 = DAT_00435524;
  if (0 < DAT_00435524) {
    do {
      iVar2 = iVar2 * *piVar4;
      iVar5 = iVar5 + -1;
      piVar4 = piVar4 + 1;
    } while (iVar5 != 0);
    if (0x20 < iVar2) {
      iVar5 = (iVar2 + -1 >> 5) + 2;
      goto LAB_00411a33;
    }
  }
  iVar5 = 2;
LAB_00411a33:
  puVar3 = FUN_0040a880(1,iVar5 * 4);
  DAT_00433208 = FUN_00417140((int *)puVar3,iVar2);
  DAT_0043320c = *(uint *)(param_1 + 0x18);
  uVar1 = DAT_0043320c + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; DAT_0043320c < uVar1; DAT_0043320c = DAT_0043320c + *(int *)(param_1 + 4) * 4) {
    FUN_00411aa0(DAT_00435524 + -1,0);
  }
  return DAT_00433208;
}



void __cdecl FUN_00411aa0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(DAT_00435530 + param_1 * 4);
  iVar3 = *(int *)(DAT_00435534 + param_1 * 4) * param_2;
  for (iVar4 = *(int *)(DAT_0043552c + param_1 * 4); iVar4 <= iVar2; iVar4 = iVar4 + 1) {
    if ((*(uint *)(DAT_0043320c + 4 + (iVar4 >> 5) * 4) & 1 << ((byte)iVar4 & 0x1f)) != 0) {
      if (param_1 == 0) {
        puVar1 = (uint *)(DAT_00433208 + 4 + (iVar3 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar3 & 0x1f);
      }
      else {
        FUN_00411aa0(param_1 + -1,iVar3);
      }
    }
    iVar3 = iVar3 + 1;
  }
  return;
}



void __cdecl FUN_00411b30(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  bool bVar11;
  int local_1c;
  uint local_18;
  int local_10;
  
  iVar2 = FUN_00411a00(param_1);
  iVar7 = 1 << ((byte)DAT_00435528 & 0x1f);
  iVar1 = *(int *)(DAT_00435534 + -4 + DAT_00435524 * 4);
  local_10 = 0;
  if (0 < iVar1) {
    local_1c = 0;
    do {
      FUN_0041b470((byte *)s_Output_space____d_00430ba0);
      for (iVar5 = 0; iVar5 <= (int)(DAT_00435528 - 8U & ((int)(DAT_00435528 - 8U) < 1) - 1);
          iVar5 = iVar5 + 1) {
        local_18 = 0;
        piVar8 = &DAT_004307e0;
        do {
          bVar11 = false;
          piVar9 = piVar8 + -0x10;
          uVar6 = 1;
          do {
            iVar3 = *piVar9 + iVar5 * 0x100;
            if (iVar3 < iVar7) {
              iVar3 = iVar3 + local_1c;
              FUN_00420314((-((1 << ((byte)iVar3 & 0x1f) & *(uint *)(iVar2 + 4 + (iVar3 >> 5) * 4))
                             != 0) & 3U) + 0x2e);
              bVar11 = true;
            }
            uVar4 = uVar6 & 0x80000003;
            bVar10 = uVar4 == 0;
            if ((int)uVar4 < 0) {
              bVar10 = (uVar4 - 1 | 0xfffffffc) == 0xffffffff;
            }
            if (bVar10) {
              FUN_00420314(' ');
            }
            uVar4 = uVar6 & 0x80000007;
            bVar10 = uVar4 == 0;
            if ((int)uVar4 < 0) {
              bVar10 = (uVar4 - 1 | 0xfffffff8) == 0xffffffff;
            }
            if (bVar10) {
              FUN_0041b470(&DAT_00430bb8);
            }
            piVar9 = piVar9 + 1;
            bVar10 = (int)uVar6 < 0x10;
            uVar6 = uVar6 + 1;
          } while (bVar10);
          if (bVar11) {
            FUN_00420314('\n');
          }
          local_18 = local_18 + 1;
          uVar6 = local_18 & 0x80000003;
          bVar11 = uVar6 == 0;
          if ((int)uVar6 < 0) {
            bVar11 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
          }
          if (bVar11) {
            if ((piVar8 != (int *)s_Output_space____d_00430ba0) && (iVar7 <= *piVar8)) break;
            FUN_00420314('\n');
          }
          uVar6 = local_18 & 0x80000007;
          bVar11 = uVar6 == 0;
          if ((int)uVar6 < 0) {
            bVar11 = (uVar6 - 1 | 0xfffffff8) == 0xffffffff;
          }
          if (bVar11) {
            FUN_00420314('\n');
          }
          piVar8 = piVar8 + 0x10;
        } while ((int)piVar8 < 0x430be0);
      }
      local_10 = local_10 + 1;
      local_1c = local_1c + iVar7;
    } while (local_10 < iVar1);
  }
  if (iVar2 != 0) {
    FUN_0041b8c0(iVar2);
  }
  return;
}



void FUN_00411d20(void)

{
  int iVar1;
  uint *puVar2;
  
  DAT_004330c0 = DAT_004330c0 + 1;
  if (DAT_004330c0 % 100 == 0) {
    DAT_004330c0 = 0;
    iVar1 = FUN_0041b360();
    if (DAT_0042fbb0 < iVar1 - DAT_004330c4) {
      FUN_0040f8b0(2);
    }
  }
  puVar2 = FUN_0040a880(1,0x2c);
  *puVar2 = 0;
  puVar2[2] = 0;
  puVar2[9] = 0;
  puVar2[6] = 0;
  puVar2[3] = 0;
  puVar2[1] = 0;
  puVar2[5] = 0;
  puVar2[4] = 0;
  puVar2[8] = 0;
  puVar2[7] = 0;
  puVar2[10] = 0;
  return;
}



void __cdecl FUN_00411db0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_004330c0 = DAT_004330c0 + 1;
  if (DAT_004330c0 % 100 == 0) {
    DAT_004330c0 = 0;
    iVar2 = FUN_0041b360();
    if (DAT_0042fbb0 < iVar2 - DAT_004330c4) {
      FUN_0040f8b0(2);
    }
  }
  iVar2 = param_2[4];
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x14);
    FUN_00416c00(iVar2);
    iVar2 = iVar1;
  }
  iVar2 = param_2[7];
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x14);
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    FUN_00402d50(iVar2);
    iVar2 = iVar1;
  }
  if (*param_2 != 0) {
    FUN_0041b8c0(*param_2);
    *param_2 = 0;
  }
  if (param_2[2] != 0) {
    FUN_0041b8c0(param_2[2]);
    param_2[2] = 0;
  }
  if (param_2 != (int *)0x0) {
    FUN_0041b8c0((int)param_2);
  }
  return;
}



int * __cdecl FUN_00411e70(int param_1)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  
  piVar3 = (int *)FUN_00411d20();
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    FUN_00411ed0(piVar3,**(int **)(param_1 + 0x14),**(int **)(param_1 + 0x20));
    for (iVar1 = *(int *)(param_1 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
      for (puVar2 = *(uint **)(iVar1 + 0xc); puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[4]) {
        FUN_00411f90(piVar3,*puVar2,puVar2[1]);
      }
    }
  }
  return piVar3;
}



void __cdecl FUN_00411ed0(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[1] <= param_2) {
    iVar2 = param_1[1] * 2;
    iVar3 = param_2 + 1;
    if (param_2 + 1 < iVar2) {
      iVar3 = iVar2;
    }
    if ((uint *)*param_1 == (uint *)0x0) {
      puVar1 = FUN_0040a880(1,iVar3 * 4);
    }
    else {
      puVar1 = (uint *)FUN_0040a8f0((uint *)*param_1,iVar3 * 4);
    }
    *param_1 = (int)puVar1;
    iVar2 = param_1[1];
    while (iVar2 < iVar3) {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*param_1 + -4 + iVar2 * 4) = 0;
    }
    param_1[1] = iVar3;
  }
  if (param_1[3] <= param_3) {
    iVar2 = param_1[3] * 2;
    iVar3 = param_3 + 1;
    if (param_3 + 1 < iVar2) {
      iVar3 = iVar2;
    }
    if ((uint *)param_1[2] == (uint *)0x0) {
      puVar1 = FUN_0040a880(1,iVar3 * 4);
    }
    else {
      puVar1 = (uint *)FUN_0040a8f0((uint *)param_1[2],iVar3 * 4);
    }
    param_1[2] = (int)puVar1;
    iVar2 = param_1[3];
    while (iVar2 < iVar3) {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(param_1[2] + -4 + iVar2 * 4) = 0;
    }
    param_1[3] = iVar3;
  }
  return;
}



uint * __cdecl FUN_00411f90(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  
  iVar2 = DAT_004330c0 + 1;
  DAT_004330c0 = iVar2 % 100;
  if ((DAT_004330c0 == 0) &&
     (iVar3 = FUN_0041b360(), iVar2 = DAT_004330c0, DAT_0042fbb0 < iVar3 - DAT_004330c4)) {
    FUN_0040f8b0(2);
    iVar2 = DAT_004330c0;
  }
  DAT_004330c0 = iVar2;
  if ((param_1[1] <= (int)param_2) || (param_1[3] <= (int)param_3)) {
    FUN_00411ed0(param_1,param_2,param_3);
  }
  puVar7 = *(uint **)(*param_1 + param_2 * 4);
  if (puVar7 == (uint *)0x0) {
    uVar4 = FUN_00416b90();
    *(undefined4 *)(*param_1 + param_2 * 4) = uVar4;
    puVar5 = *(uint **)(*param_1 + param_2 * 4);
    *puVar5 = param_2;
    puVar7 = puVar5;
    if ((int *)param_1[5] == (int *)0x0) {
      *puVar5 = param_2;
      param_1[4] = (int)puVar5;
      param_1[5] = (int)puVar5;
      puVar5[5] = 0;
      puVar5[6] = 0;
      param_1[6] = param_1[6] + 1;
    }
    else if (*(int *)param_1[5] < (int)param_2) {
      *puVar5 = param_2;
      *(uint **)(param_1[5] + 0x14) = puVar5;
      puVar5[6] = param_1[5];
      param_1[5] = (int)puVar5;
      puVar5[5] = 0;
      param_1[6] = param_1[6] + 1;
    }
    else {
      puVar7 = (uint *)param_1[4];
      if ((int)param_2 < (int)*puVar7) {
        *puVar5 = param_2;
        *(uint **)(param_1[4] + 0x18) = puVar5;
        puVar5[5] = param_1[4];
        param_1[4] = (int)puVar5;
        puVar5[6] = 0;
        param_1[6] = param_1[6] + 1;
        puVar7 = puVar5;
      }
      else {
        uVar1 = *puVar7;
        iVar2 = uVar1 - param_2;
        if ((int)uVar1 < (int)param_2) {
          do {
            puVar7 = (uint *)puVar7[5];
            uVar1 = *puVar7;
          } while ((int)uVar1 < (int)param_2);
          iVar2 = uVar1 - param_2;
        }
        if (uVar1 != param_2 && SBORROW4(uVar1,param_2) == iVar2 < 0) {
          *puVar5 = param_2;
          uVar1 = puVar7[6];
          *(uint **)(*(int *)(uVar1 + 0x14) + 0x18) = puVar5;
          puVar5[5] = *(uint *)(uVar1 + 0x14);
          *(uint **)(uVar1 + 0x14) = puVar5;
          puVar5[6] = uVar1;
          param_1[6] = param_1[6] + 1;
          puVar7 = puVar5;
        }
      }
    }
  }
  puVar5 = *(uint **)(param_1[2] + param_3 * 4);
  if (puVar5 == (uint *)0x0) {
    uVar4 = FUN_00402ce0();
    *(undefined4 *)(param_1[2] + param_3 * 4) = uVar4;
    puVar8 = *(uint **)(param_1[2] + param_3 * 4);
    *puVar8 = param_3;
    puVar5 = puVar8;
    if ((int *)param_1[8] == (int *)0x0) {
      *puVar8 = param_3;
      param_1[7] = (int)puVar8;
      param_1[8] = (int)puVar8;
      puVar8[5] = 0;
      puVar8[6] = 0;
      param_1[9] = param_1[9] + 1;
    }
    else if (*(int *)param_1[8] < (int)param_3) {
      *puVar8 = param_3;
      *(uint **)(param_1[8] + 0x14) = puVar8;
      puVar8[6] = param_1[8];
      param_1[8] = (int)puVar8;
      puVar8[5] = 0;
      param_1[9] = param_1[9] + 1;
    }
    else {
      puVar5 = (uint *)param_1[7];
      if ((int)param_3 < (int)*puVar5) {
        *puVar8 = param_3;
        *(uint **)(param_1[7] + 0x18) = puVar8;
        puVar8[5] = param_1[7];
        param_1[7] = (int)puVar8;
        puVar8[6] = 0;
        param_1[9] = param_1[9] + 1;
        puVar5 = puVar8;
      }
      else {
        uVar1 = *puVar5;
        iVar2 = uVar1 - param_3;
        if ((int)uVar1 < (int)param_3) {
          do {
            puVar5 = (uint *)puVar5[5];
            uVar1 = *puVar5;
          } while ((int)uVar1 < (int)param_3);
          iVar2 = uVar1 - param_3;
        }
        if (uVar1 != param_3 && SBORROW4(uVar1,param_3) == iVar2 < 0) {
          *puVar8 = param_3;
          uVar1 = puVar5[6];
          *(uint **)(*(int *)(uVar1 + 0x14) + 0x18) = puVar8;
          puVar8[5] = *(uint *)(uVar1 + 0x14);
          *(uint **)(uVar1 + 0x14) = puVar8;
          puVar8[6] = uVar1;
          param_1[9] = param_1[9] + 1;
          puVar5 = puVar8;
        }
      }
    }
  }
  puVar6 = FUN_0040a880(1,0x1c);
  puVar6[6] = 0;
  puVar8 = puVar6;
  if (puVar7[4] == 0) {
    puVar6[1] = param_3;
    puVar7[3] = (uint)puVar6;
    puVar7[4] = (uint)puVar6;
    puVar6[4] = 0;
    puVar6[5] = 0;
    puVar7[1] = puVar7[1] + 1;
  }
  else if (*(int *)(puVar7[4] + 4) < (int)param_3) {
    puVar6[1] = param_3;
    *(uint **)(puVar7[4] + 0x10) = puVar6;
    puVar6[5] = puVar7[4];
    puVar7[4] = (uint)puVar6;
    puVar6[4] = 0;
    puVar7[1] = puVar7[1] + 1;
  }
  else {
    puVar8 = (uint *)puVar7[3];
    uVar1 = puVar8[1];
    if ((int)param_3 < (int)uVar1) {
      puVar6[1] = param_3;
      *(uint **)(puVar7[3] + 0x14) = puVar6;
      puVar6[4] = puVar7[3];
      puVar7[3] = (uint)puVar6;
      puVar6[5] = 0;
      puVar7[1] = puVar7[1] + 1;
      puVar8 = puVar6;
    }
    else {
      while ((int)uVar1 < (int)param_3) {
        puVar8 = (uint *)puVar8[4];
        uVar1 = puVar8[1];
      }
      if ((int)param_3 < (int)puVar8[1]) {
        puVar6[1] = param_3;
        uVar1 = puVar8[5];
        *(uint **)(*(int *)(uVar1 + 0x10) + 0x14) = puVar6;
        puVar6[4] = *(uint *)(uVar1 + 0x10);
        *(uint **)(uVar1 + 0x10) = puVar6;
        puVar6[5] = uVar1;
        puVar7[1] = puVar7[1] + 1;
        puVar8 = puVar6;
      }
      else if (puVar8 != puVar6) {
        if (puVar6 == (uint *)0x0) {
          return puVar8;
        }
        FUN_0041b8c0((int)puVar6);
        return puVar8;
      }
    }
  }
  if ((int *)puVar5[4] == (int *)0x0) {
    *puVar8 = param_2;
    puVar5[3] = (uint)puVar8;
    puVar5[4] = (uint)puVar8;
    puVar8[2] = 0;
    puVar8[3] = 0;
    puVar5[1] = puVar5[1] + 1;
    return puVar8;
  }
  if (*(int *)puVar5[4] < (int)param_2) {
    *puVar8 = param_2;
    *(uint **)(puVar5[4] + 8) = puVar8;
    puVar8[3] = puVar5[4];
    puVar5[4] = (uint)puVar8;
    puVar8[2] = 0;
    puVar5[1] = puVar5[1] + 1;
    return puVar8;
  }
  puVar7 = (uint *)puVar5[3];
  if ((int)*puVar7 <= (int)param_2) {
    uVar1 = *puVar7;
    iVar2 = uVar1 - param_2;
    if ((int)uVar1 < (int)param_2) {
      do {
        puVar7 = (uint *)puVar7[2];
        uVar1 = *puVar7;
      } while ((int)uVar1 < (int)param_2);
      iVar2 = uVar1 - param_2;
    }
    if (uVar1 == param_2 || SBORROW4(uVar1,param_2) != iVar2 < 0) {
      return puVar7;
    }
    *puVar8 = param_2;
    uVar1 = puVar7[3];
    *(uint **)(*(int *)(uVar1 + 8) + 0xc) = puVar8;
    puVar8[2] = *(uint *)(uVar1 + 8);
    *(uint **)(uVar1 + 8) = puVar8;
    puVar8[3] = uVar1;
    puVar5[1] = puVar5[1] + 1;
    return puVar8;
  }
  *puVar8 = param_2;
  *(uint **)(puVar5[3] + 0xc) = puVar8;
  puVar8[2] = puVar5[3];
  puVar5[3] = (uint)puVar8;
  puVar8[3] = 0;
  puVar5[1] = puVar5[1] + 1;
  return puVar8;
}



void __cdecl FUN_00412460(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (((-1 < param_2) && (param_2 < param_1[1])) &&
     (iVar1 = *(int *)(*param_1 + param_2 * 4), iVar1 != 0)) {
    iVar4 = *(int *)(iVar1 + 0xc);
    while (iVar4 != 0) {
      iVar2 = *(int *)(iVar4 + 4);
      iVar3 = *(int *)(iVar4 + 0x10);
      if ((iVar2 < 0) || (param_1[3] <= iVar2)) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = *(int **)(param_1[2] + iVar2 * 4);
      }
      FUN_004030e0((int)piVar5,iVar4);
      iVar4 = iVar3;
      if (piVar5[3] == 0) {
        FUN_00412520(param_1,*piVar5);
      }
    }
    *(undefined4 *)(*param_1 + param_2 * 4) = 0;
    if (*(int *)(iVar1 + 0x18) == 0) {
      param_1[4] = *(int *)(iVar1 + 0x14);
    }
    else {
      *(int *)(*(int *)(iVar1 + 0x18) + 0x14) = *(int *)(iVar1 + 0x14);
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      param_1[5] = *(int *)(iVar1 + 0x18);
    }
    else {
      *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    }
    param_1[6] = param_1[6] + -1;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_00416c00(iVar1);
  }
  return;
}



void __cdecl FUN_00412520(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if (((-1 < param_2) && (param_2 < param_1[3])) &&
     (iVar1 = *(int *)(param_1[2] + param_2 * 4), iVar1 != 0)) {
    piVar4 = *(int **)(iVar1 + 0xc);
    while (piVar4 != (int *)0x0) {
      iVar2 = *piVar4;
      piVar3 = (int *)piVar4[2];
      if ((iVar2 < 0) || (param_1[1] <= iVar2)) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = *(int **)(*param_1 + iVar2 * 4);
      }
      FUN_00416f90((int)piVar5,(int)piVar4);
      piVar4 = piVar3;
      if (piVar5[3] == 0) {
        FUN_00412460(param_1,*piVar5);
      }
    }
    *(undefined4 *)(param_1[2] + param_2 * 4) = 0;
    if (*(int *)(iVar1 + 0x18) == 0) {
      param_1[7] = *(int *)(iVar1 + 0x14);
    }
    else {
      *(int *)(*(int *)(iVar1 + 0x18) + 0x14) = *(int *)(iVar1 + 0x14);
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      param_1[8] = *(int *)(iVar1 + 0x18);
    }
    else {
      *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    }
    param_1[9] = param_1[9] + -1;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_00402d50(iVar1);
  }
  return;
}



void __cdecl FUN_00412830(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = *(int *)(param_2 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
      FUN_0041b430(param_1,(byte *)s__d__d_00430bd4);
    }
  }
  return;
}



void FUN_00412a40(void)

{
  return;
}



int __cdecl FUN_00412a50(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  undefined4 local_4;
  
  if (0 < *(int *)(param_1 + 0x18)) {
    local_c = FUN_0041b360();
    local_28 = param_4;
    local_2c = (uint)(0 < param_4);
    local_24 = 0xffffffff;
    local_4 = 0xffffffff;
    iVar1 = *(int *)(param_1 + 0x10);
    local_20 = 0;
    local_8 = (uint)(param_3 != 0);
    local_18 = 0;
    local_1c = 0;
    local_14 = 0;
    local_10 = 0;
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    }
    uVar6 = 1;
    for (piVar7 = *(int **)(param_1 + 0x1c); piVar7 != (int *)0x0; piVar7 = (int *)piVar7[5]) {
      if (param_2 == (int *)0x0) {
        iVar1 = 1;
      }
      else {
        iVar1 = param_2[*piVar7];
      }
      uVar6 = uVar6 + iVar1;
    }
    puVar2 = FUN_00419cc0();
    piVar3 = FUN_00411e70(param_1);
    piVar7 = piVar3;
    puVar4 = FUN_00412c80(piVar3,(int *)puVar2,param_2,0,uVar6,(uint *)0x0,&local_2c);
    FUN_00411db0(piVar3,piVar7);
    FUN_00419cf0((int *)puVar2);
    if (local_2c != 0) {
      if (local_8 != 0) {
        FUN_0041b470((byte *)s______heuristic_covering_____00430c2c);
        FUN_0041b470((byte *)s_lower_bound____d_00430c4c);
      }
      FUN_0041b470((byte *)s_matrix____d_by__d_with__d_elemen_00430c60);
      FUN_0041b470((byte *)s_cover_size____d_elements_00430c94);
      FUN_0041b470((byte *)s_cover_cost____d_00430cb0);
      iVar1 = FUN_0041b360();
      FUN_004163a0(iVar1 - local_c);
      FUN_0041b470((byte *)s_time____s_00430cc4);
      FUN_0041b470((byte *)s_components____d_00430cd8);
      FUN_0041b470((byte *)s_gimpel____d_00430cec);
      FUN_0041b470((byte *)s_nodes____d_00430d00);
      FUN_0041b470((byte *)s_max_depth____d_00430d14);
    }
    iVar1 = FUN_00416c40(*puVar4);
    iVar5 = FUN_004132d0(param_1,iVar1);
    if (iVar5 == 0) {
      FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_Fatal_error__file__s__line__d__s_00430d6c);
      FUN_0041f0ff((int *)&DAT_00431c98);
      FUN_00420108();
    }
    FUN_00419cf0((int *)puVar4);
    return iVar1;
  }
  iVar1 = FUN_00416b90();
  return iVar1;
}



uint * __cdecl
FUN_00412c80(int *param_1,int *param_2,int *param_3,uint param_4,uint param_5,uint *param_6,
            uint *param_7)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  uint *puVar9;
  int *unaff_EDI;
  
  puVar9 = param_7;
  piVar3 = param_3;
  piVar2 = param_2;
  param_7[3] = param_7[3] + 1;
  if ((int)param_7[2] < (int)param_6) {
    param_7[2] = (uint)param_6;
  }
  if ((*param_7 == 0) || (bVar1 = true, (int)param_7[1] < (int)param_6)) {
    bVar1 = false;
  }
  FUN_00413210(param_1,param_2,(int)param_3,param_5);
  if ((int)param_5 <= piVar2[1]) {
    return (uint *)0x0;
  }
  if ((piVar3 != (int *)0x0) ||
     (iVar4 = FUN_0040cfa0(param_1,piVar2,0,param_4,param_5,param_6,(int)puVar9,(int *)&param_7),
     puVar5 = param_7, iVar4 == 0)) {
    puVar5 = FUN_0040e7a0(param_1,(int)piVar3);
    uVar6 = puVar5[1] + piVar2[1];
    if ((int)(puVar5[1] + piVar2[1]) <= (int)param_4) {
      uVar6 = param_4;
    }
    param_4 = uVar6;
    uVar6 = FUN_004130c0(param_1,(int)piVar3,(int *)puVar5);
    FUN_00419cf0((int *)puVar5);
    if (param_6 == (uint *)0x0) {
      puVar9[10] = puVar9[7] + param_4;
    }
    if (bVar1) {
      FUN_0041b470((byte *)s_ABSMIN__2d__s_00430d98);
      iVar4 = FUN_0041b360();
      FUN_004163a0(iVar4 - puVar9[8]);
      FUN_0041b470((byte *)s__3dx_3d_sel__3d_bnd__3d_lb__3d___00430da8);
    }
    if ((int)param_5 <= (int)param_4) {
      if (bVar1) {
        FUN_0041b470((byte *)s_bounded_00430dd0);
      }
      return (uint *)0x0;
    }
    if (param_1[6] == 0) {
      param_7 = FUN_00419d10(piVar2);
      if (bVar1) {
        FUN_0041b470((byte *)s_BEST_00430ddc);
      }
      puVar5 = param_7;
      if ((*puVar9 != 0) && (puVar9[4] == 0)) {
        iVar4 = FUN_0041b360();
        FUN_004163a0(iVar4 - puVar9[8]);
        FUN_0041b470((byte *)s_new__best__solution__d_at_level___00430de4);
        return param_7;
      }
    }
    else {
      iVar4 = FUN_00415ca0(param_1,&param_3,&param_2);
      piVar8 = param_3;
      if (iVar4 != 0) {
        if (param_2[9] < param_3[9]) {
          param_3 = param_2;
          param_2 = piVar8;
        }
        if (bVar1) {
          FUN_0041b470((byte *)s_comp__d__d_00430e18);
        }
        puVar9[5] = puVar9[5] + 1;
        puVar5 = FUN_00419cc0();
        puVar9[4] = puVar9[4] + 1;
        puVar7 = (uint *)((int)param_6 + 1);
        param_6 = FUN_00412c80(param_3,(int *)puVar5,piVar3,0,param_5 - piVar2[1],puVar7,puVar9);
        puVar9[4] = puVar9[4] - 1;
        FUN_00419cf0((int *)puVar5);
        FUN_00411db0(param_3,(int *)puVar5);
        if (param_6 != (uint *)0x0) {
          for (iVar4 = *(int *)(*param_6 + 0xc); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
            FUN_00419d40(piVar2,(int)piVar3,*(uint *)(iVar4 + 4));
          }
          FUN_00419cf0((int *)param_6);
          param_7 = FUN_00412c80(param_2,piVar2,piVar3,param_4,param_5,puVar7,puVar9);
          FUN_00411db0(param_2,unaff_EDI);
          return param_7;
        }
        param_7 = param_6;
        FUN_00411db0(param_2,unaff_EDI);
        return param_7;
      }
      if (bVar1) {
        FUN_0041b470((byte *)s_pick__d_00430e24);
      }
      piVar8 = FUN_00411e70((int)param_1);
      puVar5 = FUN_00419d10(piVar2);
      FUN_00419d80((int *)puVar5,piVar8,(int)piVar3,uVar6);
      puVar7 = (uint *)((int)param_6 + 1);
      param_6 = FUN_00412c80(piVar8,(int *)puVar5,piVar3,param_4,param_5,puVar7,puVar9);
      FUN_00419cf0((int *)puVar5);
      FUN_00411db0(piVar8,(int *)puVar5);
      if ((param_6 != (uint *)0x0) && ((int)param_6[1] < (int)param_5)) {
        param_5 = param_6[1];
      }
      puVar5 = param_6;
      if ((puVar9[9] == 0) && ((param_6 == (uint *)0x0 || (param_6[1] != param_4)))) {
        piVar8 = FUN_00411e70((int)param_1);
        puVar5 = FUN_00419d10(piVar2);
        FUN_00419dd0(puVar5,piVar8,piVar3,uVar6);
        puVar9 = FUN_00412c80(piVar8,(int *)puVar5,piVar3,param_4,param_5,puVar7,puVar9);
        FUN_00419cf0((int *)puVar5);
        FUN_00411db0(piVar8,(int *)puVar5);
        puVar5 = (uint *)FUN_00419df0((int *)param_6,(int *)puVar9);
      }
    }
  }
  return puVar5;
}



int __cdecl FUN_004130c0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  double dVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  double local_8;
  
  piVar5 = param_1;
  iVar6 = FUN_00416b90();
  if (param_3 == (int *)0x0) {
    for (puVar2 = (uint *)param_1[7]; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[5]) {
      FUN_00416c70(iVar6,*puVar2);
    }
  }
  else {
    for (iVar1 = *(int *)(*param_3 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      iVar7 = *(int *)(iVar1 + 4);
      if ((iVar7 < 0) || (param_1[1] <= iVar7)) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(*param_1 + iVar7 * 4);
      }
      for (iVar7 = *(int *)(iVar7 + 0xc); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x10)) {
        FUN_00416c70(iVar6,*(uint *)(iVar7 + 4));
      }
    }
  }
  iVar1 = *(int *)(iVar6 + 0xc);
  param_1 = (int *)0xffffffff;
  local_8 = -1.0;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    iVar7 = *(int *)(iVar1 + 4);
    if ((iVar7 < 0) || (piVar5[3] <= iVar7)) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = *(int **)(piVar5[2] + iVar7 * 4);
    }
    dVar4 = 0.0;
    for (piVar3 = (int *)piVar8[3]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      iVar7 = *piVar3;
      if ((iVar7 < 0) || (piVar5[1] <= iVar7)) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(*piVar5 + iVar7 * 4);
      }
      dVar4 = 1.0 / ((double)*(int *)(iVar7 + 4) - 1.0) + dVar4;
    }
    if (param_2 == 0) {
      param_3 = (int *)0x1;
    }
    else {
      param_3 = *(int **)(param_2 + *piVar8 * 4);
    }
    if (local_8 < dVar4 / (double)(int)param_3) {
      param_1 = (int *)*piVar8;
      local_8 = dVar4 / (double)(int)param_3;
    }
  }
  FUN_00416c00(iVar6);
  return (int)param_1;
}



void __cdecl FUN_00413210(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  do {
    iVar2 = FUN_0040a3d0(param_1,param_3);
    iVar3 = FUN_00416b90();
    for (iVar1 = param_1[4]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
      if (*(int *)(iVar1 + 4) == 1) {
        FUN_00416c70(iVar3,*(uint *)(*(int *)(iVar1 + 0xc) + 4));
      }
    }
    for (iVar1 = *(int *)(iVar3 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      FUN_00419d80(param_2,param_1,param_3,*(uint *)(iVar1 + 4));
      if (param_4 <= param_2[1]) {
        FUN_00416c00(iVar3);
        return;
      }
    }
    iVar1 = *(int *)(iVar3 + 4);
    FUN_00416c00(iVar3);
    iVar3 = FUN_0040a300(param_1);
  } while (((0 < iVar2) || (0 < iVar3)) || (0 < iVar1));
  return;
}



undefined4 __cdecl FUN_004132d0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    iVar2 = FUN_00416e70(iVar1,param_2);
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 0x14);
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_00413310(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  _DAT_00433218 = param_2 & 0x80000001;
  if ((int)_DAT_00433218 < 0) {
    _DAT_00433218 = (_DAT_00433218 - 1 | 0xfffffffe) + 1;
  }
  DAT_00433214 = (int)param_2 / 2 & 0x80000001;
  if ((int)DAT_00433214 < 0) {
    DAT_00433214 = (DAT_00433214 - 1 | 0xfffffffe) + 1;
  }
  DAT_00433210 = (int)(param_2 + ((int)param_2 >> 0x1f & 3U)) >> 2 & 0x80000001;
  if ((int)DAT_00433210 < 0) {
    DAT_00433210 = (DAT_00433210 - 1 | 0xfffffffe) + 1;
  }
  DAT_0043536c = _DAT_00433218;
  if (param_1[5] != 0) {
    FUN_0041b8c0(param_1[5]);
    param_1[5] = 0;
  }
  if (DAT_00433214 == 0) {
    uVar1 = FUN_004134d0(param_1,0,(uint *)0x0);
    param_1[5] = uVar1;
  }
  else {
    uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
    if (uVar1 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (uVar1 - 1 >> 5) + 2;
    }
    puVar4 = DAT_00435550;
    puVar3 = FUN_0040a880(1,iVar2 << 2);
    uVar1 = FUN_004171c0((int)puVar3,puVar4);
    param_1[5] = uVar1;
    FUN_00413400(param_1);
  }
  DAT_0043536c = 0;
  FUN_00414110((int *)param_1);
  FUN_004145c0((int *)param_1);
  return;
}



void __cdecl FUN_00413400(uint *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < *(int *)(DAT_00435534 + DAT_00435568 * 4)) {
    do {
      iVar2 = FUN_004134d0(param_1,iVar5,(uint *)param_1[5]);
      iVar1 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar5;
      uVar4 = 1 << ((byte)iVar1 & 0x1f);
      iVar1 = (iVar1 >> 5) * 4 + 4;
      if ((*(uint *)(iVar1 + iVar2) & uVar4) == 0) {
        puVar3 = (uint *)(iVar1 + param_1[5]);
        *puVar3 = *puVar3 & ~uVar4;
      }
      if ((DAT_00435408 != 0) || (DAT_004353d0 != 0)) {
        FUN_0041b470((byte *)s_OPO_loop_for_output___d_00430e30);
        FUN_00409a60(param_1[5]);
        FUN_0041b470((byte *)s_PLA_>phase_is__s_00430e4c);
        FUN_00409a60(iVar2);
        FUN_0041b470((byte *)s_phase_is__s_00430e60);
      }
      if (iVar2 != 0) {
        FUN_0041b8c0(iVar2);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(DAT_00435534 + DAT_00435568 * 4));
  }
  return;
}



int __cdecl FUN_004134d0(uint *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int unaff_ESI;
  int *unaff_EDI;
  
  uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
  if (uVar1 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = (uVar1 - 1 >> 5) + 2;
  }
  puVar6 = DAT_00435550;
  puVar3 = FUN_0040a880(1,iVar2 << 2);
  iVar2 = FUN_004171c0((int)puVar3,puVar6);
  piVar4 = (int *)FUN_00406f70();
  iVar5 = FUN_00417a20(*param_1);
  *piVar4 = iVar5;
  iVar5 = FUN_00417a20(param_1[2]);
  piVar4[2] = iVar5;
  iVar5 = FUN_00417a20(param_1[1]);
  piVar4[1] = iVar5;
  if (param_3 != (uint *)0x0) {
    uVar1 = (*param_3 & 0x3ff) * 0x20;
    if (uVar1 < 0x21) {
      iVar5 = 2;
    }
    else {
      iVar5 = (uVar1 - 1 >> 5) + 2;
    }
    puVar6 = FUN_0040a880(1,iVar5 * 4);
    iVar5 = FUN_004171c0((int)puVar6,param_3);
    piVar4[5] = iVar5;
    FUN_00414110(piVar4);
  }
  FUN_0041b360();
  FUN_00413bf0(piVar4,param_2,unaff_EDI,unaff_ESI);
  if (DAT_004353d0 != 0) {
    FUN_0041b360();
    FUN_00408b70(*piVar4);
  }
  FUN_004145c0(piVar4);
  FUN_0041b360();
  puVar6 = FUN_00413640(iVar2,(uint *)*piVar4,piVar4[1],piVar4[2],param_2);
  *piVar4 = (int)puVar6;
  if (DAT_004353d0 != 0) {
    FUN_0041b360();
    FUN_00408b70(*piVar4);
  }
  FUN_00406ff0(piVar4);
  FUN_00405270();
  iVar5 = *(int *)(DAT_00435534 + DAT_00435568 * 4);
  *(int *)(DAT_00435534 + DAT_00435568 * 4) = iVar5 - (iVar5 - param_2) / 2;
  FUN_00404e20();
  return iVar2;
}



uint * __cdecl
FUN_00413640(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint unaff_EDI;
  
  puVar2 = param_2;
  uVar11 = param_2[4];
  if ((int)uVar11 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = ((int)(uVar11 - 1) >> 5) + 2;
  }
  puVar6 = FUN_0040a880(1,iVar5 << 2);
  puVar6 = (uint *)FUN_00417170((int *)puVar6,uVar11);
  param_2 = (uint *)0x0;
  if (0 < param_5) {
    do {
      uVar11 = puVar2[6];
      iVar10 = 0;
      iVar5 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + (int)param_2;
      if (0 < (int)puVar2[4]) {
        do {
          if ((*(uint *)((iVar5 >> 5) * 4 + 4 + uVar11) & 1 << ((byte)iVar5 & 0x1f)) != 0) {
            puVar6[(iVar10 >> 5) + 1] = puVar6[(iVar10 >> 5) + 1] & ~(1 << ((byte)iVar10 & 0x1f));
          }
          iVar10 = iVar10 + 1;
          uVar11 = uVar11 + puVar2[1] * 4;
        } while (iVar10 < (int)puVar2[4]);
      }
      param_2 = (uint *)((int)param_2 + 1);
    } while ((int)param_2 < param_5);
  }
  iVar10 = (*(int *)(DAT_00435534 + DAT_00435568 * 4) - param_5) / 2;
  iVar5 = iVar10 + -1 + param_5;
  puVar8 = puVar2;
  puVar7 = FUN_00413980((int)puVar2,param_3,puVar6,iVar10,param_5,iVar5);
  uVar11 = puVar7[6];
  param_2 = FUN_00417930(puVar2[4],DAT_00435520,(uint)puVar8);
  puVar8 = (uint *)puVar2[6];
  iVar12 = 0;
  if (0 < (int)puVar2[4]) {
    do {
      if ((*(uint *)(uVar11 + 4 + (iVar12 >> 5) * 4) & 1 << ((byte)iVar12 & 0x1f)) == 0) {
        param_2 = (uint *)FUN_00417b00((int)param_2,puVar8);
      }
      iVar12 = iVar12 + 1;
      puVar8 = puVar8 + puVar2[1];
    } while (iVar12 < (int)puVar2[4]);
  }
  if (puVar6 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar6);
  }
  FUN_00417a40((short *)puVar7);
  puVar6 = FUN_00402950((int)param_2);
  puVar6 = FUN_00403160(puVar6);
  if ((int)DAT_00435520 < 0x21) {
    iVar12 = 2;
  }
  else {
    iVar12 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar11 = DAT_00435520;
  puVar8 = FUN_0040a880(1,iVar12 * 4);
  puVar8 = (uint *)FUN_00417140((int *)puVar8,uVar11);
  if ((int)DAT_00435520 < 0x21) {
    iVar12 = 2;
  }
  else {
    iVar12 = ((int)(DAT_00435520 - 1) >> 5) + 2;
  }
  uVar11 = DAT_00435520;
  puVar7 = FUN_0040a880(1,iVar12 << 2);
  puVar9 = (uint *)FUN_00417140((int *)puVar7,uVar11);
  puVar3 = (uint *)puVar2[6];
  puVar7 = puVar3 + puVar2[1] * puVar2[4];
  for (; puVar3 < puVar7; puVar3 = puVar3 + puVar2[1]) {
    puVar4 = (uint *)puVar6[6];
    puVar1 = puVar4 + puVar6[1] * puVar6[4];
    for (; puVar4 < puVar1; puVar4 = puVar4 + puVar6[1]) {
      iVar12 = FUN_00418690((int)puVar3,puVar4);
      if (iVar12 != 0) {
        iVar12 = FUN_004171f0(puVar9,puVar3,(int)puVar4);
        FUN_00417240(puVar8,puVar8,iVar12);
      }
    }
  }
  FUN_00417a40((short *)puVar2);
  FUN_00417a40((short *)puVar6);
  if (puVar9 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar9);
  }
  if (param_5 <= iVar5) {
    do {
      iVar12 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + param_5;
      uVar11 = 1 << ((byte)iVar12 & 0x1f);
      if ((puVar8[(iVar12 >> 5) + 1] & uVar11) != 0) {
        if ((puVar8[(iVar12 + iVar10 >> 5) + 1] & 1 << ((byte)(iVar12 + iVar10) & 0x1f)) == 0) {
          puVar2 = (uint *)((iVar12 >> 5) * 4 + 4 + param_1);
          *puVar2 = *puVar2 & ~uVar11;
        }
        else {
          FUN_00408c40((int *)s_error_in_output_phase_assignment_00430e8c,unaff_EDI);
        }
      }
      param_5 = param_5 + 1;
    } while (param_5 <= iVar5);
  }
  if (puVar8 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar8);
  }
  return param_2;
}



uint * __cdecl
FUN_00413980(int param_1,undefined4 param_2,uint *param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  DAT_0043321c = DAT_0043321c + 1;
  if (param_5 == param_6) {
    puVar1 = FUN_00413a90(param_1,param_3,param_5,param_4 + param_5);
    DAT_0043321c = DAT_0043321c + -1;
    return puVar1;
  }
  iVar4 = (param_5 + param_6) / 2;
  puVar1 = FUN_00413980(param_1,param_2,param_3,param_4,param_5,iVar4);
  puVar2 = FUN_00413980(param_1,param_2,param_3,param_4,iVar4 + 1,param_6);
  puVar3 = (uint *)FUN_0041aba0((int)puVar1,(int)puVar2,(uint)(DAT_0043321c == 1));
  if (DAT_00435408 != 0) {
    iVar4 = FUN_0041b360();
    FUN_004163a0(iVar4);
    FUN_0041b470((byte *)s___OPO__d____4d____4d_x__4d__time_00430eb0);
    FUN_0041f0ff((int *)&DAT_00431c98);
  }
  FUN_00417a40((short *)puVar1);
  FUN_00417a40((short *)puVar2);
  DAT_0043321c = DAT_0043321c + -1;
  return puVar3;
}



uint * __cdecl FUN_00413a90(int param_1,uint *param_2,int param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint unaff_EDI;
  
  iVar7 = *(int *)(DAT_0043552c + DAT_00435568 * 4);
  iVar6 = param_4 + iVar7;
  iVar7 = param_3 + iVar7;
  puVar4 = FUN_00417930(2,*(uint *)(param_1 + 0x10),unaff_EDI);
  uVar3 = puVar4[4];
  puVar4[4] = uVar3 + 1;
  iVar1 = puVar4[6] + puVar4[1] * uVar3 * 4;
  FUN_004171c0(iVar1,param_2);
  param_3 = *(int *)(param_1 + 0x18);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if ((*(uint *)((iVar7 >> 5) * 4 + 4 + param_3) & 1 << ((byte)iVar7 & 0x1f)) != 0) {
        *(uint *)(iVar1 + 4 + (iVar5 >> 5) * 4) =
             *(uint *)(iVar1 + 4 + (iVar5 >> 5) * 4) & ~(1 << ((byte)iVar5 & 0x1f));
      }
      iVar5 = iVar5 + 1;
      param_3 = param_3 + *(int *)(param_1 + 4) * 4;
    } while (iVar5 < *(int *)(param_1 + 0x10));
  }
  uVar3 = puVar4[4];
  puVar4[4] = uVar3 + 1;
  iVar1 = puVar4[6] + puVar4[1] * uVar3 * 4;
  FUN_004171c0(iVar1,param_2);
  iVar7 = *(int *)(param_1 + 0x18);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if ((*(uint *)((iVar6 >> 5) * 4 + 4 + iVar7) & 1 << ((byte)iVar6 & 0x1f)) != 0) {
        puVar2 = (uint *)(iVar1 + 4 + (iVar5 >> 5) * 4);
        *puVar2 = *puVar2 & ~(1 << ((byte)iVar5 & 0x1f));
      }
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + *(int *)(param_1 + 4) * 4;
    } while (iVar5 < *(int *)(param_1 + 0x10));
  }
  return puVar4;
}



void __cdecl FUN_00413bf0(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  byte bVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint unaff_EDI;
  uint in_stack_ffffffdc;
  
  if (DAT_00435568 == -1) {
    FUN_00408c40((int *)s_output_phase_setup__must_have_an_00430ed8,in_stack_ffffffdc);
  }
  psVar4 = (short *)param_3[1];
  psVar5 = (short *)param_3[2];
  iVar6 = *(int *)(DAT_00435530 + DAT_00435568 * 4);
  psVar7 = (short *)*param_3;
  iVar19 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + param_4;
  iVar20 = *(int *)(DAT_00435534 + DAT_00435568 * 4) - param_4;
  FUN_00405270();
  piVar1 = (int *)(DAT_00435534 + DAT_00435568 * 4);
  *piVar1 = *piVar1 + iVar20;
  FUN_00404e20();
  uVar10 = (*DAT_00435550 & 0x3ff) * 0x20;
  if (uVar10 < 0x21) {
    iVar11 = 2;
  }
  else {
    iVar11 = (uVar10 - 1 >> 5) + 2;
  }
  puVar13 = DAT_00435550;
  puVar12 = FUN_0040a880(1,iVar11 << 2);
  puVar13 = (uint *)FUN_004171c0((int)puVar12,puVar13);
  iVar11 = iVar19;
  if (iVar19 < (int)DAT_00435520) {
    do {
      iVar15 = iVar11 >> 5;
      bVar8 = (byte)iVar11;
      iVar11 = iVar11 + 1;
      puVar13[iVar15 + 1] = puVar13[iVar15 + 1] & ~(1 << (bVar8 & 0x1f));
    } while (iVar11 < (int)DAT_00435520);
  }
  uVar10 = (*puVar13 & 0x3ff) * 0x20;
  if (uVar10 < 0x21) {
    iVar11 = 2;
  }
  else {
    iVar11 = (uVar10 - 1 >> 5) + 2;
  }
  puVar12 = puVar13;
  puVar14 = FUN_0040a880(1,iVar11 * 4);
  puVar12 = (uint *)FUN_004171c0((int)puVar14,puVar12);
  for (iVar11 = *(int *)(DAT_0043552c + DAT_00435568 * 4); iVar11 < iVar19; iVar11 = iVar11 + 1) {
    puVar12[(iVar11 >> 5) + 1] = puVar12[(iVar11 >> 5) + 1] & ~(1 << ((byte)iVar11 & 0x1f));
  }
  uVar10 = *(int *)(psVar5 + 8) + *(int *)(psVar7 + 8);
  puVar14 = FUN_00417930(uVar10,DAT_00435520,unaff_EDI);
  *param_3 = (int)puVar14;
  uVar16 = *(int *)(psVar5 + 8) + *(int *)(psVar7 + 8);
  puVar14 = FUN_00417930(uVar16,DAT_00435520,uVar10);
  param_3[2] = (int)puVar14;
  puVar14 = FUN_00417930(*(undefined4 *)(psVar4 + 8),DAT_00435520,uVar16);
  param_3[1] = (int)puVar14;
  uVar16 = *(uint *)(psVar7 + 0xc);
  uVar10 = uVar16 + *(int *)(psVar7 + 8) * *(int *)(psVar7 + 2) * 4;
  for (; uVar16 < uVar10; uVar16 = uVar16 + *(int *)(psVar7 + 2) * 4) {
    iVar11 = *param_3;
    iVar15 = *(int *)(iVar11 + 0x10);
    *(int *)(iVar11 + 0x10) = iVar15 + 1;
    iVar18 = param_3[2];
    puVar14 = (uint *)(*(int *)(iVar11 + 0x18) + *(int *)(iVar11 + 4) * iVar15 * 4);
    puVar3 = (uint *)(*(int *)(iVar18 + 0x18) + *(int *)(iVar18 + 4) * *(int *)(iVar18 + 0x10) * 4);
    *(int *)(iVar18 + 0x10) = *(int *)(iVar18 + 0x10) + 1;
    FUN_004171f0(puVar14,puVar13,uVar16);
    FUN_004171f0(puVar3,puVar12,uVar16);
    for (iVar11 = iVar19; iVar11 <= iVar6; iVar11 = iVar11 + 1) {
      uVar17 = 1 << ((byte)iVar11 & 0x1f);
      if ((*(uint *)((iVar11 >> 5) * 4 + 4 + uVar16) & uVar17) != 0) {
        puVar2 = puVar14 + (iVar11 >> 5) + 1;
        *puVar2 = *puVar2 | uVar17;
      }
    }
    bVar9 = false;
    iVar11 = iVar19;
    if (iVar6 < iVar19) {
LAB_00413ea2:
      *(int *)(param_3[2] + 0x10) = *(int *)(param_3[2] + 0x10) + -1;
    }
    else {
      do {
        if ((*(uint *)(uVar16 + 4 + (iVar11 >> 5) * 4) & 1 << ((byte)iVar11 & 0x1f)) != 0) {
          bVar9 = true;
          iVar15 = iVar11 + iVar20 >> 5;
          puVar3[iVar15 + 1] = puVar3[iVar15 + 1] | 1 << ((byte)(iVar11 + iVar20) & 0x1f);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 <= iVar6);
      if (!bVar9) goto LAB_00413ea2;
    }
  }
  uVar16 = *(uint *)(psVar5 + 0xc);
  uVar10 = uVar16 + *(int *)(psVar5 + 8) * *(int *)(psVar5 + 2) * 4;
  do {
    if (uVar10 <= uVar16) {
      uVar16 = *(uint *)(psVar4 + 0xc);
      uVar10 = uVar16 + *(int *)(psVar4 + 8) * *(int *)(psVar4 + 2) * 4;
      for (; uVar16 < uVar10; uVar16 = uVar16 + *(int *)(psVar4 + 2) * 4) {
        iVar11 = param_3[1];
        iVar15 = *(int *)(iVar11 + 0x10);
        *(int *)(iVar11 + 0x10) = iVar15 + 1;
        puVar14 = (uint *)(*(int *)(iVar11 + 0x18) + *(int *)(iVar11 + 4) * iVar15 * 4);
        FUN_004171f0(puVar14,puVar13,uVar16);
        for (iVar11 = iVar19; iVar11 <= iVar6; iVar11 = iVar11 + 1) {
          uVar17 = 1 << ((byte)iVar11 & 0x1f);
          iVar15 = iVar11 >> 5;
          if ((*(uint *)(iVar15 * 4 + 4 + uVar16) & uVar17) != 0) {
            puVar14[iVar15 + 1] = puVar14[iVar15 + 1] | uVar17;
            iVar15 = iVar11 + iVar20 >> 5;
            puVar14[iVar15 + 1] = puVar14[iVar15 + 1] | 1 << ((byte)(iVar11 + iVar20) & 0x1f);
          }
        }
      }
      FUN_00417a40(psVar7);
      FUN_00417a40(psVar4);
      FUN_00417a40(psVar5);
      if (puVar13 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar13);
      }
      if (puVar12 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar12);
      }
      return;
    }
    iVar11 = *param_3;
    iVar15 = *(int *)(iVar11 + 0x10);
    *(int *)(iVar11 + 0x10) = iVar15 + 1;
    iVar18 = param_3[2];
    puVar14 = (uint *)(*(int *)(iVar11 + 0x18) + *(int *)(iVar11 + 4) * iVar15 * 4);
    iVar11 = *(int *)(iVar18 + 0x10);
    *(int *)(iVar18 + 0x10) = iVar11 + 1;
    puVar3 = (uint *)(*(int *)(iVar18 + 0x18) + *(int *)(iVar18 + 4) * iVar11 * 4);
    FUN_004171f0(puVar14,puVar12,uVar16);
    FUN_004171f0(puVar3,puVar13,uVar16);
    bVar9 = false;
    iVar15 = iVar19;
    iVar11 = iVar19;
    if (iVar6 < iVar19) {
LAB_00413f95:
      *(int *)(*param_3 + 0x10) = *(int *)(*param_3 + 0x10) + -1;
    }
    else {
      do {
        if ((*(uint *)(uVar16 + 4 + (iVar15 >> 5) * 4) & 1 << ((byte)iVar15 & 0x1f)) != 0) {
          bVar9 = true;
          iVar18 = iVar15 + iVar20 >> 5;
          puVar14[iVar18 + 1] = puVar14[iVar18 + 1] | 1 << ((byte)(iVar15 + iVar20) & 0x1f);
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 <= iVar6);
      if (!bVar9) goto LAB_00413f95;
    }
    for (; iVar11 <= iVar6; iVar11 = iVar11 + 1) {
      uVar17 = 1 << ((byte)iVar11 & 0x1f);
      if ((*(uint *)((iVar11 >> 5) * 4 + 4 + uVar16) & uVar17) != 0) {
        puVar14 = puVar3 + (iVar11 >> 5) + 1;
        *puVar14 = *puVar14 | uVar17;
      }
    }
    uVar16 = uVar16 + *(int *)(psVar5 + 2) * 4;
  } while( true );
}



int * __cdecl FUN_00414110(int *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  
  puVar1 = (uint *)DAT_0043554c[1];
  puVar2 = (uint *)*DAT_0043554c;
  puVar3 = *(uint **)(DAT_00435548 + -4 + DAT_00435524 * 4);
  iVar4 = param_1[5];
  FUN_00417290(puVar1,puVar3,iVar4);
  puVar11 = puVar1;
  puVar5 = (uint *)FUN_00417290(puVar2,DAT_00435550,(int)puVar3);
  puVar10 = puVar1;
  FUN_00417240(puVar1,puVar5,(int)puVar11);
  uVar9 = *(int *)(param_1[2] + 0x10) + *(int *)(*param_1 + 0x10);
  puVar5 = FUN_00417930(uVar9,DAT_00435520,(uint)puVar10);
  puVar6 = FUN_00417930(*(int *)(param_1[2] + 0x10) + *(int *)(*param_1 + 0x10),DAT_00435520,uVar9);
  iVar8 = *param_1;
  puVar11 = *(uint **)(iVar8 + 0x18);
  puVar10 = puVar11 + *(int *)(iVar8 + 0x10) * *(int *)(iVar8 + 4);
  for (; puVar11 < puVar10; puVar11 = puVar11 + *(int *)(*param_1 + 4)) {
    puVar12 = puVar3;
    puVar7 = (uint *)FUN_004171f0(puVar2,puVar11,iVar4);
    iVar8 = FUN_00417510(puVar7,(int)puVar12);
    if (iVar8 == 0) {
      uVar9 = puVar5[4];
      puVar5[4] = uVar9 + 1;
      FUN_004171c0(puVar5[6] + puVar5[1] * uVar9 * 4,puVar2);
    }
    puVar12 = puVar3;
    puVar7 = (uint *)FUN_004171f0(puVar2,puVar11,(int)puVar1);
    iVar8 = FUN_00417510(puVar7,(int)puVar12);
    if (iVar8 == 0) {
      uVar9 = puVar6[4];
      puVar6[4] = puVar6[4] + 1;
      FUN_004171c0(puVar6[6] + puVar6[1] * uVar9 * 4,puVar2);
    }
  }
  iVar8 = param_1[2];
  puVar11 = *(uint **)(iVar8 + 0x18);
  puVar10 = puVar11 + *(int *)(iVar8 + 0x10) * *(int *)(iVar8 + 4);
  for (; puVar11 < puVar10; puVar11 = puVar11 + *(int *)(param_1[2] + 4)) {
    puVar12 = puVar3;
    puVar7 = (uint *)FUN_004171f0(puVar2,puVar11,iVar4);
    iVar8 = FUN_00417510(puVar7,(int)puVar12);
    if (iVar8 == 0) {
      uVar9 = puVar6[4];
      puVar6[4] = puVar6[4] + 1;
      FUN_004171c0(puVar6[6] + puVar6[1] * uVar9 * 4,puVar2);
    }
    puVar12 = puVar3;
    puVar7 = (uint *)FUN_004171f0(puVar2,puVar11,(int)puVar1);
    iVar8 = FUN_00417510(puVar7,(int)puVar12);
    if (iVar8 == 0) {
      uVar9 = puVar5[4];
      puVar5[4] = uVar9 + 1;
      FUN_004171c0(puVar5[6] + puVar5[1] * uVar9 * 4,puVar2);
    }
  }
  FUN_00417a40((short *)*param_1);
  FUN_00417a40((short *)param_1[2]);
  *param_1 = (int)puVar5;
  param_1[2] = (int)puVar6;
  return param_1;
}



void __cdecl FUN_00414330(uint *param_1,int param_2,int param_3,short *param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  short *local_18;
  
  puVar1 = param_1;
  DAT_00433210 = param_4;
  uVar13 = 0;
  if (param_1[5] != 0) {
    FUN_0041b8c0(param_1[5]);
    param_1[5] = 0;
  }
  uVar2 = (*DAT_00435550 & 0x3ff) * 0x20;
  if (uVar2 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = (uVar2 - 1 >> 5) + 2;
  }
  puVar5 = DAT_00435550;
  puVar4 = FUN_0040a880(1,iVar3 * 4);
  uVar2 = FUN_004171c0((int)puVar4,puVar5);
  param_4 = (short *)FUN_00417a20(*param_1);
  puVar5 = (uint *)FUN_00417a20(param_1[1]);
  local_18 = (short *)FUN_00417a20(param_1[2]);
  iVar3 = 1 << (((char)param_3 - (char)param_2) + 1U & 0x1f);
  param_1 = puVar5;
  if (0 < iVar3) {
    do {
      uVar6 = FUN_00417a20(*puVar1);
      uVar7 = FUN_00417a20(puVar1[1]);
      uVar8 = FUN_00417a20(puVar1[2]);
      uVar9 = (*DAT_00435550 & 0x3ff) * 0x20;
      if (uVar9 < 0x21) {
        iVar10 = 2;
      }
      else {
        iVar10 = (uVar9 - 1 >> 5) + 2;
      }
      puVar5 = DAT_00435550;
      puVar4 = FUN_0040a880(1,iVar10 * 4);
      uVar9 = FUN_004171c0((int)puVar4,puVar5);
      puVar1[5] = uVar9;
      uVar9 = uVar13;
      iVar10 = param_3;
      if (param_2 <= param_3) {
        do {
          uVar11 = uVar9 & 0x80000001;
          bVar14 = uVar11 == 0;
          if ((int)uVar11 < 0) {
            bVar14 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if (bVar14) {
            iVar12 = *(int *)(DAT_0043552c + DAT_00435568 * 4) + iVar10;
            puVar5 = (uint *)(puVar1[5] + 4 + (iVar12 >> 5) * 4);
            *puVar5 = *puVar5 & ~(1 << ((byte)iVar12 & 0x1f));
          }
          uVar9 = (int)uVar9 / 2;
          iVar10 = iVar10 + -1;
        } while (param_2 <= iVar10);
      }
      FUN_00414110((int *)puVar1);
      FUN_00409a60(puVar1[5]);
      FUN_0041b470((byte *)s___phase_is__s_00430f00);
      DAT_004353d0 = 1;
      FUN_004145c0((int *)puVar1);
      if (*(int *)((short *)*puVar1 + 8) < *(int *)(param_4 + 8)) {
        FUN_004171c0(uVar2,(uint *)puVar1[5]);
        FUN_00417a40(param_4);
        FUN_00417a40((short *)param_1);
        FUN_00417a40(local_18);
        param_4 = (short *)*puVar1;
        param_1 = (uint *)puVar1[1];
        local_18 = (short *)puVar1[2];
      }
      else {
        FUN_00417a40((short *)*puVar1);
        FUN_00417a40((short *)puVar1[1]);
        FUN_00417a40((short *)puVar1[2]);
      }
      if (puVar1[5] != 0) {
        FUN_0041b8c0(puVar1[5]);
        puVar1[5] = 0;
      }
      puVar1[1] = uVar7;
      uVar13 = uVar13 + 1;
      *puVar1 = uVar6;
      puVar1[2] = uVar8;
    } while ((int)uVar13 < iVar3);
  }
  puVar1[5] = uVar2;
  FUN_00417a40((short *)*puVar1);
  FUN_00417a40((short *)puVar1[1]);
  FUN_00417a40((short *)puVar1[2]);
  *puVar1 = (uint)param_4;
  puVar1[1] = (uint)param_1;
  puVar1[2] = (uint)local_18;
  return;
}



void __cdecl FUN_004145c0(int *param_1)

{
  int iVar1;
  uint *puVar2;
  
  if (DAT_00433210 == 0) {
    FUN_0041b360();
    puVar2 = FUN_0040ac70((uint *)*param_1,param_1[1],(short *)param_1[2]);
    *param_1 = (int)puVar2;
    if (DAT_004353d0 != 0) {
      FUN_0041b360();
      FUN_00408b70(*param_1);
    }
  }
  else {
    FUN_0041b360();
    iVar1 = FUN_0040b380(*param_1,param_1[1],param_1[2],(short *)0x1);
    *param_1 = iVar1;
    if (DAT_004353d0 != 0) {
      FUN_0041b360();
      FUN_00408b70(*param_1);
      return;
    }
  }
  return;
}



void __cdecl FUN_00414660(undefined4 *param_1)

{
  FUN_00414670(param_1,1);
  return;
}



void __cdecl FUN_00414670(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint unaff_EDI;
  int local_824;
  int local_820;
  int local_818;
  char local_800 [2048];
  
  piVar1 = (int *)param_1[6];
  if (param_2 != 0) {
    FUN_00409c60((int)param_1);
  }
  puVar3 = FUN_0040a880(1,DAT_00435528 * 4);
  iVar4 = 0;
  puVar7 = puVar3;
  if (0 < DAT_00435528) {
    do {
      *puVar7 = 0;
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar4 < DAT_00435528);
  }
  iVar4 = 0;
  if (0 < *piVar1) {
    do {
      iVar13 = *(int *)(piVar1[1] + iVar4 * 4);
      if ((((iVar13 < 1) || (DAT_00435528 < iVar13)) ||
          (iVar10 = *(int *)(piVar1[2] + iVar4 * 4), iVar10 < 1)) || (DAT_00435528 < iVar10)) {
        FUN_00408c40((int *)s_can_only_pair_binary_valued_vari_00430f24,unaff_EDI);
      }
      else {
        puVar3[iVar13 + -1] = 1;
        puVar3[*(int *)(piVar1[2] + iVar4 * 4) + -1] = 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar1);
  }
  puVar7 = puVar3;
  puVar5 = (uint *)FUN_00414ac0((short *)*param_1,piVar1);
  uVar6 = FUN_00414c80(puVar5,(int)puVar7);
  *param_1 = uVar6;
  puVar7 = puVar3;
  puVar5 = (uint *)FUN_00414ac0((short *)param_1[2],piVar1);
  uVar6 = FUN_00414c80(puVar5,(int)puVar7);
  param_1[2] = uVar6;
  puVar7 = puVar3;
  puVar5 = (uint *)FUN_00414ac0((short *)param_1[1],piVar1);
  uVar6 = FUN_00414c80(puVar5,(int)puVar7);
  param_1[1] = uVar6;
  iVar12 = DAT_00435528;
  iVar10 = DAT_00435524;
  iVar13 = DAT_00435520;
  local_824 = DAT_00435528 * 4;
  iVar4 = *(int *)(local_824 + DAT_0043552c);
  iVar14 = 0;
  local_818 = DAT_00435528;
  local_820 = 0;
  iVar9 = DAT_00435528;
  puVar7 = puVar3;
  if (0 < DAT_00435528) {
    do {
      iVar14 = iVar14 + (uint)(*puVar7 == 0);
      iVar9 = iVar9 + -1;
      puVar7 = puVar7 + 1;
      local_820 = iVar14;
    } while (iVar9 != 0);
  }
  iVar14 = (*piVar1 - DAT_00435528) + local_820 + DAT_00435524;
  puVar7 = FUN_0040a880(1,iVar14 * 4);
  iVar9 = 0;
  if (0 < *piVar1) {
    puVar5 = puVar7 + local_820;
    do {
      *puVar5 = 4;
      iVar9 = iVar9 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar9 < *piVar1);
  }
  iVar10 = iVar10 - iVar12;
  iVar9 = 0;
  if (0 < iVar10) {
    do {
      iVar11 = *piVar1 + local_820 + iVar9;
      iVar9 = iVar9 + 1;
      puVar7[iVar11] = *(uint *)(local_824 + (int)DAT_00435534);
      local_824 = local_824 + 4;
    } while (iVar9 < iVar10);
  }
  FUN_00405270();
  if (DAT_00435534 != (uint *)0x0) {
    FUN_0041b8c0((int)DAT_00435534);
  }
  DAT_00435524 = iVar14;
  DAT_00435528 = local_820;
  DAT_00435534 = puVar7;
  FUN_00404e20();
  if (param_2 != 0) {
    piVar2 = (int *)param_1[7];
    puVar7 = FUN_0040a880(1,DAT_00435520 * 4);
    param_1[7] = puVar7;
    iVar10 = 0;
    if (0 < *piVar1) {
      do {
        iVar9 = DAT_00435528 + iVar10 * 2;
        FUN_0041ec4a(local_800,(byte *)s__s__s_00430f4c);
        puVar7 = FUN_0041a290(local_800);
        *(uint **)(param_1[7] + iVar9 * 8) = puVar7;
        FUN_0041ec4a(local_800,(byte *)s__s__s_00430f54);
        puVar7 = FUN_0041a290(local_800);
        *(uint **)(param_1[7] + 4 + iVar9 * 8) = puVar7;
        FUN_0041ec4a(local_800,(byte *)s__s__s_00430f5c);
        puVar7 = FUN_0041a290(local_800);
        *(uint **)(param_1[7] + 8 + iVar9 * 8) = puVar7;
        FUN_0041ec4a(local_800,(byte *)s__s__s_00430f64);
        puVar7 = FUN_0041a290(local_800);
        iVar10 = iVar10 + 1;
        *(uint **)(param_1[7] + 0xc + iVar9 * 8) = puVar7;
      } while (iVar10 < *piVar1);
    }
    if (0 < iVar12) {
      iVar10 = 0;
      piVar8 = piVar2;
      puVar7 = puVar3;
      do {
        if (*puVar7 == 0) {
          *(int *)(iVar10 + param_1[7]) = *piVar8;
          *(int *)(iVar10 + 4 + param_1[7]) = piVar8[1];
          piVar8[1] = 0;
          *piVar8 = 0;
          iVar10 = iVar10 + 8;
        }
        puVar7 = puVar7 + 1;
        piVar8 = piVar8 + 2;
        local_818 = local_818 + -1;
      } while (local_818 != 0);
    }
    if (iVar4 < iVar13) {
      iVar12 = (DAT_00435528 + *piVar1 * 2) * 8;
      iVar10 = iVar13 - iVar4;
      piVar8 = piVar2 + iVar4;
      do {
        *(int *)(iVar12 + param_1[7]) = *piVar8;
        *piVar8 = 0;
        iVar12 = iVar12 + 4;
        iVar10 = iVar10 + -1;
        piVar8 = piVar8 + 1;
      } while (iVar10 != 0);
    }
    piVar8 = piVar2;
    if (0 < iVar13) {
      do {
        if (*piVar8 != 0) {
          FUN_0041b8c0(*piVar8);
          *piVar8 = 0;
        }
        iVar13 = iVar13 + -1;
        piVar8 = piVar8 + 1;
      } while (iVar13 != 0);
    }
    if (piVar2 != (int *)0x0) {
      FUN_0041b8c0((int)piVar2);
    }
  }
  iVar4 = 0;
  if (0 < *piVar1) {
    do {
      iVar13 = DAT_00435528 + iVar4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(DAT_00435560 + iVar13 * 4) = 0;
    } while (iVar4 < *piVar1);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return;
}



void __cdecl FUN_00414ac0(short *param_1,int *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_14;
  
  iVar3 = *(int *)(DAT_0043552c + -4 + DAT_00435524 * 4);
  puVar5 = FUN_00418250(param_1,iVar3,*param_2 * -4);
  uVar4 = puVar5[6];
  uVar1 = uVar4 + puVar5[4] * puVar5[1] * 4;
  for (; uVar4 < uVar1; uVar4 = uVar4 + puVar5[1] * 4) {
    local_14 = 0;
    if (0 < *param_2) {
      iVar9 = iVar3 + 2;
      do {
        iVar6 = (-2 - iVar3) + iVar9;
        iVar8 = *(int *)(DAT_0043552c + -4 + *(int *)(param_2[1] + iVar6) * 4);
        iVar6 = *(int *)(DAT_0043552c + -4 + *(int *)(iVar6 + param_2[2]) * 4);
        uVar7 = 1 << ((byte)(iVar6 + 1) & 0x1f) & *(uint *)(uVar4 + 4 + (iVar6 + 1 >> 5) * 4);
        uVar10 = 1 << ((byte)iVar6 & 0x1f) & *(uint *)(uVar4 + 4 + (iVar6 >> 5) * 4);
        if ((*(uint *)(uVar4 + 4 + (iVar8 >> 5) * 4) & 1 << ((byte)iVar8 & 0x1f)) != 0) {
          if (uVar10 != 0) {
            puVar2 = (uint *)(uVar4 + 4 + (iVar9 + 1 >> 5) * 4);
            *puVar2 = *puVar2 | 1 << ((byte)(iVar9 + 1) & 0x1f);
          }
          if (uVar7 != 0) {
            puVar2 = (uint *)(uVar4 + 4 + (iVar9 >> 5) * 4);
            *puVar2 = *puVar2 | 1 << ((byte)iVar9 & 0x1f);
          }
        }
        if ((*(uint *)(uVar4 + 4 + (iVar8 + 1 >> 5) * 4) & 1 << ((byte)(iVar8 + 1) & 0x1f)) != 0) {
          if (uVar10 != 0) {
            iVar8 = iVar9 + -1 >> 5;
            *(uint *)(uVar4 + 4 + iVar8 * 4) =
                 *(uint *)(uVar4 + 4 + iVar8 * 4) | 1 << ((byte)(iVar9 + -1) & 0x1f);
          }
          if (uVar7 != 0) {
            iVar8 = iVar9 + -2 >> 5;
            *(uint *)(uVar4 + 4 + iVar8 * 4) =
                 *(uint *)(uVar4 + 4 + iVar8 * 4) | 1 << ((byte)(iVar9 + -2) & 0x1f);
          }
        }
        local_14 = local_14 + 1;
        iVar9 = iVar9 + 4;
      } while (local_14 < *param_2);
    }
  }
  return;
}



void __cdecl FUN_00414c80(uint *param_1,int param_2)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  bVar1 = false;
  iVar4 = 0;
  iVar5 = 0;
  puVar2 = param_1;
  if (0 < DAT_00435528) {
    do {
      if (*(int *)(param_2 + iVar5 * 4) == 0) {
        if (bVar1) {
          param_1 = FUN_00418250((short *)param_1,(int)puVar2 - iVar3,iVar4);
          bVar1 = false;
          iVar3 = iVar3 + iVar4;
        }
      }
      else if (bVar1) {
        iVar4 = iVar4 + *(int *)(DAT_00435534 + iVar5 * 4);
      }
      else {
        bVar1 = true;
        puVar2 = *(uint **)(DAT_0043552c + iVar5 * 4);
        iVar4 = *(int *)(DAT_00435534 + iVar5 * 4);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00435528);
    if (bVar1) {
      FUN_00418250((short *)param_1,(int)puVar2 - iVar3,iVar4);
    }
  }
  return;
}



void __cdecl FUN_00414d10(uint *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  puVar1 = FUN_00414eb0(param_1,param_2);
  if (DAT_004353d0 != 0) {
    FUN_0041b470(&DAT_00430f6c);
    iVar2 = 0;
    if (0 < DAT_00435528) {
      do {
        iVar2 = iVar2 + 1;
        FUN_0041b470(&DAT_00430f74);
      } while (iVar2 < DAT_00435528);
    }
    FUN_0041b470(&DAT_00430f7c);
    iVar2 = 0;
    if (0 < DAT_00435528) {
      do {
        iVar2 = iVar2 + 1;
        FUN_0041b470(&DAT_00430f80);
        iVar4 = 0;
        if (0 < DAT_00435528) {
          do {
            FUN_0041b470(&DAT_00430f88);
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_00435528);
        }
        FUN_0041b470(&DAT_00430f90);
      } while (iVar2 < DAT_00435528);
    }
  }
  puVar5 = param_1 + 6;
  if (DAT_00435528 < 0xf) {
    uVar3 = FUN_00415410(puVar1);
    *puVar5 = uVar3;
  }
  else {
    FUN_00415260((int *)puVar1,puVar5);
  }
  FUN_0041b470(&DAT_00430f94);
  FUN_00415210((int *)*puVar5);
  iVar2 = 0;
  puVar5 = puVar1;
  if (0 < DAT_00435528) {
    do {
      if (*puVar5 != 0) {
        FUN_0041b8c0(*puVar5);
        *puVar5 = 0;
      }
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar2 < DAT_00435528);
  }
  if (puVar1 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar1);
  }
  FUN_00414660(param_1);
  FUN_0041b360();
  puVar1 = FUN_0040ac70((uint *)*param_1,param_1[1],(short *)param_1[2]);
  *param_1 = (uint)puVar1;
  if (DAT_004353d0 != 0) {
    FUN_0041b360();
    FUN_00408b70(*param_1);
  }
  return;
}



uint * __cdecl FUN_00414eb0(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_20;
  int local_14;
  int local_10;
  uint *local_c;
  uint local_8;
  uint local_4;
  
  puVar1 = FUN_0040a880(1,DAT_00435528 * 4);
  iVar9 = 0;
  puVar3 = puVar1;
  if (0 < DAT_00435528) {
    do {
      puVar2 = FUN_0040a880(1,DAT_00435528 * 4);
      *puVar3 = (uint)puVar2;
      iVar9 = iVar9 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar9 < DAT_00435528);
  }
  iVar10 = 0;
  iVar9 = DAT_00435528;
  puVar3 = puVar1;
  if (0 < DAT_00435528) {
    do {
      iVar8 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = iVar8 + 1;
          *(undefined4 *)((*puVar3 - 4) + iVar8 * 4) = 0;
          iVar9 = DAT_00435528;
        } while (iVar8 < DAT_00435528);
      }
      iVar10 = iVar10 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar10 < iVar9);
  }
  puVar3 = FUN_00415bc0(1);
  local_20 = 0;
  param_1[6] = (uint)puVar3;
  *puVar3 = 1;
  iVar9 = DAT_00435528;
  uVar4 = param_2;
  uVar6 = param_2;
  if (DAT_00435528 != 1 && -1 < DAT_00435528 + -1) {
    do {
      iVar10 = local_20 + 1;
      iVar8 = iVar10;
      if (iVar10 < iVar9) {
        do {
          if (0 < (int)param_2) {
            uVar4 = FUN_00417a20(*param_1);
            local_8 = FUN_00417a20(param_1[1]);
            local_4 = FUN_00417a20(param_1[2]);
            local_14 = DAT_00435528;
            local_10 = DAT_00435524;
            local_c = FUN_0040a880(1,DAT_00435524 * 4);
            iVar9 = 0;
            if (0 < DAT_00435524) {
              do {
                iVar5 = iVar9 + 1;
                local_c[iVar9] = DAT_00435534[iVar9];
                iVar9 = iVar5;
              } while (iVar5 < DAT_00435524);
            }
            **(int **)(param_1[6] + 4) = iVar10;
            **(int **)(param_1[6] + 8) = iVar8 + 1;
            FUN_00414670(param_1,0);
          }
          switch(param_2) {
          case 0:
            if (DAT_00435520 < 0x21) {
              iVar9 = 2;
            }
            else {
              iVar9 = (DAT_00435520 + -1 >> 5) + 2;
            }
            iVar5 = DAT_00435520;
            puVar3 = FUN_0040a880(1,iVar9 * 4);
            puVar2 = (uint *)FUN_00417140((int *)puVar3,iVar5);
            FUN_00417240(puVar2,*(uint **)(DAT_00435548 + local_20 * 4),
                         *(int *)(DAT_00435548 + iVar8 * 4));
            puVar3 = puVar2;
            psVar7 = (short *)FUN_00417a20(*param_1);
            puVar3 = FUN_004046d0(psVar7,puVar3);
            uVar6 = *(int *)(*param_1 + 0x10) - puVar3[4];
            FUN_00417a40((short *)puVar3);
            if (puVar2 != (uint *)0x0) {
              FUN_0041b8c0((int)puVar2);
            }
            break;
          case 1:
            psVar7 = (short *)FUN_004163f0((uint *)*param_1,param_1[1]);
            *param_1 = (uint)psVar7;
            puVar3 = FUN_0040b8a0(psVar7,param_1[2],0);
            *param_1 = (uint)puVar3;
            uVar6 = FUN_0040e9b0((int *)puVar3,(short *)param_1[1]);
            *param_1 = uVar6;
            uVar6 = *(int *)(uVar4 + 0x10) - *(int *)(uVar6 + 0x10);
            break;
          case 2:
            puVar3 = FUN_0040ac70((uint *)*param_1,param_1[1],(short *)param_1[2]);
            *param_1 = (uint)puVar3;
            uVar6 = *(int *)(uVar4 + 0x10) - puVar3[4];
            break;
          case 3:
            uVar6 = FUN_0040b380(*param_1,param_1[1],param_1[2],(short *)0x1);
            *param_1 = uVar6;
            uVar6 = *(int *)(uVar4 + 0x10) - *(int *)(uVar6 + 0x10);
          }
          *(uint *)(puVar1[local_20] + iVar8 * 4) = uVar6;
          if (0 < (int)param_2) {
            FUN_00405270();
            if (DAT_00435534 != (uint *)0x0) {
              FUN_0041b8c0((int)DAT_00435534);
            }
            DAT_00435528 = local_14;
            DAT_00435524 = local_10;
            DAT_00435534 = local_c;
            FUN_00404e20();
            FUN_00417a40((short *)*param_1);
            FUN_00417a40((short *)param_1[1]);
            FUN_00417a40((short *)param_1[2]);
            *param_1 = uVar4;
            param_1[1] = local_8;
            param_1[2] = local_4;
          }
          iVar8 = iVar8 + 1;
          iVar9 = DAT_00435528;
        } while (iVar8 < DAT_00435528);
      }
      local_20 = iVar10;
    } while (iVar10 < iVar9 + -1);
  }
  FUN_00415c50(param_1[6]);
  param_1[6] = 0;
  return puVar1;
}



void __cdecl FUN_00415210(int *param_1)

{
  int iVar1;
  
  FUN_0041b470((byte *)s_pair_is_00430fa4);
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      FUN_0041b470((byte *)s___d__d__00430fac);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  FUN_0041b470(&DAT_00430fb8);
  return;
}



int __cdecl FUN_00415260(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *local_10;
  undefined4 *local_8;
  
  puVar3 = FUN_00415bc0(DAT_00435528);
  if (DAT_00435528 < 0x21) {
    iVar4 = 2;
  }
  else {
    iVar4 = (DAT_00435528 + -1 >> 5) + 2;
  }
  iVar6 = DAT_00435528;
  puVar5 = FUN_0040a880(1,iVar4 * 4);
  puVar5 = (uint *)FUN_00417170((int *)puVar5,iVar6);
  iVar4 = 0;
  iVar6 = FUN_00417030(puVar5);
  puVar8 = param_2;
  while (1 < iVar6) {
    iVar6 = -1;
    puVar7 = (undefined4 *)0x0;
    if (0 < DAT_00435528) {
      local_10 = param_1;
      do {
        puVar2 = puVar7;
        if ((puVar5[((int)puVar7 >> 5) + 1] & 1 << ((byte)puVar7 & 0x1f)) != 0) {
          while (puVar2 = (undefined4 *)((int)puVar2 + 1), (int)puVar2 < DAT_00435528) {
            if (((puVar5[((int)puVar2 >> 5) + 1] & 1 << ((byte)puVar2 & 0x1f)) != 0) &&
               (iVar1 = *(int *)(*local_10 + (int)puVar2 * 4), iVar6 < iVar1)) {
              puVar8 = puVar7;
              iVar6 = iVar1;
              local_8 = puVar2;
            }
          }
        }
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        local_10 = local_10 + 1;
      } while ((int)puVar7 < DAT_00435528);
    }
    *(int *)(puVar3[1] + *puVar3 * 4) = (int)puVar8 + 1;
    *(int *)(puVar3[2] + *puVar3 * 4) = (int)local_8 + 1;
    *puVar3 = *puVar3 + 1;
    puVar5[((int)puVar8 >> 5) + 1] = puVar5[((int)puVar8 >> 5) + 1] & ~(1 << ((byte)puVar8 & 0x1f));
    puVar5[((int)local_8 >> 5) + 1] =
         puVar5[((int)local_8 >> 5) + 1] & ~(1 << ((byte)local_8 & 0x1f));
    iVar4 = iVar4 + iVar6;
    iVar6 = FUN_00417030(puVar5);
  }
  if (puVar5 == (uint *)0x0) {
    *param_2 = puVar3;
    return iVar4;
  }
  FUN_0041b8c0((int)puVar5);
  *param_2 = puVar3;
  return iVar4;
}



undefined4 __cdecl FUN_00415410(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  DAT_00433234 = 0xffffffff;
  DAT_00433220 = 0;
  DAT_00433238 = param_1;
  puVar1 = FUN_00415bc0(DAT_00435528);
  if (DAT_00435528 < 0x21) {
    iVar2 = 2;
  }
  else {
    iVar2 = (DAT_00435528 + -1 >> 5) + 2;
  }
  iVar4 = DAT_00435528;
  puVar3 = FUN_0040a880(1,iVar2 * 4);
  puVar3 = (uint *)FUN_00417170((int *)puVar3,iVar4);
  FUN_004159e0(puVar1,DAT_00435528,puVar3,&LAB_004154b0);
  FUN_00415c50((int)puVar1);
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return DAT_00433220;
}



void __cdecl FUN_00415540(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  DAT_00433240 = param_1;
  DAT_00433224 = param_2;
  DAT_00433220 = 0;
  DAT_00433234 = *(int *)(*param_1 + 0x10) + 1;
  DAT_0043323c = 0;
  DAT_00433230 = 0;
  DAT_0043322c = 0;
  DAT_00433228 = 0;
  puVar1 = FUN_00415bc0(DAT_00435528);
  if (DAT_00435528 < 0x21) {
    iVar4 = 2;
  }
  else {
    iVar4 = (DAT_00435528 + -1 >> 5) + 2;
  }
  iVar5 = DAT_00435528;
  iVar6 = DAT_00435528;
  puVar2 = FUN_0040a880(1,iVar4 << 2);
  piVar3 = (int *)FUN_00417140((int *)puVar2,iVar5);
  puVar2 = (uint *)FUN_00417170(piVar3,iVar6);
  FUN_004159e0(puVar1,DAT_00435528,puVar2,&LAB_00415660);
  FUN_00415c50((int)puVar1);
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  param_1[6] = DAT_00433220;
  param_1[5] = DAT_0043323c;
  FUN_00414660(param_1);
  FUN_0041b470(&DAT_00430fc8);
  FUN_00415210((int *)param_1[6]);
  FUN_00417a40((short *)*param_1);
  FUN_00417a40((short *)param_1[1]);
  FUN_00417a40((short *)param_1[2]);
  *param_1 = DAT_00433228;
  param_1[1] = DAT_0043322c;
  param_1[2] = DAT_00433230;
  return;
}



void __cdecl FUN_004159e0(uint *param_1,int param_2,uint *param_3,undefined *param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  
  iVar3 = FUN_00417030(param_3);
  if (iVar3 < 2) {
    (*(code *)param_4)(param_1);
    return;
  }
  puVar4 = (uint *)FUN_00415c00(param_1,param_2);
  uVar5 = (*param_3 & 0x3ff) * 0x20;
  if (uVar5 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = (uVar5 - 1 >> 5) + 2;
  }
  puVar7 = param_3;
  puVar6 = FUN_0040a880(1,iVar3 * 4);
  puVar7 = (uint *)FUN_004171c0((int)puVar6,puVar7);
  puVar6 = (uint *)0x0;
  param_1 = (uint *)0x0;
  if (0 < param_2) {
    do {
      param_1 = puVar6;
      if ((param_3[((int)puVar6 >> 5) + 1] & 1 << ((byte)puVar6 & 0x1f)) != 0) break;
      puVar6 = (uint *)((int)puVar6 + 1);
      param_1 = puVar6;
    } while ((int)puVar6 < param_2);
  }
  iVar3 = (int)param_1 >> 5;
  puVar6 = param_1;
  while (puVar2 = puVar6, puVar6 = (uint *)((int)puVar2 + 1), (int)puVar6 < param_2) {
    uVar5 = 1 << ((byte)puVar6 & 0x1f);
    iVar9 = (int)puVar6 >> 5;
    if ((param_3[iVar9 + 1] & uVar5) != 0) {
      uVar8 = 1 << ((byte)param_1 & 0x1f);
      puVar1 = puVar7 + iVar3 + 1;
      *puVar1 = puVar7[iVar3 + 1] & ~uVar8;
      puVar7[iVar9 + 1] = puVar7[iVar9 + 1] & ~uVar5;
      *(int *)(puVar4[1] + *puVar4 * 4) = (int)param_1 + 1;
      *(int *)(puVar4[2] + *puVar4 * 4) = (int)puVar2 + 2;
      *puVar4 = *puVar4 + 1;
      FUN_004159e0(puVar4,param_2,puVar7,param_4);
      *puVar4 = *puVar4 - 1;
      *puVar1 = *puVar1 | uVar8;
      puVar7[iVar9 + 1] = puVar7[iVar9 + 1] | uVar5;
    }
  }
  uVar5 = FUN_00417030(param_3);
  uVar5 = uVar5 & 0x80000001;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
  }
  if (uVar5 == 1) {
    puVar7[iVar3 + 1] = puVar7[iVar3 + 1] & ~(1 << ((byte)param_1 & 0x1f));
    FUN_004159e0(puVar4,param_2,puVar7,param_4);
  }
  FUN_00415c50((int)puVar4);
  if (puVar7 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar7);
  }
  return;
}



uint * __cdecl FUN_00415bc0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = FUN_0040a880(1,0xc);
  *puVar1 = 0;
  puVar2 = FUN_0040a880(1,param_1 * 4);
  puVar1[1] = (uint)puVar2;
  puVar2 = FUN_0040a880(1,param_1 * 4);
  puVar1[2] = (uint)puVar2;
  return puVar1;
}



void __cdecl FUN_00415c00(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = FUN_00415bc0(param_2);
  *puVar1 = *param_1;
  iVar2 = 0;
  if (0 < (int)*param_1) {
    do {
      *(undefined4 *)(puVar1[1] + iVar2 * 4) = *(undefined4 *)(param_1[1] + iVar2 * 4);
      *(undefined4 *)(puVar1[2] + iVar2 * 4) = *(undefined4 *)(param_1[2] + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)*param_1);
  }
  return;
}



void __cdecl FUN_00415c50(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0041b8c0(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0041b8c0(*(int *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (param_1 != 0) {
    FUN_0041b8c0(param_1);
  }
  return;
}



undefined4 __cdecl FUN_00415ca0(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_4;
  
  piVar6 = param_1;
  if (param_1[6] == 0) {
    return 0;
  }
  for (iVar4 = param_1[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x14)) {
    *(undefined4 *)(iVar4 + 8) = 0;
  }
  for (iVar4 = param_1[7]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x14)) {
    *(undefined4 *)(iVar4 + 8) = 0;
  }
  piVar1 = param_1 + 4;
  local_4 = 0;
  param_1 = (int *)0x0;
  iVar4 = FUN_00415d80(piVar6,*piVar1,&local_4,(int *)&param_1);
  if (iVar4 == 0) {
    uVar5 = FUN_00411d20();
    puVar2 = param_2;
    *param_2 = uVar5;
    uVar5 = FUN_00411d20();
    puVar3 = param_3;
    *param_3 = uVar5;
    for (iVar4 = piVar6[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x14)) {
      if (*(int *)(iVar4 + 8) == 0) {
        piVar6 = (int *)*puVar3;
      }
      else {
        piVar6 = (int *)*puVar2;
      }
      FUN_00415d50(piVar6,iVar4);
    }
    return 1;
  }
  return 0;
}



void __cdecl FUN_00415d50(int *param_1,int param_2)

{
  uint *puVar1;
  
  for (puVar1 = *(uint **)(param_2 + 0xc); puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[4]) {
    FUN_00411f90(param_1,*puVar1,puVar1[1]);
  }
  return;
}



undefined4 __cdecl FUN_00415d80(int *param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_2 + 8) = 1;
    iVar1 = *param_3;
    *param_3 = iVar1 + 1;
    if (iVar1 + 1 == param_1[6]) {
      return 1;
    }
    for (iVar1 = *(int *)(param_2 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      iVar2 = *(int *)(iVar1 + 4);
      if ((iVar2 < 0) || (param_1[3] <= iVar2)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1[2] + iVar2 * 4);
      }
      if ((*(int *)(iVar2 + 8) == 0) &&
         (iVar2 = FUN_00415e00(param_1,iVar2,param_3,param_4), iVar2 != 0)) {
        return 1;
      }
    }
  }
  return 0;
}



undefined4 __cdecl FUN_00415e00(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_2 + 8) = 1;
    iVar2 = *param_4;
    *param_4 = iVar2 + 1;
    if (iVar2 + 1 == param_1[9]) {
      return 1;
    }
    for (piVar1 = *(int **)(param_2 + 0xc); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      iVar2 = *piVar1;
      if ((iVar2 < 0) || (param_1[1] <= iVar2)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*param_1 + iVar2 * 4);
      }
      if ((*(int *)(iVar2 + 8) == 0) &&
         (iVar2 = FUN_00415d80(param_1,iVar2,param_3,param_4), iVar2 != 0)) {
        return 1;
      }
    }
  }
  return 0;
}



int * __cdecl FUN_00415e80(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  
  piVar1 = param_1;
  iVar2 = FUN_00415fa0(param_1,(int *)&param_1);
  if (iVar2 == 2) {
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar7 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar2 * 4);
    puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar7);
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar7 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar2 * 4);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,iVar7);
    iVar2 = FUN_00402800(piVar1,puVar3,puVar4,1);
    piVar5 = (int *)FUN_00402360(piVar1,(uint)puVar3,iVar2);
    puVar6 = (uint *)FUN_00415e80(piVar5);
    piVar5 = (int *)FUN_00402360(piVar1,(uint)puVar4,iVar2);
    piVar5 = FUN_00415e80(piVar5);
    param_1 = (int *)FUN_00416200(puVar6,(uint)piVar5,(int *)puVar3,(int)puVar4);
    if (puVar3 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar3);
    }
    if (puVar4 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar4);
    }
    if (*piVar1 != 0) {
      FUN_0041b8c0(*piVar1);
      *piVar1 = 0;
    }
    if (piVar1 != (int *)0x0) {
      FUN_0041b8c0((int)piVar1);
    }
  }
  return param_1;
}



undefined4 __cdecl FUN_00415fa0(int *param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  uint unaff_EDI;
  int *piVar7;
  
  puVar1 = (uint *)*param_1;
  piVar6 = param_1 + 2;
  if (param_1[2] == 0) {
    puVar1 = FUN_00417930(0,DAT_00435520,unaff_EDI);
    *param_2 = (int)puVar1;
    iVar3 = *param_1;
  }
  else {
    if (param_1[3] == 0) {
      puVar2 = (uint *)FUN_00417240(puVar1,puVar1,param_1[2]);
LAB_00416010:
      puVar1 = FUN_00417930(1,DAT_00435520,(uint)puVar2);
      puVar1 = (uint *)FUN_00417b00((int)puVar1,puVar2);
    }
    else {
      puVar2 = (uint *)*piVar6;
      piVar7 = piVar6;
      while (puVar2 != (uint *)0x0) {
        piVar7 = piVar7 + 1;
        iVar3 = FUN_00418630(puVar2,(int)puVar1);
        puVar2 = DAT_00435550;
        if (iVar3 != 0) goto LAB_00416010;
        puVar2 = (uint *)*piVar7;
      }
      uVar4 = (*puVar1 & 0x3ff) * 0x20;
      if (uVar4 < 0x21) {
        iVar3 = 2;
      }
      else {
        iVar3 = (uVar4 - 1 >> 5) + 2;
      }
      puVar2 = puVar1;
      puVar5 = FUN_0040a880(1,iVar3 * 4);
      puVar2 = (uint *)FUN_004171c0((int)puVar5,puVar2);
      iVar3 = *piVar6;
      while (iVar3 != 0) {
        piVar6 = piVar6 + 1;
        FUN_00417240(puVar2,puVar2,iVar3);
        iVar3 = *piVar6;
      }
      iVar3 = FUN_004174c0(puVar2,(int)DAT_00435550);
      if (iVar3 == 0) {
        if ((int)DAT_00435520 < 0x21) {
          iVar3 = 2;
        }
        else {
          iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
        }
        uVar4 = DAT_00435520;
        puVar5 = FUN_0040a880(1,iVar3 * 4);
        puVar5 = (uint *)FUN_00417140((int *)puVar5,uVar4);
        FUN_00417290(puVar5,DAT_00435550,(int)puVar2);
        FUN_00417240(puVar1,puVar1,(int)puVar5);
        if (puVar5 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar5);
        }
        piVar6 = FUN_00415e80(param_1);
        puVar5 = (uint *)piVar6[6];
        puVar1 = puVar5 + piVar6[4] * piVar6[1];
        for (; puVar5 < puVar1; puVar5 = puVar5 + piVar6[1]) {
          FUN_004171f0(puVar5,puVar5,(int)puVar2);
        }
        *param_2 = (int)piVar6;
        if (puVar2 == (uint *)0x0) {
          return 1;
        }
        FUN_0041b8c0((int)puVar2);
        return 1;
      }
      if (puVar2 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar2);
      }
      FUN_004024a0(param_1);
      if (DAT_00435590 == 1) {
        puVar1 = DAT_00435550;
        puVar2 = FUN_00417930(1,DAT_00435520,(uint)DAT_00435550);
        iVar3 = FUN_00417b00((int)puVar2,puVar1);
        *param_2 = iVar3;
        iVar3 = *param_1;
        goto joined_r0x004161ea;
      }
      if (DAT_00435594 != DAT_00435590) {
        return 2;
      }
      puVar1 = FUN_00402bf0(param_1);
      puVar1 = FUN_004044e0((short *)puVar1);
    }
    *param_2 = (int)puVar1;
    iVar3 = *param_1;
  }
joined_r0x004161ea:
  if (iVar3 != 0) {
    FUN_0041b8c0(iVar3);
    *param_1 = 0;
  }
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return 1;
}



void __cdecl FUN_00416200(uint *param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  
  psVar5 = (short *)FUN_00416340((int)param_1,(int)param_3);
  psVar6 = (short *)FUN_00416340(param_2,param_4);
  iVar10 = 500;
  puVar7 = FUN_00417930(500,*(uint *)(psVar5 + 4),param_2);
  param_3 = (int *)puVar7[6];
  puVar8 = FUN_004177d0((int)psVar5,(int)psVar6,iVar10);
  param_1 = FUN_004044e0((short *)puVar8);
  uVar2 = *(uint *)(psVar5 + 0xc);
  uVar1 = uVar2 + *(int *)(psVar5 + 8) * *(int *)(psVar5 + 2) * 4;
  for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(psVar5 + 2) * 4) {
    puVar3 = *(uint **)(psVar6 + 0xc);
    puVar8 = puVar3 + *(int *)(psVar6 + 2) * *(int *)(psVar6 + 8);
    for (; puVar3 < puVar8; puVar3 = puVar3 + *(int *)(psVar6 + 2)) {
      iVar10 = FUN_00418790(uVar2,puVar3);
      if (iVar10 == 1) {
        FUN_00418c70(param_3,uVar2,puVar3);
        uVar4 = puVar7[4];
        puVar7[4] = uVar4 + 1;
        if ((int)(uVar4 + 1) < (int)puVar7[3]) {
          param_3 = param_3 + puVar7[1];
        }
        else {
          puVar9 = FUN_004044e0((short *)puVar7);
          puVar7 = param_1;
          param_1 = FUN_00404630((short *)param_1,(short *)puVar9);
          puVar7 = FUN_00417930(500,*(uint *)(psVar5 + 4),(uint)puVar7);
          param_3 = (int *)puVar7[6];
        }
      }
    }
  }
  FUN_00417a40(psVar5);
  FUN_00417a40(psVar6);
  puVar7 = FUN_004044e0((short *)puVar7);
  FUN_00404630((short *)param_1,(short *)puVar7);
  return;
}



void __cdecl FUN_00416340(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    FUN_004171f0(puVar2,puVar2,param_2);
    iVar3 = FUN_00418980((int)puVar2,DAT_00435550);
    if (iVar3 < 1) {
      uVar4 = *puVar2 | 0x2000;
    }
    else {
      uVar4 = *puVar2 & 0xffffdfff;
    }
    *puVar2 = uVar4;
  }
  FUN_004176e0(param_1);
  return;
}



undefined * FUN_004163a0(undefined4 param_1)

{
  FUN_0041ec4a(&DAT_00433244,(byte *)s__ld__02ld_sec_0043105c);
  return &DAT_00433244;
}



void __cdecl FUN_004163f0(uint *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  
  if (DAT_00435404 == 0) {
    if (DAT_0043106c == 0) {
      puVar3 = FUN_00407d40((short *)param_1,&LAB_004191c0);
    }
    else {
      puVar3 = FUN_00407e10(param_1);
    }
    DAT_0043106c = (uint)(DAT_0043106c == 0);
  }
  else {
    puVar3 = (uint *)FUN_00407f20((int)param_1);
  }
  puVar4 = FUN_00402a00((int)puVar3,param_2);
  puVar2 = (uint *)puVar3[6];
  puVar1 = puVar2 + puVar3[4] * puVar3[1];
  for (; puVar2 < puVar1; puVar2 = puVar2 + puVar3[1]) {
    puVar5 = (uint *)FUN_00416550(puVar4,puVar2);
    iVar6 = FUN_004174c0(puVar5,(int)puVar2);
    if (iVar6 == 0) {
      if (((byte)DAT_00435400 & 0x40) != 0) {
        iVar6 = FUN_0041b360();
        FUN_004163a0(iVar6);
        FUN_00409a80((int)puVar5);
        FUN_00409a60((int)puVar2);
        FUN_0041b470((byte *)s_REDUCE___s_to__s__s_00431070);
      }
      FUN_004171c0((int)puVar2,puVar5);
      *puVar2 = *puVar2 & 0xffff7fff;
      iVar6 = FUN_00417440(puVar5);
      if (iVar6 == 0) {
        uVar7 = *puVar2 | 0x2000;
      }
      else {
        uVar7 = *puVar2 & 0xffffdfff;
      }
    }
    else {
      uVar7 = *puVar2 | 0xa000;
    }
    *puVar2 = uVar7;
    if (puVar5 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar5);
    }
  }
  if (*puVar4 != 0) {
    FUN_0041b8c0(*puVar4);
    *puVar4 = 0;
  }
  if (puVar4 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar4);
  }
  FUN_004176e0((int)puVar3);
  return;
}



void __cdecl FUN_00416550(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)FUN_00402260(param_1,param_2);
  puVar1 = FUN_00416580(puVar1);
  FUN_004171f0(puVar1,puVar1,(int)param_2);
  return;
}



uint * __cdecl FUN_00416580(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  
  puVar1 = param_1;
  iVar2 = DAT_0043326c;
  if (((byte)DAT_00435400 & 0x80) != 0) {
    DAT_0043326c = DAT_0043326c + 1;
    FUN_00409aa0((int *)param_1,&DAT_00431088,iVar2);
  }
  iVar2 = FUN_00416790((int *)puVar1,(int *)&param_1);
  if (iVar2 == 2) {
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar7 = DAT_00435520;
    puVar3 = FUN_0040a880(1,iVar2 * 4);
    puVar3 = (uint *)FUN_00417140((int *)puVar3,iVar7);
    if (DAT_00435520 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (DAT_00435520 + -1 >> 5) + 2;
    }
    iVar7 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar2 * 4);
    puVar5 = (uint *)FUN_00417140((int *)puVar4,iVar7);
    iVar2 = FUN_00402800((int *)puVar1,puVar3,puVar5,0x80);
    puVar4 = puVar3;
    puVar6 = (uint *)FUN_00402360(puVar1,(uint)puVar5,iVar2);
    puVar6 = FUN_00416580(puVar6);
    puVar3 = (uint *)FUN_00402360(puVar1,(uint)puVar3,iVar2);
    puVar3 = FUN_00416580(puVar3);
    param_1 = FUN_004166e0(puVar3,puVar6,(int)puVar4,(int)puVar5);
    if (*puVar1 != 0) {
      FUN_0041b8c0(*puVar1);
      *puVar1 = 0;
    }
    if (puVar1 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar1);
    }
  }
  if (((byte)DAT_00435400 & 0x80) != 0) {
    DAT_0043326c = DAT_0043326c + -1;
    FUN_00409a60((int)param_1);
    FUN_0041b470((byte *)s_SCCC__d___result_is__s_00431090);
  }
  return param_1;
}



uint * __cdecl FUN_004166e0(uint *param_1,uint *param_2,int param_3,int param_4)

{
  FUN_004171f0(param_1,param_1,param_3);
  FUN_004171f0(param_2,param_2,param_4);
  FUN_00417240(param_1,param_1,(int)param_2);
  if (param_2 != (uint *)0x0) {
    FUN_0041b8c0((int)param_2);
  }
  if (param_3 != 0) {
    FUN_0041b8c0(param_3);
  }
  if (param_4 != 0) {
    FUN_0041b8c0(param_4);
  }
  return param_1;
}



uint * __cdecl FUN_00416740(uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)*DAT_0043554c;
  iVar2 = FUN_00418e20(param_2);
  if (-1 < iVar2) {
    FUN_004172e0(puVar1,param_2,*(int *)(DAT_00435548 + iVar2 * 4));
    FUN_004171f0(param_1,param_1,(int)puVar1);
    return param_1;
  }
  return param_1;
}



undefined4 __cdecl FUN_00416790(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  uint *local_8;
  uint *local_4;
  
  puVar6 = (uint *)param_1;
  local_4 = *(uint **)(DAT_0043554c + 4);
  puVar4 = (uint *)*param_1;
  piVar8 = param_1 + 2;
  if (param_1[2] == 0) {
    uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
    if (uVar1 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (uVar1 - 1 >> 5) + 2;
    }
    puVar4 = DAT_00435550;
    puVar3 = FUN_0040a880(1,iVar2 * 4);
    iVar2 = FUN_004171c0((int)puVar3,puVar4);
LAB_004167ef:
    *param_2 = iVar2;
LAB_004167f8:
    iVar2 = *puVar6;
joined_r0x00416a23:
    if (iVar2 != 0) {
      FUN_0041b8c0(iVar2);
      *puVar6 = 0;
    }
  }
  else {
    puVar3 = (uint *)*piVar8;
    piVar9 = piVar8;
    while (puVar3 != (uint *)0x0) {
      piVar9 = piVar9 + 1;
      iVar2 = FUN_00418630(puVar3,(int)puVar4);
      if (iVar2 != 0) {
        if (DAT_00435520 < 0x21) {
          iVar2 = 2;
        }
        else {
          iVar2 = (DAT_00435520 + -1 >> 5) + 2;
        }
        iVar10 = DAT_00435520;
        puVar4 = FUN_0040a880(1,iVar2 * 4);
        iVar2 = FUN_00417140((int *)puVar4,iVar10);
        goto LAB_004167ef;
      }
      puVar3 = (uint *)*piVar9;
    }
    FUN_004024a0((int *)puVar6);
    if ((DAT_00435594 != DAT_00435590) && (((int *)puVar6)[3] != 0)) {
      uVar1 = (*puVar4 & 0x3ff) * 0x20;
      if (uVar1 < 0x21) {
        iVar2 = 2;
      }
      else {
        iVar2 = (uVar1 - 1 >> 5) + 2;
      }
      puVar3 = FUN_0040a880(1,iVar2 << 2);
      puVar4 = (uint *)FUN_004171c0((int)puVar3,puVar4);
      iVar2 = *piVar8;
      while (iVar2 != 0) {
        piVar8 = piVar8 + 1;
        FUN_00417240(puVar4,puVar4,iVar2);
        iVar2 = *piVar8;
      }
      iVar2 = FUN_004174c0(puVar4,(int)DAT_00435550);
      if (iVar2 == 0) {
        uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
        if (uVar1 < 0x21) {
          iVar2 = 2;
        }
        else {
          iVar2 = (uVar1 - 1 >> 5) + 2;
        }
        puVar3 = DAT_00435550;
        puVar7 = puVar4;
        puVar5 = FUN_0040a880(1,iVar2 * 4);
        puVar3 = (uint *)FUN_004171c0((int)puVar5,puVar3);
        puVar3 = FUN_00416740(puVar3,puVar7);
        piVar8 = param_2;
        *param_2 = (int)puVar3;
        iVar2 = FUN_004174c0(puVar3,(int)DAT_00435550);
        if (iVar2 == 0) {
          uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
          if (uVar1 < 0x21) {
            iVar2 = 2;
          }
          else {
            iVar2 = (uVar1 - 1 >> 5) + 2;
          }
          iVar10 = *piVar8;
          puVar3 = DAT_00435550;
          puVar7 = puVar4;
          puVar5 = FUN_0040a880(1,iVar2 << 2);
          puVar3 = (uint *)FUN_004171c0((int)puVar5,puVar3);
          puVar4 = (uint *)FUN_00402260(puVar6,puVar4);
          puVar4 = FUN_00416580(puVar4);
          puVar4 = FUN_004166e0(puVar4,puVar3,(int)puVar7,iVar10);
          *piVar8 = (int)puVar4;
        }
        else if (puVar4 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar4);
        }
        goto LAB_004167f8;
      }
      if (puVar4 != (uint *)0x0) {
        FUN_0041b8c0((int)puVar4);
      }
      if (DAT_00435590 != 1) {
        if ((((((int *)puVar6)[1] - (int)puVar6 >> 2) + -3) / 2 <=
             *(int *)(DAT_00435584 + DAT_00435598 * 4)) ||
           (iVar2 = FUN_00407ff0(puVar6,(int *)&param_1,(int *)&local_8,DAT_00435400 & 0x80),
           iVar2 == 0)) {
          return 2;
        }
        if (*puVar6 != 0) {
          FUN_0041b8c0(*puVar6);
          *puVar6 = 0;
        }
        if (puVar6 != (uint *)0x0) {
          FUN_0041b8c0((int)puVar6);
        }
        puVar4 = FUN_00416580((uint *)param_1);
        piVar8 = param_2;
        *param_2 = (int)puVar4;
        puVar6 = FUN_00416580(local_8);
        FUN_004171f0((uint *)*piVar8,(uint *)*piVar8,(int)puVar6);
        if (puVar6 == (uint *)0x0) {
          return 1;
        }
        goto LAB_00416b74;
      }
      if (DAT_00435520 < 0x21) {
        iVar2 = 2;
      }
      else {
        iVar2 = (DAT_00435520 + -1 >> 5) + 2;
      }
      iVar10 = DAT_00435520;
      puVar4 = FUN_0040a880(1,iVar2 * 4);
      iVar2 = FUN_00417140((int *)puVar4,iVar10);
      *param_2 = iVar2;
      iVar2 = *puVar6;
      goto joined_r0x00416a23;
    }
    uVar1 = (*DAT_00435550 & 0x3ff) * 0x20;
    if (uVar1 < 0x21) {
      iVar2 = 2;
    }
    else {
      iVar2 = (uVar1 - 1 >> 5) + 2;
    }
    puVar3 = DAT_00435550;
    puVar7 = FUN_0040a880(1,iVar2 * 4);
    iVar2 = FUN_004171c0((int)puVar7,puVar3);
    piVar9 = param_2;
    *param_2 = iVar2;
    puVar3 = (uint *)*piVar8;
    while (puVar3 != (uint *)0x0) {
      piVar8 = piVar8 + 1;
      puVar3 = (uint *)FUN_00417240(local_4,puVar3,(int)puVar4);
      FUN_00416740((uint *)*piVar9,puVar3);
      puVar3 = (uint *)*piVar8;
    }
    if (*puVar6 != 0) {
      FUN_0041b8c0(*puVar6);
      *puVar6 = 0;
    }
  }
  if (puVar6 == (uint *)0x0) {
    return 1;
  }
LAB_00416b74:
  FUN_0041b8c0((int)puVar6);
  return 1;
}



void FUN_00416b90(void)

{
  int iVar1;
  uint *puVar2;
  
  DAT_004330c0 = DAT_004330c0 + 1;
  if (DAT_004330c0 % 100 == 0) {
    DAT_004330c0 = 0;
    iVar1 = FUN_0041b360();
    if (DAT_0042fbb0 < iVar1 - DAT_004330c4) {
      FUN_0040f8b0(2);
    }
  }
  puVar2 = FUN_0040a880(1,0x20);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[4] = 0;
  puVar2[3] = 0;
  puVar2[6] = 0;
  puVar2[5] = 0;
  puVar2[2] = 0;
  puVar2[7] = 0;
  return;
}



void __cdecl FUN_00416c00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x10);
    if (iVar2 != 0) {
      FUN_0041b8c0(iVar2);
    }
  }
  if (param_1 != 0) {
    FUN_0041b8c0(param_1);
  }
  return;
}



int __cdecl FUN_00416c40(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_00416b90();
  for (iVar1 = *(int *)(param_1 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    FUN_00416c70(iVar2,*(uint *)(iVar1 + 4));
  }
  return iVar2;
}



uint * __cdecl FUN_00416c70(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = FUN_0040a880(1,0x1c);
  puVar3[6] = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    puVar3[1] = param_2;
    *(uint **)(param_1 + 0xc) = puVar3;
    *(uint **)(param_1 + 0x10) = puVar3;
    puVar3[4] = 0;
    puVar3[5] = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  if (*(int *)(*(int *)(param_1 + 0x10) + 4) < (int)param_2) {
    puVar3[1] = param_2;
    *(uint **)(*(int *)(param_1 + 0x10) + 0x10) = puVar3;
    puVar3[5] = *(uint *)(param_1 + 0x10);
    *(uint **)(param_1 + 0x10) = puVar3;
    puVar3[4] = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  puVar1 = *(uint **)(param_1 + 0xc);
  uVar2 = puVar1[1];
  if ((int)param_2 < (int)uVar2) {
    puVar3[1] = param_2;
    *(uint **)(*(int *)(param_1 + 0xc) + 0x14) = puVar3;
    puVar3[4] = *(uint *)(param_1 + 0xc);
    *(uint **)(param_1 + 0xc) = puVar3;
    puVar3[5] = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  while ((int)uVar2 < (int)param_2) {
    puVar1 = (uint *)puVar1[4];
    uVar2 = puVar1[1];
  }
  if ((int)param_2 < (int)puVar1[1]) {
    puVar3[1] = param_2;
    uVar2 = puVar1[5];
    *(uint **)(*(int *)(uVar2 + 0x10) + 0x14) = puVar3;
    puVar3[4] = *(uint *)(uVar2 + 0x10);
    *(uint **)(uVar2 + 0x10) = puVar3;
    puVar3[5] = uVar2;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return puVar3;
  }
  if ((puVar3 != puVar1) && (puVar3 != (uint *)0x0)) {
    FUN_0041b8c0((int)puVar3);
  }
  return puVar1;
}



void __cdecl FUN_00416d40(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    while (*(int *)(iVar1 + 4) < param_2) {
      iVar1 = *(int *)(iVar1 + 0x10);
      if (iVar1 == 0) {
        return;
      }
    }
    if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == param_2)) {
      if (*(int *)(iVar1 + 0x14) == 0) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
      }
      else {
        *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      }
      if (*(int *)(iVar1 + 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar1 + 0x14);
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
        FUN_0041b8c0(iVar1);
        return;
      }
      *(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x14) = *(undefined4 *)(iVar1 + 0x14);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      FUN_0041b8c0(iVar1);
    }
  }
  return;
}



undefined4 __cdecl FUN_00416df0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_004330c0 + 1;
  DAT_004330c0 = iVar1 % 100;
  if ((DAT_004330c0 == 0) &&
     (iVar2 = FUN_0041b360(), iVar1 = DAT_004330c0, DAT_0042fbb0 < iVar2 - DAT_004330c4)) {
    FUN_0040f8b0(2);
    iVar1 = DAT_004330c0;
  }
  DAT_004330c0 = iVar1;
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_2 + 0xc);
  while( true ) {
    if (iVar2 == 0) {
      return 1;
    }
    if ((iVar1 == 0) || (*(int *)(iVar2 + 4) < *(int *)(iVar1 + 4))) break;
    if (*(int *)(iVar2 + 4) == *(int *)(iVar1 + 4)) {
      iVar2 = *(int *)(iVar2 + 0x10);
    }
    iVar1 = *(int *)(iVar1 + 0x10);
  }
  return 0;
}



undefined4 __cdecl FUN_00416e70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_2 + 0xc);
  if (iVar2 != 0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      while( true ) {
        if (*(int *)(iVar1 + 4) <= *(int *)(iVar2 + 4)) break;
        iVar2 = *(int *)(iVar2 + 0x10);
        if (iVar2 == 0) {
          return 0;
        }
      }
      if (*(int *)(iVar2 + 4) <= *(int *)(iVar1 + 4)) {
        return 1;
      }
    }
  }
  return 0;
}



int __cdecl FUN_00416f00(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = FUN_00416b90();
  iVar5 = *(int *)(param_2 + 0xc);
  iVar4 = *(int *)(param_1 + 0xc);
  iVar1 = iVar5;
  if (iVar4 != 0) {
    while (iVar1 != 0) {
      while( true ) {
        uVar2 = *(uint *)(iVar4 + 4);
        if ((int)uVar2 < *(int *)(iVar5 + 4)) break;
        if (*(int *)(iVar5 + 4) < (int)uVar2) {
          iVar5 = *(int *)(iVar5 + 0x10);
        }
        else {
          FUN_00416c70(iVar3,uVar2);
          iVar4 = *(int *)(iVar4 + 0x10);
          if (iVar4 == 0) {
            return iVar3;
          }
          iVar5 = *(int *)(iVar5 + 0x10);
        }
        if (iVar5 == 0) {
          return iVar3;
        }
      }
      iVar4 = *(int *)(iVar4 + 0x10);
      iVar1 = iVar4;
    }
  }
  return iVar3;
}



void __cdecl FUN_00416f90(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0x10);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = *(undefined4 *)(param_2 + 0x10);
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x14);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0x10) + 0x14) = *(undefined4 *)(param_2 + 0x14);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  if (param_2 != 0) {
    FUN_0041b8c0(param_2);
  }
  return;
}



int __cdecl FUN_00417010(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    uVar1 = param_1 & 1;
    while (uVar1 == 0) {
      param_1 = param_1 >> 1;
      iVar2 = iVar2 + 1;
      uVar1 = param_1 & 1;
    }
    return iVar2;
  }
  return -1;
}



int __cdecl FUN_00417030(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  
  iVar8 = 0;
  puVar2 = (uint *)(*param_1 & 0x3ff);
  if (puVar2 != (uint *)0x0) {
    puVar7 = param_1 + (int)puVar2;
    param_1 = puVar2;
    do {
      uVar1 = *puVar7;
      if (uVar1 != 0) {
        iVar3 = FUN_0040d180(uVar1 >> 0x10 & 0xff);
        iVar4 = FUN_0040d180(uVar1 >> 0x18);
        iVar5 = FUN_0040d180(uVar1 >> 8 & 0xff);
        iVar6 = FUN_0040d180(uVar1 & 0xff);
        iVar8 = iVar6 + iVar8 + iVar3 + iVar4 + iVar5;
      }
      puVar7 = puVar7 + -1;
      param_1 = (uint *)((int)param_1 + -1);
    } while (param_1 != (uint *)0x0);
    return iVar8;
  }
  return 0;
}



int __cdecl FUN_004170b0(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  puVar1 = (uint *)(*param_1 & 0x3ff);
  if (puVar1 != (uint *)0x0) {
    puVar7 = (uint *)(param_2 + (int)puVar1 * 4);
    iVar8 = (int)param_1 - param_2;
    param_1 = puVar1;
    do {
      uVar6 = *(uint *)(iVar8 + (int)puVar7) & *puVar7;
      if (uVar6 != 0) {
        iVar5 = FUN_0040d180(uVar6 >> 0x10 & 0xff);
        iVar2 = FUN_0040d180(uVar6 >> 0x18);
        iVar3 = FUN_0040d180(uVar6 >> 8 & 0xff);
        iVar4 = FUN_0040d180(uVar6 & 0xff);
        iVar5 = iVar4 + local_4 + iVar5 + iVar2 + iVar3;
        local_4 = iVar5;
      }
      puVar7 = puVar7 + -1;
      param_1 = (uint *)((int)param_1 + -1);
    } while (param_1 != (uint *)0x0);
    return iVar5;
  }
  return 0;
}



void __cdecl FUN_00417140(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 < 0x21) {
    iVar1 = 1;
  }
  else {
    iVar1 = (param_2 + -1 >> 5) + 1;
  }
  *param_1 = iVar1;
  piVar2 = param_1 + iVar1;
  do {
    *piVar2 = 0;
    iVar1 = iVar1 + -1;
    piVar2 = piVar2 + -1;
  } while (0 < iVar1);
  return;
}



void __cdecl FUN_00417170(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 0x21) {
    iVar2 = 1;
  }
  else {
    iVar2 = (param_2 + -1 >> 5) + 1;
  }
  *param_1 = iVar2;
  iVar3 = iVar2 + -1;
  param_1[iVar2] = 0xffffffff >> (-(char)param_2 & 0x1fU);
  if (0 < iVar3) {
    piVar1 = param_1 + iVar3;
    do {
      *piVar1 = -1;
      piVar1 = piVar1 + -1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}



void __cdecl FUN_004171c0(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = *param_2 & 0x3ff;
  puVar2 = (undefined4 *)(param_1 + uVar1 * 4);
  do {
    uVar1 = uVar1 - 1;
    *puVar2 = *(undefined4 *)(((int)param_2 - param_1) + (int)puVar2);
    puVar2 = puVar2 + -1;
  } while (-1 < (int)uVar1);
  return;
}



void __cdecl FUN_004171f0(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar1;
  puVar2 = (uint *)(param_3 + uVar1 * 4);
  do {
    uVar1 = uVar1 - 1;
    *(uint *)(((int)param_1 - param_3) + (int)puVar2) =
         *(uint *)(((int)param_2 - param_3) + (int)puVar2) & *puVar2;
    puVar2 = puVar2 + -1;
  } while (0 < (int)uVar1);
  return;
}



void __cdecl FUN_00417240(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar1;
  puVar2 = (uint *)(param_3 + uVar1 * 4);
  do {
    uVar1 = uVar1 - 1;
    *(uint *)(((int)param_1 - param_3) + (int)puVar2) =
         *(uint *)(((int)param_2 - param_3) + (int)puVar2) | *puVar2;
    puVar2 = puVar2 + -1;
  } while (0 < (int)uVar1);
  return;
}



void __cdecl FUN_00417290(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar1;
  puVar2 = param_2 + uVar1;
  do {
    uVar1 = uVar1 - 1;
    *(uint *)(((int)param_1 - (int)param_2) + (int)puVar2) =
         ~*(uint *)((param_3 - (int)param_2) + (int)puVar2) & *puVar2;
    puVar2 = puVar2 + -1;
  } while (0 < (int)uVar1);
  return;
}



void __cdecl FUN_004172e0(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar1;
  puVar2 = (uint *)(param_3 + uVar1 * 4);
  do {
    uVar1 = uVar1 - 1;
    *(uint *)(((int)param_1 - param_3) + (int)puVar2) =
         *(uint *)(((int)param_2 - param_3) + (int)puVar2) ^ *puVar2;
    puVar2 = puVar2 + -1;
  } while (0 < (int)uVar1);
  return;
}



uint * __cdecl FUN_00417330(uint *param_1,uint *param_2,int param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar3;
  puVar2 = (uint *)(param_4 + uVar3 * 4);
  do {
    uVar1 = *puVar2;
    puVar4 = (uint *)(((int)param_2 - param_4) + (int)puVar2);
    puVar2 = puVar2 + -1;
    uVar3 = uVar3 - 1;
    *(uint *)((int)param_1 + (4 - param_4) + (int)puVar2) =
         *(uint *)((int)puVar4 + (param_3 - (int)param_2)) & ~uVar1 | *puVar4 & uVar1;
  } while (0 < (int)uVar3);
  return param_1;
}



bool __cdecl FUN_004173a0(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar2 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar2;
  puVar3 = (uint *)(param_3 + uVar2 * 4);
  do {
    uVar1 = *(uint *)(((int)param_2 - param_3) + (int)puVar3) & *puVar3;
    uVar4 = uVar4 | uVar1;
    *(uint *)(((int)param_1 - param_3) + (int)puVar3) = uVar1;
    uVar2 = uVar2 - 1;
    puVar3 = puVar3 + -1;
  } while (0 < (int)uVar2);
  return uVar4 != 0;
}



bool __cdecl FUN_004173f0(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar2 = *param_2 & 0x3ff;
  *param_1 = *param_1 & 0xfffffc00 | uVar2;
  puVar3 = (uint *)(param_3 + uVar2 * 4);
  do {
    uVar1 = *(uint *)(((int)param_2 - param_3) + (int)puVar3) | *puVar3;
    uVar4 = uVar4 | uVar1;
    *(uint *)(((int)param_1 - param_3) + (int)puVar3) = uVar1;
    uVar2 = uVar2 - 1;
    puVar3 = puVar3 + -1;
  } while (0 < (int)uVar2);
  return uVar4 != 0;
}



undefined4 __cdecl FUN_00417440(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = *param_1 & 0x3ff;
  uVar1 = param_1[uVar2];
  puVar3 = param_1 + uVar2;
  while( true ) {
    if (uVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 - 1;
    puVar3 = puVar3 + -1;
    if ((int)uVar2 < 1) break;
    uVar1 = *puVar3;
  }
  return 1;
}



undefined4 __cdecl FUN_004174c0(uint *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = *param_1 & 0x3ff;
  piVar2 = (int *)(param_2 + uVar1 * 4);
  if (param_1[uVar1] == *(uint *)(param_2 + uVar1 * 4)) {
    do {
      uVar1 = uVar1 - 1;
      piVar2 = piVar2 + -1;
      if ((int)uVar1 < 1) {
        return 1;
      }
    } while (*(int *)(((int)param_1 - param_2) + (int)piVar2) == *piVar2);
  }
  return 0;
}



undefined4 __cdecl FUN_00417510(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_1 & 0x3ff;
  puVar2 = (uint *)(param_2 + uVar1 * 4);
  if ((*(uint *)(param_2 + uVar1 * 4) & param_1[uVar1]) == 0) {
    do {
      uVar1 = uVar1 - 1;
      puVar2 = puVar2 + -1;
      if ((int)uVar1 < 1) {
        return 1;
      }
    } while ((*puVar2 & *(uint *)(((int)param_1 - param_2) + (int)puVar2)) == 0);
  }
  return 0;
}



undefined4 __cdecl FUN_00417560(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_1 & 0x3ff;
  puVar2 = param_1 + uVar1;
  if ((param_1[uVar1] & ~*(uint *)(param_2 + uVar1 * 4)) == 0) {
    do {
      uVar1 = uVar1 - 1;
      puVar2 = puVar2 + -1;
      if ((int)uVar1 < 1) {
        return 1;
      }
    } while ((*puVar2 & ~*(uint *)((param_2 - (int)param_1) + (int)puVar2)) == 0);
  }
  return 0;
}



uint * __cdecl FUN_004175b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  if (iVar5 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = (iVar5 + -1 >> 5) + 2;
  }
  puVar4 = FUN_0040a880(1,iVar3 << 2);
  puVar4 = (uint *)FUN_00417140((int *)puVar4,iVar5);
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar1 = uVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(param_1 + 4) * 4) {
    FUN_00417240(puVar4,puVar4,uVar2);
  }
  return puVar4;
}



uint * __cdecl FUN_00417620(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)(param_1 + 8);
  if (iVar6 < 0x21) {
    iVar5 = 2;
  }
  else {
    iVar5 = (iVar6 + -1 >> 5) + 2;
  }
  iVar7 = iVar6;
  puVar3 = FUN_0040a880(1,iVar5 * 4);
  piVar4 = (int *)FUN_00417140((int *)puVar3,iVar6);
  puVar3 = (uint *)FUN_00417170(piVar4,iVar7);
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar1 = uVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar2 < uVar1; uVar2 = uVar2 + *(int *)(param_1 + 4) * 4) {
    FUN_004171f0(puVar3,puVar3,uVar2);
  }
  return puVar3;
}



void __cdecl FUN_004176a0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    *puVar2 = *puVar2 | 0x2000;
  }
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  return;
}



int __cdecl FUN_004176e0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  iVar3 = DAT_004330c0 + 1;
  DAT_004330c0 = iVar3 % 100;
  if ((DAT_004330c0 == 0) &&
     (iVar4 = FUN_0041b360(), iVar3 = DAT_004330c0, DAT_0042fbb0 < iVar4 - DAT_004330c4)) {
    FUN_0040f8b0(2);
    iVar3 = DAT_004330c0;
  }
  DAT_004330c0 = iVar3;
  iVar3 = *(int *)(param_1 + 4);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + iVar3 * *(int *)(param_1 + 0x10);
  puVar5 = puVar2;
  for (; puVar2 < puVar1; puVar2 = puVar2 + iVar3) {
    if ((*puVar2 & 0x2000) == 0) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
    else {
      if (puVar5 != puVar2) {
        FUN_004171c0((int)puVar5,puVar2);
      }
      iVar3 = *(int *)(param_1 + 4);
      puVar5 = puVar5 + iVar3;
    }
  }
  return param_1;
}



int __cdecl FUN_00417770(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  FUN_004177b0(*(undefined4 **)(param_1 + 0x18),*(undefined4 **)(param_2 + 0x18),
               *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4));
  return param_1;
}



void __cdecl FUN_004177b0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (0 < param_3) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



uint * __cdecl FUN_004177d0(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint unaff_EBP;
  int iVar2;
  uint unaff_EDI;
  
  iVar2 = *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 8) != *(int *)(param_2 + 8)) {
    FUN_00408c40((int *)s_sf_join__sf_size_mismatch_004310ac,unaff_EDI);
  }
  puVar1 = FUN_00417930(*(int *)(param_2 + 0x10) + *(int *)(param_1 + 0x10),*(uint *)(param_1 + 8),
                        unaff_EBP);
  puVar1[4] = *(int *)(param_2 + 0x10) + *(int *)(param_1 + 0x10);
  puVar1[5] = *(int *)(param_1 + 0x14) + *(int *)(param_2 + 0x14);
  FUN_004177b0((undefined4 *)puVar1[6],*(undefined4 **)(param_1 + 0x18),iVar2);
  FUN_004177b0((undefined4 *)(puVar1[6] + iVar2 * 4),*(undefined4 **)(param_2 + 0x18),param_3);
  return puVar1;
}



int __cdecl FUN_00417860(int param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint unaff_EDI;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_2 + 2);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_2 + 8);
  if (*(int *)(param_1 + 8) != *(int *)(param_2 + 4)) {
    FUN_00408c40((int *)s_sf_append__sf_size_mismatch_004310c8,unaff_EDI);
  }
  iVar1 = *(int *)(param_2 + 8) + *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0xc) = iVar1;
  if ((iVar1 < 1) || (iVar6 = *(int *)(param_1 + 4), iVar6 < 1)) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if (*(uint **)(param_1 + 0x18) == (uint *)0x0) {
    puVar8 = FUN_0040a880(1,iVar1 * iVar6 * 4);
    *(uint **)(param_1 + 0x18) = puVar8;
  }
  else {
    uVar7 = FUN_0040a8f0(*(uint **)(param_1 + 0x18),iVar1 * iVar6 * 4);
    *(undefined4 *)(param_1 + 0x18) = uVar7;
  }
  DAT_004332e8 = DAT_004332e8 + 1;
  FUN_004177b0((undefined4 *)(*(int *)(param_1 + 0x18) + iVar2 * iVar4 * 4),
               *(undefined4 **)(param_2 + 0xc),iVar3 * iVar5);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + *(int *)(param_2 + 8);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + *(int *)(param_2 + 10);
  FUN_00417a40(param_2);
  return param_1;
}



uint * __cdecl FUN_00417930(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  DAT_004330c0 = DAT_004330c0 + 1;
  if (DAT_004330c0 % 100 == 0) {
    DAT_004330c0 = 0;
    iVar1 = FUN_0041b360();
    if (DAT_0042fbb0 < iVar1 - DAT_004330c4) {
      FUN_0040f8b0(2);
    }
  }
  if (DAT_004332ec == (uint *)0x0) {
LAB_004179a3:
    puVar2 = FUN_0040a880(1,0x20);
  }
  else {
    do {
      if (*(short *)DAT_004332ec != 1) {
        if (DAT_004332ec == (uint *)0x0) goto LAB_004179a3;
        puVar2 = DAT_004332ec;
        DAT_004332ec = (uint *)DAT_004332ec[7];
        goto LAB_004179bc;
      }
      DAT_004332ec = (uint *)DAT_004332ec[7];
    } while (DAT_004332ec != (uint *)0x0);
    puVar2 = FUN_0040a880(1,0x20);
  }
LAB_004179bc:
  *(short *)puVar2 = 1;
  puVar2[2] = param_3;
  if ((int)param_3 < 0x21) {
    uVar3 = 2;
  }
  else {
    uVar3 = ((int)(param_3 - 1) >> 5) + 2;
  }
  puVar2[1] = uVar3;
  puVar2[3] = param_2;
  if ((0 < (int)param_2) && (0 < (int)param_3)) {
    puVar4 = FUN_0040a880(1,puVar2[1] * puVar2[3] * 4);
    puVar2[6] = (uint)puVar4;
    puVar2[4] = 0;
    puVar2[5] = 0;
    return puVar2;
  }
  puVar2[6] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  return puVar2;
}



void __cdecl FUN_00417a20(uint param_1)

{
  uint *puVar1;
  
  puVar1 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),*(uint *)(param_1 + 8),param_1);
  FUN_00417770((int)puVar1,param_1);
  return;
}



int __cdecl FUN_00417a40(short *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_004330c0 + 1;
  iVar2 = iVar1 / 100;
  DAT_004330c0 = iVar1 % 100;
  if (DAT_004330c0 == 0) {
    iVar2 = FUN_0041b360();
    iVar2 = iVar2 - DAT_004330c4;
    iVar1 = DAT_004330c0;
    if (DAT_0042fbb0 < iVar2) {
      iVar2 = FUN_0040f8b0(2);
      iVar1 = DAT_004330c0;
    }
  }
  DAT_004330c0 = iVar1;
  if (*param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 != 0) {
      iVar2 = FUN_0041b8c0(iVar2);
      param_1[0xc] = 0;
      param_1[0xd] = 0;
    }
    *param_1 = 0;
    *(short **)(param_1 + 0xe) = DAT_004332ec;
    DAT_004332ec = param_1;
  }
  return iVar2;
}



void FUN_00417ac0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_004332ec;
  if (DAT_004332ec == 0) {
    DAT_004332ec = 0;
    return;
  }
  do {
    iVar1 = *(int *)(iVar2 + 0x1c);
    if (iVar2 != 0) {
      FUN_0041b8c0(iVar2);
    }
    iVar2 = iVar1;
  } while (iVar1 != 0);
  DAT_004332ec = iVar1;
  return;
}



int __cdecl FUN_00417b00(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 <= *(int *)(param_1 + 0x10)) {
    iVar1 = iVar1 / 2 + 1 + iVar1;
    *(int *)(param_1 + 0xc) = iVar1;
    if ((iVar1 < 1) || (iVar2 = *(int *)(param_1 + 4), iVar2 < 1)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else if (*(uint **)(param_1 + 0x18) == (uint *)0x0) {
      puVar4 = FUN_0040a880(1,iVar2 * iVar1 * 4);
      *(uint **)(param_1 + 0x18) = puVar4;
    }
    else {
      uVar3 = FUN_0040a8f0(*(uint **)(param_1 + 0x18),iVar2 * iVar1 * 4);
      *(undefined4 *)(param_1 + 0x18) = uVar3;
    }
  }
  iVar1 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar1 + 1;
  FUN_004171c0(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * iVar1 * 4,param_2);
  return param_1;
}



void __cdecl FUN_00417b90(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10) + -1;
  *(int *)(param_1 + 0x10) = iVar1;
  FUN_004171c0(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * param_2 * 4,
               (uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * iVar1 * 4));
  return;
}



void __cdecl FUN_00417bc0(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = *(uint **)(param_1 + 0x18);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      FUN_00417ed0(puVar1);
      FUN_0041b470((byte *)s_A__d_____s_004310e4);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + *(int *)(param_1 + 4);
    } while (iVar2 < *(int *)(param_1 + 0x10));
  }
  return;
}



void __cdecl FUN_00417c40(int *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  FUN_0041b430(param_1,(byte *)s__d__d_004310fc);
  puVar2 = *(uint **)(param_2 + 0x18);
  puVar1 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
    FUN_00417d50(param_1,puVar2);
  }
  FUN_0041f0ff(param_1);
  return;
}



void __cdecl FUN_00417d50(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = *param_2;
  uVar4 = 0;
  do {
    FUN_0041b430(param_1,&DAT_00431114);
    uVar1 = uVar4 + 1;
    uVar3 = uVar1 & 0x80000007;
    bVar5 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar5 = (uVar3 - 1 | 0xfffffff8) == 0xffffffff;
    }
    if ((bVar5) && (uVar4 != (uVar2 & 0x3ff))) {
      FUN_0041b430(param_1,&DAT_00431118);
    }
    uVar4 = uVar1;
  } while ((int)uVar1 <= (int)(uVar2 & 0x3ff));
  FUN_0041b430(param_1,&DAT_0043111c);
  return;
}



undefined * __cdecl FUN_00417ed0(uint *param_1)

{
  char *pcVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char acStack_15 [21];
  
  uVar2 = *param_1;
  bVar3 = true;
  iVar5 = 0;
  DAT_00433270 = 0x5b;
  iVar7 = 1;
  if ((uVar2 & 0x3ff) != 0) {
    do {
      if ((param_1[(iVar5 >> 5) + 1] & 1 << ((byte)iVar5 & 0x1f)) != 0) {
        iVar6 = 0;
        if (!bVar3) {
          (&DAT_00433270)[iVar7] = 0x2c;
          iVar7 = iVar7 + 1;
        }
        bVar3 = false;
        iVar4 = iVar5;
        do {
          acStack_15[iVar6 + 1] = (char)(iVar4 % 10) + '0';
          iVar4 = iVar4 / 10;
          iVar6 = iVar6 + 1;
        } while (0 < iVar4);
        do {
          iVar4 = iVar7;
          pcVar1 = acStack_15 + iVar6;
          iVar6 = iVar6 + -1;
          (&DAT_00433270)[iVar4] = *pcVar1;
          iVar7 = iVar4 + 1;
        } while (0 < iVar6);
        if (0x69 < iVar7) {
          (&DAT_00433271)[iVar4] = 0x2e;
          (&DAT_00433272)[iVar4] = 0x2e;
          (&DAT_00433273)[iVar4] = 0x2e;
          iVar7 = iVar4 + 4;
          break;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)((uVar2 & 0x3ff) << 5));
  }
  (&DAT_00433270)[iVar7] = 0x5d;
  (&DAT_00433271)[iVar7] = 0;
  return &DAT_00433270;
}



void __cdecl FUN_00418010(uint *param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = *param_1 & 0x3ff;
  if (uVar3 != 0) {
    puVar4 = param_1 + uVar3;
    do {
      uVar2 = *puVar4;
      uVar3 = uVar3 - 1;
      puVar4 = puVar4 + -1;
      if (uVar2 != 0) {
        piVar1 = (int *)(param_2 + uVar3 * 0x80);
        do {
          if ((uVar2 & 1) != 0) {
            *piVar1 = *piVar1 + param_3;
          }
          piVar1 = piVar1 + 1;
          uVar2 = uVar2 >> 1;
        } while (uVar2 != 0);
      }
    } while (0 < (int)uVar3);
  }
  return;
}



void __cdecl FUN_00418060(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  if (*(int *)(param_1 + 8) < 1) {
    puVar2 = (uint *)0x0;
  }
  else {
    puVar2 = FUN_0040a880(1,*(int *)(param_1 + 8) << 2);
  }
  iVar5 = *(int *)(param_1 + 8);
  if (-1 < iVar5 + -1) {
    puVar3 = puVar2 + iVar5 + -1;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + -1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar3 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar1 < puVar3; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    uVar7 = *puVar1 & 0x3ff;
    if (uVar7 != 0) {
      puVar8 = puVar1 + uVar7;
      do {
        uVar6 = *puVar8;
        uVar7 = uVar7 - 1;
        puVar8 = puVar8 + -1;
        if (uVar6 != 0) {
          puVar4 = puVar2 + uVar7 * 0x20;
          do {
            if ((uVar6 & 1) != 0) {
              *puVar4 = *puVar4 + 1;
            }
            puVar4 = puVar4 + 1;
            uVar6 = uVar6 >> 1;
          } while (uVar6 != 0);
        }
      } while (0 < (int)uVar7);
    }
  }
  return;
}



uint * __cdecl FUN_004180f0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *local_c;
  
  if (*(int *)(param_1 + 8) < 1) {
    local_c = (uint *)0x0;
  }
  else {
    local_c = FUN_0040a880(1,*(int *)(param_1 + 8) << 2);
  }
  iVar2 = *(int *)(param_1 + 8);
  if (-1 < iVar2 + -1) {
    puVar1 = local_c + iVar2 + -1;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + -1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  puVar5 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar5 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  if (puVar1 <= puVar5) {
    return local_c;
  }
  do {
    iVar2 = FUN_00417030(puVar5);
    uVar6 = *puVar5 & 0x3ff;
    if (uVar6 != 0) {
      puVar7 = (uint *)(param_2 + uVar6 * 4);
      do {
        uVar3 = *(uint *)(((int)puVar5 - param_2) + (int)puVar7) & *puVar7;
        uVar6 = uVar6 - 1;
        puVar7 = puVar7 + -1;
        if (uVar3 != 0) {
          puVar4 = local_c + uVar6 * 0x20;
          do {
            if ((uVar3 & 1) != 0) {
              *puVar4 = *puVar4 + (int)(0x400 / (longlong)(iVar2 + -1));
            }
            puVar4 = puVar4 + 1;
            uVar3 = uVar3 >> 1;
          } while (uVar3 != 0);
        }
      } while (0 < (int)uVar6);
    }
    puVar5 = puVar5 + *(int *)(param_1 + 4);
  } while (puVar5 < puVar1);
  return local_c;
}



void __cdecl FUN_004181e0(short *param_1,int param_2,int param_3)

{
  FUN_00418250(param_1,param_2,(param_3 - param_2) + 1);
  return;
}



void __cdecl FUN_00418200(short *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_2 == iVar1) {
    if (iVar1 < 0x21) {
      iVar2 = 1;
    }
    else {
      iVar2 = (iVar1 + -1 >> 5) + 1;
    }
    if (iVar1 + param_3 <= iVar2 * 0x20) {
      *(int *)(param_1 + 4) = iVar1 + param_3;
      return;
    }
  }
  FUN_00418250(param_1,param_2,-param_3);
  return;
}



uint * __cdecl FUN_00418250(short *param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint unaff_EDI;
  
  puVar4 = FUN_00417930(*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 4) - param_3,unaff_EDI);
  uVar3 = *(uint *)(param_1 + 0xc);
  uVar1 = uVar3 + *(int *)(param_1 + 2) * *(int *)(param_1 + 8) * 4;
  for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(param_1 + 2) * 4) {
    uVar5 = puVar4[4];
    puVar4[4] = uVar5 + 1;
    piVar2 = (int *)(puVar4[6] + puVar4[1] * uVar5 * 4);
    FUN_00417140(piVar2,puVar4[2]);
    iVar6 = 0;
    if (0 < param_2) {
      do {
        uVar5 = 1 << ((byte)iVar6 & 0x1f);
        if ((*(uint *)((iVar6 >> 5) * 4 + 4 + uVar3) & uVar5) != 0) {
          piVar2[(iVar6 >> 5) + 1] = piVar2[(iVar6 >> 5) + 1] | uVar5;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_2);
    }
    iVar6 = param_2;
    if (0 < param_3) {
      iVar6 = param_2 + param_3;
    }
    if (iVar6 < *(int *)(param_1 + 4)) {
      do {
        if ((*(uint *)(uVar3 + 4 + (iVar6 >> 5) * 4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {
          iVar7 = iVar6 - param_3 >> 5;
          piVar2[iVar7 + 1] = piVar2[iVar7 + 1] | 1 << ((byte)(iVar6 - param_3) & 0x1f);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 4));
    }
  }
  FUN_00417a40(param_1);
  return puVar4;
}



int __cdecl FUN_00418360(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_3 + 0x18);
  iVar4 = *(int *)(param_1 + 0x18);
  uVar1 = uVar3 + *(int *)(param_3 + 0x10) * *(int *)(param_3 + 4) * 4;
  for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(param_3 + 4) * 4) {
    if ((*(uint *)(uVar3 + ((param_4 >> 5) + 1) * 4) & 1 << ((byte)param_4 & 0x1f)) != 0) {
      puVar2 = (uint *)(iVar4 + ((param_2 >> 5) + 1) * 4);
      *puVar2 = *puVar2 | 1 << ((byte)param_2 & 0x1f);
    }
    iVar4 = iVar4 + *(int *)(param_1 + 4) * 4;
  }
  return param_1;
}



uint * __cdecl FUN_004183e0(short *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = param_2;
  uVar1 = FUN_00417030(param_2);
  puVar2 = FUN_00417930(*(undefined4 *)(param_1 + 8),uVar1,(uint)puVar2);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      uVar1 = puVar2[4];
      puVar2[4] = uVar1 + 1;
      FUN_00417140((int *)(puVar2[6] + puVar2[1] * uVar1 * 4),puVar2[2]);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 8));
  }
  iVar5 = 0;
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      iVar3 = iVar4;
      if ((param_2[(iVar5 >> 5) + 1] & 1 << ((byte)iVar5 & 0x1f)) != 0) {
        iVar3 = iVar4 + 1;
        FUN_00418360((int)puVar2,iVar4,(int)param_1,iVar5);
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar3;
    } while (iVar5 < *(int *)(param_1 + 4));
  }
  FUN_00417a40(param_1);
  return puVar2;
}



uint * __cdecl FUN_00418550(short *param_1,int *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint unaff_EDI;
  int *piVar8;
  
  puVar6 = FUN_00417930(*(undefined4 *)(param_1 + 8),param_3,unaff_EDI);
  uVar2 = *(uint *)(param_1 + 8);
  puVar6[4] = uVar2;
  piVar3 = (int *)puVar6[6];
  piVar8 = piVar3 + uVar2 * puVar6[1];
  for (; piVar3 < piVar8; piVar3 = piVar3 + puVar6[1]) {
    FUN_00417140(piVar3,param_3);
  }
  uVar4 = puVar6[6];
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar2 = uVar5 + *(int *)(param_1 + 2) * *(int *)(param_1 + 8) * 4;
  for (; uVar5 < uVar2; uVar5 = uVar5 + *(int *)(param_1 + 2) * 4) {
    iVar7 = 0;
    piVar8 = param_2;
    if (0 < (int)param_3) {
      do {
        if ((*(uint *)(uVar5 + 4 + (*piVar8 >> 5) * 4) & 1 << ((byte)*piVar8 & 0x1f)) != 0) {
          puVar1 = (uint *)(uVar4 + 4 + (iVar7 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)iVar7 & 0x1f);
        }
        iVar7 = iVar7 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar7 < (int)param_3);
    }
    uVar4 = uVar4 + puVar6[1] * 4;
  }
  FUN_00417a40(param_1);
  return puVar6;
}



undefined4 __cdecl FUN_00418630(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_1 & 0x3ff;
  puVar2 = (uint *)(param_2 + uVar1 * 4);
  if ((param_1[uVar1] | *(uint *)(param_2 + uVar1 * 4)) == *(uint *)(DAT_00435550 + uVar1 * 4)) {
    do {
      uVar1 = uVar1 - 1;
      puVar2 = puVar2 + -1;
      if ((int)uVar1 < 1) {
        return 1;
      }
    } while ((*(uint *)(((int)param_1 - param_2) + (int)puVar2) | *puVar2) ==
             *(uint *)((DAT_00435550 - param_2) + (int)puVar2));
  }
  return 0;
}



undefined4 __cdecl FUN_00418690(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = param_1;
  if (DAT_0043555c != -1) {
    uVar2 = *(uint *)(param_1 + DAT_0043555c * 4) & param_2[DAT_0043555c];
    if ((~(uVar2 >> 1 | uVar2) & DAT_00435558) != 0) {
      return 0;
    }
    iVar5 = 1;
    if (1 < DAT_0043555c) {
      puVar3 = param_2;
      do {
        puVar3 = puVar3 + 1;
        uVar2 = *(uint *)((param_1 - (int)param_2) + (int)puVar3) & *puVar3;
        if ((~(uVar2 >> 1 | uVar2) & 0x55555555) != 0) {
          return 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_0043555c);
    }
  }
  param_1 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524) {
    piVar4 = (int *)(DAT_0043553c + DAT_00435528 * 4);
    do {
      iVar5 = *(int *)((DAT_00435538 - DAT_0043553c) + (int)piVar4);
      puVar3 = (uint *)(iVar1 + iVar5 * 4);
      while( true ) {
        if (*piVar4 < iVar5) {
          return 0;
        }
        if ((*puVar3 &
            *(uint *)(((int)param_2 - iVar1) + (int)puVar3) &
            *(uint *)((*(int *)((DAT_00435548 - DAT_0043553c) + (int)piVar4) - iVar1) + (int)puVar3)
            ) != 0) break;
        iVar5 = iVar5 + 1;
        puVar3 = puVar3 + 1;
      }
      param_1 = param_1 + 1;
      piVar4 = piVar4 + 1;
    } while (param_1 < DAT_00435524);
  }
  return 1;
}



int __cdecl FUN_00418790(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int local_10;
  int local_8;
  
  iVar7 = DAT_0043555c;
  local_10 = 0;
  if (DAT_0043555c != -1) {
    uVar1 = *(uint *)(param_1 + DAT_0043555c * 4) & param_2[DAT_0043555c];
    uVar1 = ~(uVar1 >> 1 | uVar1) & DAT_00435558;
    if (uVar1 != 0) {
      iVar2 = FUN_0040d180(uVar1 >> 0x10 & 0xff);
      iVar3 = FUN_0040d180(uVar1 >> 8 & 0xff);
      iVar4 = FUN_0040d180(uVar1 >> 0x18);
      local_10 = FUN_0040d180(uVar1 & 0xff);
      local_10 = iVar2 + iVar3 + iVar4 + local_10;
      if (1 < local_10) {
        return 2;
      }
    }
    local_8 = 1;
    if (1 < iVar7) {
      puVar6 = param_2;
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *(uint *)((param_1 - (int)param_2) + (int)puVar6) & *puVar6;
        uVar1 = ~(uVar1 >> 1 | uVar1);
        uVar8 = uVar1 & 0x55555555;
        if (uVar8 != 0) {
          if (local_10 == 1) {
            return 2;
          }
          iVar2 = FUN_0040d180(uVar8 >> 0x10 & 0xff);
          iVar3 = FUN_0040d180(uVar8 >> 8 & 0xff);
          iVar4 = FUN_0040d180(uVar8 >> 0x18);
          iVar5 = FUN_0040d180(uVar1 & 0x55);
          local_10 = iVar5 + local_10 + iVar2 + iVar3 + iVar4;
          if (1 < local_10) {
            return 2;
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < iVar7);
    }
  }
  local_8 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524) {
    piVar9 = (int *)(DAT_0043553c + DAT_00435528 * 4);
    do {
      iVar7 = *(int *)((int)piVar9 + (DAT_00435538 - DAT_0043553c));
      if (iVar7 <= *piVar9) {
        puVar6 = (uint *)(param_1 + iVar7 * 4);
        do {
          if ((*puVar6 &
              *(uint *)(((int)param_2 - param_1) + (int)puVar6) &
              *(uint *)((*(int *)((DAT_00435548 - DAT_0043553c) + (int)piVar9) - param_1) +
                       (int)puVar6)) != 0) goto LAB_00418959;
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar7 <= *piVar9);
      }
      local_10 = local_10 + 1;
      if (1 < local_10) {
        return 2;
      }
LAB_00418959:
      local_8 = local_8 + 1;
      piVar9 = piVar9 + 1;
    } while (local_8 < DAT_00435524);
  }
  return local_10;
}



int __cdecl FUN_00418980(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  int local_10;
  int local_8;
  
  local_8 = DAT_0043555c;
  local_10 = 0;
  if (DAT_0043555c != -1) {
    uVar1 = *(uint *)(param_1 + DAT_0043555c * 4) & param_2[DAT_0043555c];
    uVar1 = ~(uVar1 >> 1 | uVar1) & DAT_00435558;
    if (uVar1 != 0) {
      iVar2 = FUN_0040d180(uVar1 >> 0x10 & 0xff);
      iVar3 = FUN_0040d180(uVar1 >> 8 & 0xff);
      iVar4 = FUN_0040d180(uVar1 >> 0x18);
      local_10 = FUN_0040d180(uVar1 & 0xff);
      local_10 = iVar2 + iVar3 + iVar4 + local_10;
    }
    if (1 < local_8) {
      local_8 = local_8 + -1;
      puVar6 = param_2;
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *(uint *)((param_1 - (int)param_2) + (int)puVar6) & *puVar6;
        uVar1 = ~(uVar1 >> 1 | uVar1);
        uVar7 = uVar1 & 0x55555555;
        if (uVar7 != 0) {
          iVar2 = FUN_0040d180(uVar7 >> 0x10 & 0xff);
          iVar3 = FUN_0040d180(uVar7 >> 8 & 0xff);
          iVar4 = FUN_0040d180(uVar7 >> 0x18);
          iVar5 = FUN_0040d180(uVar1 & 0x55);
          local_10 = iVar5 + local_10 + iVar2 + iVar3 + iVar4;
        }
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  if (DAT_00435528 < DAT_00435524) {
    local_8 = DAT_00435524 - DAT_00435528;
    piVar8 = (int *)(DAT_0043553c + DAT_00435528 * 4);
    do {
      iVar2 = *(int *)((DAT_00435538 - DAT_0043553c) + (int)piVar8);
      if (iVar2 <= *piVar8) {
        puVar6 = (uint *)(param_1 + iVar2 * 4);
        do {
          if ((*puVar6 &
              *(uint *)(((int)param_2 - param_1) + (int)puVar6) &
              *(uint *)((*(int *)((DAT_00435548 - DAT_0043553c) + (int)piVar8) - param_1) +
                       (int)puVar6)) != 0) goto LAB_00418b04;
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar2 <= *piVar8);
      }
      local_10 = local_10 + 1;
LAB_00418b04:
      piVar8 = piVar8 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return local_10;
}



int __cdecl FUN_00418b20(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  puVar3 = param_2;
  iVar9 = DAT_0043555c;
  if (DAT_0043555c != -1) {
    uVar8 = *(uint *)(param_3 + DAT_0043555c * 4) & param_2[DAT_0043555c];
    uVar8 = ~(uVar8 >> 1 | uVar8) & DAT_00435558;
    if (uVar8 != 0) {
      puVar5 = (uint *)(param_1 + DAT_0043555c * 4);
      *puVar5 = *puVar5 | (uVar8 * 2 | uVar8) & param_2[DAT_0043555c];
    }
    if (1 < iVar9) {
      iVar7 = param_3 - (int)param_2;
      iVar6 = param_1 - (int)param_2;
      puVar5 = param_2;
      param_2 = (uint *)(iVar9 + -1);
      do {
        puVar5 = puVar5 + 1;
        uVar8 = *(uint *)((int)puVar5 + iVar7) & *puVar5;
        uVar8 = ~(uVar8 >> 1 | uVar8) & 0x55555555;
        if (uVar8 != 0) {
          *(uint *)(iVar6 + (int)puVar5) =
               *(uint *)(iVar6 + (int)puVar5) | (uVar8 * 2 | uVar8) & *puVar5;
        }
        param_2 = (uint *)((int)param_2 + -1);
      } while (param_2 != (uint *)0x0);
    }
  }
  iVar9 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524) {
    do {
      iVar6 = *(int *)(DAT_00435548 + iVar9 * 4);
      iVar7 = *(int *)(DAT_0043553c + iVar9 * 4);
      iVar2 = *(int *)(DAT_00435538 + iVar9 * 4);
      if (iVar2 <= iVar7) {
        puVar5 = puVar3 + iVar2;
        iVar4 = iVar2;
        do {
          if ((*puVar5 &
              *(uint *)((iVar6 - (int)puVar3) + (int)puVar5) &
              *(uint *)((int)puVar5 + (param_3 - (int)puVar3))) != 0) goto LAB_00418c4a;
          iVar4 = iVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar4 <= iVar7);
      }
      if (iVar2 <= iVar7) {
        iVar7 = (iVar7 - iVar2) + 1;
        puVar5 = (uint *)(param_1 + iVar2 * 4);
        do {
          puVar1 = (uint *)(((int)puVar3 - param_1) + (int)puVar5);
          iVar7 = iVar7 + -1;
          *puVar5 = *puVar5 | *(uint *)((int)puVar1 + (iVar6 - (int)puVar3)) & *puVar1;
          puVar5 = puVar5 + 1;
        } while (iVar7 != 0);
      }
LAB_00418c4a:
      iVar9 = iVar9 + 1;
    } while (iVar9 < DAT_00435524);
  }
  return param_1;
}



void __cdecl FUN_00418c70(int *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  bool bVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  puVar3 = param_3;
  FUN_00417140(param_1,DAT_00435520);
  iVar5 = DAT_0043555c;
  if (DAT_0043555c != -1) {
    uVar6 = param_3[DAT_0043555c] & *(uint *)(param_2 + DAT_0043555c * 4);
    param_1[DAT_0043555c] = uVar6;
    uVar6 = ~(uVar6 >> 1 | uVar6) & DAT_00435558;
    if (uVar6 != 0) {
      param_1[iVar5] =
           param_1[iVar5] | (uVar6 * 2 | uVar6) & (param_3[iVar5] | *(uint *)(param_2 + iVar5 * 4));
    }
    if (1 < iVar5) {
      iVar7 = (int)param_1 - (int)param_3;
      iVar8 = param_2 - (int)param_3;
      puVar4 = param_3;
      param_3 = (uint *)(iVar5 + -1);
      do {
        puVar4 = puVar4 + 1;
        uVar6 = *(uint *)(iVar8 + (int)puVar4) & *puVar4;
        *(uint *)((int)puVar4 + iVar7) = uVar6;
        uVar6 = ~(uVar6 >> 1 | uVar6) & 0x55555555;
        if (uVar6 != 0) {
          *(uint *)((int)puVar4 + iVar7) =
               *(uint *)((int)puVar4 + iVar7) |
               (uVar6 * 2 | uVar6) & (*(uint *)(iVar8 + (int)puVar4) | *puVar4);
        }
        param_3 = (uint *)((int)param_3 + -1);
      } while (param_3 != (uint *)0x0);
    }
  }
  iVar5 = DAT_00435528;
  if (DAT_00435528 < DAT_00435524) {
    do {
      bVar2 = true;
      iVar7 = *(int *)(DAT_00435548 + iVar5 * 4);
      iVar8 = *(int *)(DAT_0043553c + iVar5 * 4);
      iVar9 = *(int *)(DAT_00435538 + iVar5 * 4);
      if (iVar8 < iVar9) {
LAB_00418dbf:
        iVar9 = *(int *)(DAT_00435538 + iVar5 * 4);
        if (iVar9 <= iVar8) {
          iVar8 = (iVar8 - iVar9) + 1;
          puVar4 = puVar3 + iVar9;
          do {
            puVar1 = (uint *)((int)puVar4 + ((int)param_1 - (int)puVar3));
            *puVar1 = *puVar1 | (*(uint *)((int)puVar4 + (param_2 - (int)puVar3)) | *puVar4) &
                                *(uint *)((iVar7 - (int)puVar3) + -4 + (int)(puVar4 + 1));
            iVar8 = iVar8 + -1;
            puVar4 = puVar4 + 1;
          } while (iVar8 != 0);
        }
      }
      else {
        puVar4 = (uint *)(param_2 + iVar9 * 4);
        iVar9 = (iVar8 - iVar9) + 1;
        do {
          uVar6 = *(uint *)((int)puVar4 + ((int)puVar3 - param_2)) &
                  *(uint *)((int)puVar4 + (iVar7 - param_2)) & *puVar4;
          if (uVar6 != 0) {
            bVar2 = false;
            *(uint *)(((int)param_1 - param_2) + (int)puVar4) =
                 *(uint *)(((int)param_1 - param_2) + (int)puVar4) | uVar6;
          }
          puVar4 = puVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (bVar2) goto LAB_00418dbf;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00435524);
  }
  return;
}



int __cdecl FUN_00418e20(uint *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int local_14;
  int local_10;
  int local_8;
  int local_4;
  
  iVar9 = DAT_0043555c;
  local_10 = -1;
  local_14 = 0;
  if (DAT_0043555c != -1) {
    uVar6 = ~(param_1[DAT_0043555c] >> 1 & param_1[DAT_0043555c]) & DAT_00435558;
    if (uVar6 != 0) {
      iVar1 = FUN_0040d180(uVar6 >> 0x10 & 0xff);
      iVar2 = FUN_0040d180(uVar6 >> 8 & 0xff);
      iVar3 = FUN_0040d180(uVar6 >> 0x18);
      local_14 = FUN_0040d180(uVar6 & 0xff);
      local_14 = iVar1 + iVar2 + iVar3 + local_14;
      if (1 < local_14) {
        return -1;
      }
      iVar1 = FUN_00417010(uVar6);
      local_10 = iVar1 / 2 + -0x10 + iVar9 * 0x10;
    }
    local_4 = 1;
    if (1 < iVar9) {
      local_8 = 0x10;
      puVar5 = param_1;
      do {
        puVar5 = puVar5 + 1;
        uVar6 = ~(*puVar5 >> 1 & *puVar5);
        uVar7 = uVar6 & 0x55555555;
        if (uVar7 != 0) {
          iVar1 = FUN_0040d180(uVar7 >> 0x10 & 0xff);
          iVar2 = FUN_0040d180(uVar7 >> 8 & 0xff);
          iVar3 = FUN_0040d180(uVar7 >> 0x18);
          iVar4 = FUN_0040d180(uVar6 & 0x55);
          local_14 = iVar4 + local_14 + iVar1 + iVar2 + iVar3;
          if (1 < local_14) {
            return -1;
          }
          iVar1 = FUN_00417010(uVar7);
          local_10 = iVar1 / 2 + -0x10 + local_8;
        }
        local_4 = local_4 + 1;
        local_8 = local_8 + 0x10;
      } while (local_4 < iVar9);
    }
  }
  if (DAT_00435528 < DAT_00435524) {
    piVar8 = (int *)(DAT_0043553c + DAT_00435528 * 4);
    iVar9 = DAT_00435528;
    do {
      iVar1 = *(int *)((DAT_00435548 - DAT_0043553c) + (int)piVar8);
      iVar2 = *(int *)((DAT_00435538 - DAT_0043553c) + (int)piVar8);
      if (iVar2 <= *piVar8) {
        puVar5 = (uint *)(iVar1 + iVar2 * 4);
        do {
          if ((*puVar5 & ~*(uint *)(((int)param_1 - iVar1) + (int)puVar5)) != 0) {
            local_14 = local_14 + 1;
            local_10 = iVar9;
            if (1 < local_14) {
              return -1;
            }
            break;
          }
          iVar2 = iVar2 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar2 <= *piVar8);
      }
      iVar9 = iVar9 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar9 < DAT_00435524);
  }
  return local_10;
}



undefined4 __cdecl FUN_00419020(int param_1,int param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  int iVar9;
  int local_10;
  int local_c;
  
  if (DAT_0043555c != -1) {
    uVar6 = *(uint *)(param_2 + DAT_0043555c * 4) | param_3[DAT_0043555c];
    uVar3 = *(uint *)(param_1 + DAT_0043555c * 4) | param_3[DAT_0043555c];
    if ((~(uVar6 >> 1 & uVar6) & ~(uVar3 >> 1 & uVar3) & DAT_00435558) != 0) {
      return 1;
    }
    local_10 = 1;
    if (1 < DAT_0043555c) {
      puVar5 = param_3;
      do {
        puVar5 = puVar5 + 1;
        puVar7 = (uint *)((param_2 - (int)param_3) + (int)puVar5);
        uVar6 = *puVar7 | *puVar5;
        uVar3 = *(uint *)((int)puVar7 + (param_1 - param_2)) | *puVar5;
        if ((~(uVar6 >> 1 & uVar6) & ~(uVar3 >> 1 & uVar3) & 0x55555555) != 0) {
          return 1;
        }
        local_10 = local_10 + 1;
      } while (local_10 < DAT_0043555c);
    }
  }
  local_c = DAT_00435528;
  if (DAT_00435524 <= DAT_00435528) {
    return 0;
  }
  piVar8 = (int *)(DAT_00435538 + DAT_00435528 * 4);
  do {
    piVar1 = (int *)((DAT_0043553c - DAT_00435538) + (int)piVar8);
    iVar2 = *piVar1;
    iVar4 = *piVar8;
    if (iVar4 <= iVar2) {
      puVar5 = param_3 + iVar4;
      iVar9 = *(int *)((int)piVar1 + (DAT_00435548 - DAT_0043553c)) - (int)param_3;
      do {
        if ((~*puVar5 &
            ~*(uint *)((param_1 - (int)param_3) + (int)puVar5) & *(uint *)(iVar9 + (int)puVar5)) !=
            0) {
          iVar4 = *piVar8;
          if (iVar4 <= iVar2) {
            puVar5 = param_3 + iVar4;
            do {
              if ((~*puVar5 &
                  ~*(uint *)((int)puVar5 + (param_2 - (int)param_3)) &
                  *(uint *)((int)puVar5 + iVar9)) != 0) {
                return 1;
              }
              iVar4 = iVar4 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar4 <= iVar2);
          }
          break;
        }
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar4 <= iVar2);
    }
    local_c = local_c + 1;
    piVar8 = piVar8 + 1;
    if (DAT_00435524 <= local_c) {
      return 0;
    }
  } while( true );
}



undefined4 __cdecl FUN_00419320(int *param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  bool bVar7;
  
  iVar1 = *DAT_0043554c;
  puVar2 = (uint *)*param_1;
  uVar5 = *puVar2 & 0x3ff;
  uVar4 = *(uint *)(iVar1 + uVar5 * 4);
  uVar3 = puVar2[uVar5] | uVar4;
  uVar4 = *(uint *)(*param_2 + uVar5 * 4) | uVar4;
  if (uVar3 <= uVar4) {
    puVar6 = (uint *)(iVar1 + uVar5 * 4);
    bVar7 = uVar3 < uVar4;
    do {
      if (bVar7) {
        return 1;
      }
      uVar5 = uVar5 - 1;
      puVar6 = puVar6 + -1;
      if ((int)uVar5 < 1) {
        return 0;
      }
      uVar3 = *(uint *)((int)puVar6 + (*param_2 - iVar1)) | *puVar6;
      uVar4 = *(uint *)(((int)puVar2 - iVar1) + (int)puVar6) | *puVar6;
      bVar7 = uVar4 < uVar3;
    } while (uVar4 <= uVar3);
  }
  return 0xffffffff;
}



uint __cdecl FUN_004193a0(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 == (uint *)0x0) {
    return (uint)(param_2 != (uint *)0x0);
  }
  if (param_2 == (uint *)0x0) {
    return 0xffffffff;
  }
  uVar2 = *param_1 & 0xffff0000;
  if ((*param_2 & 0xffff0000) < uVar2) {
    return 0xffffffff;
  }
  if ((*param_2 & 0xffff0000) <= uVar2) {
    uVar2 = *param_1 & 0x3ff;
    puVar1 = param_2 + uVar2;
    if (param_1[uVar2] <= param_2[uVar2]) {
      do {
        if (*(uint *)(((int)param_1 - (int)param_2) + (int)puVar1) < *puVar1) {
          return 1;
        }
        uVar2 = uVar2 - 1;
        puVar1 = puVar1 + -1;
        if ((int)uVar2 < 1) {
          return 0;
        }
      } while (*(uint *)(((int)param_1 - (int)param_2) + (int)puVar1) <= *puVar1);
    }
    return 0xffffffff;
  }
  return 1;
}



uint * __cdecl FUN_00419430(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  short *psVar4;
  uint unaff_EDI;
  
  puVar3 = FUN_00417930(0,DAT_00435520,unaff_EDI);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    psVar4 = (short *)FUN_00419490(puVar2,param_2);
    puVar3 = FUN_00404630((short *)puVar3,psVar4);
  }
  return puVar3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_00419490(uint *param_1,int param_2)

{
  uint *puVar1;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    puVar1 = FUN_00417930(1,DAT_00435520,(uint)param_1);
    FUN_00417b00((int)puVar1,param_1);
    return;
  }
  _DAT_0043530c = FUN_0041b360();
  FUN_004194e0(param_1,param_2,0,*(int *)(param_2 + 0x10) + -1,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint * __cdecl FUN_004194e0(uint *param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_3 == param_4) {
    puVar1 = FUN_004195c0(param_1,(uint *)(*(int *)(param_2 + 0x18) +
                                          *(int *)(param_2 + 4) * param_3 * 4));
    return puVar1;
  }
  iVar4 = (param_3 + param_4) / 2;
  puVar1 = FUN_004194e0(param_1,param_2,param_3,iVar4,param_5 + 1);
  puVar2 = FUN_004194e0(param_1,param_2,iVar4 + 1,param_4,param_5 + 1);
  puVar3 = (uint *)FUN_00419a60((int)puVar1,(int)puVar2);
  if (((DAT_00435400 & 0x2000) != 0) && (param_5 < 4)) {
    iVar4 = FUN_0041b360();
    FUN_004163a0(iVar4 - _DAT_0043530c);
    FUN_0041b470((byte *)s___SHARP__d____4d____4d_x__4d__ti_00431170);
    FUN_0041f0ff((int *)&DAT_00431c98);
  }
  FUN_00417a40((short *)puVar1);
  FUN_00417a40((short *)puVar2);
  return puVar3;
}



uint * __cdecl FUN_004195c0(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint unaff_EDI;
  
  puVar8 = (uint *)*DAT_0043554c;
  puVar1 = (uint *)DAT_0043554c[1];
  puVar2 = (uint *)DAT_0043554c[2];
  puVar4 = FUN_00417930(DAT_00435524,DAT_00435520,unaff_EDI);
  iVar5 = FUN_00418690((int)param_1,param_2);
  if (iVar5 != 0) {
    FUN_00417290(puVar8,param_1,(int)param_2);
    iVar5 = 0;
    if (0 < DAT_00435524) {
      do {
        puVar6 = (uint *)FUN_004171f0(puVar1,puVar8,*(int *)(DAT_00435548 + iVar5 * 4));
        iVar7 = FUN_00417440(puVar6);
        if (iVar7 == 0) {
          FUN_00417290(puVar2,param_1,*(int *)(DAT_00435548 + iVar5 * 4));
          uVar3 = puVar4[4];
          puVar4[4] = uVar3 + 1;
          FUN_00417240((uint *)(puVar4[6] + puVar4[1] * uVar3 * 4),puVar1,(int)puVar2);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_00435524);
    }
    return puVar4;
  }
  puVar8 = (uint *)FUN_00417b00((int)puVar4,param_1);
  return puVar8;
}



uint * __cdecl FUN_004196b0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint unaff_EDI;
  
  puVar3 = FUN_00417930(0,DAT_00435520,unaff_EDI);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    puVar4 = FUN_004197c0(puVar2,(int)puVar3);
    puVar3 = (uint *)FUN_00417860((int)puVar3,(short *)puVar4);
  }
  return puVar3;
}



uint * __cdecl FUN_00419700(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint unaff_EDI;
  
  puVar3 = FUN_00417930(0,DAT_00435520,unaff_EDI);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    puVar4 = FUN_004197c0(puVar2,param_2);
    puVar3 = FUN_00404630((short *)puVar3,(short *)puVar4);
  }
  return puVar3;
}



uint * __cdecl FUN_00419760(int param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint unaff_EDI;
  
  puVar3 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),DAT_00435520,unaff_EDI);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 4) * *(int *)(param_1 + 0x10);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    puVar4 = FUN_00419860(puVar2,param_2);
    puVar3 = FUN_00404630((short *)puVar3,(short *)puVar4);
  }
  return puVar3;
}



uint * __cdecl FUN_004197c0(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint unaff_EDI;
  
  if (*(int *)(param_2 + 0x10) != 0) {
    puVar4 = FUN_00417930(*(int *)(param_2 + 0x10),DAT_00435520,unaff_EDI);
    uVar1 = puVar4[4];
    puVar4[4] = uVar1 + 1;
    FUN_004171c0(puVar4[6] + puVar4[1] * uVar1 * 4,param_1);
    puVar2 = *(uint **)(param_2 + 0x18);
    puVar3 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
    for (; puVar2 < puVar3; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
      puVar5 = FUN_00419760((int)puVar4,puVar2);
      FUN_00417a40((short *)puVar4);
      puVar4 = puVar5;
    }
    return puVar4;
  }
  puVar3 = FUN_00417930(1,DAT_00435520,(uint)param_1);
  puVar3 = (uint *)FUN_00417b00((int)puVar3,param_1);
  return puVar3;
}



uint * __cdecl FUN_00419860(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint unaff_EDI;
  uint uVar8;
  
  puVar7 = (uint *)*DAT_0043554c;
  puVar2 = FUN_00417930(DAT_00435524,DAT_00435520,unaff_EDI);
  iVar3 = FUN_00418690((int)param_1,param_2);
  if (iVar3 != 0) {
    if ((int)DAT_00435520 < 0x21) {
      iVar3 = 2;
    }
    else {
      iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
    }
    uVar8 = DAT_00435520;
    puVar5 = param_1;
    puVar6 = param_2;
    puVar4 = FUN_0040a880(1,iVar3 << 2);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,uVar8);
    puVar5 = (uint *)FUN_00417290(puVar4,puVar5,(int)puVar6);
    if ((int)DAT_00435520 < 0x21) {
      iVar3 = 2;
    }
    else {
      iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
    }
    uVar8 = DAT_00435520;
    puVar6 = param_1;
    puVar4 = FUN_0040a880(1,iVar3 * 4);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,uVar8);
    puVar6 = (uint *)FUN_004171f0(puVar4,puVar6,(int)param_2);
    if ((int)DAT_00435520 < 0x21) {
      iVar3 = 2;
    }
    else {
      iVar3 = ((int)(DAT_00435520 - 1) >> 5) + 2;
    }
    uVar8 = DAT_00435520;
    puVar4 = FUN_0040a880(1,iVar3 * 4);
    puVar4 = (uint *)FUN_00417140((int *)puVar4,uVar8);
    param_2 = (uint *)0x0;
    if (0 < DAT_00435524) {
      do {
        iVar3 = FUN_00417510(puVar5,*(int *)(DAT_00435548 + (int)param_2 * 4));
        if (iVar3 == 0) {
          uVar8 = puVar2[4];
          puVar2[4] = uVar8 + 1;
          puVar1 = (uint *)(puVar2[6] + puVar2[1] * uVar8 * 4);
          FUN_004171f0(puVar1,puVar5,*(int *)(DAT_00435548 + (int)param_2 * 4));
          FUN_004171f0(puVar7,puVar6,(int)puVar4);
          FUN_00417240(puVar1,puVar1,(int)puVar7);
          FUN_00417240(puVar4,puVar4,*(int *)(DAT_00435548 + (int)param_2 * 4));
          FUN_00417290(puVar7,param_1,(int)puVar4);
          FUN_00417240(puVar1,puVar1,(int)puVar7);
        }
        param_2 = (uint *)((int)param_2 + 1);
      } while ((int)param_2 < DAT_00435524);
    }
    if (puVar5 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar5);
    }
    if (puVar6 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar6);
    }
    if (puVar4 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar4);
    }
    return puVar2;
  }
  puVar7 = (uint *)FUN_00417b00((int)puVar2,param_1);
  return puVar7;
}



void __cdecl FUN_00419a60(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint unaff_EDI;
  uint *local_c;
  
  local_c = (uint *)0x0;
  puVar5 = FUN_00417930(500,DAT_00435520,unaff_EDI);
  puVar8 = *(uint **)(param_1 + 0x18);
  puVar7 = (uint *)puVar5[6];
  puVar2 = puVar8 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  if (puVar8 < puVar2) {
    do {
      puVar3 = *(uint **)(param_2 + 0x18);
      puVar1 = puVar3 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
      for (; puVar3 < puVar1; puVar3 = puVar3 + *(int *)(param_2 + 4)) {
        iVar6 = FUN_00418690((int)puVar8,puVar3);
        if (iVar6 != 0) {
          FUN_004171f0(puVar7,puVar8,(int)puVar3);
          uVar4 = puVar5[4];
          puVar5[4] = uVar4 + 1;
          if ((int)(uVar4 + 1) < (int)puVar5[3]) {
            puVar7 = puVar7 + puVar5[1];
          }
          else {
            if (local_c == (uint *)0x0) {
              local_c = FUN_004044e0((short *)puVar5);
            }
            else {
              puVar7 = FUN_004044e0((short *)puVar5);
              local_c = FUN_00404630((short *)local_c,(short *)puVar7);
            }
            puVar5 = FUN_00417930(500,DAT_00435520,unaff_EDI);
            puVar7 = (uint *)puVar5[6];
          }
        }
      }
      puVar8 = puVar8 + *(int *)(param_1 + 4);
    } while (puVar8 < puVar2);
    if (local_c != (uint *)0x0) {
      puVar7 = FUN_004044e0((short *)puVar5);
      FUN_00404630((short *)local_c,(short *)puVar7);
      return;
    }
  }
  FUN_004044e0((short *)puVar5);
  return;
}



int __cdecl FUN_00419b90(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint local_10;
  
  piVar2 = (int *)FUN_00411d20();
  local_10 = 0;
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar5 = puVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar1 < puVar5; puVar1 = puVar1 + *(int *)(param_1 + 4)) {
    uVar10 = *puVar1 & 0x3ff;
    if (uVar10 != 0) {
      puVar8 = puVar1 + uVar10;
      do {
        uVar10 = uVar10 - 1;
        uVar9 = uVar10 * 0x20;
        for (uVar7 = *puVar8; uVar7 != 0; uVar7 = uVar7 >> 1) {
          if ((uVar7 & 1) != 0) {
            FUN_00411f90(piVar2,local_10,uVar9);
          }
          uVar9 = uVar9 + 1;
        }
        puVar8 = puVar8 + -1;
      } while (0 < (int)uVar10);
    }
    local_10 = local_10 + 1;
  }
  piVar11 = piVar2;
  iVar3 = FUN_00412a50((int)piVar2,(int *)0x0,1,0);
  FUN_00411db0(piVar2,piVar11);
  iVar12 = *(int *)(param_1 + 8);
  if (iVar12 < 0x21) {
    iVar4 = 2;
  }
  else {
    iVar4 = (iVar12 + -1 >> 5) + 2;
  }
  puVar5 = FUN_0040a880(1,iVar4 << 2);
  iVar4 = FUN_00417140((int *)puVar5,iVar12);
  for (iVar12 = *(int *)(iVar3 + 0xc); iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x10)) {
    iVar6 = *(int *)(iVar12 + 4) >> 5;
    *(uint *)(iVar4 + 4 + iVar6 * 4) =
         *(uint *)(iVar4 + 4 + iVar6 * 4) | 1 << ((byte)*(int *)(iVar12 + 4) & 0x1f);
  }
  FUN_00416c00(iVar3);
  return iVar4;
}



uint * FUN_00419cc0(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = FUN_0040a880(1,8);
  puVar1[1] = 0;
  uVar2 = FUN_00416b90();
  *puVar1 = uVar2;
  return puVar1;
}



void __cdecl FUN_00419cf0(int *param_1)

{
  FUN_00416c00(*param_1);
  if (param_1 != (int *)0x0) {
    FUN_0041b8c0((int)param_1);
  }
  return;
}



uint * __cdecl FUN_00419d10(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = FUN_0040a880(1,8);
  puVar1[1] = param_1[1];
  uVar2 = FUN_00416c40(*param_1);
  *puVar1 = uVar2;
  return puVar1;
}



void __cdecl FUN_00419d40(int *param_1,int param_2,uint param_3)

{
  FUN_00416c70(*param_1,param_3);
  if (param_2 == 0) {
    param_1[1] = param_1[1] + 1;
    return;
  }
  param_1[1] = param_1[1] + *(int *)(param_2 + param_3 * 4);
  return;
}



void __cdecl FUN_00419d80(int *param_1,int *param_2,int param_3,uint param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  FUN_00419d40(param_1,param_3,param_4);
  if (((int)param_4 < 0) || (param_2[3] <= (int)param_4)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_2[2] + param_4 * 4);
  }
  piVar2 = *(int **)(iVar3 + 0xc);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[2];
    FUN_00412460(param_2,*piVar2);
    piVar2 = piVar1;
  }
  return;
}



void __cdecl FUN_00419dd0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  FUN_00412520(param_2,param_4);
  return;
}



int * __cdecl FUN_00419df0(int *param_1,int *param_2)

{
  if (param_1 == (int *)0x0) {
    return param_2;
  }
  if (param_2 != (int *)0x0) {
    if (param_2[1] < param_1[1]) {
      FUN_00419cf0(param_1);
      return param_2;
    }
    FUN_00419cf0(param_2);
  }
  return param_1;
}



undefined4 __cdecl FUN_00419e30(int param_1,undefined **param_2)

{
  FUN_0040f8e0(param_1,param_2);
  return 0;
}



uint * __cdecl FUN_00419e50(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 local_30 [4];
  int local_20;
  undefined4 local_18 [4];
  int local_8;
  
  FUN_00408930(param_1,local_18);
  iVar1 = FUN_0041b360();
  puVar2 = (uint *)FUN_00419f40(param_1,param_2);
  FUN_00408bb0(iVar1,0xc,(int)puVar2,local_30);
  if (local_20 != local_8) {
    do {
      FUN_00408b10(local_30,local_18);
      iVar1 = FUN_0041b360();
      puVar2 = FUN_0040b8a0((short *)puVar2,param_3,1);
      FUN_00408bb0(iVar1,0xd,(int)puVar2,local_30);
      if (local_20 == local_8) {
        return puVar2;
      }
      FUN_00408b10(local_30,local_18);
      if (DAT_0043556c == 0) {
        return puVar2;
      }
      iVar1 = FUN_0041b360();
      puVar2 = (uint *)FUN_00419f40((int)puVar2,param_2);
      FUN_00408bb0(iVar1,0xc,(int)puVar2,local_30);
    } while (local_20 != local_8);
  }
  return puVar2;
}



int __cdecl FUN_00419f40(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  uint unaff_EDI;
  uint uVar13;
  int local_18;
  int local_8;
  
  local_8 = 0;
  if (0 < DAT_00435524) {
    local_18 = 0;
    iVar12 = DAT_00435530;
    do {
      if ((*(int *)(local_18 + DAT_00435560) != 0) &&
         (iVar9 = *(int *)(local_18 + DAT_0043552c), iVar9 <= *(int *)(local_18 + iVar12))) {
        do {
          uVar13 = 1;
          puVar5 = FUN_0040a880(1,*(int *)(param_1 + 0x10) << 2);
          puVar6 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),DAT_00435520,uVar13);
          puVar11 = *(uint **)(param_1 + 0x18);
          puVar1 = puVar11 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
          bVar4 = (byte)iVar9;
          iVar12 = iVar9 >> 5;
          if (puVar11 < puVar1) {
            uVar13 = 1 << (bVar4 & 0x1f);
            do {
              if ((puVar11[iVar12 + 1] & uVar13) != 0) {
                puVar5[puVar6[4]] = (uint)puVar11;
                puVar7 = (uint *)(puVar6[6] + puVar6[1] * puVar6[4] * 4);
                puVar6[4] = puVar6[4] + 1;
                FUN_00417290(puVar7,puVar11,*(int *)(local_18 + DAT_00435548));
                puVar7[iVar12 + 1] = puVar7[iVar12 + 1] | uVar13;
              }
              puVar11 = puVar11 + *(int *)(param_1 + 4);
            } while (puVar11 < puVar1);
          }
          puVar7 = FUN_00417930(*(undefined4 *)(param_2 + 0x10),DAT_00435520,unaff_EDI);
          puVar11 = *(uint **)(param_2 + 0x18);
          puVar1 = puVar11 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
          if (puVar11 < puVar1) {
            uVar13 = 1 << (bVar4 & 0x1f);
            do {
              if ((puVar11[iVar12 + 1] & uVar13) != 0) {
                uVar2 = puVar7[4];
                puVar7[4] = uVar2 + 1;
                puVar10 = (uint *)(puVar7[6] + puVar7[1] * uVar2 * 4);
                FUN_00417290(puVar10,puVar11,*(int *)(local_18 + DAT_00435548));
                puVar10[iVar12 + 1] = puVar10[iVar12 + 1] | uVar13;
              }
              puVar11 = puVar11 + *(int *)(param_2 + 4);
            } while (puVar11 < puVar1);
          }
          FUN_0040e9d0((int *)puVar6,(short *)puVar7);
          puVar11 = (uint *)puVar6[6];
          puVar1 = puVar11 + puVar6[4] * puVar6[1];
          puVar10 = puVar5;
          for (; puVar11 < puVar1; puVar11 = puVar11 + puVar6[1]) {
            if ((*puVar11 & 0x2000) == 0) {
              puVar3 = (uint *)*puVar10;
              if ((local_8 == DAT_00435524 + -1) ||
                 (iVar8 = FUN_00417560(*(uint **)(local_18 + DAT_00435548),(int)puVar3), iVar8 == 0)
                 ) {
                puVar3[iVar12 + 1] = puVar3[iVar12 + 1] & ~(1 << (bVar4 & 0x1f));
              }
              *puVar3 = *puVar3 & 0xffff7fff;
            }
            puVar10 = puVar10 + 1;
          }
          FUN_00417a40((short *)puVar6);
          FUN_00417a40((short *)puVar7);
          if (puVar5 != (uint *)0x0) {
            FUN_0041b8c0((int)puVar5);
          }
          iVar9 = iVar9 + 1;
          iVar12 = DAT_00435530;
        } while (iVar9 <= *(int *)(local_18 + DAT_00435530));
      }
      local_8 = local_8 + 1;
      local_18 = local_18 + 4;
    } while (local_8 < DAT_00435524);
  }
  FUN_004176a0(param_1);
  iVar12 = 0;
  if (0 < DAT_00435524) {
    do {
      if (*(int *)(DAT_00435560 + iVar12 * 4) != 0) {
        puVar11 = *(uint **)(param_1 + 0x18);
        puVar1 = puVar11 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
        for (; puVar11 < puVar1; puVar11 = puVar11 + *(int *)(param_1 + 4)) {
          if (((*puVar11 & 0x2000) != 0) &&
             (iVar9 = FUN_00417510(puVar11,*(int *)(DAT_00435548 + iVar12 * 4)), iVar9 != 0)) {
            *puVar11 = *puVar11 & 0xffffdfff;
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
          }
        }
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < DAT_00435524);
  }
  if (*(int *)(param_1 + 0x10) == *(int *)(param_1 + 0x14)) {
    return param_1;
  }
  iVar12 = FUN_004176e0(param_1);
  return iVar12;
}



uint * __cdecl FUN_0041a290(char *param_1)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  char *pcVar6;
  uint *puVar7;
  
  uVar3 = 0xffffffff;
  pcVar6 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  puVar2 = FUN_0040a880(1,~uVar3);
  uVar3 = 0xffffffff;
  do {
    pcVar6 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  puVar5 = (uint *)(pcVar6 + -uVar3);
  puVar7 = puVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)puVar7 = *(char *)puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
    puVar7 = (uint *)((int)puVar7 + 1);
  }
  return puVar2;
}



uint * __cdecl FUN_0041a2e0(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint unaff_EDI;
  int *piVar6;
  int local_10;
  int local_c;
  
  puVar4 = FUN_00417930((*(int *)(param_1 + 4) - param_1 >> 2) + -3,DAT_00435594,unaff_EDI);
  piVar6 = (int *)puVar4[6];
  iVar5 = 0;
  uVar1 = (*(int *)(param_1 + 4) - param_1 >> 2) - 3;
  puVar4[4] = uVar1;
  if (0 < (int)uVar1) {
    do {
      FUN_00417140(piVar6,puVar4[2]);
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + puVar4[1];
    } while (iVar5 < (int)puVar4[4]);
  }
  iVar5 = 0;
  local_10 = 0;
  local_c = 0;
  if (0 < DAT_00435520) {
    do {
      if (0 < *(int *)(DAT_00435580 + local_c * 4)) {
        if ((int)DAT_00435594 < iVar5) {
          FUN_0041b430((int *)&DAT_00431cb8,(byte *)s_Assertion_failed__file__s__line___00431200);
          FUN_0041f0ff((int *)&DAT_00431c98);
          puVar4 = (uint *)FUN_00420108();
          return puVar4;
        }
        uVar1 = puVar4[6];
        iVar3 = *(int *)(param_1 + 8);
        piVar6 = (int *)(param_1 + 0xc);
        while (iVar3 != 0) {
          if ((*(uint *)(iVar3 + ((local_c >> 5) + 1) * 4) & 1 << ((byte)local_c & 0x1f)) == 0) {
            puVar2 = (uint *)(uVar1 + ((iVar5 >> 5) + 1) * 4);
            *puVar2 = *puVar2 | 1 << ((byte)iVar5 & 0x1f);
          }
          uVar1 = uVar1 + puVar4[1] * 4;
          iVar3 = *piVar6;
          piVar6 = piVar6 + 1;
        }
        iVar5 = local_10 + 1;
        local_10 = iVar5;
      }
      local_c = local_c + 1;
    } while (local_c < DAT_00435520);
  }
  return puVar4;
}



uint * __cdecl FUN_0041a420(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint unaff_EDI;
  int iVar9;
  uint *local_18;
  int local_10;
  
  puVar4 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),DAT_00435520,unaff_EDI);
  puVar4[4] = *(uint *)(param_1 + 0x10);
  puVar5 = FUN_0040a880(1,DAT_00435524 * 4);
  iVar9 = 0;
  uVar6 = 0;
  local_10 = 0;
  puVar8 = puVar5;
  if (0 < DAT_00435524) {
    do {
      if (*(int *)(DAT_0043558c + uVar6 * 4) != 0) {
        *puVar8 = uVar6;
        iVar9 = iVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      uVar6 = uVar6 + 1;
      local_10 = iVar9;
    } while ((int)uVar6 < DAT_00435524);
  }
  uVar1 = *(uint *)(param_1 + 0x18);
  piVar2 = (int *)puVar4[6];
  uVar6 = uVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4) * 4;
  for (; uVar1 < uVar6; uVar1 = uVar1 + *(int *)(param_1 + 4) * 4) {
    FUN_00417170(piVar2,DAT_00435520);
    iVar9 = 0;
    local_18 = puVar5;
    if (0 < local_10) {
      do {
        if ((*(uint *)(uVar1 + 4 + (iVar9 >> 5) * 4) & 1 << ((byte)iVar9 & 0x1f)) != 0) {
          iVar3 = *(int *)(*local_18 * 4 + DAT_00435530);
          for (iVar7 = *(int *)(*local_18 * 4 + DAT_0043552c); iVar7 <= iVar3; iVar7 = iVar7 + 1) {
            if (*(int *)(DAT_00435580 + iVar7 * 4) == 0) {
              piVar2[(iVar7 >> 5) + 1] = piVar2[(iVar7 >> 5) + 1] & ~(1 << ((byte)iVar7 & 0x1f));
            }
          }
        }
        iVar9 = iVar9 + 1;
        local_18 = local_18 + 1;
      } while (iVar9 < local_10);
    }
    piVar2 = piVar2 + puVar4[1];
  }
  if (puVar5 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar5);
  }
  return puVar4;
}



void __cdecl FUN_0041a5a0(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  puVar1 = (uint *)param_1[6];
  puVar3 = puVar1 + param_1[4] * param_1[1];
  for (; puVar1 < puVar3; puVar1 = puVar1 + param_1[1]) {
    *puVar1 = *puVar1 & 0xffff;
    iVar2 = FUN_00417030(puVar1);
    *puVar1 = *puVar1 | iVar2 << 0x10;
  }
  puVar3 = FUN_0041a5f0(param_1);
  FUN_00404540((short *)puVar3);
  return;
}



uint * __cdecl FUN_0041a5f0(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint unaff_EDI;
  
  puVar6 = param_1;
  if (param_1[4] == 0) {
    FUN_00417a40((short *)param_1);
    puVar2 = FUN_00417930(1,param_1[2],(uint)puVar6);
    uVar10 = puVar2[4];
    puVar2[4] = uVar10 + 1;
    FUN_00417140((int *)(puVar2[6] + puVar2[1] * uVar10 * 4),param_1[2]);
  }
  else if (param_1[4] == 1) {
    uVar10 = param_1[6];
    puVar2 = FUN_00417930(param_1[2],param_1[2],unaff_EDI);
    puVar8 = param_1 + 2;
    param_1 = (uint *)0x0;
    if (0 < (int)*puVar8) {
      do {
        uVar9 = 1 << ((byte)param_1 & 0x1f);
        iVar4 = ((int)param_1 >> 5) * 4 + 4;
        if ((*(uint *)(iVar4 + uVar10) & uVar9) != 0) {
          uVar1 = puVar2[4];
          puVar2[4] = uVar1 + 1;
          iVar3 = FUN_00417140((int *)(puVar2[6] + puVar2[1] * uVar1 * 4),puVar6[2]);
          *(uint *)(iVar4 + iVar3) = *(uint *)(iVar4 + iVar3) | uVar9;
        }
        param_1 = (uint *)((int)param_1 + 1);
      } while ((int)param_1 < (int)puVar6[2]);
    }
    FUN_00417a40((short *)puVar6);
  }
  else {
    uVar10 = param_1[2];
    if ((int)uVar10 < 0x21) {
      iVar4 = 2;
    }
    else {
      iVar4 = ((int)(uVar10 - 1) >> 5) + 2;
    }
    puVar2 = FUN_0040a880(1,iVar4 << 2);
    puVar5 = (uint *)FUN_00417140((int *)puVar2,uVar10);
    puVar8 = (uint *)param_1[6];
    puVar2 = param_1 + 4;
    uVar10 = param_1[2] + 1;
    param_1 = (uint *)0x0;
    if (0 < (int)*puVar2) {
      do {
        if (*puVar8 >> 0x10 < uVar10) {
          FUN_004171c0((int)puVar5,puVar8);
          uVar10 = *puVar8 >> 0x10;
        }
        else if (*puVar8 >> 0x10 == uVar10) {
          FUN_00417240(puVar5,puVar5,(int)puVar8);
        }
        param_1 = (uint *)((int)param_1 + 1);
        puVar8 = puVar8 + puVar6[1];
      } while ((int)param_1 < (int)puVar6[4]);
    }
    if (uVar10 == 0) {
      puVar6[4] = 0;
      puVar2 = puVar6;
    }
    else if (uVar10 == 1) {
      puVar2 = FUN_0041adb0((int)puVar6,(int)puVar5);
      puVar2 = FUN_0041a5f0(puVar2);
      FUN_00417a40((short *)puVar6);
      puVar6 = (uint *)puVar2[6];
      iVar4 = 0;
      if (0 < (int)puVar2[4]) {
        do {
          FUN_00417240(puVar6,puVar6,(int)puVar5);
          iVar4 = iVar4 + 1;
          puVar6 = puVar6 + puVar2[1];
        } while (iVar4 < (int)puVar2[4]);
      }
    }
    else {
      iVar4 = FUN_0041ae30((int)puVar6,(int)puVar5);
      puVar2 = FUN_0041ad20((int)puVar6,iVar4);
      puVar2 = FUN_0041a5f0(puVar2);
      iVar7 = 0;
      uVar10 = puVar2[6];
      iVar3 = iVar4 >> 5;
      if (0 < (int)puVar2[4]) {
        do {
          puVar8 = (uint *)(iVar3 * 4 + 4 + uVar10);
          *puVar8 = *puVar8 | 1 << ((byte)iVar4 & 0x1f);
          iVar7 = iVar7 + 1;
          uVar10 = uVar10 + puVar2[1] * 4;
        } while (iVar7 < (int)puVar2[4]);
      }
      puVar8 = (uint *)puVar6[6];
      param_1 = (uint *)0x0;
      if (0 < (int)puVar6[4]) {
        uVar10 = 1 << ((byte)iVar4 & 0x1f);
        do {
          if ((uVar10 & puVar8[iVar3 + 1]) != 0) {
            puVar8[iVar3 + 1] = ~uVar10 & puVar8[iVar3 + 1];
            *puVar8 = *puVar8 & 0xffff | ((*puVar8 >> 0x10) - 1) * 0x10000;
          }
          puVar8 = puVar8 + puVar6[1];
          param_1 = (uint *)((int)param_1 + 1);
        } while ((int)param_1 < (int)puVar6[4]);
      }
      puVar6 = FUN_0041a5f0(puVar6);
      puVar2 = (uint *)FUN_00417860((int)puVar2,(short *)puVar6);
    }
    if (puVar5 != (uint *)0x0) {
      FUN_0041b8c0((int)puVar5);
    }
  }
  if (0xffff < puVar2[4]) {
    FUN_0040f8b0(2);
  }
  return puVar2;
}



uint * __cdecl FUN_0041a8b0(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  short *psVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  uint **ppuVar12;
  uint unaff_EDI;
  int iVar13;
  uint uVar14;
  uint in_stack_fffffee4;
  int local_118;
  uint *local_114;
  int local_110;
  uint *local_108;
  int local_104;
  uint *local_100;
  int local_fc [63];
  
  local_104 = FUN_0041b360();
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 < 1) {
    puVar2 = FUN_00417930(1,*(uint *)(param_1 + 8),in_stack_fffffee4);
    return puVar2;
  }
  iVar13 = 0;
  for (; iVar3 != 0; iVar3 = iVar3 >> 1) {
    iVar13 = iVar13 + 1;
  }
  iVar3 = iVar13;
  psVar4 = (short *)FUN_00417a20(param_1);
  puVar5 = FUN_00407cc0(psVar4);
  local_110 = 1;
  puVar6 = FUN_00417930(1,puVar5[2],(uint)psVar4);
  uVar11 = puVar6[4];
  puVar6[4] = uVar11 + 1;
  local_100 = puVar6;
  local_fc[0] = iVar13;
  FUN_00417170((int *)(puVar6[6] + puVar6[1] * uVar11 * 4),puVar5[2]);
  local_114 = (uint *)puVar5[6];
  local_108 = local_114 + puVar5[1] * puVar5[4];
  puVar2 = local_114 + (puVar5[4] - 1) * puVar5[1];
  if (local_114 < local_108) {
    do {
      uVar11 = puVar5[2];
      iVar13 = FUN_00417030(local_114);
      puVar6 = FUN_00417930(iVar13,uVar11,unaff_EDI);
      local_118 = 0;
      if (0 < (int)puVar5[2]) {
        do {
          uVar11 = 1 << ((byte)local_118 & 0x1f);
          iVar13 = (local_118 >> 5) * 4 + 4;
          if ((local_114[(local_118 >> 5) + 1] & uVar11) != 0) {
            uVar14 = puVar6[4];
            puVar6[4] = uVar14 + 1;
            iVar7 = FUN_00417170((int *)(puVar6[6] + puVar6[1] * uVar14 * 4),puVar5[2]);
            *(uint *)(iVar13 + iVar7) = *(uint *)(iVar13 + iVar7) & ~uVar11;
          }
          local_118 = local_118 + 1;
        } while (local_118 < (int)puVar5[2]);
      }
      local_fc[local_110 * 2 + -1] = (int)puVar6;
      local_fc[local_110 * 2] = iVar3;
      local_110 = local_110 + 1;
      if (1 < local_110) {
        ppuVar12 = &local_108 + local_110 * 2;
        do {
          if ((ppuVar12[1] != ppuVar12[-1]) && (local_114 != puVar2)) break;
          puVar6 = ppuVar12[-2];
          puVar1 = *ppuVar12;
          puVar8 = (uint *)FUN_0041aba0((int)puVar1,(int)puVar6,0);
          puVar10 = ppuVar12[1];
          if ((int)ppuVar12[-1] <= (int)ppuVar12[1]) {
            puVar10 = ppuVar12[-1];
          }
          if (((DAT_00435400 & 0x800) != 0) && ((int)puVar10 + -1 < 10)) {
            iVar13 = FUN_0041b360();
            FUN_004163a0(iVar13 - local_104);
            FUN_0041b470((byte *)s___EXACT_MINCOV__d____4d____4d_x___00431224);
            FUN_0041f0ff((int *)&DAT_00431c98);
          }
          FUN_00417a40((short *)puVar6);
          FUN_00417a40((short *)puVar1);
          ppuVar12[-2] = puVar8;
          ppuVar12[-1] = (uint *)((int)puVar10 + -1);
          local_110 = local_110 + -1;
          ppuVar12 = ppuVar12 + -2;
        } while (1 < local_110);
      }
      local_114 = local_114 + puVar5[1];
      puVar6 = local_100;
    } while (local_114 < local_108);
  }
  uVar11 = puVar5[2];
  if ((int)uVar11 < 0x21) {
    iVar3 = 2;
  }
  else {
    iVar3 = ((int)(uVar11 - 1) >> 5) + 2;
  }
  uVar14 = uVar11;
  puVar2 = FUN_0040a880(1,iVar3 << 2);
  piVar9 = (int *)FUN_00417140((int *)puVar2,uVar11);
  puVar10 = (uint *)FUN_00417170(piVar9,uVar14);
  puVar1 = (uint *)puVar6[6];
  puVar2 = puVar1 + puVar6[4] * puVar6[1];
  for (; puVar1 < puVar2; puVar1 = puVar1 + puVar6[1]) {
    FUN_00417290(puVar1,puVar10,(int)puVar1);
  }
  if (puVar10 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar10);
  }
  if ((DAT_00435400 & 0x1000) != 0) {
    FUN_0041b470((byte *)s_MINCOV__family_of_all_minimal_co_00431254);
    FUN_00417bc0((int)puVar6);
  }
  FUN_00417a40((short *)puVar5);
  return puVar6;
}



void __cdecl FUN_0041aba0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint *puVar6;
  undefined3 extraout_var;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint unaff_EDI;
  uint *puVar10;
  uint *local_14;
  int local_c;
  
  puVar6 = FUN_00417930(500,*(uint *)(param_1 + 8),unaff_EDI);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar10 = (uint *)puVar6[6];
  local_14 = (uint *)0x0;
  puVar9 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  local_c = 0;
  do {
    if (puVar9 <= puVar2) {
      puVar9 = FUN_004044e0((short *)puVar6);
      if (local_14 != (uint *)0x0) {
        FUN_00404630((short *)local_14,(short *)puVar9);
      }
      return;
    }
    uVar3 = *(uint *)(param_2 + 0x18);
    uVar1 = uVar3 + *(int *)(param_2 + 4) * *(int *)(param_2 + 0x10) * 4;
    for (; uVar3 < uVar1; uVar3 = uVar3 + *(int *)(param_2 + 4) * 4) {
      bVar5 = FUN_004173a0(puVar10,puVar2,uVar3);
      if (CONCAT31(extraout_var,bVar5) != 0) {
        if (param_3 != 0) {
          iVar7 = FUN_00417030(puVar10);
          if (local_c < iVar7) {
            if (local_14 != (uint *)0x0) {
              FUN_00417a40((short *)local_14);
              local_14 = (uint *)0x0;
            }
            puVar10 = (uint *)puVar6[6];
            puVar6[4] = 0;
            FUN_004171f0(puVar10,puVar2,uVar3);
            local_c = iVar7;
          }
          else if (iVar7 < local_c) goto LAB_0041acc3;
        }
        uVar4 = puVar6[4];
        puVar6[4] = uVar4 + 1;
        if ((int)(uVar4 + 1) < (int)puVar6[3]) {
          puVar10 = puVar10 + puVar6[1];
        }
        else {
          puVar8 = FUN_004044e0((short *)puVar6);
          if (local_14 != (uint *)0x0) {
            puVar8 = FUN_00404630((short *)local_14,(short *)puVar8);
          }
          puVar6 = FUN_00417930(500,*(uint *)(param_1 + 8),unaff_EDI);
          puVar10 = (uint *)puVar6[6];
          local_14 = puVar8;
        }
      }
LAB_0041acc3:
    }
    puVar2 = puVar2 + *(int *)(param_1 + 4);
  } while( true );
}



uint * __cdecl FUN_0041ad20(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint unaff_EDI;
  
  puVar2 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),*(uint *)(param_1 + 8),unaff_EDI);
  puVar4 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar4 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  uVar3 = puVar2[6];
  if (puVar4 < puVar1) {
    do {
      if ((puVar4[(param_2 >> 5) + 1] & 1 << ((byte)param_2 & 0x1f)) == 0) {
        FUN_004171c0(uVar3,puVar4);
        uVar3 = uVar3 + puVar2[1] * 4;
        puVar2[4] = puVar2[4] + 1;
      }
      puVar4 = puVar4 + *(int *)(param_1 + 4);
    } while (puVar4 < puVar1);
  }
  return puVar2;
}



uint * __cdecl FUN_0041adb0(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint unaff_EDI;
  
  puVar3 = FUN_00417930(*(undefined4 *)(param_1 + 0x10),*(uint *)(param_1 + 8),unaff_EDI);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  uVar5 = puVar3[6];
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    iVar4 = FUN_00417510(puVar2,param_2);
    if (iVar4 != 0) {
      FUN_004171c0(uVar5,puVar2);
      puVar3[4] = puVar3[4] + 1;
      uVar5 = uVar5 + puVar3[1] * 4;
    }
  }
  return puVar3;
}



int __cdecl FUN_0041ae30(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint unaff_ESI;
  uint *puVar5;
  
  puVar1 = FUN_004180f0(param_1,param_2);
  iVar4 = -1;
  uVar3 = 0;
  iVar2 = 0;
  puVar5 = puVar1;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      if (uVar3 < *puVar5) {
        uVar3 = *puVar5;
        iVar4 = iVar2;
      }
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
    if (iVar4 != -1) goto LAB_0041ae7d;
  }
  FUN_00408c40((int *)s_abs_select_restricted__should_no_00431280,unaff_ESI);
LAB_0041ae7d:
  if (puVar1 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar1);
  }
  return iVar4;
}



undefined4 __cdecl FUN_0041ae90(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 local_4;
  
  local_4 = 0;
  puVar3 = FUN_00402a00(param_2,param_3);
  puVar2 = *(uint **)(param_1 + 0x18);
  puVar1 = puVar2 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_1 + 4)) {
    iVar4 = FUN_0040ef50(puVar3,puVar2);
    if (iVar4 == 0) {
      FUN_0040aa50(1,0x16);
      local_4 = 1;
      if (DAT_00435570 == 0) break;
      FUN_00409a60((int)puVar2);
      FUN_0041b470(&DAT_004312b8);
    }
  }
  if (*puVar3 != 0) {
    FUN_0041b8c0(*puVar3);
    *puVar3 = 0;
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  puVar3 = FUN_00402a00(param_1,param_3);
  puVar2 = *(uint **)(param_2 + 0x18);
  puVar1 = puVar2 + *(int *)(param_2 + 0x10) * *(int *)(param_2 + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + *(int *)(param_2 + 4)) {
    iVar4 = FUN_0040ef50(puVar3,puVar2);
    if (iVar4 == 0) {
      FUN_0040aa50(1,0x17);
      local_4 = 1;
      if (DAT_00435570 == 0) break;
      FUN_00409a60((int)puVar2);
      FUN_0041b470(&DAT_004312bc);
    }
  }
  if (*puVar3 != 0) {
    FUN_0041b8c0(*puVar3);
    *puVar3 = 0;
  }
  if (puVar3 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar3);
  }
  return local_4;
}



undefined4 __cdecl FUN_0041afd0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (((int *)param_1[7] != (int *)0x0) && (*(int *)param_1[7] != 0)) {
    if (((int *)param_2[7] != (int *)0x0) && (*(int *)param_2[7] != 0)) {
      FUN_0041b050(param_1,param_2);
      if (*(int *)(*param_1 + 8) != *(int *)(*param_2 + 8)) {
        FUN_0040aa50(1,0x19);
        return 1;
      }
      uVar1 = FUN_0041ae90(*param_2,*param_1,param_1[1]);
      return uVar1;
    }
  }
  FUN_0040aa50(1,0x18);
  return 1;
}



void __cdecl FUN_0041b050(int *param_1,int *param_2)

{
  byte bVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  uint uVar10;
  bool bVar11;
  uint local_14;
  uint *local_c;
  int local_8;
  
  uVar7 = 0;
  local_14 = 0;
  puVar2 = FUN_0040a880(1,*(int *)(*param_2 + 8) << 2);
  local_8 = 0;
  local_c = puVar2;
  if (0 < *(int *)(*param_2 + 8)) {
    do {
      uVar10 = 0;
      if (0 < *(int *)(*param_1 + 8)) {
        puVar8 = (undefined4 *)param_1[7];
        do {
          pbVar9 = (byte *)*puVar8;
          pbVar3 = *(byte **)(param_2[7] + local_8 * 4);
          do {
            bVar1 = *pbVar3;
            bVar11 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_0041b0d8:
              iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
              goto LAB_0041b0dd;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar11 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_0041b0d8;
            pbVar3 = pbVar3 + 2;
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_0041b0dd:
          if (iVar4 == 0) {
            local_14 = local_14 + 1;
            *local_c = uVar10;
            local_c = local_c + 1;
            uVar7 = local_14;
            break;
          }
          uVar10 = uVar10 + 1;
          puVar8 = puVar8 + 1;
          uVar7 = local_14;
        } while ((int)uVar10 < *(int *)(*param_1 + 8));
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(*param_2 + 8));
  }
  if ((short *)*param_1 != (short *)0x0) {
    puVar5 = FUN_00418550((short *)*param_1,(int *)puVar2,uVar7);
    *param_1 = (int)puVar5;
  }
  if ((short *)param_1[2] != (short *)0x0) {
    puVar5 = FUN_00418550((short *)param_1[2],(int *)puVar2,uVar7);
    param_1[2] = (int)puVar5;
  }
  if ((short *)param_1[1] != (short *)0x0) {
    puVar5 = FUN_00418550((short *)param_1[1],(int *)puVar2,uVar7);
    param_1[1] = (int)puVar5;
  }
  puVar5 = FUN_0040a880(1,DAT_00435520 * 4);
  uVar10 = uVar7;
  if (0 < (int)uVar7) {
    puVar6 = puVar5;
    do {
      uVar7 = uVar7 - 1;
      *puVar6 = *(uint *)(param_1[7] + *(int *)(((int)puVar2 - (int)puVar5) + (int)puVar6) * 4);
      puVar6 = puVar6 + 1;
      uVar10 = local_14;
    } while (uVar7 != 0);
  }
  if ((int)uVar10 < DAT_00435520) {
    puVar6 = puVar5 + uVar10;
    do {
      *puVar6 = 0;
      uVar10 = uVar10 + 1;
      puVar6 = puVar6 + 1;
    } while ((int)uVar10 < DAT_00435520);
  }
  if (param_1[7] != 0) {
    FUN_0041b8c0(param_1[7]);
    param_1[7] = 0;
  }
  param_1[7] = (int)puVar5;
  if (puVar2 != (uint *)0x0) {
    FUN_0041b8c0((int)puVar2);
  }
  return;
}



undefined4 __cdecl FUN_0041b200(int *param_1)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  psVar1 = (short *)FUN_00419a60(*param_1,param_1[1]);
  if (*(int *)(psVar1 + 8) != 0) {
    FUN_0040aa50(4,0x1a);
    if (DAT_00435570 != 0) {
      FUN_00409c20((int)psVar1);
    }
    uVar5 = 1;
  }
  FUN_0041f0ff((int *)&DAT_00431c98);
  FUN_00417a40(psVar1);
  psVar1 = (short *)FUN_00419a60(*param_1,param_1[2]);
  if (*(int *)(psVar1 + 8) != 0) {
    FUN_0040aa50(4,0x1b);
    if (DAT_00435570 != 0) {
      FUN_00409c20((int)psVar1);
    }
    uVar5 = 1;
  }
  FUN_0041f0ff((int *)&DAT_00431c98);
  FUN_00417a40(psVar1);
  psVar1 = (short *)FUN_00419a60(param_1[1],param_1[2]);
  if (*(int *)(psVar1 + 8) != 0) {
    FUN_0040aa50(4,0x1c);
    if (DAT_00435570 != 0) {
      FUN_00409c20((int)psVar1);
    }
    uVar5 = 1;
  }
  FUN_0041f0ff((int *)&DAT_00431c98);
  FUN_00417a40(psVar1);
  piVar2 = (int *)FUN_00402b00(*param_1,param_1[1],param_1[2]);
  iVar3 = FUN_0040ef70(piVar2);
  if (iVar3 == 0) {
    puVar4 = (uint *)FUN_00402b00(*param_1,param_1[1],param_1[2]);
    puVar4 = FUN_00403160(puVar4);
    FUN_0041b470((byte *)s_There_are_minterms_left_unspecif_004312c0);
    if (DAT_00435570 != 0) {
      FUN_00409c20((int)puVar4);
    }
    uVar5 = 1;
    FUN_00417a40((short *)puVar4);
  }
  FUN_0041f0ff((int *)&DAT_00431c98);
  return uVar5;
}



int FUN_0041b360(void)

{
  int local_4;
  
  FUN_0041feca(&local_4);
  return local_4 * 1000;
}



void __cdecl FUN_0041b380(char param_1,int *param_2)

{
  undefined uStack00000005;
  
  uStack00000005 = 0;
  FUN_0041b3c0(&param_1,param_2);
  return;
}



void __cdecl FUN_0041b3a0(char param_1,int *param_2)

{
  FUN_0041b380(param_1,param_2);
  return;
}



int __cdecl FUN_0041b3c0(char *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)&DAT_00431c98) {
    FUN_00427c0d(&DAT_00435270,param_1);
    return 0;
  }
  if (param_2 == (int *)&DAT_00431cb8) {
    FUN_00427c0d(&DAT_00435210,param_1);
    return 0;
  }
  iVar1 = FUN_0041f46a(param_1,param_2);
  return iVar1;
}



void __cdecl FUN_0041b430(int *param_1,byte *param_2)

{
  char local_800 [2048];
  
  FUN_0041ffa6(local_800,param_2,(undefined4 *)&stack0x0000000c);
  FUN_0041b3c0(local_800,param_1);
  return;
}



undefined4 __cdecl FUN_0041b470(byte *param_1)

{
  char local_800 [2048];
  
  FUN_0041ffa6(local_800,param_1,(undefined4 *)&stack0x00000008);
  FUN_00427c0d(&DAT_00435270,local_800);
  return 0;
}



void __cdecl FUN_0041b4e0(int param_1,undefined4 param_2,byte *param_3,undefined4 *param_4)

{
  int *piVar1;
  
  if (DAT_00433518 != 0) {
    DAT_00433518 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  }
  if (param_1 == -1) {
    FUN_0041c730(-1,param_2,param_3,param_4);
    return;
  }
  piVar1 = FUN_0041c190(&DAT_00433510,0x431354);
  FUN_0041c940(piVar1);
  return;
}



uint * __cdecl FUN_0041b590(int param_1)

{
  int iVar1;
  undefined4 *unaff_EBP;
  int iVar2;
  uint uVar3;
  byte *unaff_EDI;
  uint *puVar4;
  
  iVar2 = param_1 + 4;
  if (iVar2 < 8) {
    iVar2 = 8;
  }
  if (DAT_0043353c == 0) {
    DAT_0043353c = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  }
  DAT_00433518 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  if (iVar2 < 1) {
    uVar3 = 0;
    iVar2 = 0;
  }
  else {
    if (iVar2 < 0x101) {
      uVar3 = (iVar2 - 1U >> 2) + 1;
    }
    else {
      iVar1 = 8;
      for (uVar3 = iVar2 + -1 >> 8; uVar3 != 0; uVar3 = uVar3 >> 1) {
        iVar1 = iVar1 + 1;
      }
      uVar3 = (iVar1 * 2 + 0x30) - (uint)(iVar2 <= 3 << ((char)iVar1 - 2U & 0x1f));
    }
    if (uVar3 < 0x41) {
      iVar2 = uVar3 * 4;
    }
    else {
      iVar2 = ((uVar3 - 0x33 & 1) != 0) + 3 << ((byte)(uVar3 - 0x33 >> 1) & 0x1f);
    }
  }
  puVar4 = (uint *)(&DAT_004332f0)[uVar3];
  if (puVar4 == (uint *)0x0) {
    if ((int)DAT_00431344 < iVar2) {
      FUN_0041b7e0(DAT_0043351c,DAT_00431344);
      DAT_00431344 = (((int)(iVar2 + (iVar2 >> 0x1f & 0xffffU)) >> 0x10) + 1) * 0x10000;
      DAT_0043351c = (uint *)VirtualAlloc((LPVOID)0x0,DAT_00431344,0x2000,1);
      VirtualAlloc(DAT_0043351c,DAT_00431344,0x1000,4);
      if ((DAT_0043351c == (uint *)0xffffffff) || (DAT_0043351c == (uint *)0x0)) {
        FUN_0041bc00(uVar3);
        if (DAT_0043351c == (uint *)0x0) {
          if (DAT_00433540 == (code *)0x0) {
            FUN_0041b4e0(-1,s_out_of_memory_0043139c,unaff_EDI,unaff_EBP);
          }
          else {
            (*DAT_00433540)();
          }
        }
      }
      else {
        if ((DAT_00433520 == (uint *)0x0) || (DAT_0043351c < DAT_00433520)) {
          DAT_00433520 = DAT_0043351c;
        }
        if ((DAT_00433524 == (uint *)0x0) ||
           (DAT_00433524 < (uint *)((int)DAT_0043351c + (DAT_00431344 - 1)))) {
          DAT_00433524 = (uint *)((int)DAT_0043351c + (DAT_00431344 - 1));
        }
        DAT_00433528 = DAT_00433528 + 1;
        DAT_00433530 = DAT_00433530 + DAT_00431344;
      }
    }
    DAT_00431344 = DAT_00431344 - iVar2;
    puVar4 = DAT_0043351c;
    DAT_0043351c = (uint *)((int)DAT_0043351c + iVar2);
  }
  else {
    (&DAT_004332f0)[uVar3] = *puVar4;
  }
  if ((puVar4 < DAT_00433520) || (DAT_00433524 < puVar4)) {
    FUN_0041b4e0(-2,s_free_list_was_corrupted_somehow___004313ac,unaff_EDI,unaff_EBP);
  }
  *puVar4 = uVar3 & 0xffff0fff | 0xa5a50000;
  DAT_00433534 = DAT_00433534 + iVar2;
  DAT_0043352c = DAT_0043352c + 1;
  if (DAT_00433538 < DAT_00433534) {
    DAT_00433538 = DAT_00433534;
  }
  if (DAT_00433518 != 0) {
    DAT_00433518 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  }
  return puVar4 + 1;
}



void __cdecl FUN_0041b7e0(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (3 < param_2) {
    if (param_2 < 1) {
      uVar2 = 0;
      iVar1 = 0;
    }
    else {
      if (param_2 < 0x101) {
        uVar2 = (param_2 - 1U >> 2) + 1;
      }
      else {
        iVar1 = 8;
        for (uVar2 = param_2 + -1 >> 8; uVar2 != 0; uVar2 = uVar2 >> 1) {
          iVar1 = iVar1 + 1;
        }
        uVar2 = (iVar1 * 2 + 0x30) - (uint)(param_2 <= 3 << ((char)iVar1 - 2U & 0x1f));
      }
      if (uVar2 < 0x41) {
        iVar1 = uVar2 * 4;
      }
      else {
        iVar1 = ((uVar2 - 0x33 & 1) != 0) + 3 << ((byte)(uVar2 - 0x33 >> 1) & 0x1f);
      }
    }
    uVar3 = uVar2;
    if (iVar1 != param_2) {
      uVar3 = uVar2 - 1;
      if (uVar3 < 0x41) {
        iVar1 = uVar3 * 4;
      }
      else {
        iVar1 = ((uVar2 - 0x34 & 1) != 0) + 3 << ((byte)(uVar2 - 0x34 >> 1) & 0x1f);
      }
      FUN_0041b7e0((undefined4 *)(iVar1 + (int)param_1),param_2 - iVar1);
    }
    *param_1 = (&DAT_004332f0)[uVar3];
    (&DAT_004332f0)[uVar3] = param_1;
  }
  return;
}



void __cdecl FUN_0041b8c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *unaff_ESI;
  uint *puVar4;
  undefined4 *unaff_retaddr;
  char *pcVar5;
  
  if (param_1 != 0) {
    if (DAT_0043353c == 0) {
      DAT_0043353c = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
    }
    DAT_00433518 = 1;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
    puVar4 = (uint *)(param_1 + -4);
    if ((puVar4 < DAT_00433520) || (DAT_00433524 < puVar4)) {
      FUN_0041b4e0(-3,s_attempt_to_free___bogus_pointer_004313d0,unaff_ESI,unaff_retaddr);
    }
    uVar1 = *puVar4;
    if (((uVar1 & 0xffff0000) == 0xa5a50000) && (uVar2 = uVar1 & 0xfff, uVar2 < 0x81)) {
      if ((uVar1 & 0x1000) == 0) {
        DAT_0043352c = DAT_0043352c + -1;
        if (uVar2 < 0x41) {
          iVar3 = uVar2 * 4;
        }
        else {
          iVar3 = ((uVar2 - 0x33 & 1) != 0) + 3 << ((byte)(uVar2 - 0x33 >> 1) & 0x1f);
        }
        DAT_00433534 = DAT_00433534 - iVar3;
        *puVar4 = (&DAT_004332f0)[uVar2];
        (&DAT_004332f0)[uVar2] = puVar4;
      }
    }
    else {
      iVar3 = FUN_0041ba00(puVar4);
      if (iVar3 == 0) {
        pcVar5 = s_attempt_to_free___corrupt_pointe_00431420;
        iVar3 = -3;
      }
      else {
        pcVar5 = s_attempt_to_free___pointer_which_i_004313f0;
        iVar3 = -4;
      }
      FUN_0041b4e0(iVar3,pcVar5,unaff_ESI,unaff_retaddr);
    }
    if (DAT_00433518 != 0) {
      DAT_00433518 = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
    }
  }
  return;
}



undefined4 __cdecl FUN_0041ba00(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_004332f0;
  do {
    for (puVar1 = (undefined4 *)*puVar2; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1
        ) {
      if (param_1 == puVar1) {
        return 1;
      }
    }
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x4334f4);
  return 0;
}



uint * __cdecl FUN_0041ba30(uint *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *unaff_EBP;
  byte *unaff_ESI;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  
  if (param_1 == (uint *)0x0) {
    puVar1 = FUN_0041b590(param_2);
    return puVar1;
  }
  if (DAT_0043353c == 0) {
    DAT_0043353c = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  }
  DAT_00433518 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  puVar1 = param_1 + -1;
  if ((puVar1 < DAT_00433520) || (DAT_00433524 < puVar1)) {
    FUN_0041b4e0(-3,s_attempt_to_realloc___bogus_point_00431444,unaff_ESI,unaff_EBP);
  }
  if (((*puVar1 & 0xffff0000) == 0xa5a50000) && (uVar2 = *puVar1 & 0xfff, uVar2 < 0x81)) {
    if (uVar2 < 0x41) {
      iVar3 = uVar2 << 2;
    }
    else {
      iVar3 = ((uVar2 - 0x33 & 1) != 0) + 3 << ((byte)(uVar2 - 0x33 >> 1) & 0x1f);
    }
    uVar2 = iVar3 - 4;
    if ((int)uVar2 < param_2) {
      if (DAT_00433518 != 0) {
        DAT_00433518 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
      }
      puVar1 = FUN_0041b590(param_2);
      if (puVar1 != (uint *)0x0) {
        puVar5 = param_1;
        puVar6 = puVar1;
        for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined *)puVar6 = *(undefined *)puVar5;
          puVar5 = (uint *)((int)puVar5 + 1);
          puVar6 = (uint *)((int)puVar6 + 1);
        }
        FUN_0041b8c0((int)param_1);
      }
    }
    else {
      puVar1 = param_1;
      if (DAT_00433518 != 0) {
        DAT_00433518 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
        return param_1;
      }
    }
    return puVar1;
  }
  iVar3 = FUN_0041ba00(puVar1);
  if (iVar3 == 0) {
    pcVar7 = s_attempt_to_realloc___corrupt_poi_00431498;
    iVar3 = -3;
  }
  else {
    pcVar7 = s_attempt_to_realloc___an_already_f_00431468;
    iVar3 = -4;
  }
  FUN_0041b4e0(iVar3,pcVar7,unaff_ESI,unaff_EBP);
  if (DAT_00433518 != 0) {
    DAT_00433518 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004334f8);
  }
  return (uint *)0x0;
}



undefined4 * __cdecl FUN_0041bbc0(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = param_1 * param_2;
  puVar1 = FUN_0041b590(uVar3);
  puVar4 = puVar1;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined *)puVar4 = 0;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  return puVar1;
}



void __cdecl FUN_0041bc00(int param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = param_1 + 1;
  do {
    if (uVar1 < 0x81) {
      piVar2 = &DAT_004332f0 + uVar1;
      uVar3 = uVar1;
      do {
        if (*piVar2 != 0) {
          DAT_00431344 = uVar3 * 4;
          DAT_0043351c = (undefined4 *)(&DAT_004332f0)[uVar3];
          if (uVar3 < 0x41) {
            (&DAT_004332f0)[uVar3] = *DAT_0043351c;
            return;
          }
          DAT_00431344 = ((uVar3 - 0x33 & 1) != 0) + 3 << ((byte)(uVar3 - 0x33 >> 1) & 0x1f);
          (&DAT_004332f0)[uVar3] = *DAT_0043351c;
          return;
        }
        piVar2 = piVar2 + 1;
        uVar3 = uVar3 + 1;
      } while ((int)piVar2 < 0x4334f4);
    }
    if (iVar4 == 0) {
      FUN_0041bcb0();
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  DAT_0043351c = (undefined4 *)0x0;
  DAT_00431344 = 0xffffffff;
  return;
}



void FUN_0041bcb0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int local_8;
  undefined4 *local_4;
  
  iVar8 = 0;
  local_4 = (undefined4 *)0x0;
  puVar7 = (undefined4 *)0x0;
  local_8 = 0;
  iVar9 = 2;
  do {
    iVar5 = iVar9 * 4;
    puVar1 = (undefined4 *)(&DAT_004332f0)[iVar9];
    if (puVar1 != (undefined4 *)0x0) {
      if (0x40 < iVar9) {
        iVar5 = ((iVar9 - 0x33U & 1) != 0) + 3 << ((byte)(iVar9 - 0x33U >> 1) & 0x1f);
      }
      while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {
        puVar3[1] = iVar5;
        iVar8 = iVar8 + 1;
        local_8 = local_8 + iVar5;
        puVar7 = puVar3;
        puVar1 = (undefined4 *)*puVar3;
      }
      *puVar7 = local_4;
      local_4 = (undefined4 *)(&DAT_004332f0)[iVar9];
      (&DAT_004332f0)[iVar9] = 0;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0x81);
  if ((local_8 != 0) && (local_4 != (undefined4 *)0x0)) {
    piVar6 = FUN_0041bde0(local_4,&LAB_0041bea0,iVar8);
    piVar2 = piVar6;
    while (piVar4 = piVar2, piVar4 != (int *)0x0) {
      piVar2 = (int *)*piVar4;
      if ((int *)(piVar4[1] + (int)piVar4) == piVar2) {
        piVar4[1] = piVar4[1] + piVar2[1];
        *piVar4 = *piVar2;
        piVar2 = piVar4;
      }
      else if ((int *)(piVar4[1] + (int)piVar4 + 4) == piVar2) {
        iVar8 = FUN_0041be90();
        if (iVar8 == 0) {
          piVar2 = (int *)*piVar4;
        }
        else {
          piVar4[1] = piVar4[1] + ((int *)*piVar4)[1] + 4;
          *piVar4 = *(int *)*piVar4;
          piVar2 = piVar4;
        }
      }
    }
    while (piVar6 != (int *)0x0) {
      piVar2 = (int *)*piVar6;
      FUN_0041b7e0(piVar6,piVar6[1]);
      piVar6 = piVar2;
    }
  }
  return;
}



undefined4 * __cdecl FUN_0041bde0(undefined4 *param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 **ppuVar8;
  undefined4 **ppuVar9;
  undefined4 **ppuVar10;
  
  iVar5 = param_3;
  if (1 < param_3) {
    iVar7 = param_3 / 2;
    iVar2 = iVar7 + -1;
    puVar6 = param_1;
    if (0 < iVar2) {
      do {
        puVar6 = (undefined4 *)*puVar6;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    ppuVar4 = (undefined4 **)*puVar6;
    *puVar6 = 0;
    ppuVar3 = (undefined4 **)param_1;
    if (1 < iVar7) {
      ppuVar3 = (undefined4 **)FUN_0041bde0(param_1,param_2,iVar7);
    }
    puVar1 = param_2;
    if (1 < iVar5 - iVar7) {
      ppuVar4 = (undefined4 **)FUN_0041bde0(ppuVar4,param_2,iVar5 - iVar7);
    }
    ppuVar8 = &param_1;
    do {
      while (ppuVar10 = ppuVar3, ppuVar9 = ppuVar4, iVar5 = (*(code *)puVar1)(ppuVar10,ppuVar9),
            iVar5 < 1) {
        *ppuVar8 = ppuVar10;
        ppuVar8 = ppuVar10;
        ppuVar4 = ppuVar9;
        ppuVar3 = (undefined4 **)*ppuVar10;
        if ((undefined4 **)*ppuVar10 == (undefined4 **)0x0) {
          *ppuVar10 = ppuVar9;
          return param_1;
        }
      }
      *ppuVar8 = ppuVar9;
      ppuVar8 = ppuVar9;
      ppuVar4 = (undefined4 **)*ppuVar9;
      ppuVar3 = ppuVar10;
    } while ((undefined4 **)*ppuVar9 != (undefined4 **)0x0);
    *ppuVar9 = ppuVar10;
  }
  return param_1;
}



undefined4 FUN_0041be90(void)

{
  DAT_004332f4 = 0;
  return 1;
}



void __cdecl FUN_0041bfc0(int param_1)

{
  FUN_0041b8c0(param_1);
  return;
}



void __cdecl FUN_0041bfd0(int param_1)

{
  FUN_0041b590(param_1);
  return;
}



undefined4 __cdecl FUN_0041bfe0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00433540;
  DAT_00433540 = param_1;
  return uVar1;
}



undefined4 * __thiscall FUN_0041c000(void *this,undefined4 param_1,byte *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  void *pvVar3;
  uint uVar4;
  void *extraout_ECX;
  void *extraout_ECX_00;
  
  *(undefined4 *)this = 0;
  *(undefined *)((int)this + 6) = 0;
  if (DAT_00433548 == (void *)0x0) {
    pvVar3 = (void *)FUN_0041bfd0(0x10);
    if (pvVar3 == (void *)0x0) {
      DAT_00433548 = (void *)0x0;
    }
    else {
      FUN_0041dd70(pvVar3,0x173,&LAB_0041e3c0);
      DAT_00433548 = pvVar3;
    }
  }
  FUN_0041de50(DAT_00433548,param_2,this,0);
  bVar1 = *param_2;
  pvVar3 = extraout_ECX;
  while ((bVar1 != 0 &&
         (uVar4 = FUN_0042031f(pvVar3,(int)(char)bVar1), pvVar3 = extraout_ECX_00, uVar4 == 0))) {
    bVar1 = param_2[1];
    param_2 = param_2 + 1;
  }
  if (*param_2 == 0) {
    *(undefined2 *)((int)this + 4) = 0xffff;
    return (undefined4 *)this;
  }
  uVar2 = FUN_0041f45f(pvVar3,param_2);
  *(undefined2 *)((int)this + 4) = uVar2;
  return (undefined4 *)this;
}



undefined4 __fastcall FUN_0041c0a0(undefined4 *param_1)

{
  int iVar1;
  int *this;
  char *pcVar2;
  bool bVar3;
  char local_800 [2048];
  
  this = DAT_0043354c;
  if ((*(byte *)((int)param_1 + 6) & 2) != 0) {
    bVar3 = DAT_0043354c == (int *)0x0;
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xfd;
    if (bVar3) {
      return 0;
    }
    iVar1 = *(int *)(*this + 4);
    if (*(int *)(iVar1 + 0x34 + (int)this) < 0) {
      FUN_004282ad((LPCRITICAL_SECTION)((int)this + iVar1 + 0x38));
    }
    *(undefined4 *)((int)this + iVar1 + 8) = 0;
    if (*(int *)((int)this + iVar1 + 0x34) < 0) {
      FUN_004282b8((LPCRITICAL_SECTION)((int)this + iVar1 + 0x38));
    }
    FUN_00428197(this,*param_1);
    FUN_004280a1(this,(int)local_800,0x800,10);
    if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) != 0) {
      return 0;
    }
    FUN_0041ced0();
    FUN_0041c170(local_800);
    pcVar2 = FUN_0041d070(local_800);
    *param_1 = pcVar2;
    FUN_0041ceb0();
  }
  return *param_1;
}



void __cdecl FUN_0041c170(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (param_1[~uVar2 - 2] == '\r') {
    param_1[~uVar2 - 2] = '\0';
  }
  return;
}



int * __thiscall FUN_0041c190(void *this,int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)((int)this + 6) & 2) != 0) {
    uVar1 = FUN_0041c0a0((undefined4 *)this);
    *(undefined4 *)this = uVar1;
  }
                    // WARNING: Load size is inaccurate
  if (*this == 0) {
    *(int *)this = param_1;
  }
  return (int *)this;
}



void FUN_0041c3f0(void)

{
  FUN_00428a46();
  return;
}



void FUN_0041c400(void)

{
  FUN_0042047d(0x41c410);
  return;
}



int * __thiscall FUN_0041c5b0(void *this,int param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined **)this = &DAT_0042b13c;
    FUN_00428b7f((undefined4 *)((int)this + 0x10));
  }
  FUN_00428fac();
                    // WARNING: Load size is inaccurate
  *(undefined4 *)((int)this + 8) = 0;
  *(int *)((int)this + 0xc) = param_1;
  *(undefined ***)(*(int *)(*this + 4) + (int)this) = &PTR_LAB_0042b138;
  return (int *)this;
}



void __fastcall FUN_0041c600(int param_1)

{
  int *this;
  char *pcVar1;
  
  this = (int *)(param_1 + -0x10);
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x10) + 4) + -0x10 + param_1) = &PTR_LAB_0042b138;
  if (*(int *)(param_1 + -8) == 0) {
    FUN_00429070(this,0);
    pcVar1 = (char *)FUN_00428d06(*(int *)(*(int *)(*this + 4) + 4 + (int)this));
    if (*(int *)(&DAT_00433d98 + *(int *)(DAT_00433d90 + 4)) == 0) {
      FUN_00427c0d(&DAT_00433d90,pcVar1);
      FUN_00427c36(&DAT_00433d90);
    }
    if (*(int *)(param_1 + -4) == 0) {
      FUN_00427c0d(&DAT_00435270,pcVar1);
      FUN_00427c36(&DAT_00435270);
    }
    FUN_0041bfc0((int)pcVar1);
  }
  FUN_0042905d(param_1 + -8);
  return;
}



void __fastcall FUN_0041c690(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  
  param_1[2] = 1;
  FUN_00429070(param_1,0);
  pcVar1 = (char *)FUN_00428d06(*(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
  if (*(int *)(&DAT_00433d98 + *(int *)(DAT_00433d90 + 4)) == 0) {
    piVar2 = FUN_00427c0d(&DAT_00433d90,pcVar1);
    FUN_00429070(piVar2,10);
    FUN_00427c36(&DAT_00433d90);
  }
  if (param_1[3] == 0) {
    if (DAT_00433df8 != (code *)0x0) {
      (*DAT_00433df8)();
      FUN_0041bfc0((int)pcVar1);
      return;
    }
    piVar2 = FUN_00427c0d(&DAT_00435270,pcVar1);
    FUN_00429070(piVar2,10);
    FUN_00427c36(&DAT_00435270);
  }
  FUN_0041bfc0((int)pcVar1);
  return;
}



void FUN_0041c730(int param_1,undefined4 param_2,byte *param_3,undefined4 *param_4)

{
  int *piVar1;
  char *pcVar2;
  void *this;
  int *piVar3;
  int unaff_retaddr;
  void *this_00;
  
  FUN_0041d740();
  FUN_00429070(&DAT_00435270,10);
  if (DAT_00433de8 == 0) {
    piVar1 = FUN_0041c190(&DAT_00433d88,0x4315d0);
    pcVar2 = (char *)*piVar1;
  }
  else {
    piVar1 = FUN_0041c190(&DAT_00433d80,0x4315c0);
    pcVar2 = FUN_0041d5e0((byte *)*piVar1);
  }
  FUN_00427c0d(&DAT_00435270,pcVar2);
  piVar1 = FUN_0041c190(&DAT_00433e00,0x4315dc);
  piVar1 = FUN_00427c0d(&DAT_00435270,(char *)*piVar1);
  FUN_00429070(piVar1,10);
  FUN_00428b4c(&DAT_00433d90);
  this_00 = (void *)0xffffffff;
  FUN_0041ef48(0xffffffff);
  FUN_0041bfe0(FUN_0041c730);
  this = (void *)FUN_0041bfd0(0x60);
  if (this == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_0041c5b0(this,0,1);
  }
  FUN_0041c890(piVar1,param_1);
  piVar3 = FUN_0041c190(&DAT_00433d88,0x4315ec);
  FUN_00427c0d(piVar1,(char *)*piVar3);
  if (-1 < unaff_retaddr) {
    pcVar2 = FUN_0041d5e0((byte *)s__E_d__004315f8);
    FUN_00427c0d(piVar1,pcVar2);
  }
  if (param_3 != (byte *)0x0) {
    FUN_0041ffa6(&DAT_00433580,param_3,param_4);
    FUN_00427c0d(piVar1,&DAT_00433580);
  }
  FUN_0041c690(piVar1);
  if (piVar1 != (int *)0x0) {
    (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
  }
  FUN_00428b4c(&DAT_00433d90);
  FUN_0041ef48(0xffffffff);
  FUN_0041d740();
  if ((DAT_00433de8 == 0) || (unaff_retaddr == 0)) {
    FUN_0041c910(this_00);
  }
  if (DAT_00433de8 != 0) {
    if (unaff_retaddr != 0) {
      piVar1 = FUN_0041c190(&DAT_00433550,0x431600);
      pcVar2 = FUN_0041d5e0((byte *)*piVar1);
      FUN_00427c0d(this_00,pcVar2);
      return;
    }
    pcVar2 = FUN_0041d5e0((byte *)s__s__00431618);
    FUN_00427c0d(this_00,pcVar2);
  }
  return;
}



void FUN_0041c7c0(int param_1,int param_2,undefined4 param_3,byte *param_4,undefined4 *param_5)

{
  void *this;
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  void *unaff_retaddr;
  
  FUN_0041bfe0(FUN_0041c730);
  this = (void *)FUN_0041bfd0(0x60);
  if (this == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_0041c5b0(this,0,1);
  }
  FUN_0041c890(piVar1,param_2);
  piVar2 = FUN_0041c190(&DAT_00433d88,0x4315ec);
  FUN_00427c0d(piVar1,(char *)*piVar2);
  if (-1 < param_1) {
    pcVar3 = FUN_0041d5e0((byte *)s__E_d__004315f8);
    FUN_00427c0d(piVar1,pcVar3);
  }
  if (param_4 != (byte *)0x0) {
    FUN_0041ffa6(&DAT_00433580,param_4,param_5);
    FUN_00427c0d(piVar1,&DAT_00433580);
  }
  FUN_0041c690(piVar1);
  if (piVar1 != (int *)0x0) {
    (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
  }
  FUN_00428b4c(&DAT_00433d90);
  FUN_0041ef48(0xffffffff);
  FUN_0041d740();
  if ((DAT_00433de8 == 0) || (param_1 == 0)) {
    FUN_0041c910(unaff_retaddr);
  }
  if (DAT_00433de8 != 0) {
    if (param_1 != 0) {
      piVar1 = FUN_0041c190(&DAT_00433550,0x431600);
      pcVar3 = FUN_0041d5e0((byte *)*piVar1);
      FUN_00427c0d(unaff_retaddr,pcVar3);
      return;
    }
    pcVar3 = FUN_0041d5e0((byte *)s__s__00431618);
    FUN_00427c0d(unaff_retaddr,pcVar3);
  }
  return;
}



void __cdecl FUN_0041c890(void *param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  
  FUN_0041d740();
  if ((DAT_00433de8 == 0) || (param_2 == 0)) {
    FUN_0041c910(param_1);
  }
  if (DAT_00433de8 != 0) {
    if (param_2 != 0) {
      piVar1 = FUN_0041c190(&DAT_00433550,0x431600);
      pcVar2 = FUN_0041d5e0((byte *)*piVar1);
      FUN_00427c0d(param_1,pcVar2);
      return;
    }
    pcVar2 = FUN_0041d5e0((byte *)s__s__00431618);
    FUN_00427c0d(param_1,pcVar2);
  }
  return;
}



void __cdecl FUN_0041c910(void *param_1)

{
  int *this;
  char *pcVar1;
  
  FUN_0041d740();
  if (DAT_00433dec != (char *)0x0) {
    pcVar1 = &DAT_00431620;
    this = FUN_00427c0d(param_1,DAT_00433dec);
    FUN_00427c0d(this,pcVar1);
  }
  return;
}



void __cdecl FUN_0041c940(undefined4 *param_1)

{
  FUN_0041c7c0((int)*(short *)(param_1 + 1),0,0,(byte *)*param_1,(undefined4 *)&stack0x00000008);
  return;
}



bool FUN_0041ceb0(void)

{
  DAT_00433e08 = DAT_00433e08 + 1;
  return 0 < DAT_00433e08;
}



bool FUN_0041ced0(void)

{
  DAT_00433e08 = DAT_00433e08 + -1;
  return 0 < DAT_00433e08;
}



void FUN_0041cef0(void)

{
  int in_stack_00000004;
  undefined4 in_stack_00000008;
  byte *in_stack_0000000c;
  undefined4 *in_stack_00000010;
  
  FUN_0041bfc0(DAT_00433e14);
  DAT_00433e14 = 0;
  FUN_0041c730(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}



int __cdecl FUN_0041cf10(uint param_1)

{
  uint *puVar1;
  
  if (param_1 < 4) {
    param_1 = 4;
  }
  puVar1 = FUN_0041b590(param_1);
  if (puVar1 == (uint *)0x0) {
    FUN_0041cef0();
  }
  return (int)puVar1;
}



char * __cdecl FUN_0041d070(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)FUN_0041cf10(~uVar3);
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      do {
        pcVar5 = param_1;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar5 + -uVar3;
      pcVar6 = pcVar2;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
      return pcVar2;
    }
  }
  return (char *)0x0;
}



undefined * __cdecl FUN_0041d5e0(byte *param_1)

{
  FUN_0041ffa6(&DAT_00433e18,param_1,(undefined4 *)&stack0x00000008);
  return &DAT_00433e18;
}



void FUN_0041d740(void)

{
  if (DAT_00434e18 != 0) {
    do {
      FUN_00429070(&DAT_00435270,0x20);
      DAT_00434e18 = DAT_00434e18 + -1;
    } while (DAT_00434e18 != 0);
    FUN_00429070(&DAT_00435270,0xd);
  }
  return;
}



char * __cdecl FUN_0041d770(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = _strrchr(param_1,0x5c);
  if (pcVar1 != (char *)0x0) {
    return pcVar1 + 1;
  }
  pcVar1 = _strchr(param_1,0x3a);
  if (pcVar1 != (char *)0x0) {
    return pcVar1 + 1;
  }
  return param_1;
}



char * __cdecl FUN_0041d7a0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  for (pcVar2 = param_1 + (~uVar3 - 2); (param_1 <= pcVar2 && (*pcVar2 != '\\'));
      pcVar2 = pcVar2 + -1) {
    if (*pcVar2 == '.') {
      return pcVar2;
    }
  }
  return (char *)0x0;
}



void __cdecl FUN_0041d7d0(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar4 = 0xffffffff;
  do {
    pcVar2 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar2 + -uVar4;
  pcVar6 = param_3;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pcVar2 = FUN_0041d7a0(param_3);
  if (pcVar2 == (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar2 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar3 = ~uVar4 - 1;
  }
  else {
    iVar3 = (int)pcVar2 - (int)param_3;
  }
  if (param_2 == (char *)0x0) {
    param_3[iVar3] = '\0';
    return;
  }
  param_3[iVar3] = '.';
  uVar4 = 0xffffffff;
  do {
    pcVar2 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar2 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar2;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar2 + -uVar4;
  pcVar6 = param_3 + iVar3 + 1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  return;
}



void __cdecl FUN_0041d850(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  pcVar2 = FUN_0041d7a0(param_1);
  if (pcVar2 == (char *)0x0) {
    FUN_0041d7d0(param_1,param_2,param_3);
    return;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar2 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar2 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)param_3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    param_3 = param_3 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_3 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



void __cdecl FUN_0041d920(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  pcVar2 = FUN_0041d770(param_1);
  uVar6 = (int)pcVar2 - (int)param_1;
  pcVar3 = param_2;
  for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *param_1;
    param_1 = param_1 + 1;
    pcVar3 = pcVar3 + 1;
  }
  pcVar3 = FUN_0041d7a0(pcVar2);
  if (pcVar3 == (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar7 = pcVar2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
  }
  else {
    uVar4 = (int)pcVar3 - (int)pcVar2;
  }
  if (8 < (int)uVar4) {
    uVar4 = 8;
  }
  pcVar7 = param_2 + uVar6;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar7 = pcVar7 + 1;
  }
  param_2[uVar4 + uVar6] = '\0';
  if (pcVar3 != (char *)0x0) {
    _strncat(param_2 + uVar4 + uVar6,pcVar3,4);
  }
  return;
}



undefined4 * __thiscall FUN_0041dd70(void *this,uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)((int)this + 0xc) = 0;
  puVar1 = (undefined4 *)FUN_0041bfd0(param_1 * 4);
  *(undefined4 **)this = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_0043188c)(0xc,s_ghsearch___not_enough_memory_00431a14);
    return (undefined4 *)this;
  }
  for (uVar2 = param_1 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  *(uint *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  return (undefined4 *)this;
}



undefined4 __thiscall FUN_0041de50(void *this,byte *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  bool bVar10;
  
  uVar7 = 0xffffffff;
  pbVar4 = param_1;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  if (param_1 == (byte *)0x0) {
    (*(code *)PTR_FUN_0043188c)(0,s_ghsearch___insert_called_with_nu_00431a54);
    return 0;
  }
  iVar2 = (**(code **)((int)this + 8))(param_1,*(undefined4 *)((int)this + 4));
                    // WARNING: Load size is inaccurate
  puVar5 = *(undefined4 **)(*this + iVar2 * 4);
  if (puVar5 == (undefined4 *)0x0) {
    uVar6 = FUN_0041bfd0(~uVar7 + 8);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)(*this + iVar2 * 4) = uVar6;
                    // WARNING: Load size is inaccurate
    puVar5 = *(undefined4 **)(*this + iVar2 * 4);
  }
  else {
    do {
      puVar3 = puVar5;
      if (param_3 == 0) {
        pbVar4 = (byte *)(puVar3 + 2);
        pbVar9 = param_1;
        do {
          bVar1 = *pbVar4;
          bVar10 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_0041ded1:
            iVar2 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_0041ded6;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar10 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_0041ded1;
          pbVar4 = pbVar4 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_0041ded6:
        if (iVar2 == 0) {
          return puVar3[1];
        }
      }
      puVar5 = (undefined4 *)*puVar3;
    } while ((undefined4 *)*puVar3 != (undefined4 *)0x0);
    puVar5 = (undefined4 *)FUN_0041bfd0(~uVar7 + 8);
    *puVar3 = puVar5;
  }
  if (puVar5 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_0043188c)(0xc,s_ghsearch___not_enough_memory_00431a80);
    return 0;
  }
  puVar5[1] = param_2;
  uVar7 = 0xffffffff;
  do {
    pbVar4 = param_1;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pbVar4 = param_1 + 1;
    bVar1 = *param_1;
    param_1 = pbVar4;
  } while (bVar1 != 0);
  uVar7 = ~uVar7;
  pbVar4 = pbVar4 + -uVar7;
  pbVar9 = (byte *)(puVar5 + 2);
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar4;
    pbVar4 = pbVar4 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pbVar9 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    pbVar9 = pbVar9 + 1;
  }
  *puVar5 = 0;
  return 0;
}



undefined4 __thiscall FUN_0041e060(void *this,byte *param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  bool bVar8;
  
  if (param_1 == (byte *)0x0) {
    (*(code *)PTR_FUN_0043188c)(0,s_ghsearch___remove_called_with_nu_00431aec);
  }
  iVar3 = (**(code **)((int)this + 8))(param_1,*(undefined4 *)((int)this + 4));
                    // WARNING: Load size is inaccurate
  piVar2 = *(int **)(*this + iVar3 * 4);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == 0) {
      if (*(int *)((int)this + 0xc) == 0) {
        FUN_0041bfc0(piVar2[1]);
      }
      FUN_0041bfc0((int)piVar2);
                    // WARNING: Load size is inaccurate
      *(undefined4 *)(*this + iVar3 * 4) = 0;
      return 0;
    }
    pbVar6 = (byte *)(piVar2 + 2);
    pbVar4 = param_1;
    do {
      bVar1 = *pbVar4;
      bVar8 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_0041e0f5:
        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0041e0fa;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar8 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_0041e0f5;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_0041e0fa:
    if (iVar5 == 0) {
      if (*(int *)((int)this + 0xc) == 0) {
        FUN_0041bfc0(piVar2[1]);
      }
                    // WARNING: Load size is inaccurate
      *(int *)(*this + iVar3 * 4) = *piVar2;
      FUN_0041bfc0((int)piVar2);
      return 0;
    }
    while (piVar7 = piVar2, piVar2 = (int *)*piVar7, piVar2 != (int *)0x0) {
      pbVar6 = (byte *)(piVar2 + 2);
      pbVar4 = param_1;
      do {
        bVar1 = *pbVar4;
        bVar8 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_0041e15d:
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_0041e162;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar8 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_0041e15d;
        pbVar4 = pbVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0041e162:
      if (iVar3 == 0) {
        if (*(int *)((int)this + 0xc) == 0) {
          FUN_0041bfc0(piVar2[1]);
        }
        *piVar7 = *piVar2;
        FUN_0041bfc0((int)piVar2);
        return 0;
      }
    }
  }
  return 0xffffffff;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042b148;
  puStack_10 = &LAB_00421114;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_00434e70 = DVar1 >> 8 & 0xff;
  _DAT_00434e6c = DVar1 & 0xff;
  _DAT_00434e68 = _DAT_00434e6c * 0x100 + _DAT_00434e70;
  _DAT_00434e64 = DVar1 >> 0x10;
  iVar2 = FUN_00420fdd(1);
  if (iVar2 == 0) {
    FUN_0041ea05(0x1c);
  }
  iVar2 = FUN_00420f0f();
  if (iVar2 == 0) {
    FUN_0041ea05(0x10);
  }
  local_8 = 0;
  FUN_00420d53();
  DAT_00437944 = GetCommandLineA();
  DAT_00434e50 = FUN_00420c21();
  FUN_004209d4();
  FUN_0042091b();
  FUN_0041ef1b();
  DAT_00434e84 = DAT_00434e80;
  UVar3 = FUN_00419e30(DAT_00434e74,DAT_00434e78);
  FUN_0041ef48(UVar3);
  FUN_004207a3(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}



// Library Function - Single Match
//  __amsg_exit
// 
// Library: Visual Studio 2003 Release

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00434e58 != 2) {
    FUN_004211ec();
  }
  FUN_00421225(param_1);
  (*(code *)PTR___exit_00431c70)(0xff);
  return;
}



void __cdecl FUN_0041ea05(DWORD param_1)

{
  if (DAT_00434e58 != 2) {
    FUN_004211ec();
  }
  FUN_00421225(param_1);
                    // WARNING: Subroutine does not return
  ExitProcess(0xff);
}



undefined4 __cdecl FUN_0041ea29(FILE *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((*(byte *)&param_1->_flag & 0x40) == 0) {
    FUN_0041eb62((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_0041ebb4((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}



// Library Function - Single Match
//  __fclose_lk
// 
// Library: Visual Studio 2003 Release

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((*(byte *)&param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_0041f15c((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_00421378(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_0041b8c0((int)param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}



void __cdecl FUN_0041eb62(uint param_1)

{
  if ((0x431c77 < param_1) && (param_1 < 0x431ed9)) {
    FUN_0042152d(((int)(param_1 - 0x431c78) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



void __cdecl FUN_0041eb91(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_0042152d(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



void __cdecl FUN_0041ebb4(uint param_1)

{
  if ((0x431c77 < param_1) && (param_1 < 0x431ed9)) {
    FUN_0042158e(((int)(param_1 - 0x431c78) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



void __cdecl FUN_0041ebe3(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_0042158e(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



undefined4 * FUN_0041ec06(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = FUN_00421713();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_004215a3(param_1,param_2,param_3,puVar1);
  FUN_0041ebb4((uint)puVar1);
  return puVar2;
}



void __cdecl FUN_0041ec37(undefined4 param_1,undefined4 param_2)

{
  FUN_0041ec06(param_1,param_2,0x40);
  return;
}



int __cdecl FUN_0041ec4a(undefined *param_1,byte *param_2)

{
  int iVar1;
  undefined *local_24;
  int local_20;
  undefined *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_004218f3((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_004217db(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



void __cdecl FUN_0041ec9c(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_fc [30];
  int local_84 [30];
  int *local_c;
  int local_8;
  
  if ((param_2 < (undefined4 *)0x2) || (param_3 == 0)) {
    return;
  }
  local_8 = 0;
  iVar4 = (int)param_2 + -1;
  param_2 = local_fc;
  piVar5 = (int *)(iVar4 * param_3 + (int)param_1);
  piVar3 = param_1;
  param_1 = local_84;
LAB_0041ecdb:
  uVar2 = (uint)((int)piVar5 - (int)piVar3) / param_3 + 1;
  if (8 < uVar2) {
    FUN_0041ee3e((undefined *)((uVar2 >> 1) * param_3 + (int)piVar3),(undefined *)piVar3,param_3);
    piVar6 = (int *)(param_3 + (int)piVar5);
    local_c = piVar3;
LAB_0041ed32:
    local_c = (int *)((int)local_c + param_3);
    if (local_c <= piVar5) goto code_r0x0041ed3f;
    goto LAB_0041ed4a;
  }
  FUN_0041edf0((undefined *)piVar3,(undefined *)piVar5,param_3,param_4);
  goto LAB_0041ecfa;
code_r0x0041ed3f:
  iVar4 = (*(code *)param_4)(local_c,piVar3);
  if (iVar4 < 1) goto LAB_0041ed32;
LAB_0041ed4a:
  do {
    piVar6 = (int *)((int)piVar6 - param_3);
    if (piVar6 <= piVar3) break;
    iVar4 = (*(code *)param_4)(piVar6,piVar3);
  } while (-1 < iVar4);
  if (local_c <= piVar6) {
    FUN_0041ee3e((undefined *)local_c,(undefined *)piVar6,param_3);
    goto LAB_0041ed32;
  }
  FUN_0041ee3e((undefined *)piVar3,(undefined *)piVar6,param_3);
  piVar1 = local_c;
  if ((int)((int)piVar6 + (-1 - (int)piVar3)) < (int)piVar5 - (int)local_c) {
    if (local_c < piVar5) {
      local_8 = local_8 + 1;
      *param_2 = local_c;
      *param_1 = (int)piVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int *)(param_3 + (int)piVar3) < piVar6) {
      piVar5 = (int *)((int)piVar6 - param_3);
      goto LAB_0041ecdb;
    }
  }
  else {
    if ((int *)((int)piVar3 + param_3) < piVar6) {
      local_8 = local_8 + 1;
      *param_2 = piVar3;
      *param_1 = (int)piVar6 - param_3;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    piVar3 = piVar1;
    if (piVar1 < piVar5) goto LAB_0041ecdb;
  }
LAB_0041ecfa:
  local_8 = local_8 + -1;
  param_2 = param_2 + -1;
  param_1 = param_1 + -1;
  if (local_8 < 0) {
    return;
  }
  piVar5 = (int *)*param_1;
  piVar3 = (int *)*param_2;
  goto LAB_0041ecdb;
}



void __cdecl FUN_0041edf0(undefined *param_1,undefined *param_2,int param_3,undefined *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (param_1 < param_2) {
    puVar2 = param_1;
    puVar3 = param_1 + param_3;
    do {
      for (; puVar3 <= param_2; puVar3 = puVar3 + param_3) {
        iVar1 = (*(code *)param_4)(puVar3,puVar2);
        if (0 < iVar1) {
          puVar2 = puVar3;
        }
      }
      FUN_0041ee3e(puVar2,param_2,param_3);
      param_2 = param_2 + -param_3;
      puVar2 = param_1;
      puVar3 = param_1 + param_3;
    } while (param_1 < param_2);
  }
  return;
}



void __cdecl FUN_0041ee3e(undefined *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  
  if ((param_1 != param_2) && (param_3 != 0)) {
    do {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



uint __cdecl FUN_0041ee6a(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  
  FUN_0041eb62((uint)param_1);
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_004220fd(param_1);
  }
  else {
    uVar2 = (uint)*(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
  }
  FUN_0041ebb4((uint)param_1);
  return uVar2;
}



void __cdecl FUN_0041ee9b(undefined4 *param_1)

{
  FUN_0041ee6a(param_1);
  return;
}



uint __thiscall FUN_0041eea6(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_00431ef8 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_00431ef8[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_004221d9(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}



void FUN_0041ef1b(void)

{
  if (PTR_FUN_004321d8 != (undefined *)0x0) {
    (*(code *)PTR_FUN_004321d8)();
  }
  FUN_0041f021((undefined4 *)&DAT_0042d05c,(undefined4 *)&DAT_0042d070);
  FUN_0041f021((undefined4 *)&DAT_0042d000,(undefined4 *)&DAT_0042d058);
  return;
}



void __cdecl FUN_0041ef48(UINT param_1)

{
  FUN_0041ef6a(param_1,0,0);
  return;
}



// Library Function - Single Match
//  __exit
// 
// Library: Visual Studio 2003 Release

void __cdecl __exit(int _Code)

{
  FUN_0041ef6a(_Code,1,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_0041ef6a(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_0041f00f();
  if (DAT_00434ea0 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00434e9c = 1;
  DAT_00434e98 = (undefined)param_3;
  if (param_2 == 0) {
    if ((DAT_00436938 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00436934 - 4), DAT_00436938 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00436938 <= puVar1);
    }
    FUN_0041f021((undefined4 *)&DAT_0042d074,(undefined4 *)&DAT_0042d07c);
  }
  FUN_0041f021((undefined4 *)&DAT_0042d080,(undefined4 *)&DAT_0042d088);
  if (param_3 == 0) {
    DAT_00434ea0 = 1;
                    // WARNING: Subroutine does not return
    ExitProcess(param_1);
  }
  FUN_0041f018();
  return;
}



void FUN_0041f00f(void)

{
  FUN_0042152d(0xd);
  return;
}



void FUN_0041f018(void)

{
  FUN_0042158e(0xd);
  return;
}



void __cdecl FUN_0041f021(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



int __cdecl FUN_0041f03b(int *param_1,byte *param_2)

{
  int iVar1;
  void *this;
  
  FUN_0041eb62((uint)param_1);
  iVar1 = FUN_00422322(this,param_1,param_2,(undefined4 *)&stack0x0000000c);
  FUN_0041ebb4((uint)param_1);
  return iVar1;
}



uint __cdecl FUN_0041f068(uint param_1,int *param_2)

{
  uint uVar1;
  
  FUN_0041eb62((uint)param_2);
  uVar1 = FUN_0041f091(param_1,param_2);
  FUN_0041ebb4((uint)param_2);
  return uVar1;
}



uint __cdecl FUN_0041f091(uint param_1,int *param_2)

{
  uint uVar1;
  
  if ((param_1 != 0xffffffff) &&
     ((uVar1 = param_2[3], (uVar1 & 1) != 0 || (((uVar1 & 0x80) != 0 && ((uVar1 & 2) == 0)))))) {
    if (param_2[2] == 0) {
      FUN_00422dd3(param_2);
    }
    if (*param_2 == param_2[2]) {
      if (param_2[1] != 0) {
        return 0xffffffff;
      }
      *param_2 = *param_2 + 1;
    }
    if ((*(byte *)(param_2 + 3) & 0x40) == 0) {
      *param_2 = *param_2 + -1;
      *(char *)*param_2 = (char)param_1;
    }
    else {
      *param_2 = *param_2 + -1;
      if (*(char *)*param_2 != (char)param_1) {
        *param_2 = (int)((char *)*param_2 + 1);
        return 0xffffffff;
      }
    }
    param_2[1] = param_2[1] + 1;
    param_2[3] = param_2[3] & 0xffffffefU | 1;
    return param_1 & 0xff;
  }
  return 0xffffffff;
}



int __cdecl FUN_0041f0ff(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_0041f1c1(0);
    return iVar1;
  }
  FUN_0041eb62((uint)param_1);
  iVar1 = FUN_0041f12e(param_1);
  FUN_0041ebb4((uint)param_1);
  return iVar1;
}



int __cdecl FUN_0041f12e(int *param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_0041f15c(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    DVar2 = FUN_00422e17(param_1[4]);
    return -(uint)(DVar2 != 0);
  }
  return 0;
}



undefined4 __cdecl FUN_0041f15c(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_00422eaa(param_1[4],(char *)param_1[2],uVar3);
      if (uVar1 == uVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}



int __cdecl FUN_0041f1c1(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_0042152d(2);
  iVar4 = 0;
  if (0 < DAT_00437940) {
    do {
      iVar2 = *(int *)(DAT_0043693c + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_0041eb91(iVar4,iVar2);
        piVar1 = *(int **)(DAT_0043693c + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_0041f12e(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_0041f12e(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_0041ebe3(iVar4,*(int *)(DAT_0043693c + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00437940);
  }
  FUN_0042158e(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}



void __cdecl FUN_0041f265(char *param_1,byte *param_2)

{
  void *this;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_18 = 0x49;
  local_1c = param_1;
  local_24 = param_1;
  local_20 = _strlen(param_1);
  FUN_00422322(this,(int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  return;
}



uint __cdecl FUN_0041f299(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_00435050 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_0043680c);
    bVar1 = DAT_00436808 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_0043680c);
      this = (void *)0x13;
      FUN_0042152d(0x13);
    }
    param_1 = FUN_0041f308(this,param_1);
    if (bVar1) {
      FUN_0042158e(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_0043680c);
    }
  }
  return param_1;
}



uint __thiscall FUN_0041f308(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_00435050 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      uVar1 = param_1 - 0x20;
    }
  }
  else {
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_00432104 < 2) {
        uVar2 = (byte)PTR_DAT_00431ef8[param_1 * 2] & 2;
      }
      else {
        uVar2 = FUN_0041eea6(this,param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_00431ef8[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      iVar3 = 1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_0042311b(DAT_00435050,0x200,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



int __thiscall FUN_0041f3d4(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  
  while( true ) {
    if (DAT_00432104 < 2) {
      uVar1 = (byte)PTR_DAT_00431ef8[(uint)*param_1 * 2] & 8;
      this = PTR_DAT_00431ef8;
    }
    else {
      puVar6 = (undefined *)0x8;
      uVar1 = FUN_0041eea6(this,(uint)*param_1,8);
      this = puVar6;
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar5 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar4 = uVar1, uVar1 == 0x2b)) {
    uVar4 = (uint)*pbVar5;
    pbVar5 = param_1 + 2;
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_00432104 < 2) {
      uVar2 = (byte)PTR_DAT_00431ef8[uVar4 * 2] & 4;
    }
    else {
      puVar6 = (undefined *)0x4;
      uVar2 = FUN_0041eea6(this,uVar4,4);
      this = puVar6;
    }
    if (uVar2 == 0) break;
    iVar3 = (uVar4 - 0x30) + iVar3 * 10;
    uVar4 = (uint)*pbVar5;
    pbVar5 = pbVar5 + 1;
  }
  if (uVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return iVar3;
}



void __thiscall FUN_0041f45f(void *this,byte *param_1)

{
  FUN_0041f3d4(this,param_1);
  return;
}



int __cdecl FUN_0041f46a(char *param_1,int *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = _strlen(param_1);
  FUN_0041eb62((uint)param_2);
  iVar2 = FUN_00423374(param_2);
  uVar3 = FUN_0042342b(param_1,1,sVar1,param_2);
  FUN_00423401(iVar2,param_2);
  FUN_0041ebb4((uint)param_2);
  return (uVar3 == sVar1) - 1;
}



void __cdecl FUN_0041f4b8(byte *param_1,uint param_2,byte *param_3,int *param_4)

{
  FUN_0041f4d3(param_1,param_2,param_3,param_4,(undefined *)0x0);
  return;
}



int __cdecl FUN_0041f4d3(byte *param_1,uint param_2,byte *param_3,int *param_4,undefined *param_5)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  
  puVar2 = param_5;
  if (param_5 == (undefined *)0x0) {
    puVar2 = PTR_PTR_DAT_00432110;
  }
  param_5 = (undefined *)param_2;
  InterlockedIncrement((LONG *)&DAT_0043680c);
  bVar5 = DAT_00436808 == 0;
  pbVar3 = param_3;
  if (!bVar5) {
    InterlockedDecrement((LONG *)&DAT_0043680c);
    FUN_0042152d(0x13);
    pbVar3 = param_3;
  }
  while ((param_5 != (undefined *)0x0 && (bVar1 = *pbVar3, bVar1 != 0))) {
    if (bVar1 == 0x25) {
      pbVar4 = pbVar3 + 1;
      bVar1 = *pbVar4;
      if (bVar1 == 0x23) {
        pbVar4 = pbVar3 + 2;
      }
      DAT_00436924 = (uint)(bVar1 == 0x23);
      FUN_0041f5cd(*pbVar4,param_4,(byte *)&param_1,(uint *)&param_5,(int)puVar2);
    }
    else {
      if (((PTR_DAT_00431ef8[(uint)bVar1 * 2 + 1] & 0x80) != 0) && ((undefined *)0x1 < param_5)) {
        *param_1 = bVar1;
        param_1 = param_1 + 1;
        pbVar3 = pbVar3 + 1;
        param_5 = param_5 + -1;
      }
      *param_1 = *pbVar3;
      param_1 = param_1 + 1;
      param_5 = param_5 + -1;
      pbVar4 = pbVar3;
    }
    pbVar3 = pbVar4 + 1;
  }
  if (bVar5) {
    InterlockedDecrement((LONG *)&DAT_0043680c);
  }
  else {
    FUN_0042158e(0x13);
  }
  if (param_5 == (undefined *)0x0) {
    return 0;
  }
  *param_1 = 0;
  return param_2 - (int)param_5;
}



void __cdecl FUN_0041f5cd(char param_1,int *param_2,byte *param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  char *pcVar6;
  
  if (param_1 < '[') {
    if (param_1 != 'Z') {
      if ('M' < param_1) {
        if (param_1 == 'S') {
          uVar5 = 2;
          iVar2 = *param_2;
        }
        else {
          if (param_1 == 'U') {
            iVar3 = param_2[6];
          }
          else {
            if (param_1 != 'W') {
              if (param_1 == 'X') {
                DAT_00436924 = 0;
                pbVar4 = *(byte **)(param_5 + 0xa8);
                goto LAB_0041f953;
              }
              if (param_1 != 'Y') {
                return;
              }
              uVar5 = 4;
              iVar2 = (param_2[5] / 100 + 0x13) * 100 + param_2[5] % 100;
              goto LAB_0041f709;
            }
            if (param_2[6] == 0) {
              iVar3 = 6;
            }
            else {
              iVar3 = param_2[6] + -1;
            }
          }
          iVar1 = param_2[7];
          if (iVar1 < iVar3) {
            iVar2 = 0;
          }
          else {
            iVar2 = iVar1 / 7;
            if (iVar3 <= iVar1 % 7) {
              iVar2 = iVar2 + 1;
            }
          }
          uVar5 = 2;
        }
        goto LAB_0041f709;
      }
      if (param_1 == 'M') {
        uVar5 = 2;
        iVar2 = param_2[1];
        goto LAB_0041f709;
      }
      if (param_1 == '%') {
        **(undefined **)param_3 = 0x25;
        *(int *)param_3 = *(int *)param_3 + 1;
        *param_4 = *param_4 - 1;
        return;
      }
      if (param_1 == 'A') {
        pcVar6 = *(char **)(param_5 + 0x1c + param_2[6] * 4);
        goto LAB_0041f9af;
      }
      if (param_1 == 'B') {
        pcVar6 = *(char **)(param_5 + 0x68 + param_2[4] * 4);
        goto LAB_0041f9af;
      }
      if (param_1 == 'H') {
        uVar5 = 2;
        iVar2 = param_2[2];
        goto LAB_0041f709;
      }
      if (param_1 != 'I') {
        return;
      }
      iVar2 = param_2[2] % 0xc;
      if (iVar2 == 0) {
        iVar2 = 0xc;
      }
LAB_0041f636:
      uVar5 = 2;
LAB_0041f709:
      DAT_00436928 = DAT_00436924;
      FUN_0041f9e3(iVar2,uVar5,(int *)param_3,param_4);
      return;
    }
  }
  else {
    if (param_1 < 'n') {
      if (param_1 == 'm') {
        iVar2 = param_2[4];
        uVar5 = 2;
      }
      else {
        if (param_1 == 'a') {
          pcVar6 = *(char **)(param_5 + param_2[6] * 4);
          goto LAB_0041f9af;
        }
        if (param_1 == 'b') {
          pcVar6 = *(char **)(param_5 + 0x38 + param_2[4] * 4);
          goto LAB_0041f9af;
        }
        if (param_1 == 'c') {
          if (DAT_00436924 == 0) {
            pbVar4 = *(byte **)(param_5 + 0xa0);
          }
          else {
            DAT_00436924 = 0;
            pbVar4 = *(byte **)(param_5 + 0xa4);
          }
          FUN_0041fa9b(pbVar4,(int)param_2,param_3,param_4,param_5);
          if (*param_4 == 0) {
            return;
          }
          **(undefined **)param_3 = 0x20;
          *(int *)param_3 = *(int *)param_3 + 1;
          *param_4 = *param_4 - 1;
          pbVar4 = *(byte **)(param_5 + 0xa8);
          goto LAB_0041f953;
        }
        if (param_1 == 'd') {
          uVar5 = 2;
          iVar2 = param_2[3];
          goto LAB_0041f709;
        }
        if (param_1 != 'j') {
          return;
        }
        iVar2 = param_2[7];
        uVar5 = 3;
      }
      iVar2 = iVar2 + 1;
      goto LAB_0041f709;
    }
    if (param_1 == 'p') {
      if (param_2[2] < 0xc) {
        pcVar6 = *(char **)(param_5 + 0x98);
      }
      else {
        pcVar6 = *(char **)(param_5 + 0x9c);
      }
      goto LAB_0041f9af;
    }
    if (param_1 == 'w') {
      uVar5 = 1;
      iVar2 = param_2[6];
      goto LAB_0041f709;
    }
    if (param_1 == 'x') {
      if (DAT_00436924 == 0) {
        pbVar4 = *(byte **)(param_5 + 0xa0);
      }
      else {
        DAT_00436924 = 0;
        pbVar4 = *(byte **)(param_5 + 0xa4);
      }
LAB_0041f953:
      FUN_0041fa9b(pbVar4,(int)param_2,param_3,param_4,param_5);
      return;
    }
    if (param_1 == 'y') {
      iVar2 = param_2[5] % 100;
      goto LAB_0041f636;
    }
    if (param_1 != 'z') {
      return;
    }
  }
  FUN_00423965();
  pcVar6 = (&PTR_DAT_0043272c)[param_2[8] != 0];
LAB_0041f9af:
  FUN_0041f9bc(pcVar6,(int *)param_3,(int *)param_4);
  return;
}



void __cdecl FUN_0041f9bc(char *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  for (; (iVar1 != 0 && (*param_1 != '\0')); param_1 = param_1 + 1) {
    *(char *)*param_2 = *param_1;
    *param_2 = *param_2 + 1;
    *param_3 = *param_3 + -1;
    iVar1 = *param_3;
  }
  return;
}



void __cdecl FUN_0041f9e3(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  if (DAT_00436928 == 0) {
    if (param_2 < *param_4) {
      iVar1 = param_2 - 1;
      if (param_2 != 0) {
        do {
          *(char *)(*param_3 + iVar1) = (char)(param_1 % 10) + '0';
          param_1 = param_1 / 10;
          local_8 = local_8 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != -1);
      }
      *param_3 = *param_3 + local_8;
      *param_4 = *param_4 - local_8;
    }
    else {
      *param_4 = 0;
    }
  }
  else {
    FUN_0041fa52(param_1,param_3,param_4);
  }
  return;
}



void __cdecl FUN_0041fa52(int param_1,int *param_2,uint *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)*param_2;
  do {
    if (*param_3 < 2) break;
    *pcVar3 = (char)(param_1 % 10) + '0';
    pcVar3 = pcVar3 + 1;
    param_1 = param_1 / 10;
    *param_3 = *param_3 - 1;
  } while (0 < param_1);
  pcVar2 = (char *)*param_2;
  *param_2 = (int)pcVar3;
  pcVar3 = pcVar3 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar3 = *pcVar2;
    pcVar3 = pcVar3 + -1;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (pcVar2 < pcVar3);
  return;
}



void __cdecl FUN_0041fa9b(byte *param_1,int param_2,byte *param_3,uint *param_4,int param_5)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  
  puVar3 = param_4;
  pbVar2 = param_3;
  bVar1 = *param_1;
  do {
    if ((bVar1 == 0) || (*puVar3 == 0)) {
      return;
    }
    DAT_00436928 = 0;
    bVar1 = *param_1;
    uVar7 = 0;
    pbVar5 = param_1 + 1;
    do {
      param_3 = pbVar5;
      uVar6 = uVar7;
      uVar7 = uVar6 + 1;
      pbVar5 = param_3 + 1;
    } while (*param_3 == bVar1);
    if ((char)bVar1 < 'e') {
      if (bVar1 == 100) {
        if (uVar6 == 0) {
          DAT_00436928 = 1;
        }
        else if (uVar6 != 1) {
          if (uVar6 == 2) {
            param_4._0_1_ = 'a';
          }
          else {
            if (uVar6 != 3) goto LAB_0041fb1f;
            param_4._0_1_ = 'A';
          }
          goto LAB_0041fd55;
        }
        param_4._0_1_ = 'd';
        goto LAB_0041fd55;
      }
      if (bVar1 != 0x27) {
        if (bVar1 != 0x41) {
          if (bVar1 == 0x48) {
            if (uVar6 == 0) {
              DAT_00436928 = 1;
            }
            else if (uVar7 != 2) goto LAB_0041fb1f;
            param_4._0_1_ = 'H';
            goto LAB_0041fd55;
          }
          if (bVar1 == 0x4d) {
            if (uVar6 == 0) {
              DAT_00436928 = 1;
            }
            else if (uVar6 != 1) {
              if (uVar6 == 2) {
                param_4._0_1_ = 'b';
              }
              else {
                if (uVar6 != 3) goto LAB_0041fb1f;
                param_4._0_1_ = 'B';
              }
              goto LAB_0041fd55;
            }
            param_4._0_1_ = 'm';
            goto LAB_0041fd55;
          }
          if (bVar1 != 0x61) goto LAB_0041fb1f;
        }
        iVar4 = FUN_00407400((char *)param_1,"am/pm");
        if (iVar4 == 0) {
          param_3 = param_1 + 5;
        }
        else {
          iVar4 = FUN_00407400((char *)param_1,"a/p");
          if (iVar4 == 0) {
            param_3 = param_1 + 3;
          }
        }
        param_4._0_1_ = 'p';
        goto LAB_0041fd55;
      }
      if ((uVar7 & 1) == 0) {
        param_3 = param_1 + uVar7;
      }
      else {
        param_3 = param_1 + uVar7;
        while( true ) {
          bVar1 = *param_3;
          if ((bVar1 == 0) || (*puVar3 == 0)) goto LAB_0041fb45;
          if (bVar1 == 0x27) break;
          if (((PTR_DAT_00431ef8[(uint)bVar1 * 2 + 1] & 0x80) != 0) && (1 < *puVar3)) {
            **(byte **)pbVar2 = bVar1;
            *(int *)pbVar2 = *(int *)pbVar2 + 1;
            param_3 = param_3 + 1;
            *puVar3 = *puVar3 - 1;
          }
          **(byte **)pbVar2 = *param_3;
          *(int *)pbVar2 = *(int *)pbVar2 + 1;
          param_3 = param_3 + 1;
          *puVar3 = *puVar3 - 1;
        }
        param_3 = param_3 + 1;
      }
    }
    else {
      if (bVar1 == 0x68) {
        if (uVar6 == 0) {
          DAT_00436928 = 1;
        }
        else if (uVar7 != 2) goto LAB_0041fb1f;
        param_4._0_1_ = 'I';
      }
      else if (bVar1 == 0x6d) {
        if (uVar6 == 0) {
          DAT_00436928 = 1;
        }
        else if (uVar7 != 2) goto LAB_0041fb1f;
        param_4._0_1_ = 'M';
      }
      else if (bVar1 == 0x73) {
        if (uVar6 == 0) {
          DAT_00436928 = 1;
        }
        else if (uVar7 != 2) goto LAB_0041fb1f;
        param_4._0_1_ = 'S';
      }
      else {
        if (bVar1 == 0x74) {
          if (*(int *)(param_2 + 8) < 0xc) {
            pbVar5 = *(byte **)(param_5 + 0x98);
          }
          else {
            pbVar5 = *(byte **)(param_5 + 0x9c);
          }
          while ((0 < (int)uVar7 && (*puVar3 != 0))) {
            if (((PTR_DAT_00431ef8[(uint)*pbVar5 * 2 + 1] & 0x80) != 0) && (1 < *puVar3)) {
              **(byte **)pbVar2 = *pbVar5;
              *(int *)pbVar2 = *(int *)pbVar2 + 1;
              pbVar5 = pbVar5 + 1;
              *puVar3 = *puVar3 - 1;
            }
            **(byte **)pbVar2 = *pbVar5;
            *(int *)pbVar2 = *(int *)pbVar2 + 1;
            pbVar5 = pbVar5 + 1;
            *puVar3 = *puVar3 - 1;
            uVar7 = uVar7 - 1;
          }
          goto LAB_0041fb45;
        }
        if (bVar1 != 0x79) {
LAB_0041fb1f:
          if ((PTR_DAT_00431ef8[(uint)bVar1 * 2 + 1] & 0x80) != 0) {
            **(byte **)pbVar2 = bVar1;
            *(int *)pbVar2 = *(int *)pbVar2 + 1;
            *puVar3 = *puVar3 - 1;
            param_1 = param_1 + 1;
          }
          **(byte **)pbVar2 = *param_1;
          *(int *)pbVar2 = *(int *)pbVar2 + 1;
          param_3 = param_1 + 1;
          *puVar3 = *puVar3 - 1;
          goto LAB_0041fb45;
        }
        if (uVar6 == 1) {
          param_4._0_1_ = 'y';
        }
        else {
          if (uVar6 != 3) goto LAB_0041fb1f;
          param_4._0_1_ = 'Y';
        }
      }
LAB_0041fd55:
      FUN_0041f5cd((char)param_4,(int *)param_2,pbVar2,puVar3,param_5);
    }
LAB_0041fb45:
    bVar1 = *param_3;
    param_1 = param_3;
  } while( true );
}



int * __cdecl FUN_0041fd6a(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  
  piVar2 = param_1;
  if (*param_1 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00423965();
    iVar3 = *piVar2;
    if ((iVar3 < 0x3f481) || (0x7ffc0b7e < iVar3)) {
      piVar2 = FUN_00423f27(piVar2);
      bVar1 = FUN_00423c1a(piVar2);
      iVar3 = *piVar2;
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        iVar3 = iVar3 - DAT_004326a8;
      }
      param_1 = (int *)(iVar3 - DAT_004326a0);
      iVar3 = (int)param_1 % 0x3c;
      *piVar2 = iVar3;
      if (iVar3 < 0) {
        *piVar2 = iVar3 + 0x3c;
        param_1 = param_1 + -0xf;
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar2[1]);
      iVar3 = (int)param_1 % 0x3c;
      piVar2[1] = iVar3;
      if (iVar3 < 0) {
        piVar2[1] = iVar3 + 0x3c;
        param_1 = param_1 + -0xf;
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar2[2]);
      iVar3 = (int)param_1 % 0x18;
      piVar2[2] = iVar3;
      if (iVar3 < 0) {
        piVar2[2] = iVar3 + 0x18;
        param_1 = param_1 + -6;
      }
      iVar3 = (int)param_1 / 0x18;
      if (iVar3 < 1) {
        if (-1 < iVar3) {
          return piVar2;
        }
        piVar2[6] = (piVar2[6] + 7 + iVar3) % 7;
        piVar2[3] = piVar2[3] + iVar3;
        if (piVar2[3] < 1) {
          piVar2[5] = piVar2[5] + -1;
          piVar2[3] = piVar2[3] + 0x1f;
          piVar2[7] = 0x16c;
          piVar2[4] = 0xb;
          return piVar2;
        }
      }
      else {
        piVar2[6] = (piVar2[6] + iVar3) % 7;
        piVar2[3] = piVar2[3] + iVar3;
      }
      piVar2[7] = piVar2[7] + iVar3;
    }
    else {
      param_1 = (int *)(iVar3 - DAT_004326a0);
      piVar2 = FUN_00423f27((int *)&param_1);
      if ((DAT_004326a4 != 0) && (bVar1 = FUN_00423c1a(piVar2), CONCAT31(extraout_var,bVar1) != 0))
      {
        param_1 = (int *)((int)param_1 - DAT_004326a8);
        piVar2 = FUN_00423f27((int *)&param_1);
        piVar2[8] = 1;
      }
    }
  }
  return piVar2;
}



void __cdecl FUN_0041feca(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_00434eb8._2_2_) {
    if (local_24.wHour == (WORD)DAT_00434eb8) {
      if (local_24.wDay == DAT_00434eb4._2_2_) {
        if (local_24.wMonth == DAT_00434eb0._2_2_) {
          if (local_24.wYear == (WORD)DAT_00434eb0) goto LAB_0041ff74;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_00434ea8 = -1;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_00434ea8 = 1;
  }
  else {
    DAT_00434ea8 = 0;
  }
  DAT_00434eb0._0_2_ = local_24.wYear;
  DAT_00434eb0._2_2_ = local_24.wMonth;
  DAT_00434eb4._0_2_ = local_24.wDayOfWeek;
  DAT_00434eb4._2_2_ = local_24.wDay;
  DAT_00434eb8._0_2_ = local_24.wHour;
  DAT_00434eb8._2_2_ = local_24.wMinute;
  DAT_00434ebc._0_2_ = local_24.wSecond;
  DAT_00434ebc._2_2_ = local_24.wMilliseconds;
LAB_0041ff74:
  iVar2 = FUN_00424031((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                       (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,
                       DAT_00434ea8);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}



int __cdecl FUN_0041ffa6(undefined *param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined *local_24;
  int local_20;
  undefined *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_004218f3((int *)&local_24,param_2,param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_004217db(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



// Library Function - Single Match
//  _strchr
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (uint)_Str & 3;
  while (uVar1 != 0) {
    if (*_Str == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if (*_Str == '\0') {
      return (char *)0x0;
    }
    uVar1 = (uint)((int)_Str + 1) & 3;
    _Str = (char *)((int)_Str + 1);
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



// Library Function - Single Match
//  _strncmp
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    _MaxCount = ~uVar5;
  }
  return _MaxCount;
}



void FUN_00420108(void)

{
  FUN_00421225(10);
  FUN_004240f3((DWORD *)0x16);
                    // WARNING: Subroutine does not return
  __exit(3);
}



// WARNING: Unable to track spacebase fully for stack
// Library Function - Single Match
//  _longjmp
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
// Studio 2003 Release

void __cdecl _longjmp(int *_Buf,int _Value)

{
  PVOID pvVar1;
  int iVar2;
  
  pvVar1 = (PVOID)_Buf[6];
  if (pvVar1 != ExceptionList) {
    __global_unwind2(pvVar1);
  }
  if (pvVar1 != (PVOID)0x0) {
    iVar2 = FUN_004242b2(_Buf + 8);
    if ((iVar2 == 0) || (_Buf[8] != 0x56433230)) {
      __local_unwind2((int)pvVar1,_Buf[7]);
    }
    else if ((code *)_Buf[9] != (code *)0x0) {
      (*(code *)_Buf[9])(_Buf);
    }
  }
  FUN_004210f2();
                    // WARNING: Could not recover jumptable at 0x00420195. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)_Buf[5])();
  return;
}



int __cdecl FUN_00420199(uchar *param_1)

{
  int iVar1;
  
  FUN_0042152d(0xc);
  iVar1 = FUN_004201ba(param_1);
  FUN_0042158e(0xc);
  return iVar1;
}



int __cdecl FUN_004201ba(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_0043692c != 0) &&
      ((DAT_00434e80 != (int *)0x0 ||
       (((DAT_00434e88 != 0 && (iVar1 = FUN_00424356(), iVar1 == 0)) && (DAT_00434e80 != (int *)0x0)
        ))))) && (piVar3 = DAT_00434e80, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00420237(void)

{
  void *extraout_ECX;
  
  FUN_0042024e();
  _DAT_00434ec4 = FUN_00424414();
  FUN_004243c4(extraout_ECX);
  return;
}



void FUN_0042024e(void)

{
  PTR_FUN_00432758 = &LAB_00424497;
  PTR_FUN_00432754 = __cfltcvt;
  PTR_FUN_0043275c = __fassign;
  PTR_FUN_00432760 = FUN_0042443d;
  PTR_FUN_00432764 = &LAB_004244e5;
  PTR_FUN_00432768 = __cfltcvt;
  return;
}



// Library Function - Single Match
//  __setjmp3
// 
// Library: Visual Studio

undefined4 __cdecl __setjmp3(undefined4 *param_1,int param_2,void *param_3,undefined4 param_4)

{
  void *pvVar1;
  uint uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 unaff_EDI;
  undefined4 *puVar4;
  undefined4 unaff_retaddr;
  
  *param_1 = unaff_EBP;
  param_1[1] = unaff_EBX;
  param_1[2] = unaff_EDI;
  param_1[3] = unaff_ESI;
  param_1[4] = register0x00000010;
  param_1[5] = unaff_retaddr;
  param_1[8] = 0x56433230;
  param_1[9] = 0;
  pvVar1 = ExceptionList;
  param_1[6] = ExceptionList;
  if (pvVar1 == (void *)0xffffffff) {
    param_1[7] = 0xffffffff;
  }
  else if ((param_2 == 0) || (param_1[9] = param_3, pvVar1 = param_3, param_2 == 1)) {
    param_1[7] = *(undefined4 *)((int)pvVar1 + 0xc);
  }
  else {
    param_1[7] = param_4;
    uVar2 = param_2 - 2;
    if (uVar2 != 0) {
      puVar3 = (undefined4 *)&stack0x00000014;
      puVar4 = param_1 + 10;
      if (6 < uVar2) {
        uVar2 = 6;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return 0;
}



void __cdecl FUN_00420303(char param_1)

{
  FUN_0041b3a0(param_1,(int *)&DAT_00431c98);
  return;
}



void __cdecl FUN_00420314(char param_1)

{
  FUN_00420303(param_1);
  return;
}



uint __thiscall FUN_0042031f(void *this,int param_1)

{
  uint uVar1;
  
  if (1 < DAT_00432104) {
    uVar1 = FUN_0041eea6(this,param_1,4);
    return uVar1;
  }
  return (byte)PTR_DAT_00431ef8[param_1 * 2] & 4;
}



uint __thiscall FUN_00420347(void *this,int param_1)

{
  uint uVar1;
  
  if (1 < DAT_00432104) {
    uVar1 = FUN_0041eea6(this,param_1,8);
    return uVar1;
  }
  return (byte)PTR_DAT_00431ef8[param_1 * 2] & 8;
}



uint __thiscall FUN_0042036f(void *this,int param_1)

{
  uint uVar1;
  
  if (1 < DAT_00432104) {
    uVar1 = FUN_0041eea6(this,param_1,0x107);
    return uVar1;
  }
  return *(ushort *)(PTR_DAT_00431ef8 + param_1 * 2) & 0x107;
}



uint __thiscall FUN_0042039d(void *this,int param_1)

{
  uint uVar1;
  
  if (1 < DAT_00432104) {
    uVar1 = FUN_0041eea6(this,param_1,0x157);
    return uVar1;
  }
  return *(ushort *)(PTR_DAT_00431ef8 + param_1 * 2) & 0x157;
}



// WARNING: Unable to track spacebase fully for stack

void FUN_004203d0(undefined1 param_1)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &param_1;
  if (0xfff < in_EAX) {
    do {
      puVar1 = puVar1 + -0x1000;
      in_EAX = in_EAX - 0x1000;
    } while (0xfff < in_EAX);
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



uint __cdecl FUN_004203ff(uint param_1)

{
  SIZE_T SVar1;
  uint *puVar2;
  
  FUN_0041f00f();
  SVar1 = FUN_00424863(DAT_00436938);
  if (SVar1 < (uint)((int)DAT_00436934 + (4 - (int)DAT_00436938))) {
    SVar1 = FUN_00424863(DAT_00436938);
    puVar2 = FUN_0041ba30(DAT_00436938,SVar1 + 0x10);
    if (puVar2 == (uint *)0x0) {
      param_1 = 0;
      goto LAB_00420474;
    }
    DAT_00436934 = puVar2 + ((int)DAT_00436934 - (int)DAT_00436938 >> 2);
    DAT_00436938 = puVar2;
  }
  *DAT_00436934 = param_1;
  DAT_00436934 = DAT_00436934 + 1;
LAB_00420474:
  FUN_0041f018();
  return param_1;
}



int __cdecl FUN_0042047d(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_004203ff(param_1);
  return (uVar1 != 0) - 1;
}



// Library Function - Single Match
//  _strrchr
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}



// Library Function - Single Match
//  _strncat
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

char * __cdecl _strncat(char *_Dest,char *_Source,size_t _Count)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if (_Count != 0) {
    uVar4 = (uint)_Dest & 3;
    puVar5 = (uint *)_Dest;
    while (uVar4 != 0) {
      bVar1 = *(byte *)puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      if (bVar1 == 0) goto LAB_0042054b;
      uVar4 = (uint)puVar5 & 3;
    }
    do {
      do {
        puVar6 = puVar5;
        puVar5 = puVar6 + 1;
      } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
      uVar4 = *puVar6;
      if ((char)uVar4 == '\0') goto LAB_0042055b;
      if ((char)(uVar4 >> 8) == '\0') {
        puVar6 = (uint *)((int)puVar6 + 1);
        goto LAB_0042055b;
      }
      if ((uVar4 & 0xff0000) == 0) {
        puVar6 = (uint *)((int)puVar6 + 2);
        goto LAB_0042055b;
      }
    } while ((uVar4 & 0xff000000) != 0);
LAB_0042054b:
    puVar6 = (uint *)((int)puVar5 + -1);
LAB_0042055b:
    if (((uint)_Source & 3) == 0) {
      uVar3 = _Count >> 2;
    }
    else {
      do {
        bVar1 = *_Source;
        uVar4 = (uint)bVar1;
        _Source = (char *)((int)_Source + 1);
        if (bVar1 == 0) goto LAB_004205aa;
        *(byte *)puVar6 = bVar1;
        puVar6 = (uint *)((int)puVar6 + 1);
        _Count = _Count - 1;
        if (_Count == 0) goto LAB_004205a0;
      } while (((uint)_Source & 3) != 0);
      uVar3 = _Count >> 2;
    }
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      uVar2 = *(uint *)_Source;
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar4 == '\0') {
LAB_004205aa:
          *(byte *)puVar6 = (byte)uVar4;
          return _Dest;
        }
        if ((char)(uVar4 >> 8) == '\0') {
          *(short *)puVar6 = (short)uVar4;
          return _Dest;
        }
        if ((uVar4 & 0xff0000) == 0) {
          *(short *)puVar6 = (short)uVar4;
          *(byte *)((int)puVar6 + 2) = 0;
          return _Dest;
        }
        if ((uVar4 & 0xff000000) == 0) {
          *puVar6 = uVar4;
          return _Dest;
        }
      }
      *puVar6 = uVar4;
      puVar6 = puVar6 + 1;
    }
    for (_Count = _Count & 3; _Count != 0; _Count = _Count - 1) {
      bVar1 = *_Source;
      _Source = (char *)((int)_Source + 1);
      *(byte *)puVar6 = bVar1;
      puVar6 = (uint *)((int)puVar6 + 1);
      if (bVar1 == 0) {
        return _Dest;
      }
    }
LAB_004205a0:
    *(byte *)puVar6 = (byte)_Count;
  }
  return _Dest;
}



// Library Function - Single Match
//  _strncpy
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      cVar3 = *_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = cVar3;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if (cVar3 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x0042065e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0042069b;
        goto LAB_00420709;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x00420705:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00420709:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0042069b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00420705;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00420705;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00420705;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0042065e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = *_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_0042069b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



void __cdecl FUN_0042071e(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_0042079a();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_004321f0;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_00420791();
      *pDVar1 = (&DAT_004321f4)[iVar3 * 2];
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x432358);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_00420791();
    *pDVar1 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    pDVar1 = FUN_00420791();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_00420791();
  *pDVar1 = 0x16;
  return;
}



DWORD * FUN_00420791(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_00420f76();
  return pDVar1 + 2;
}



DWORD * FUN_0042079a(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_00420f76();
  return pDVar1 + 3;
}



LONG __cdecl FUN_004207a3(int param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  DWORD DVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  int *piVar5;
  LONG LVar6;
  int iVar7;
  int iVar8;
  
  pDVar4 = FUN_00420f76();
  piVar5 = FUN_004208e1(param_1,(int *)pDVar4[0x14]);
  if ((piVar5 == (int *)0x0) || (pcVar1 = (code *)piVar5[2], pcVar1 == (code *)0x0)) {
    LVar6 = UnhandledExceptionFilter(param_2);
  }
  else if (pcVar1 == (code *)0x5) {
    piVar5[2] = 0;
    LVar6 = 1;
  }
  else {
    if (pcVar1 != (code *)0x1) {
      DVar2 = pDVar4[0x15];
      pDVar4[0x15] = (DWORD)param_2;
      if (piVar5[1] == 8) {
        if (DAT_004323d0 < DAT_004323d4 + DAT_004323d0) {
          iVar7 = DAT_004323d0 * 0xc;
          iVar8 = DAT_004323d0;
          do {
            *(undefined4 *)(iVar7 + 8 + pDVar4[0x14]) = 0;
            iVar8 = iVar8 + 1;
            iVar7 = iVar7 + 0xc;
          } while (iVar8 < DAT_004323d4 + DAT_004323d0);
        }
        iVar7 = *piVar5;
        DVar3 = pDVar4[0x16];
        if (iVar7 == -0x3fffff72) {
          pDVar4[0x16] = 0x83;
        }
        else if (iVar7 == -0x3fffff70) {
          pDVar4[0x16] = 0x81;
        }
        else if (iVar7 == -0x3fffff6f) {
          pDVar4[0x16] = 0x84;
        }
        else if (iVar7 == -0x3fffff6d) {
          pDVar4[0x16] = 0x85;
        }
        else if (iVar7 == -0x3fffff73) {
          pDVar4[0x16] = 0x82;
        }
        else if (iVar7 == -0x3fffff71) {
          pDVar4[0x16] = 0x86;
        }
        else if (iVar7 == -0x3fffff6e) {
          pDVar4[0x16] = 0x8a;
        }
        (*pcVar1)(8,pDVar4[0x16]);
        pDVar4[0x16] = DVar3;
      }
      else {
        piVar5[2] = 0;
        (*pcVar1)(piVar5[1]);
      }
      pDVar4[0x15] = DVar2;
    }
    LVar6 = -1;
  }
  return LVar6;
}



int * __cdecl FUN_004208e1(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = param_2;
  if (*param_2 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (param_2 + DAT_004323dc * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_004323dc * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



void FUN_0042091b(void)

{
  char cVar1;
  size_t sVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *_Str;
  
  if (DAT_00436930 == 0) {
    FUN_00424c80();
  }
  iVar5 = 0;
  for (puVar3 = DAT_00434e50; *(char *)puVar3 != '\0'; puVar3 = (uint *)((int)puVar3 + sVar2 + 1)) {
    if (*(char *)puVar3 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar3);
  }
  puVar3 = FUN_0041b590(iVar5 * 4 + 4);
  DAT_00434e80 = puVar3;
  if (puVar3 == (uint *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *(char *)DAT_00434e50;
  _Str = DAT_00434e50;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)_Str);
    if (*(char *)_Str != '=') {
      puVar4 = FUN_0041b590(sVar2 + 1);
      *puVar3 = (uint)puVar4;
      if (puVar4 == (uint *)0x0) {
        __amsg_exit(9);
      }
      FUN_00423540((uint *)*puVar3,_Str);
      puVar3 = puVar3 + 1;
    }
    _Str = (uint *)((int)_Str + sVar2 + 1);
    cVar1 = *(char *)_Str;
  }
  FUN_0041b8c0((int)DAT_00434e50);
  DAT_00434e50 = (uint *)0x0;
  *puVar3 = 0;
  DAT_0043692c = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_004209d4(void)

{
  uint *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_00436930 == 0) {
    FUN_00424c80();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_00434ec8,0x104);
  _DAT_00434e90 = &DAT_00434ec8;
  pbVar2 = &DAT_00434ec8;
  if (*DAT_00437944 != 0) {
    pbVar2 = DAT_00437944;
  }
  FUN_00420a6d(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = FUN_0041b590(local_c + local_8 * 4);
  if (puVar1 == (uint *)0x0) {
    __amsg_exit(8);
  }
  FUN_00420a6d(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  DAT_00434e78 = puVar1;
  DAT_00434e74 = local_8 + -1;
  return;
}



void __cdecl FUN_00420a6d(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if ((((&DAT_00436701)[bVar1] & 4) != 0) && (*param_5 = *param_5 + 1, param_3 != (byte *)0x0))
      {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if (((&DAT_00436701)[bVar1] & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00420b18;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00420b18:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar7 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = param_3;
      puVar7 = puVar7 + 1;
      param_2 = puVar7;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar6 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar4 == 0x22) {
        pbVar5 = pbVar4;
        if ((uVar6 & 1) == 0) {
          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {
            bVar3 = false;
            pbVar5 = pbVar4;
          }
          bVar2 = !bVar2;
          puVar7 = param_2;
        }
        uVar6 = uVar6 >> 1;
        pbVar4 = pbVar5;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if (((&DAT_00436701)[bVar1] & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if (((&DAT_00436701)[bVar1] & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



uint * FUN_00420c21(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  int cbMultiByte;
  uint *puVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  uint *local_8;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_00434fcc == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_00434fcc = 1;
LAB_00420c78:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (uint *)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      cbMultiByte = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                       );
      local_8 = (uint *)0x0;
      if (((cbMultiByte != 0) && (puVar6 = FUN_0041b590(cbMultiByte), puVar6 != (uint *)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)puVar6,cbMultiByte,(LPCSTR)0x0,
                                      (LPBOOL)0x0), local_8 = puVar6, iVar5 == 0)) {
        FUN_0041b8c0((int)puVar6);
        local_8 = (uint *)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (uint *)0x0;
    }
    DAT_00434fcc = 2;
  }
  else {
    if (DAT_00434fcc == 1) goto LAB_00420c78;
    if (DAT_00434fcc != 2) {
      return (uint *)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (uint *)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  puVar6 = FUN_0041b590((int)(pcVar7 + (1 - (int)pCVar9)));
  if (puVar6 == (uint *)0x0) {
    puVar6 = (uint *)0x0;
  }
  else {
    FUN_00423630(puVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return puVar6;
}



void FUN_00420d53(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  UINT UVar9;
  UINT UVar10;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  puVar3 = FUN_0041b590(0x480);
  if (puVar3 == (uint *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00436920 = 0x20;
  DAT_00436820 = puVar3;
  for (; puVar3 < DAT_00436820 + 0x120; puVar3 = puVar3 + 9) {
    *(undefined *)(puVar3 + 1) = 0;
    *puVar3 = 0xffffffff;
    puVar3[2] = 0;
    *(undefined *)((int)puVar3 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar9 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar9);
    if (0x7ff < (int)UVar9) {
      UVar9 = 0x800;
    }
    UVar10 = UVar9;
    if ((int)DAT_00436920 < (int)UVar9) {
      piVar7 = &DAT_00436824;
      do {
        puVar3 = FUN_0041b590(0x480);
        UVar10 = DAT_00436920;
        if (puVar3 == (uint *)0x0) break;
        DAT_00436920 = DAT_00436920 + 0x20;
        *piVar7 = (int)puVar3;
        puVar2 = puVar3;
        for (; puVar3 < puVar2 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined *)((int)puVar3 + 5) = 10;
          puVar2 = (uint *)*piVar7;
        }
        piVar7 = piVar7 + 1;
        UVar10 = UVar9;
      } while ((int)DAT_00436920 < (int)UVar9);
    }
    uVar8 = 0;
    if (0 < (int)UVar10) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*(byte *)pUVar5 & 1) != 0)) &&
           (((*(byte *)pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0))))
        {
          puVar1 = (undefined4 *)((int)(&DAT_00436820)[(int)uVar8 >> 5] + (uVar8 & 0x1f) * 0x24);
          *puVar1 = *(undefined4 *)local_8;
          *(byte *)(puVar1 + 1) = *(byte *)pUVar5;
        }
        local_8 = local_8 + 4;
        uVar8 = uVar8 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar8 < (int)UVar10);
    }
  }
  iVar6 = 0;
  do {
    puVar3 = DAT_00436820 + iVar6 * 9;
    if (DAT_00436820[iVar6 * 9] == 0xffffffff) {
      *(undefined *)(puVar3 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar3 = (uint)hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar3 + 1) = *(byte *)(puVar3 + 1) | 8;
          }
          goto LAB_00420ef8;
        }
      }
      *(byte *)(puVar3 + 1) = *(byte *)(puVar3 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar3 + 1) = *(byte *)(puVar3 + 1) | 0x80;
    }
LAB_00420ef8:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_00436920);
      return;
    }
  } while( true );
}



undefined4 FUN_00420f0f(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_00421504();
  DAT_00432404 = TlsAlloc();
  if (DAT_00432404 != 0xffffffff) {
    lpTlsValue = FUN_0041bbc0(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00432404,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00420f63((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}



void __cdecl FUN_00420f63(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_00432358;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



DWORD * FUN_00420f76(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = (DWORD *)TlsGetValue(DAT_00432404);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = FUN_0041bbc0(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00432404,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00420f63((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_00420fd1;
      }
    }
    __amsg_exit(0x10);
  }
LAB_00420fd1:
  SetLastError(dwErrCode);
  return lpTlsValue;
}



undefined4 __cdecl FUN_00420fdd(int param_1)

{
  int iVar1;
  
  DAT_00436810 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_00436810 != (HANDLE)0x0) {
    iVar1 = FUN_00424c9c();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_00436810);
  }
  return 0;
}



// Library Function - Single Match
//  __global_unwind2
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
// Studio 2003 Release

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x421034,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



// Library Function - Single Match
//  __local_unwind2
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
// Studio 2003 Release

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  undefined *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_0042103c;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_004210f2();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}



// Library Function - Single Match
//  __abnormal_termination
// 
// Library: Visual Studio

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(undefined **)((int)ExceptionList + 4) == &LAB_0042103c) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}



// Library Function - Single Match
//  __NLG_Notify1
// 
// Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
// Studio 2019 Release

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_00432414 = param_1;
  DAT_00432410 = in_EAX;
  DAT_00432418 = unaff_EBP;
  return;
}



void FUN_004210f2(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_00432414 = *(undefined4 *)(unaff_EBP + 8);
  DAT_00432410 = in_EAX;
  DAT_00432418 = unaff_EBP;
  return;
}



void FUN_004211d1(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



void FUN_004211ec(void)

{
  if ((DAT_00434e58 == 1) || ((DAT_00434e58 == 0 && (DAT_00431c74 == 1)))) {
    FUN_00421225(0xfc);
    if (DAT_00434fd0 != (code *)0x0) {
      (*DAT_00434fd0)();
    }
    FUN_00421225(0xff);
  }
  return;
}



void __cdecl FUN_00421225(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
  iVar5 = 0;
  pDVar2 = &DAT_00432420;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x4324b0);
  if (param_1 == (&DAT_00432420)[iVar5 * 2]) {
    if ((DAT_00434e58 == 1) || ((DAT_00434e58 == 0 && (DAT_00431c74 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x432424);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_00423540(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_00423540(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_00423550(local_a4,_Dest);
      FUN_00423550(local_a4,(uint *)&DAT_0042b538);
      FUN_00423550(local_a4,*(uint **)(iVar5 * 8 + 0x432424));
      auStackY_1e3._3_4_ = 0x421349;
      FUN_00424d05(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



undefined4 __cdecl FUN_00421378(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_00436920) &&
     ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00424fee(param_1);
    uVar1 = FUN_004213d5(param_1);
    FUN_0042504d(param_1);
    return uVar1;
  }
  pDVar2 = FUN_00420791();
  *pDVar2 = 9;
  pDVar2 = FUN_0042079a();
  *pDVar2 = 0;
  return 0xffffffff;
}



undefined4 __cdecl FUN_004213d5(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_00424fac(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_00424fac(2);
      iVar2 = FUN_00424fac(1);
      if (iVar2 == iVar1) goto LAB_00421423;
    }
    hObject = (HANDLE)FUN_00424fac(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_00421425;
    }
  }
LAB_00421423:
  DVar4 = 0;
LAB_00421425:
  FUN_00424f2d(param_1);
  *(undefined *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_0042071e(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



// Library Function - Single Match
//  __freebuf
// 
// Library: Visual Studio 2003 Release

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_0041b8c0((int)_File->_base);
    *(ushort *)&_File->_flag = *(ushort *)&_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}



void FUN_00421504(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_004324f4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_004324e4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_004324d4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_004324b4);
  return;
}



void __cdecl FUN_0042152d(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = (int *)(&DAT_004324b0 + param_1 * 4);
  if (*(int *)(&DAT_004324b0 + param_1 * 4) == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_0041b590(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_0042152d(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_0041b8c0((int)lpCriticalSection);
    }
    FUN_0042158e(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}



void __cdecl FUN_0042158e(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_004324b0 + param_1 * 4));
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 * __cdecl FUN_004215a3(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  
  bVar4 = false;
  bVar3 = false;
  cVar1 = *param_2;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar6 = DAT_00435180 | 1;
      goto LAB_004215e4;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_00435180 | 2;
LAB_004215e4:
  bVar2 = true;
LAB_004215e7:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_00425086(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_00434e5c = _DAT_00434e5c + 1;
    param_4[3] = uVar6;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = uVar5;
    return param_4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_004215e7;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_004215e7;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_004215e7;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_004215e7;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_004215e7;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_004216c7;
      uVar5 = uVar5 | 0x8000;
      goto LAB_004215e7;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_004215e7;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_004216c7;
        uVar5 = uVar5 | 0x4000;
        goto LAB_004215e7;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_004215e7;
      }
    }
  }
LAB_004216c7:
  bVar2 = false;
  goto LAB_004215e7;
}



undefined4 * FUN_00421713(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_0042152d(2);
  iVar3 = 0;
  if (0 < DAT_00437940) {
    do {
      iVar1 = *(int *)(DAT_0043693c + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        puVar2 = FUN_0041b590(0x38);
        *(uint **)(iVar3 + DAT_0043693c) = puVar2;
        if (*(int *)(iVar3 + DAT_0043693c) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_0043693c) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_0043693c) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_0043693c);
LAB_004217b7:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        FUN_0041eb91(iVar3,iVar1);
        iVar1 = *(int *)(DAT_0043693c + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_0043693c + iVar3 * 4);
          goto LAB_004217b7;
        }
        FUN_0041ebe3(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00437940);
  }
  FUN_0042158e(2);
  return puVar4;
}



uint __cdecl FUN_004217db(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  undefined3 extraout_var;
  undefined *puVar6;
  int *piVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_004218e7:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_004218e7;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_00431c98 && (piVar4 != (int *)&DAT_00431cb8)) ||
        (bVar5 = FUN_0042542d(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_00422dd3(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_00422eaa(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_004323e0;
        }
        else {
          puVar6 = (undefined *)((&DAT_00436820)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_00425355(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_00422eaa(uVar2,pcVar3,(uint)piVar7);
      }
      *(undefined *)piVar4[2] = (undefined)param_1;
    }
    if (param_2 == piVar7) {
      return param_1 & 0xff;
    }
    piVar4[3] = piVar4[3] | 0x20;
  }
  return 0xffffffff;
}



int __cdecl FUN_004218f3(int *param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  LPSTR pCVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  LPSTR pCVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined local_24c [511];
  undefined local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  LPSTR local_10;
  WCHAR *local_c;
  uint local_8;
  
  local_34 = 0;
  bVar9 = *param_2;
  param_2 = param_2 + 1;
  local_10 = (LPSTR)0x0;
  local_18 = 0;
  do {
    if ((bVar9 == 0) || (local_18 < 0)) {
      return local_18;
    }
    if (((char)bVar9 < ' ') || ('x' < (char)bVar9)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"Runtime Error!\n\nProgram: "[(char)bVar9 + 0x18] & 0xf;
    }
    local_34 = (int)(char)(&DAT_0042b574)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_00421961_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_00431ef8[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_00422034((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = param_2 + 1;
      }
      FUN_00422034((int)(char)bVar9,param_1,&local_18);
      break;
    case 1:
      local_14 = -1;
      local_38 = 0;
      local_2c = 0;
      local_24 = 0;
      local_20 = 0;
      local_8 = 0;
      local_28 = 0;
      break;
    case 2:
      if (bVar9 == 0x20) {
        local_8 = local_8 | 2;
      }
      else if (bVar9 == 0x23) {
        local_8 = local_8 | 0x80;
      }
      else if (bVar9 == 0x2b) {
        local_8 = local_8 | 1;
      }
      else if (bVar9 == 0x2d) {
        local_8 = local_8 | 4;
      }
      else if (bVar9 == 0x30) {
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar9 == 0x2a) {
        local_24 = FUN_004220d2((int *)&param_3);
        if (local_24 < 0) {
          local_8 = local_8 | 4;
          local_24 = -local_24;
        }
      }
      else {
        local_24 = (char)bVar9 + -0x30 + local_24 * 10;
      }
      break;
    case 4:
      local_14 = 0;
      break;
    case 5:
      if (bVar9 == 0x2a) {
        local_14 = FUN_004220d2((int *)&param_3);
        if (local_14 < 0) {
          local_14 = -1;
        }
      }
      else {
        local_14 = (char)bVar9 + -0x30 + local_14 * 10;
      }
      break;
    case 6:
      if (bVar9 == 0x49) {
        if ((*param_2 != 0x36) || (param_2[1] != 0x34)) {
          local_34 = 0;
          goto switchD_00421961_caseD_0;
        }
        param_2 = param_2 + 2;
        local_8 = local_8 | 0x8000;
      }
      else if (bVar9 == 0x68) {
        local_8 = local_8 | 0x20;
      }
      else if (bVar9 == 0x6c) {
        local_8 = local_8 | 0x10;
      }
      else if (bVar9 == 0x77) {
        local_8 = local_8 | 0x800;
      }
      break;
    case 7:
      pWVar4 = local_c;
      if ((char)bVar9 < 'h') {
        if ((char)bVar9 < 'e') {
          if ((char)bVar9 < 'Y') {
            if (bVar9 == 0x58) {
LAB_00421d72:
              local_30 = 7;
LAB_00421d79:
              local_10 = (LPSTR)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_00421de3;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_00421b20;
                }
                goto LAB_00421efd;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_00421b81;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_00421bae:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_004220d2((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (LPSTR)0x1;
            }
            else {
              uVar5 = FUN_004220ef((int *)&param_3);
              local_10 = FUN_00425456(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_004220d2((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_s__null__00432570;
              pWVar4 = (WCHAR *)PTR_s__null__00432570;
              goto LAB_00421cf3;
            }
            if ((local_8 & 0x800) == 0) {
              local_28 = 0;
              local_10 = (LPSTR)(int)*psVar6;
            }
            else {
              local_28 = 1;
              local_10 = (LPSTR)((uint)(int)*psVar6 >> 1);
            }
          }
          else {
            if (bVar9 == 99) goto LAB_00421bae;
            if (bVar9 == 100) goto LAB_00421dd8;
          }
        }
        else {
LAB_00421b81:
          local_8 = local_8 | 0x40;
          pWVar4 = (WCHAR *)local_24c;
          if (local_14 < 0) {
            local_14 = 6;
          }
          else if ((local_14 == 0) && (bVar9 == 0x67)) {
            local_14 = 1;
          }
          local_4c = *param_3;
          local_48 = param_3[1];
          param_3 = param_3 + 2;
          local_c = pWVar4;
          (*(code *)PTR_FUN_00432754)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR_FUN_00432760)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR_FUN_00432758)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_00421cf3:
          local_10 = (LPSTR)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_00421dd8:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_004220d2((int *)&param_3);
            if ((local_8 & 0x20) == 0) {
              *piVar7 = local_18;
            }
            else {
              *(undefined2 *)piVar7 = (undefined2)local_18;
            }
            local_2c = 1;
            break;
          }
          if (bVar9 == 0x6f) {
            local_10 = (LPSTR)0x8;
            if ((local_8 & 0x80) != 0) {
              local_8 = local_8 | 0x200;
            }
            goto LAB_00421de3;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_00421d72;
          }
          if (bVar9 == 0x73) {
LAB_00421b20:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_004220d2((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_s__null__00432570;
                pWVar4 = (WCHAR *)PTR_s__null__00432570;
              }
              for (; (iVar10 != 0 && (*(char *)pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1)
                  ) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (LPSTR)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_00432574;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (LPSTR)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_00421efd;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_00421efd;
            local_30 = 0x27;
            goto LAB_00421d79;
          }
        }
        local_10 = (LPSTR)0xa;
LAB_00421de3:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_004220d2((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_00421e36;
            }
            uVar2 = FUN_004220d2((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_004220d2((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_004220d2((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_004220df((int *)&param_3);
        }
LAB_00421e36:
        iVar10 = (int)(uVar13 >> 0x20);
        if ((((local_8 & 0x40) != 0) && (iVar10 == 0 || (longlong)uVar13 < 0)) &&
           ((longlong)uVar13 < 0)) {
          local_8 = local_8 | 0x100;
          uVar13 = CONCAT44(-(iVar10 + (uint)((int)uVar13 != 0)),-(int)uVar13);
        }
        uVar2 = (uint)(uVar13 >> 0x20);
        uVar15 = uVar13 & 0xffffffff;
        if ((local_8 & 0x8000) == 0) {
          uVar2 = 0;
        }
        if (local_14 < 0) {
          local_14 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((int)uVar13 == 0 && uVar2 == 0) {
          local_20 = 0;
        }
        local_c = (WCHAR *)&local_4d;
        while( true ) {
          uVar11 = (uint)uVar15;
          iVar10 = local_14 + -1;
          if ((local_14 < 1) && (uVar11 == 0 && uVar2 == 0)) break;
          local_40 = (int)local_10 >> 0x1f;
          local_44 = (uint)local_10;
          local_14 = iVar10;
          uVar14 = __aullrem(uVar11,uVar2,(uint)local_10,local_40);
          iVar10 = (int)uVar14 + 0x30;
          uVar15 = __aulldiv(uVar11,uVar2,local_44,local_40);
          uVar2 = (uint)(uVar15 >> 0x20);
          if (0x39 < iVar10) {
            iVar10 = iVar10 + local_30;
          }
          pWVar4 = (WCHAR *)((int)local_c + -1);
          *(char *)local_c = (char)iVar10;
          local_c = pWVar4;
        }
        iVar1 = -(int)local_c;
        local_10 = &local_4d + iVar1;
        pWVar4 = (WCHAR *)((int)local_c + 1);
        local_14 = iVar10;
        if (((local_8 & 0x200) != 0) && ((*(char *)pWVar4 != '0' || (local_10 == (LPSTR)0x0)))) {
          *(char *)local_c = '0';
          local_10 = (LPSTR)((int)&local_4c + iVar1);
          pWVar4 = local_c;
        }
      }
LAB_00421efd:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_00421f35;
              local_1a = ' ';
            }
            else {
              local_1a = '+';
            }
          }
          else {
            local_1a = '-';
          }
          local_20 = 1;
        }
LAB_00421f35:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_00422069(0x20,iVar10,param_1,&local_18);
        }
        FUN_0042209a(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_00422069(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (pCVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_0042209a((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            pCVar12 = pCVar12 + -1;
            pCVar8 = FUN_00425456(local_3c,*pWVar4);
            if ((int)pCVar8 < 1) break;
            FUN_0042209a(local_3c,(int)pCVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (pCVar12 != (LPSTR)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_00422069(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    param_2 = param_2 + 1;
  } while( true );
}



void __cdecl FUN_00422034(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_004217db(param_1,param_2);
  }
  else {
    *(undefined *)*param_2 = (undefined)param_1;
    *param_2 = *param_2 + 1;
    uVar2 = param_1 & 0xff;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}



void __cdecl FUN_00422069(uint param_1,int param_2,int *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      FUN_00422034(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



void __cdecl FUN_0042209a(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      FUN_00422034((int)cVar1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



undefined4 __cdecl FUN_004220d2(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}



undefined8 __cdecl FUN_004220df(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}



undefined4 __cdecl FUN_004220ef(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}



uint __cdecl FUN_004220fd(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      param_1[3] = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        FUN_00422dd3(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_00425605(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_004323e0;
          }
          else {
            puVar4 = (undefined *)((&DAT_00436820)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            param_1[3] = param_1[3] | 0x2000;
          }
        }
        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
          param_1[6] = 0x1000;
        }
        param_1[1] = iVar3 + -1;
        bVar1 = *(byte *)*param_1;
        *param_1 = (byte *)*param_1 + 1;
        return (uint)bVar1;
      }
      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      param_1[1] = 0;
    }
    else {
      param_1[3] = uVar2 | 0x20;
    }
  }
  return 0xffffffff;
}



BOOL __cdecl
FUN_004221d9(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined *puVar1;
  BOOL BVar2;
  int iVar3;
  undefined unaff_DI;
  WORD local_20 [2];
  undefined *local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042b5f0;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_00435038;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_00435038 == 0) {
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_00435038 = iVar3;
  if (DAT_00435038 != 2) {
    if (DAT_00435038 == 1) {
      if (param_5 == 0) {
        param_5 = DAT_00435060;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_004203d0(unaff_DI);
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return BVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_00435050;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}



int __thiscall FUN_00422322(void *this,int *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  void *this_00;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *this_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *piVar7;
  byte bVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  WCHAR *pWVar13;
  undefined *puVar14;
  int iVar15;
  bool bVar16;
  int *piVar17;
  char local_1c8;
  char local_1c7 [351];
  byte local_68 [32];
  undefined4 *local_48;
  WCHAR local_42;
  uint local_40;
  byte local_3c;
  undefined local_3b;
  byte local_39;
  int local_38;
  WCHAR *local_34;
  WCHAR *local_30;
  undefined8 local_2c;
  int local_24;
  int local_20;
  byte local_1c;
  char local_1b;
  char local_1a;
  char local_19;
  int *local_18;
  char local_13;
  char local_12;
  char local_11;
  int local_10;
  char local_9;
  undefined *local_8;
  
  local_19 = '\0';
  bVar1 = *param_2;
  local_8 = (undefined *)0x0;
  local_38 = 0;
  pbVar9 = param_2;
  piVar7 = (int *)PTR_DAT_00431ef8;
  do {
    PTR_DAT_00431ef8 = (undefined *)piVar7;
    if (bVar1 == 0) {
LAB_00422d28:
      if (local_18 == (int *)0xffffffff) {
LAB_00422d2e:
        if ((local_38 == 0) && (local_19 == '\0')) {
          local_38 = -1;
        }
      }
      return local_38;
    }
    if ((int)DAT_00432104 < 2) {
      uVar5 = *(byte *)((int)piVar7 + (uint)bVar1 * 2) & 8;
    }
    else {
      piVar7 = (int *)0x8;
      uVar5 = FUN_0041eea6(this,(uint)bVar1,8);
    }
    if (uVar5 != 0) {
      local_8 = local_8 + -1;
      piVar7 = param_1;
      uVar5 = FUN_00422daf((int *)&local_8,param_1);
      FUN_00422d98(uVar5,piVar7);
      uVar5 = FUN_00420347(this_00,(uint)pbVar9[1]);
      piVar7 = extraout_ECX;
      pbVar10 = pbVar9;
      while (pbVar9 = pbVar10 + 1, uVar5 != 0) {
        piVar17 = (int *)(uint)pbVar10[2];
        uVar5 = FUN_00420347(piVar7,(int)(uint)pbVar10[2]);
        piVar7 = piVar17;
        pbVar10 = pbVar9;
      }
    }
    if (*pbVar9 == 0x25) {
      local_39 = 0;
      local_1c = 0;
      local_1b = '\0';
      local_12 = '\0';
      local_13 = '\0';
      local_1a = '\0';
      puVar14 = (undefined *)0x0;
      local_9 = '\0';
      local_20 = 0;
      local_24 = 0;
      local_10 = 0;
      local_11 = '\x01';
      local_34 = (WCHAR *)0x0;
      do {
        uVar5 = (uint)pbVar9[1];
        param_2 = pbVar9 + 1;
        if ((int)DAT_00432104 < 2) {
          uVar6 = (byte)PTR_DAT_00431ef8[uVar5 * 2] & 4;
          piVar7 = (int *)PTR_DAT_00431ef8;
        }
        else {
          piVar17 = (int *)0x4;
          uVar6 = FUN_0041eea6(piVar7,uVar5,4);
          piVar7 = piVar17;
        }
        if (uVar6 == 0) {
          if (uVar5 < 0x4f) {
            if (uVar5 != 0x4e) {
              if (uVar5 == 0x2a) {
                local_12 = local_12 + '\x01';
              }
              else if (uVar5 != 0x46) {
                if (uVar5 == 0x49) {
                  if ((pbVar9[2] != 0x36) || (pbVar9[3] != 0x34)) goto LAB_0042247d;
                  local_34 = (WCHAR *)((int)local_34 + 1);
                  local_2c = 0;
                  param_2 = pbVar9 + 3;
                }
                else if (uVar5 == 0x4c) {
                  local_11 = local_11 + '\x01';
                }
                else {
LAB_0042247d:
                  local_13 = local_13 + '\x01';
                }
              }
            }
          }
          else if (uVar5 == 0x68) {
            local_11 = local_11 + -1;
            local_9 = local_9 + -1;
          }
          else {
            if (uVar5 == 0x6c) {
              local_11 = local_11 + '\x01';
            }
            else if (uVar5 != 0x77) goto LAB_0042247d;
            local_9 = local_9 + '\x01';
          }
        }
        else {
          local_24 = local_24 + 1;
          local_10 = (uVar5 - 0x30) + local_10 * 10;
        }
        pbVar9 = param_2;
      } while (local_13 == '\0');
      puVar2 = param_3;
      if (local_12 == '\0') {
        local_30 = (WCHAR *)*param_3;
        puVar2 = param_3 + 1;
        local_48 = param_3;
      }
      param_3 = puVar2;
      local_13 = '\0';
      if (local_9 == '\0') {
        if ((*param_2 == 0x53) || (*param_2 == 0x43)) {
          local_9 = '\x01';
        }
        else {
          local_9 = -1;
        }
      }
      uVar5 = *param_2 | 0x20;
      local_40 = uVar5;
      if (uVar5 != 0x6e) {
        if ((uVar5 == 99) || (uVar5 == 0x7b)) {
          local_8 = local_8 + 1;
          piVar7 = param_1;
          local_18 = (int *)FUN_00422d7e(param_1);
        }
        else {
          piVar7 = param_1;
          local_18 = (int *)FUN_00422daf((int *)&local_8,param_1);
        }
      }
      if ((local_24 != 0) && (local_10 == 0)) {
LAB_00422d08:
        local_8 = local_8 + -1;
        FUN_00422d98((uint)local_18,param_1);
        goto LAB_00422d28;
      }
      if (uVar5 < 0x70) {
        if (uVar5 == 0x6f) {
LAB_00422a35:
          if (local_18 == (int *)0x2d) {
            local_1b = '\x01';
          }
          else if (local_18 != (int *)0x2b) goto LAB_00422a6a;
          local_10 = local_10 + -1;
          if ((local_10 == 0) && (local_24 != 0)) {
            local_13 = '\x01';
          }
          else {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_00422d7e(param_1);
          }
          goto LAB_00422a6a;
        }
        if (uVar5 != 99) {
          if (uVar5 == 100) goto LAB_00422a35;
          if (uVar5 < 0x65) {
LAB_004227ad:
            if ((int *)(uint)*param_2 != local_18) goto LAB_00422d08;
            local_19 = local_19 + -1;
            if (local_12 == '\0') {
              param_3 = local_48;
            }
            goto LAB_00422c89;
          }
          if (0x67 < uVar5) {
            if (uVar5 == 0x69) {
              uVar5 = 100;
              goto LAB_0042256b;
            }
            if (uVar5 != 0x6e) goto LAB_004227ad;
            puVar14 = local_8;
            if (local_12 != '\0') goto LAB_00422c89;
            goto LAB_00422c63;
          }
          pcVar11 = &local_1c8;
          if (local_18 == (int *)0x2d) {
            local_1c8 = '-';
            pcVar11 = local_1c7;
LAB_004225a1:
            local_10 = local_10 + -1;
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_00422d7e(param_1);
          }
          else if (local_18 == (int *)0x2b) goto LAB_004225a1;
          if ((local_24 == 0) || (0x15d < local_10)) {
            local_10 = 0x15d;
          }
          while( true ) {
            piVar17 = local_18;
            if ((int)DAT_00432104 < 2) {
              uVar5 = (byte)PTR_DAT_00431ef8[(int)local_18 * 2] & 4;
            }
            else {
              uVar5 = FUN_0041eea6(piVar7,(int)local_18,4);
            }
            if ((uVar5 == 0) ||
               (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16)) break;
            local_20 = local_20 + 1;
            *pcVar11 = (char)piVar17;
            pcVar11 = pcVar11 + 1;
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_00422d7e(param_1);
          }
          if ((DAT_00432108 == (char)piVar17) &&
             (iVar15 = local_10 + -1, bVar16 = local_10 != 0, local_10 = iVar15, bVar16)) {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            piVar17 = (int *)FUN_00422d7e(param_1);
            *pcVar11 = DAT_00432108;
            while( true ) {
              pcVar11 = pcVar11 + 1;
              local_18 = piVar17;
              if ((int)DAT_00432104 < 2) {
                uVar5 = (byte)PTR_DAT_00431ef8[(int)piVar17 * 2] & 4;
              }
              else {
                uVar5 = FUN_0041eea6(piVar7,(int)piVar17,4);
              }
              if ((uVar5 == 0) ||
                 (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16)) break;
              local_20 = local_20 + 1;
              *pcVar11 = (char)piVar17;
              local_8 = local_8 + 1;
              piVar7 = param_1;
              piVar17 = (int *)FUN_00422d7e(param_1);
            }
          }
          pcVar12 = pcVar11;
          if ((local_20 != 0) &&
             (((piVar17 == (int *)0x65 || (piVar17 == (int *)0x45)) &&
              (iVar15 = local_10 + -1, bVar16 = local_10 != 0, local_10 = iVar15, bVar16)))) {
            *pcVar11 = 'e';
            pcVar12 = pcVar11 + 1;
            local_8 = local_8 + 1;
            piVar7 = param_1;
            piVar17 = (int *)FUN_00422d7e(param_1);
            local_18 = piVar17;
            if (piVar17 == (int *)0x2d) {
              *pcVar12 = '-';
              pcVar12 = pcVar11 + 2;
LAB_004226c8:
              bVar16 = local_10 != 0;
              local_10 = local_10 + -1;
              if (bVar16) goto LAB_004226d7;
              local_10 = 0;
            }
            else if (piVar17 == (int *)0x2b) goto LAB_004226c8;
            while( true ) {
              if ((int)DAT_00432104 < 2) {
                uVar5 = (byte)PTR_DAT_00431ef8[(int)piVar17 * 2] & 4;
              }
              else {
                uVar5 = FUN_0041eea6(piVar7,(int)piVar17,4);
              }
              if ((uVar5 == 0) ||
                 (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16)) break;
              local_20 = local_20 + 1;
              *pcVar12 = (char)piVar17;
              pcVar12 = pcVar12 + 1;
LAB_004226d7:
              local_8 = local_8 + 1;
              piVar7 = param_1;
              piVar17 = (int *)FUN_00422d7e(param_1);
              local_18 = piVar17;
            }
          }
          local_8 = local_8 + -1;
          piVar7 = param_1;
          FUN_00422d98((uint)piVar17,param_1);
          if (local_20 != 0) {
            if (local_12 == '\0') {
              local_38 = local_38 + 1;
              *pcVar12 = '\0';
              (*(code *)PTR_FUN_0043275c)(local_11 + -1,local_30,&local_1c8);
              piVar7 = extraout_ECX_00;
            }
            goto LAB_00422c89;
          }
          goto LAB_00422d28;
        }
        if (local_24 == 0) {
          local_10 = local_10 + 1;
          local_24 = 1;
        }
        if ('\0' < local_9) {
          local_1a = '\x01';
        }
        pcVar11 = &DAT_00432580;
LAB_0042288e:
        local_1c = 0xff;
        pbVar9 = (byte *)pcVar11;
        pbVar10 = param_2;
LAB_00422892:
        param_2 = pbVar10;
        _memset(local_68,0,0x20);
        if ((local_40 == 0x7b) && (*pbVar9 == 0x5d)) {
          uVar5 = 0x5d;
          local_68[0xb] = 0x20;
          pbVar9 = pbVar9 + 1;
        }
        else {
          uVar5 = (uint)local_39;
        }
        while (pWVar13 = local_30, bVar1 = *pbVar9, bVar1 != 0x5d) {
          if (((bVar1 == 0x2d) && (bVar8 = (byte)uVar5, bVar8 != 0)) &&
             (bVar4 = pbVar9[1], bVar4 != 0x5d)) {
            if (bVar4 <= bVar8) {
              uVar5 = (uint)bVar4;
              bVar4 = bVar8;
            }
            if ((byte)uVar5 <= bVar4) {
              iVar15 = (bVar4 - uVar5) + 1;
              do {
                local_68[uVar5 >> 3] = local_68[uVar5 >> 3] | '\x01' << ((byte)uVar5 & 7);
                uVar5 = uVar5 + 1;
                iVar15 = iVar15 + -1;
              } while (iVar15 != 0);
            }
            uVar5 = 0;
            pbVar9 = pbVar9 + 2;
          }
          else {
            uVar5 = (uint)bVar1;
            local_68[bVar1 >> 3] = local_68[bVar1 >> 3] | '\x01' << (bVar1 & 7);
            pbVar9 = pbVar9 + 1;
          }
        }
        if (*pbVar9 == 0) goto LAB_00422d28;
        if (local_40 == 0x7b) {
          param_2 = pbVar9;
        }
        local_8 = local_8 + -1;
        local_34 = local_30;
        piVar7 = param_1;
        FUN_00422d98((uint)local_18,param_1);
        while( true ) {
          if ((local_24 != 0) &&
             (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16))
          goto LAB_004229f7;
          local_8 = local_8 + 1;
          local_18 = (int *)FUN_00422d7e(param_1);
          if (local_18 == (int *)0xffffffff) break;
          bVar1 = (byte)local_18;
          piVar7 = (int *)(int)(char)(local_68[(int)local_18 >> 3] ^ local_1c);
          if (((uint)piVar7 & 1 << (bVar1 & 7)) == 0) break;
          if (local_12 == '\0') {
            if (local_1a == '\0') {
              *(byte *)pWVar13 = bVar1;
              pWVar13 = (WCHAR *)((int)pWVar13 + 1);
              local_30 = pWVar13;
            }
            else {
              local_3c = bVar1;
              if ((PTR_DAT_00431ef8[((uint)local_18 & 0xff) * 2 + 1] & 0x80) != 0) {
                local_8 = local_8 + 1;
                uVar5 = FUN_00422d7e(param_1);
                local_3b = (undefined)uVar5;
              }
              FUN_004258a8(&local_42,&local_3c,DAT_00432104);
              *pWVar13 = local_42;
              pWVar13 = pWVar13 + 1;
              piVar7 = extraout_ECX_01;
              local_30 = pWVar13;
            }
          }
          else {
            local_34 = (WCHAR *)((int)local_34 + 1);
          }
        }
        local_8 = local_8 + -1;
        piVar7 = param_1;
        FUN_00422d98((uint)local_18,param_1);
LAB_004229f7:
        if (local_34 == pWVar13) goto LAB_00422d28;
        if ((local_12 == '\0') && (local_38 = local_38 + 1, local_40 != 99)) {
          if (local_1a == '\0') {
            *(byte *)local_30 = 0;
          }
          else {
            *local_30 = L'\0';
          }
        }
      }
      else {
        if (uVar5 == 0x70) {
          local_11 = '\x01';
          goto LAB_00422a35;
        }
        if (uVar5 == 0x73) {
          if ('\0' < local_9) {
            local_1a = '\x01';
          }
          pcVar11 = s_____00432578;
          goto LAB_0042288e;
        }
        if (uVar5 == 0x75) goto LAB_00422a35;
        if (uVar5 != 0x78) {
          if (uVar5 != 0x7b) goto LAB_004227ad;
          if ('\0' < local_9) {
            local_1a = '\x01';
          }
          pbVar9 = param_2 + 1;
          pbVar10 = pbVar9;
          if (*pbVar9 == 0x5e) {
            pcVar11 = (char *)(param_2 + 2);
            param_2 = pbVar9;
            goto LAB_0042288e;
          }
          goto LAB_00422892;
        }
LAB_0042256b:
        if (local_18 == (int *)0x2d) {
          local_1b = '\x01';
LAB_004227fa:
          local_10 = local_10 + -1;
          if ((local_10 == 0) && (local_24 != 0)) {
            local_13 = '\x01';
          }
          else {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_00422d7e(param_1);
          }
        }
        else if (local_18 == (int *)0x2b) goto LAB_004227fa;
        if (local_18 == (int *)0x30) {
          local_8 = local_8 + 1;
          piVar7 = param_1;
          local_18 = (int *)FUN_00422d7e(param_1);
          if (((char)local_18 == 'x') || ((char)local_18 == 'X')) {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_00422d7e(param_1);
            uVar5 = 0x78;
          }
          else {
            local_20 = 1;
            if (uVar5 == 0x78) {
              local_8 = local_8 + -1;
              piVar7 = param_1;
              FUN_00422d98((uint)local_18,param_1);
              local_18 = (int *)0x30;
            }
            else {
              uVar5 = 0x6f;
            }
          }
        }
LAB_00422a6a:
        if (local_34 == (WCHAR *)0x0) {
          if (local_13 == '\0') {
            while ((piVar17 = local_18, uVar5 != 0x78 && (uVar5 != 0x70))) {
              if ((int)DAT_00432104 < 2) {
                uVar6 = (byte)PTR_DAT_00431ef8[(int)local_18 * 2] & 4;
              }
              else {
                piVar3 = (int *)0x4;
                uVar6 = FUN_0041eea6(piVar7,(int)local_18,4);
                piVar7 = piVar3;
              }
              if (uVar6 == 0) goto LAB_00422c31;
              if (uVar5 == 0x6f) {
                if (0x37 < (int)piVar17) goto LAB_00422c31;
                iVar15 = (int)puVar14 << 3;
              }
              else {
                iVar15 = (int)puVar14 * 10;
              }
LAB_00422c09:
              local_20 = local_20 + 1;
              puVar14 = (undefined *)(iVar15 + -0x30 + (int)piVar17);
              if ((local_24 != 0) && (local_10 = local_10 + -1, local_10 == 0)) goto LAB_00422c3f;
              local_8 = local_8 + 1;
              piVar7 = param_1;
              local_18 = (int *)FUN_00422d7e(param_1);
            }
            if ((int)DAT_00432104 < 2) {
              uVar6 = (byte)PTR_DAT_00431ef8[(int)local_18 * 2] & 0x80;
            }
            else {
              piVar3 = (int *)0x80;
              uVar6 = FUN_0041eea6(piVar7,(int)local_18,0x80);
              piVar7 = piVar3;
            }
            if (uVar6 != 0) {
              iVar15 = (int)puVar14 << 4;
              piVar3 = piVar17;
              piVar17 = (int *)FUN_00422d47(piVar7,(uint)piVar17);
              piVar7 = piVar3;
              local_18 = piVar17;
              goto LAB_00422c09;
            }
LAB_00422c31:
            local_8 = local_8 + -1;
            piVar7 = param_1;
            FUN_00422d98((uint)piVar17,param_1);
          }
LAB_00422c3f:
          if (local_1b != '\0') {
            puVar14 = (undefined *)-(int)puVar14;
          }
        }
        else {
          if (local_13 == '\0') {
            while (piVar17 = local_18, uVar5 != 0x78) {
              if ((int)DAT_00432104 < 2) {
                uVar6 = (byte)PTR_DAT_00431ef8[(int)local_18 * 2] & 4;
              }
              else {
                uVar6 = FUN_0041eea6(piVar7,(int)local_18,4);
              }
              if (uVar6 == 0) goto LAB_00422b53;
              if (uVar5 == 0x6f) {
                if (0x37 < (int)piVar17) goto LAB_00422b53;
                local_2c = __allshl(3,(int)local_2c._4_4_);
                piVar7 = extraout_ECX_02;
              }
              else {
                local_2c = __allmul((uint)local_2c,(int)local_2c._4_4_,10,0);
                piVar7 = extraout_ECX_03;
              }
LAB_00422b25:
              local_20 = local_20 + 1;
              piVar17 = piVar17 + -0xc;
              local_2c = CONCAT44((int)local_2c._4_4_ + ((int)piVar17 >> 0x1f) +
                                  (uint)CARRY4((uint)local_2c,(uint)piVar17),
                                  (undefined *)((uint)local_2c + (int)piVar17));
              if ((local_24 != 0) && (local_10 = local_10 + -1, local_10 == 0)) goto LAB_00422b61;
              local_8 = local_8 + 1;
              piVar7 = param_1;
              local_18 = (int *)FUN_00422d7e(param_1);
            }
            if ((int)DAT_00432104 < 2) {
              uVar6 = (byte)PTR_DAT_00431ef8[(int)local_18 * 2] & 0x80;
            }
            else {
              uVar6 = FUN_0041eea6(piVar7,(int)local_18,0x80);
            }
            if (uVar6 != 0) {
              local_2c = __allshl(4,(int)local_2c._4_4_);
              piVar7 = piVar17;
              piVar17 = (int *)FUN_00422d47(this_01,(uint)piVar17);
              local_18 = piVar17;
              goto LAB_00422b25;
            }
LAB_00422b53:
            local_8 = local_8 + -1;
            piVar7 = param_1;
            FUN_00422d98((uint)piVar17,param_1);
          }
LAB_00422b61:
          if (local_1b != '\0') {
            piVar7 = (int *)-((int)local_2c._4_4_ + (uint)((uint)local_2c != 0));
            local_2c = CONCAT44(piVar7,-(uint)local_2c);
          }
        }
        if (uVar5 == 0x46) {
          local_20 = 0;
        }
        if (local_20 == 0) goto LAB_00422d28;
        if (local_12 == '\0') {
          local_38 = local_38 + 1;
LAB_00422c63:
          if (local_34 == (WCHAR *)0x0) {
            if (local_11 == '\0') {
              *local_30 = (WCHAR)puVar14;
            }
            else {
              *(undefined **)local_30 = puVar14;
            }
          }
          else {
            *(uint *)local_30 = (uint)local_2c;
            *(int **)(local_30 + 2) = local_2c._4_4_;
            piVar7 = local_2c._4_4_;
          }
        }
      }
LAB_00422c89:
      local_19 = local_19 + '\x01';
      param_2 = param_2 + 1;
      this = piVar7;
    }
    else {
      local_8 = local_8 + 1;
      piVar7 = (int *)FUN_00422d7e(param_1);
      param_2 = pbVar9 + 1;
      local_18 = piVar7;
      if ((int *)(uint)*pbVar9 != piVar7) goto LAB_00422d08;
      this = PTR_DAT_00431ef8;
      if ((PTR_DAT_00431ef8[((uint)piVar7 & 0xff) * 2 + 1] & 0x80) != 0) {
        local_8 = local_8 + 1;
        piVar17 = (int *)FUN_00422d7e(param_1);
        this = (void *)(uint)*param_2;
        param_2 = pbVar9 + 2;
        if ((int *)this != piVar17) {
          local_8 = local_8 + -1;
          FUN_00422d98((uint)piVar17,param_1);
          local_8 = local_8 + -1;
          FUN_00422d98((uint)piVar7,param_1);
          goto LAB_00422d28;
        }
        local_8 = local_8 + -1;
      }
    }
    if ((local_18 == (int *)0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e))))
    goto LAB_00422d2e;
    bVar1 = *param_2;
    pbVar9 = param_2;
    piVar7 = (int *)PTR_DAT_00431ef8;
  } while( true );
}



uint __thiscall FUN_00422d47(void *this,uint param_1)

{
  uint uVar1;
  
  if (DAT_00432104 < 2) {
    uVar1 = (byte)PTR_DAT_00431ef8[param_1 * 2] & 4;
  }
  else {
    uVar1 = FUN_0041eea6(this,param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}



uint __cdecl FUN_00422d7e(undefined4 *param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    bVar2 = *(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
    return (uint)bVar2;
  }
  uVar3 = FUN_004220fd(param_1);
  return uVar3;
}



void __cdecl FUN_00422d98(uint param_1,int *param_2)

{
  if (param_1 != 0xffffffff) {
    FUN_0041f091(param_1,param_2);
  }
  return;
}



uint __cdecl FUN_00422daf(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  void *this;
  
  do {
    *param_1 = *param_1 + 1;
    uVar1 = FUN_00422d7e(param_2);
    uVar2 = FUN_00420347(this,uVar1);
  } while (uVar2 != 0);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_00422dd3(undefined4 *param_1)

{
  uint *puVar1;
  
  _DAT_00434e5c = _DAT_00434e5c + 1;
  puVar1 = FUN_0041b590(0x1000);
  param_1[2] = puVar1;
  if (puVar1 == (uint *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}



DWORD __cdecl FUN_00422e17(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  
  if (DAT_00436920 <= param_1) {
LAB_00422e98:
    pDVar3 = FUN_00420791();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_00422e98;
  FUN_00424fee(param_1);
  if ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_00424fac(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    if (DVar2 == 0) goto LAB_00422e8d;
    pDVar3 = FUN_0042079a();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_00420791();
  *pDVar3 = 9;
  DVar2 = 0xffffffff;
LAB_00422e8d:
  FUN_0042504d(param_1);
  return DVar2;
}



int __cdecl FUN_00422eaa(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_00436920) &&
     ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00424fee(param_1);
    iVar1 = FUN_00422f0f(param_1,param_2,param_3);
    FUN_0042504d(param_1);
    return iVar1;
  }
  pDVar2 = FUN_00420791();
  *pDVar2 = 9;
  pDVar2 = FUN_0042079a();
  *pDVar2 = 0;
  return -1;
}



int __cdecl FUN_00422f0f(DWORD param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  DWORD *pDVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  if (param_3 == 0) {
LAB_00422f28:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_00436820 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_004253ba(param_1,0,2);
    }
    if ((*(byte *)((undefined4 *)(*piVar1 + iVar4) + 1) & 0x80) == 0) {
      BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        param_1 = GetLastError();
      }
      else {
        local_c = local_10;
        param_1 = 0;
      }
LAB_00422ff7:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_00423069;
      if (param_1 == 5) {
        pDVar7 = FUN_00420791();
        *pDVar7 = 9;
        pDVar7 = FUN_0042079a();
        *pDVar7 = 5;
      }
      else {
        FUN_0042071e(param_1);
      }
    }
    else {
      local_8 = param_2;
      param_1 = 0;
      if (param_3 != 0) {
        do {
          pcVar5 = local_418;
          do {
            if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
            pcVar2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = pcVar2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *pcVar5 = '\r';
              pcVar5 = pcVar5 + 1;
            }
            *pcVar5 = cVar3;
            pcVar5 = pcVar5 + 1;
          } while ((int)pcVar5 - (int)local_418 < 0x400);
          BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),local_418,(int)pcVar5 - (int)local_418,
                            &local_10,(LPOVERLAPPED)0x0);
          if (BVar6 == 0) {
            param_1 = GetLastError();
            goto LAB_00422ff7;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_00422ff7;
        } while( true );
      }
LAB_00423069:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_00422f28;
      pDVar7 = FUN_00420791();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_0042079a();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}



// Library Function - Single Match
//  _strlen
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

size_t __cdecl _strlen(char *_Str)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  uVar2 = (uint)_Str & 3;
  puVar3 = (uint *)_Str;
  while (uVar2 != 0) {
    cVar1 = *(char *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if (cVar1 == '\0') goto LAB_004230f3;
    uVar2 = (uint)puVar3 & 3;
  }
  do {
    do {
      puVar4 = puVar3;
      puVar3 = puVar4 + 1;
    } while (((*puVar4 ^ 0xffffffff ^ *puVar4 + 0x7efefeff) & 0x81010100) == 0);
    uVar2 = *puVar4;
    if ((char)uVar2 == '\0') {
      return (int)puVar4 - (int)_Str;
    }
    if ((char)(uVar2 >> 8) == '\0') {
      return (size_t)((int)puVar4 + (1 - (int)_Str));
    }
    if ((uVar2 & 0xff0000) == 0) {
      return (size_t)((int)puVar4 + (2 - (int)_Str));
    }
  } while ((uVar2 & 0xff000000) != 0);
LAB_004230f3:
  return (size_t)((int)puVar3 + (-1 - (int)_Str));
}



int __cdecl
FUN_0042311b(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined unaff_DI;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042b600;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00435068 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_00435068 = 2;
    }
    else {
      DAT_00435068 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_00425d77(param_3,param_4);
  }
  if (DAT_00435068 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_00435068 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_00435060;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_004203d0(unaff_DI);
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_004203d0(unaff_DI);
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5
                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (param_6 == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (param_6 < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



// Library Function - Single Match
//  __allmul
// 
// Library: Visual Studio

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 __cdecl FUN_00423374(undefined4 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  uint *puVar4;
  
  bVar2 = FUN_0042542d(param_1[4]);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  if (param_1 == (undefined4 *)&DAT_00431c98) {
    iVar3 = 0;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_00431cb8) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_00434e5c = _DAT_00434e5c + 1;
  if ((*(ushort *)(param_1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_0043506c)[iVar3] == 0) {
    puVar4 = FUN_0041b590(0x1000);
    (&DAT_0043506c)[iVar3] = puVar4;
    if (puVar4 == (uint *)0x0) {
      param_1[2] = param_1 + 5;
      *param_1 = param_1 + 5;
      param_1[6] = 2;
      param_1[1] = 2;
      goto LAB_004233f0;
    }
  }
  uVar1 = (&DAT_0043506c)[iVar3];
  param_1[6] = 0x1000;
  param_1[2] = uVar1;
  *param_1 = uVar1;
  param_1[1] = 0x1000;
LAB_004233f0:
  *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x1102;
  return 1;
}



void __cdecl FUN_00423401(int param_1,int *param_2)

{
  if ((param_1 != 0) && ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0)) {
    FUN_0041f15c(param_2);
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
  }
  return;
}



uint __cdecl FUN_0042342b(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar1 = param_4;
  piVar6 = (int *)(param_2 * param_3);
  if (piVar6 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar5 = piVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar7 = (int *)piVar1[1], piVar7 == (int *)0x0)) {
        if (param_4 <= piVar5) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_0041f15c(piVar1), iVar2 != 0)) {
LAB_0042352c:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          piVar7 = piVar5;
          if (param_4 != (int *)0x0) {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_00422eaa(piVar1[4],param_1,(uint)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_0042352c;
          }
          goto LAB_004234e3;
        }
        uVar4 = FUN_004217db((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_0042352c;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar5 = (int *)((int)piVar5 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        piVar3 = piVar5;
        if (piVar7 <= piVar5) {
          piVar3 = piVar7;
        }
        FUN_00423630((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_004234e3:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}



uint * __cdecl FUN_00423540(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)param_2 & 3;
  puVar4 = param_1;
  while (uVar3 != 0) {
    bVar1 = *(byte *)param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_00423628;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    uVar3 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00423628:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}



uint * __cdecl FUN_00423550(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = (uint)param_1 & 3;
  puVar3 = param_1;
  while (uVar4 != 0) {
    bVar1 = *(byte *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if (bVar1 == 0) goto LAB_0042359f;
    uVar4 = (uint)puVar3 & 3;
  }
  do {
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto LAB_004235b1;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto LAB_004235b1;
    }
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto LAB_004235b1;
    }
  } while ((uVar4 & 0xff000000) != 0);
LAB_0042359f:
  puVar5 = (uint *)((int)puVar3 + -1);
LAB_004235b1:
  uVar4 = (uint)param_2 & 3;
  while (uVar4 != 0) {
    bVar1 = *(byte *)param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_00423628;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
    uVar4 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar4 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_00423628:
        *(byte *)puVar5 = (byte)uVar4;
        return param_1;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar5 = (short)uVar4;
        return param_1;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar5 = (short)uVar4;
        *(byte *)((int)puVar5 + 2) = 0;
        return param_1;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar5 = uVar4;
        return param_1;
      }
    }
    *puVar5 = uVar4;
    puVar5 = puVar5 + 1;
  } while( true );
}



undefined4 * __cdecl FUN_00423630(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_004237e7_caseD_2;
        case 3:
          goto switchD_004237e7_caseD_3;
        }
        goto switchD_004237e7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_004237e7_caseD_0;
      case 1:
        goto switchD_004237e7_caseD_1;
      case 2:
        goto switchD_004237e7_caseD_2;
      case 3:
        goto switchD_004237e7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004237e7_caseD_2;
            case 3:
              goto switchD_004237e7_caseD_3;
            }
            goto switchD_004237e7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004237e7_caseD_2;
            case 3:
              goto switchD_004237e7_caseD_3;
            }
            goto switchD_004237e7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
          *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined *)((int)puVar4 + 1) = *(undefined *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004237e7_caseD_2;
            case 3:
              goto switchD_004237e7_caseD_3;
            }
            goto switchD_004237e7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_004237e7_caseD_1:
      *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_004237e7_caseD_2:
      *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
      *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_004237e7_caseD_3:
      *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
      *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
      *(undefined *)((int)puVar4 + 1) = *(undefined *)((int)puVar3 + 1);
      return param_1;
    }
switchD_004237e7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00423665_caseD_2;
      case 3:
        goto switchD_00423665_caseD_3;
      }
      goto switchD_00423665_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00423665_caseD_0;
    case 1:
      goto switchD_00423665_caseD_1;
    case 2:
      goto switchD_00423665_caseD_2;
    case 3:
      goto switchD_00423665_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined *)param_1 = *(undefined *)param_2;
        *(undefined *)((int)param_1 + 1) = *(undefined *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined *)((int)param_1 + 2) = *(undefined *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00423665_caseD_2;
          case 3:
            goto switchD_00423665_caseD_3;
          }
          goto switchD_00423665_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined *)param_1 = *(undefined *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined *)((int)param_1 + 1) = *(undefined *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00423665_caseD_2;
          case 3:
            goto switchD_00423665_caseD_3;
          }
          goto switchD_00423665_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined *)param_1 = *(undefined *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00423665_caseD_2;
          case 3:
            goto switchD_00423665_caseD_3;
          }
          goto switchD_00423665_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00423665_caseD_1:
    *(undefined *)puVar3 = *(undefined *)param_2;
    return param_1;
  case 2:
switchD_00423665_caseD_2:
    *(undefined *)puVar3 = *(undefined *)param_2;
    *(undefined *)((int)puVar3 + 1) = *(undefined *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00423665_caseD_3:
    *(undefined *)puVar3 = *(undefined *)param_2;
    *(undefined *)((int)puVar3 + 1) = *(undefined *)((int)param_2 + 1);
    *(undefined *)((int)puVar3 + 2) = *(undefined *)((int)param_2 + 2);
    return param_1;
  }
switchD_00423665_caseD_0:
  return param_1;
}



void FUN_00423965(void)

{
  if (DAT_00435130 == 0) {
    FUN_0042152d(0xb);
    if (DAT_00435130 == 0) {
      FUN_00423993();
      DAT_00435130 = DAT_00435130 + 1;
    }
    FUN_0042158e(0xb);
  }
  return;
}



void FUN_00423993(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_8;
  
  FUN_0042152d(0xc);
  DAT_00432748 = 0xffffffff;
  DAT_00432738 = 0xffffffff;
  DAT_00435078 = 0;
  _Str1 = (uint *)FUN_004201ba("TZ");
  if (_Str1 == (uint *)0x0) {
    FUN_0042158e(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00435080);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_004326a0 = (void *)(DAT_00435080 * 0x3c);
    DAT_00435078 = 1;
    if (DAT_004350c6 != 0) {
      DAT_004326a0 = (void *)((int)DAT_004326a0 + DAT_004350d4 * 0x3c);
    }
    if ((DAT_0043511a == 0) || (DAT_00435128 == 0)) {
      DAT_004326a4 = 0;
      DAT_004326a8 = 0;
    }
    else {
      DAT_004326a4 = 1;
      DAT_004326a8 = (DAT_00435128 - DAT_004350d4) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_00435060,0x220,(LPCWSTR)&DAT_00435084,-1,PTR_DAT_0043272c,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_0043272c = 0;
    }
    else {
      PTR_DAT_0043272c[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_00435060,0x220,(LPCWSTR)&DAT_004350d8,-1,PTR_DAT_00432730,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_00432730[0x3f] = 0;
      return;
    }
LAB_00423c04:
    *PTR_DAT_00432730 = 0;
  }
  else {
    if ((*(char *)_Str1 != '\0') &&
       ((DAT_0043512c == (uint *)0x0 ||
        (iVar4 = _strcmp((char *)_Str1,(char *)DAT_0043512c), iVar4 != 0)))) {
      FUN_0041b8c0((int)DAT_0043512c);
      sVar5 = _strlen((char *)_Str1);
      DAT_0043512c = FUN_0041b590(sVar5 + 1);
      if (DAT_0043512c != (uint *)0x0) {
        FUN_00423540(DAT_0043512c,_Str1);
        FUN_0042158e(0xc);
        _strncpy(PTR_DAT_0043272c,(char *)_Str1,3);
        _Source = (uint *)((int)_Str1 + 3);
        PTR_DAT_0043272c[3] = 0;
        cVar2 = *(char *)_Source;
        if (cVar2 == '-') {
          _Source = _Str1 + 1;
        }
        iVar4 = FUN_0041f3d4(this,(byte *)_Source);
        DAT_004326a0 = (void *)(iVar4 * 0xe10);
        for (; (cVar1 = *(char *)_Source, cVar1 == '+' || (('/' < cVar1 && (cVar1 < ':'))));
            _Source = (uint *)((int)_Source + 1)) {
        }
        if (*(char *)_Source == ':') {
          _Source = (uint *)((int)_Source + 1);
          iVar4 = FUN_0041f3d4(DAT_004326a0,(byte *)_Source);
          DAT_004326a0 = (void *)((int)DAT_004326a0 + iVar4 * 0x3c);
          for (; ('/' < *(char *)_Source && (*(char *)_Source < ':'));
              _Source = (uint *)((int)_Source + 1)) {
          }
          if (*(char *)_Source == ':') {
            _Source = (uint *)((int)_Source + 1);
            iVar4 = FUN_0041f3d4(DAT_004326a0,(byte *)_Source);
            DAT_004326a0 = (void *)((int)DAT_004326a0 + iVar4);
            for (; ('/' < *(char *)_Source && (*(char *)_Source < ':'));
                _Source = (uint *)((int)_Source + 1)) {
            }
          }
        }
        if (cVar2 == '-') {
          DAT_004326a0 = (void *)-(int)DAT_004326a0;
        }
        DAT_004326a4 = (int)*(char *)_Source;
        if (DAT_004326a4 != 0) {
          _strncpy(PTR_DAT_00432730,(char *)_Source,3);
          PTR_DAT_00432730[3] = 0;
          return;
        }
        goto LAB_00423c04;
      }
    }
    FUN_0042158e(0xc);
  }
  return;
}



bool __cdecl FUN_00423c1a(int *param_1)

{
  bool bVar1;
  
  FUN_0042152d(0xb);
  bVar1 = FUN_00423c3b(param_1);
  FUN_0042158e(0xb);
  return bVar1;
}



bool __cdecl FUN_00423c3b(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (DAT_004326a4 != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_00432738) || (uVar5 != DAT_00432748)) {
      if (DAT_00435078 == 0) {
        FUN_00423de7(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_00423de7(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_00435118 != 0) {
          uVar6 = (uint)DAT_0043511e;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_0043511c;
          uVar6 = 0;
          uVar4 = (uint)DAT_0043511e;
        }
        FUN_00423de7(1,(uint)(DAT_00435118 == 0),uVar5,(uint)DAT_0043511a,uVar4,uVar3,uVar6,
                     (uint)DAT_00435120,(uint)DAT_00435122,(uint)DAT_00435124,(uint)DAT_00435126);
        if (DAT_004350c4 != 0) {
          uVar6 = (uint)DAT_004350ca;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_004350c8;
          uVar6 = 0;
          uVar4 = (uint)DAT_004350ca;
          uVar5 = param_1[5];
        }
        FUN_00423de7(0,(uint)(DAT_004350c4 == 0),uVar5,(uint)DAT_004350c6,uVar4,uVar3,uVar6,
                     (uint)DAT_004350cc,(uint)DAT_004350ce,(uint)DAT_004350d0,(uint)DAT_004350d2);
      }
    }
    iVar1 = param_1[7];
    if (DAT_0043273c < DAT_0043274c) {
      if ((DAT_0043273c <= iVar1) && (iVar1 <= DAT_0043274c)) {
        if ((DAT_0043273c < iVar1) && (iVar1 < DAT_0043274c)) {
          return true;
        }
LAB_00423db3:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_0043273c) {
          return DAT_00432740 <= iVar2;
        }
        return iVar2 < DAT_00432750;
      }
    }
    else {
      if (iVar1 < DAT_0043274c) {
        return true;
      }
      if (DAT_0043273c < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_0043274c) || (DAT_0043273c <= iVar1)) goto LAB_00423db3;
    }
  }
  return false;
}



void __cdecl
FUN_00423de7(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_0043286c + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_004328a0 + param_4 * 4);
    }
    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;
    if (iVar2 < param_6) {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_00432870 + param_4 * 4);
      }
      else {
        iVar2 = (&DAT_004328a4)[param_4];
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_0043286c + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_004328a0 + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_00432738 = param_3;
    DAT_00432740 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;
    DAT_0043273c = iVar1;
  }
  else {
    DAT_00432750 = ((param_8 * 0x3c + param_9) * 0x3c + DAT_004326a8 + param_10) * 1000 + param_11;
    if (DAT_00432750 < 0) {
      DAT_00432750 = DAT_00432750 + 86400000;
      DAT_0043274c = iVar1 + -1;
    }
    else {
      DAT_0043274c = iVar1;
      if (86399999 < DAT_00432750) {
        DAT_00432750 = DAT_00432750 + -86400000;
        DAT_0043274c = iVar1 + 1;
      }
    }
    DAT_00432748 = param_3;
  }
  return;
}



int * __cdecl FUN_00423f27(int *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  iVar4 = *param_1;
  bVar1 = false;
  pDVar2 = FUN_00420f76();
  if (iVar4 < 0) {
    return (int *)0x0;
  }
  if (pDVar2[0x10] == 0) {
    puVar3 = FUN_0041b590(0x24);
    pDVar2[0x10] = (DWORD)puVar3;
    piVar5 = (int *)&DAT_00435138;
    if (puVar3 == (uint *)0x0) goto LAB_00423f61;
  }
  piVar5 = (int *)pDVar2[0x10];
LAB_00423f61:
  iVar8 = iVar4 % 0x7861f80;
  iVar4 = (iVar4 / 0x7861f80) * 4;
  iVar6 = iVar4 + 0x46;
  iVar9 = iVar8;
  if (0x1e1337f < iVar8) {
    iVar9 = iVar8 + -0x1e13380;
    iVar6 = iVar4 + 0x47;
    if (0x1e1337f < iVar9) {
      iVar9 = iVar8 + -0x3c26700;
      iVar6 = iVar4 + 0x48;
      if (iVar9 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar6 = iVar4 + 0x49;
        iVar9 = iVar8 + -0x5a4ec00;
      }
    }
  }
  piVar5[5] = iVar6;
  piVar10 = (int *)&DAT_00432870;
  piVar5[7] = iVar9 / 0x15180;
  if (!bVar1) {
    piVar10 = &DAT_004328a4;
  }
  iVar4 = 1;
  piVar7 = piVar10;
  while (piVar7 = piVar7 + 1, *piVar7 < piVar5[7]) {
    iVar4 = iVar4 + 1;
  }
  piVar5[4] = iVar4 + -1;
  piVar5[3] = piVar5[7] - piVar10[iVar4 + -1];
  piVar5[6] = (*param_1 / 0x15180 + 4) % 7;
  piVar5[2] = (iVar9 % 0x15180) / 0xe10;
  iVar4 = (iVar9 % 0x15180) % 0xe10;
  piVar5[1] = iVar4 / 0x3c;
  piVar5[8] = 0;
  *piVar5 = iVar4 % 0x3c;
  return piVar5;
}



int __cdecl
FUN_00424031(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    iVar2 = -1;
  }
  else {
    iVar4 = *(int *)(&DAT_004328a0 + param_2 * 4) + param_3;
    if (((uVar3 & 3) == 0) && (2 < param_2)) {
      iVar4 = iVar4 + 1;
    }
    FUN_00423965();
    local_20 = param_4;
    local_18 = param_2 + -1;
    iVar2 = ((param_4 + (uVar3 * 0x16d + iVar4 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c + param_5)
            * 0x3c + DAT_004326a0 + 0x7c558180 + param_6;
    if ((param_7 == 1) ||
       (((param_7 == -1 && (DAT_004326a4 != 0)) &&
        (local_14 = uVar3, local_c = iVar4, bVar1 = FUN_00423c1a(local_28),
        CONCAT31(extraout_var,bVar1) != 0)))) {
      iVar2 = iVar2 + DAT_004326a8;
    }
  }
  return iVar2;
}



undefined4 __cdecl FUN_004240f3(DWORD *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  DWORD local_10;
  DWORD local_c;
  
  bVar1 = false;
  if (param_1 == (DWORD *)0x2) {
    puVar7 = &DAT_0043515c;
    pcVar6 = DAT_0043515c;
LAB_00424179:
    bVar1 = true;
    FUN_0042152d(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_00435168;
        pcVar6 = DAT_00435168;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_00435160;
        pcVar6 = DAT_00435160;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_00435164;
        pcVar6 = DAT_00435164;
      }
      goto LAB_00424179;
    }
    pDVar2 = FUN_00420f76();
    uVar3 = FUN_00424275((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_0042158e(1);
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_0042158e(1);
    }
                    // WARNING: Subroutine does not return
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = 0;
    if (param_1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_004241ed;
    }
  }
  else {
LAB_004241ed:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_004323d0 < DAT_004323d4 + DAT_004323d0) {
        iVar4 = DAT_004323d0 * 0xc;
        iVar5 = DAT_004323d0;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_004323d4 + DAT_004323d0);
      }
      goto LAB_0042422b;
    }
  }
  *puVar7 = 0;
LAB_0042422b:
  if (bVar1) {
    FUN_0042158e(1);
  }
  if (param_1 == (DWORD *)0x8) {
    (*pcVar6)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar6)(param_1);
    if ((param_1 != (DWORD *)0xb) && (param_1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (param_1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}



uint __cdecl FUN_00424275(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_004323dc * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_004323dc * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}



void FUN_004242b2(undefined4 param_1)

{
  return;
}



// Library Function - Single Match
//  __mbsnbicoll
// 
// Library: Visual Studio 2003 Release

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_00425afa(DAT_00436804,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_004365d4);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}



undefined4 FUN_00424356(void)

{
  LPCWSTR lpWideCharStr;
  int iVar1;
  uint *lpMultiByteStr;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWSTR)*DAT_00434e88;
  puVar2 = DAT_00434e88;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    iVar1 = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((iVar1 == 0) || (lpMultiByteStr = FUN_0041b590(iVar1), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,iVar1,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_00425da2(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}



void __fastcall FUN_004243c4(void *param_1)

{
  FUN_0042601d(param_1,0x10000,0x30000);
  return;
}



// WARNING: Removing unreachable block (ram,0x0042440b)

undefined4 FUN_004243d6(void)

{
  return 0;
}



void FUN_00424414(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  FUN_004243d6();
  return;
}



void __cdecl FUN_0042443d(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this;
  uint uVar3;
  undefined *puVar4;
  
  this = (undefined *)(int)*param_1;
  uVar3 = FUN_0042614e((uint)this);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_00432104 < 2) {
        uVar3 = (byte)PTR_DAT_00431ef8[*param_1 * 2] & 4;
        this = PTR_DAT_00431ef8;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_0041eea6(this,(int)*param_1,4);
        this = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_00432108;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}



// Library Function - Single Match
//  __fassign
// 
// Library: Visual Studio 2003 Release

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;
  
  if (flag != 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    FUN_0042661a(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_00426647(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}



undefined * __cdecl FUN_0042453b(undefined8 *param_1,undefined *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];
  
  FUN_004266eb((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),local_14,local_2c);
  FUN_00426674(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,(int)local_14
              );
  FUN_0042459c(param_2,param_3,param_4,local_14,'\0');
  return param_2;
}



undefined * __cdecl
FUN_0042459c(undefined *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_5 != '\0') {
    FUN_0042483e(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
  }
  puVar1 = param_1;
  if (*param_4 == 0x2d) {
    *param_1 = 0x2d;
    puVar1 = param_1 + 1;
  }
  puVar2 = puVar1;
  if (0 < param_2) {
    puVar2 = puVar1 + 1;
    *puVar1 = puVar1[1];
    *puVar2 = DAT_00432108;
  }
  puVar3 = FUN_00423540((uint *)(puVar2 + param_2 + (uint)(param_5 == '\0')),(uint *)"e+000");
  if (param_3 != 0) {
    *(undefined *)puVar3 = 0x45;
  }
  if (*(char *)param_4[3] != '0') {
    iVar4 = param_4[1] + -1;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      *(undefined *)((int)puVar3 + 1) = 0x2d;
    }
    if (99 < iVar4) {
      *(char *)((int)puVar3 + 2) = *(char *)((int)puVar3 + 2) + (char)(iVar4 / 100);
      iVar4 = iVar4 % 100;
    }
    if (9 < iVar4) {
      *(char *)((int)puVar3 + 3) = *(char *)((int)puVar3 + 3) + (char)(iVar4 / 10);
      iVar4 = iVar4 % 10;
    }
    *(char *)(puVar3 + 1) = *(char *)(puVar3 + 1) + (char)iVar4;
  }
  return param_1;
}



char * __cdecl FUN_0042465e(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_004266eb((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  FUN_00426674(param_2 + (local_14 == 0x2d),local_10 + param_3,(int)&local_14);
  FUN_004246b3(param_2,param_3,&local_14,'\0');
  return param_2;
}



char * __cdecl FUN_004246b3(char *param_1,size_t param_2,int *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = param_3[1];
  if ((param_4 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *param_3;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = '0';
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = '\0';
  }
  pcVar3 = param_1;
  if (*param_3 == 0x2d) {
    *param_1 = '-';
    pcVar3 = param_1 + 1;
  }
  if (param_3[1] < 1) {
    FUN_0042483e(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + param_3[1];
  }
  if (0 < (int)param_2) {
    FUN_0042483e(pcVar3,1);
    *pcVar3 = DAT_00432108;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if ((param_4 != '\0') || (SBORROW4(param_2,-iVar1) == (int)(param_2 + iVar1) < 0)) {
        param_2 = -iVar1;
      }
      FUN_0042483e(pcVar3 + 1,param_2);
      _memset(pcVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}



void __cdecl FUN_0042475a(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_004266eb((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  iVar1 = local_10 + -1;
  FUN_00426674(param_2 + (local_14 == 0x2d),param_3,(int)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    FUN_0042459c(param_2,param_3,param_4,&local_14,'\x01');
  }
  else {
    pcVar2 = param_2 + (local_14 == 0x2d);
    if (iVar1 < local_10) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_004246b3(param_2,param_3,&local_14,'\x01');
  }
  return;
}



// Library Function - Single Match
//  __cfltcvt
// 
// Library: Visual Studio 2003 Release

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined *puVar2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_0042453b(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_0042465e(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined *)FUN_0042475a(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}



void __cdecl FUN_0042483e(char *param_1,int param_2)

{
  size_t sVar1;
  
  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_00426800((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}



SIZE_T __cdecl FUN_00424863(LPCVOID param_1)

{
  uint uVar1;
  SIZE_T SVar2;
  
  FUN_0042152d(9);
  uVar1 = FUN_00424cda((int)param_1);
  if (uVar1 == 0) {
    FUN_0042158e(9);
    SVar2 = HeapSize(DAT_00436810,0,param_1);
  }
  else {
    SVar2 = *(int *)((int)param_1 + -4) - 9;
    FUN_0042158e(9);
  }
  return SVar2;
}



undefined4 __cdecl FUN_004248a8(int param_1)

{
  BYTE *pBVar1;
  byte bVar2;
  byte bVar3;
  UINT CodePage;
  UINT *pUVar4;
  BOOL BVar5;
  uint uVar6;
  uint uVar7;
  BYTE *pBVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_0042152d(0x19);
  CodePage = FUN_00424a55(param_1);
  if (CodePage != DAT_004365d4) {
    if (CodePage != 0) {
      iVar11 = 0;
      pUVar4 = &DAT_00432778;
LAB_004248e5:
      if (*pUVar4 != CodePage) goto code_r0x004248e9;
      local_8 = 0;
      puVar14 = (undefined4 *)&DAT_00436700;
      for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined *)puVar14 = 0;
      pbVar12 = &DAT_00432788 + iVar11 * 0x30;
      do {
        bVar2 = *pbVar12;
        pbVar10 = pbVar12;
        while ((bVar2 != 0 && (bVar2 = pbVar10[1], bVar2 != 0))) {
          uVar7 = (uint)*pbVar10;
          if (uVar7 <= bVar2) {
            bVar3 = (&DAT_00432770)[local_8];
            do {
              (&DAT_00436701)[uVar7] = (&DAT_00436701)[uVar7] | bVar3;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= bVar2);
          }
          pbVar10 = pbVar10 + 2;
          bVar2 = *pbVar10;
        }
        local_8 = local_8 + 1;
        pbVar12 = pbVar12 + 8;
      } while (local_8 < 4);
      DAT_004365ec = 1;
      DAT_004365d4 = CodePage;
      DAT_00436804 = FUN_00424a9f(CodePage);
      DAT_004365e0 = (&DAT_0043277c)[iVar11 * 0xc];
      DAT_004365e4 = (&DAT_00432780)[iVar11 * 0xc];
      DAT_004365e8 = (&DAT_00432784)[iVar11 * 0xc];
      goto LAB_00424a39;
    }
    goto LAB_00424a34;
  }
  goto LAB_004248cf;
code_r0x004248e9:
  pUVar4 = pUVar4 + 0xc;
  iVar11 = iVar11 + 1;
  if (0x432867 < (int)pUVar4) goto code_r0x004248f4;
  goto LAB_004248e5;
code_r0x004248f4:
  BVar5 = GetCPInfo(CodePage,&local_1c);
  uVar7 = 1;
  if (BVar5 == 1) {
    DAT_00436804 = 0;
    puVar14 = (undefined4 *)&DAT_00436700;
    for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    *(undefined *)puVar14 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_004365ec = 0;
      DAT_004365d4 = CodePage;
    }
    else {
      DAT_004365d4 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar8 = local_1c.LeadByte + 1;
        do {
          bVar2 = *pBVar8;
          if (bVar2 == 0) break;
          for (uVar6 = (uint)pBVar8[-1]; uVar6 <= bVar2; uVar6 = uVar6 + 1) {
            (&DAT_00436701)[uVar6] = (&DAT_00436701)[uVar6] | 4;
          }
          pBVar1 = pBVar8 + 1;
          pBVar8 = pBVar8 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        (&DAT_00436701)[uVar7] = (&DAT_00436701)[uVar7] | 8;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 0xff);
      DAT_00436804 = FUN_00424a9f(CodePage);
      DAT_004365ec = 1;
    }
    DAT_004365e0 = 0;
    DAT_004365e4 = 0;
    DAT_004365e8 = 0;
  }
  else {
    if (DAT_00435170 == 0) {
      uVar13 = 0xffffffff;
      goto LAB_00424a46;
    }
LAB_00424a34:
    FUN_00424ad2();
  }
LAB_00424a39:
  FUN_00424afb();
LAB_004248cf:
  uVar13 = 0;
LAB_00424a46:
  FUN_0042158e(0x19);
  return uVar13;
}



int __cdecl FUN_00424a55(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00435170 = 1;
                    // WARNING: Could not recover jumptable at 0x00424a6f. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00435170 = 1;
                    // WARNING: Could not recover jumptable at 0x00424a84. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00435060;
  }
  DAT_00435170 = (uint)bVar2;
  return param_1;
}



undefined4 __cdecl FUN_00424a9f(int param_1)

{
  if (param_1 == 0x3a4) {
    return 0x411;
  }
  if (param_1 == 0x3a8) {
    return 0x804;
  }
  if (param_1 == 0x3b5) {
    return 0x412;
  }
  if (param_1 != 0x3b6) {
    return 0;
  }
  return 0x404;
}



void FUN_00424ad2(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_00436700;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined *)puVar2 = 0;
  DAT_004365d4 = 0;
  DAT_004365ec = 0;
  DAT_00436804 = 0;
  DAT_004365e0 = 0;
  DAT_004365e4 = 0;
  DAT_004365e8 = 0;
  return;
}



void FUN_00424afb(void)

{
  BOOL BVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  undefined uVar7;
  BYTE *pBVar8;
  CHAR *pCVar9;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  BVar1 = GetCPInfo(DAT_004365d4,&local_18);
  if (BVar1 == 1) {
    uVar2 = 0;
    do {
      local_118[uVar2] = (CHAR)uVar2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar8 = local_18.LeadByte + 1;
      do {
        uVar2 = (uint)local_18.LeadByte[0];
        if (uVar2 <= *pBVar8) {
          uVar4 = (*pBVar8 - uVar2) + 1;
          uVar5 = uVar4 >> 2;
          pCVar9 = local_118 + uVar2;
          while (uVar5 != 0) {
            uVar5 = uVar5 - 1;
            builtin_memcpy(pCVar9,"    ",4);
            pCVar9 = pCVar9 + 4;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pCVar9 = ' ';
            pCVar9 = pCVar9 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar8[1];
        pBVar8 = pBVar8 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_004221d9(1,local_118,0x100,local_518,DAT_004365d4,DAT_00436804,0);
    FUN_0042311b(DAT_00436804,0x100,local_118,0x100,local_218,0x100,DAT_004365d4,0);
    FUN_0042311b(DAT_00436804,0x200,local_118,0x100,local_318,0x100,DAT_004365d4,0);
    uVar2 = 0;
    puVar6 = local_518;
    do {
      if ((*puVar6 & 1) == 0) {
        if ((*puVar6 & 2) != 0) {
          (&DAT_00436701)[uVar2] = (&DAT_00436701)[uVar2] | 0x20;
          uVar7 = *(undefined *)((int)local_318 + uVar2);
          goto LAB_00424c07;
        }
        (&DAT_00436600)[uVar2] = 0;
      }
      else {
        (&DAT_00436701)[uVar2] = (&DAT_00436701)[uVar2] | 0x10;
        uVar7 = *(undefined *)((int)local_218 + uVar2);
LAB_00424c07:
        (&DAT_00436600)[uVar2] = uVar7;
      }
      uVar2 = uVar2 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar2 < 0x100);
  }
  else {
    uVar2 = 0;
    do {
      if ((uVar2 < 0x41) || (0x5a < uVar2)) {
        if ((0x60 < uVar2) && (uVar2 < 0x7b)) {
          (&DAT_00436701)[uVar2] = (&DAT_00436701)[uVar2] | 0x20;
          cVar3 = (char)uVar2 + -0x20;
          goto LAB_00424c51;
        }
        (&DAT_00436600)[uVar2] = 0;
      }
      else {
        (&DAT_00436701)[uVar2] = (&DAT_00436701)[uVar2] | 0x10;
        cVar3 = (char)uVar2 + ' ';
LAB_00424c51:
        (&DAT_00436600)[uVar2] = cVar3;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x100);
  }
  return;
}



void FUN_00424c80(void)

{
  if (DAT_00436930 == 0) {
    FUN_004248a8(-3);
    DAT_00436930 = 1;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00424c9c(void)

{
  DAT_004365d0 = HeapAlloc(DAT_00436810,0,0x140);
  if (DAT_004365d0 == (LPVOID)0x0) {
    return 0;
  }
  _DAT_004365c8 = 0;
  DAT_004365cc = 0;
  _DAT_004365c4 = DAT_004365d0;
  _DAT_004365c0 = 0x10;
  return 1;
}



uint __cdecl FUN_00424cda(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_004365d0;
  while( true ) {
    if (DAT_004365d0 + DAT_004365cc * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}



int __cdecl FUN_00424d05(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00435174 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00435174 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00435174 != (FARPROC)0x0) {
        DAT_00435178 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_0043517c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_00424d54;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_00424d54:
    if (DAT_00435178 != (FARPROC)0x0) {
      iVar1 = (*DAT_00435178)();
      if ((iVar1 != 0) && (DAT_0043517c != (FARPROC)0x0)) {
        iVar1 = (*DAT_0043517c)(iVar1);
      }
    }
    iVar1 = (*DAT_00435174)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}



uint FUN_00424d8e(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_8;
  int local_4;
  
  uVar6 = 0xffffffff;
  FUN_0042152d(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar4 = &DAT_00436820;
  while (puVar5 = (undefined4 *)*piVar4, puVar1 = puVar5, puVar5 != (undefined4 *)0x0) {
    for (; puVar5 < puVar1 + 0x120; puVar5 = puVar5 + 9) {
      if ((*(byte *)(puVar5 + 1) & 1) == 0) {
        if (puVar5[2] == 0) {
          FUN_0042152d(0x11);
          if (puVar5[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 3));
            puVar5[2] = puVar5[2] + 1;
          }
          FUN_0042158e(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar5 + 3));
        if ((*(byte *)(puVar5 + 1) & 1) == 0) {
          *puVar5 = 0xffffffff;
          uVar6 = ((int)puVar5 - *piVar4) / 0x24 + local_4;
          if (uVar6 != 0xffffffff) goto LAB_00424ea0;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar5 + 3));
      }
      puVar1 = (undefined4 *)*piVar4;
    }
    local_4 = local_4 + 0x20;
    piVar4 = piVar4 + 1;
    local_8 = local_8 + 1;
    if (0x43691f < (int)piVar4) goto LAB_00424ea0;
  }
  puVar3 = FUN_0041b590(0x480);
  if (puVar3 != (uint *)0x0) {
    DAT_00436920 = DAT_00436920 + 0x20;
    (&DAT_00436820)[local_8] = puVar3;
    puVar2 = puVar3;
    for (; puVar3 < puVar2 + 0x120; puVar3 = puVar3 + 9) {
      *(undefined *)(puVar3 + 1) = 0;
      *puVar3 = 0xffffffff;
      puVar3[2] = 0;
      *(undefined *)((int)puVar3 + 5) = 10;
      puVar2 = (uint *)(&DAT_00436820)[local_8];
    }
    uVar6 = local_8 << 5;
    FUN_00424fee(uVar6);
  }
LAB_00424ea0:
  FUN_0042158e(0x12);
  return uVar6;
}



undefined4 __cdecl FUN_00424eb1(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_00436920) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_00436820)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_00431c74 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00424f0a;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_00424f0a:
      *(HANDLE *)((&DAT_00436820)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_00420791();
  *pDVar1 = 9;
  pDVar1 = FUN_0042079a();
  *pDVar1 = 0;
  return 0xffffffff;
}



undefined4 __cdecl FUN_00424f2d(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_00436920) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_00436820)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00431c74 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00424f89;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00424f89:
      *(undefined4 *)((&DAT_00436820)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_00420791();
  *pDVar2 = 9;
  pDVar2 = FUN_0042079a();
  *pDVar2 = 0;
  return 0xffffffff;
}



undefined4 __cdecl FUN_00424fac(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_00436920) &&
     ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_00436820)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_00420791();
  *pDVar1 = 9;
  pDVar1 = FUN_0042079a();
  *pDVar1 = 0;
  return 0xffffffff;
}



void __cdecl FUN_00424fee(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_00436820)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_0042152d(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_0042158e(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_00436820)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



void __cdecl FUN_0042504d(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00436820)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



uint __cdecl FUN_00425086(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  DWORD *pDVar4;
  HANDLE hFile;
  DWORD DVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;
  
  bVar8 = (param_2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar8) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar8;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_004351ec != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) goto LAB_0042518a;
    local_10 = 0xc0000000;
  }
  if (param_3 == 0x10) {
    local_14 = 0;
  }
  else if (param_3 == 0x20) {
    local_14 = 1;
  }
  else if (param_3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (param_3 != 0x40) goto LAB_0042518a;
    local_14 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_004251a4;
      if (uVar2 != 0x300) goto LAB_0042518a;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_004251a4:
        local_c = 5;
        goto LAB_004251b4;
      }
      if (uVar2 != 0x700) {
LAB_0042518a:
        pDVar4 = FUN_00420791();
        *pDVar4 = 0x16;
        pDVar4 = FUN_0042079a();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_004251b4:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_00434e60 & param_4 & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = FUN_00424d8e();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_00420791();
    *pDVar4 = 0x18;
    pDVar4 = FUN_0042079a();
    *pDVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      FUN_00424eb1(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_00436820)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_004253ba(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_0042079a();
          if (*pDVar4 == 0x83) goto LAB_0042532e;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_0042566a(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_00426b3e(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_004253ba(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_0042532e;
        }
        FUN_00421378(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_0042532e:
        uVar2 = uVar3;
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_00436820)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
      }
      goto LAB_00425347;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_0042071e(DVar5);
  uVar2 = 0xffffffff;
LAB_00425347:
  FUN_0042504d(uVar3);
  return uVar2;
}



DWORD __cdecl FUN_00425355(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_00436920) &&
     ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00424fee(param_1);
    DVar1 = FUN_004253ba(param_1,param_2,param_3);
    FUN_0042504d(param_1);
    return DVar1;
  }
  pDVar2 = FUN_00420791();
  *pDVar2 = 9;
  pDVar2 = FUN_0042079a();
  *pDVar2 = 0;
  return 0xffffffff;
}



DWORD __cdecl FUN_004253ba(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_00424fac(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_00420791();
    *pDVar2 = 9;
  }
  else {
    DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
    if (DVar3 == 0xffffffff) {
      uVar4 = GetLastError();
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pbVar1 = (byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_0042071e(uVar4);
  }
  return 0xffffffff;
}



byte __cdecl FUN_0042542d(uint param_1)

{
  if (DAT_00436920 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



LPSTR __cdecl FUN_00425456(LPSTR param_1,WCHAR param_2)

{
  LPSTR pCVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_0043680c);
  bVar2 = DAT_00436808 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_0043680c);
    FUN_0042152d(0x13);
  }
  pCVar1 = FUN_004254af(param_1,param_2);
  if (bVar2) {
    FUN_0042158e(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_0043680c);
  }
  return pCVar1;
}



LPSTR __cdecl FUN_004254af(LPSTR param_1,WCHAR param_2)

{
  LPSTR pCVar1;
  DWORD *pDVar2;
  
  pCVar1 = param_1;
  if (param_1 == (LPSTR)0x0) {
    return param_1;
  }
  if (DAT_00435050 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return (LPSTR)0x1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    pCVar1 = (LPSTR)WideCharToMultiByte(DAT_00435060,0x220,&param_2,1,pCVar1,DAT_00432104,
                                        (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((pCVar1 != (LPSTR)0x0) && (param_1 == (LPSTR)0x0)) {
      return pCVar1;
    }
  }
  pDVar2 = FUN_00420791();
  *pDVar2 = 0x2a;
  return (LPSTR)0xffffffff;
}



// Library Function - Single Match
//  __aulldiv
// 
// Library: Visual Studio

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



// Library Function - Single Match
//  __aullrem
// 
// Library: Visual Studio

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



int __cdecl FUN_00425605(uint param_1,char *param_2,char *param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_00436920) &&
     ((*(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00424fee(param_1);
    iVar1 = FUN_0042566a(param_1,param_2,param_3);
    FUN_0042504d(param_1);
    return iVar1;
  }
  pDVar2 = FUN_00420791();
  *pDVar2 = 9;
  pDVar2 = FUN_0042079a();
  *pDVar2 = 0;
  return -1;
}



int __cdecl FUN_0042566a(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  DWORD *pDVar7;
  char *pcVar8;
  int iVar9;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_00436820 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_00436820)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_00436820)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
        param_3 = param_3 + -1;
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined *)(*piVar1 + 5 + iVar9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          pDVar7 = FUN_00420791();
          *pDVar7 = 9;
          pDVar7 = FUN_0042079a();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_0042071e(DVar6);
        }
        return -1;
      }
      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);
      if ((bVar4 & 0x80) == 0) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*param_2 != '\n')) {
        bVar4 = bVar4 & 0xfb;
      }
      else {
        bVar4 = bVar4 | 4;
      }
      *(byte *)(*piVar1 + 4 + iVar9) = bVar4;
      param_3 = param_2;
      local_c = param_2 + (int)local_c + local_10;
      pcVar8 = param_2;
      if (param_2 < local_c) {
        do {
          cVar3 = *param_3;
          if (cVar3 == '\x1a') {
            pbVar2 = (byte *)(*piVar1 + 4 + iVar9);
            bVar4 = *pbVar2;
            if ((bVar4 & 0x40) == 0) {
              *pbVar2 = bVar4 | 2;
            }
            break;
          }
          if (cVar3 == '\r') {
            if (param_3 < local_c + -1) {
              if (param_3[1] == '\n') {
                param_3 = param_3 + 2;
                goto LAB_004257f5;
              }
              *pcVar8 = '\r';
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              param_3 = param_3 + 1;
              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_0042580f:
                *pcVar8 = '\r';
LAB_00425812:
                pcVar8 = pcVar8 + 1;
              }
              else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_004257f5:
                  *pcVar8 = '\n';
                  goto LAB_00425812;
                }
                FUN_004253ba(param_1,-1,1);
                if (local_5 != '\n') goto LAB_0042580f;
              }
              else {
                if (local_5 == '\n') goto LAB_004257f5;
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                *(char *)(*piVar1 + 5 + iVar9) = local_5;
              }
            }
          }
          else {
            *pcVar8 = cVar3;
            pcVar8 = pcVar8 + 1;
            param_3 = param_3 + 1;
          }
        } while (param_3 < local_c);
      }
      return (int)pcVar8 - (int)param_2;
    }
  }
  return 0;
}



// Library Function - Single Match
//  _memset
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = (uint *)_Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined *)puVar4 = (undefined)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



uint __cdecl FUN_004258a8(LPWSTR param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_0043680c);
  bVar2 = DAT_00436808 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_0043680c);
    FUN_0042152d(0x13);
  }
  uVar1 = FUN_00425905(param_1,param_2,param_3);
  if (bVar2) {
    FUN_0042158e(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_0043680c);
  }
  return uVar1;
}



uint __cdecl FUN_00425905(LPWSTR param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  DWORD *pDVar3;
  
  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
    bVar1 = *param_2;
    if (bVar1 != 0) {
      if (DAT_00435050 == 0) {
        if (param_1 != (LPWSTR)0x0) {
          *param_1 = (ushort)bVar1;
        }
        return 1;
      }
      if ((PTR_DAT_00431ef8[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(DAT_00435060,9,(LPCSTR)param_2,1,param_1,
                                    (uint)(param_1 != (LPWSTR)0x0));
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        if (1 < (int)DAT_00432104) {
          if ((int)param_3 < (int)DAT_00432104) goto LAB_00425997;
          iVar2 = MultiByteToWideChar(DAT_00435060,9,(LPCSTR)param_2,DAT_00432104,param_1,
                                      (uint)(param_1 != (LPWSTR)0x0));
          if (iVar2 != 0) {
            return DAT_00432104;
          }
        }
        if ((DAT_00432104 <= param_3) && (param_2[1] != 0)) {
          return DAT_00432104;
        }
      }
LAB_00425997:
      pDVar3 = FUN_00420791();
      *pDVar3 = 0x2a;
      return 0xffffffff;
    }
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
  }
  return 0;
}



// Library Function - Single Match
//  __allshl
// 
// Library: Visual Studio

longlong __fastcall __allshl(byte param_1,int param_2)

{
  uint in_EAX;
  
  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 << (param_1 & 0x1f) | in_EAX >> 0x20 - (param_1 & 0x1f),
                    in_EAX << (param_1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (param_1 & 0x1f)) << 0x20;
}



// Library Function - Single Match
//  _strcmp
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_00425a34;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00425a00;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_00425a34;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < ((byte *)_Str2)[1];
    if (bVar4 != ((byte *)_Str2)[1]) goto LAB_00425a34;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = (char *)((byte *)_Str2 + 2);
  }
LAB_00425a00:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < ((byte *)_Str2)[1];
    if (bVar4 != ((byte *)_Str2)[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < ((byte *)_Str2)[2];
    if (bVar4 != ((byte *)_Str2)[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < ((byte *)_Str2)[3];
    if (bVar3 != ((byte *)_Str2)[3]) break;
    _Str2 = (char *)((byte *)_Str2 + 4);
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_00425a34:
  return (uint)bVar5 * -2 + 1;
}



int __cdecl FUN_00425a80(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return iVar2;
}



byte * __cdecl FUN_00425ac0(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)(uint)bVar1;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}



int __cdecl
FUN_00425afa(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  undefined *puVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  int iVar5;
  undefined unaff_DI;
  _cpinfo local_40;
  undefined *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined *local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042b6f0;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_004351e8 == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,"",1,"",1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_004351e8 = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_004351e8 = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_00425d77((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_00425d77((char *)param_5,param_6);
  }
  if (DAT_004351e8 == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_004351e8 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_00435060;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        ExceptionList = local_14;
        return 2;
      }
      if (1 < param_6) {
        ExceptionList = local_14;
        return 1;
      }
      if (1 < param_4) {
        ExceptionList = local_14;
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (0 < param_4) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 3;
      }
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 1;
      }
    }
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_004203d0(unaff_DI);
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_004203d0(unaff_DI);
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined *)0x50) &&
             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,
             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,
                                         iVar2), iVar5 != 0)) {
            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2
                                  );
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



int __cdecl FUN_00425d77(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*pcVar1 == '\0') {
    return (int)pcVar1 - (int)param_1;
  }
  return param_2;
}



undefined4 __cdecl FUN_00425da2(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  size_t sVar4;
  byte *pbVar5;
  uint *puVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = (uint *)FUN_00426d71((byte *)param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(byte *)((int)puVar1 + 1) == 0;
  if (DAT_00434e80 == DAT_00434e84) {
    DAT_00434e80 = FUN_00425f81((int *)DAT_00434e80);
  }
  if (DAT_00434e80 == (uint *)0x0) {
    if ((param_2 == 0) || (DAT_00434e88 == (uint *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_00434e80 = FUN_0041b590(4);
      if (DAT_00434e80 == (uint *)0x0) {
        return 0xffffffff;
      }
      *DAT_00434e80 = 0;
      if (DAT_00434e88 == (uint *)0x0) {
        DAT_00434e88 = FUN_0041b590(4);
        if (DAT_00434e88 == (uint *)0x0) {
          return 0xffffffff;
        }
        *DAT_00434e88 = 0;
      }
    }
    else {
      iVar2 = FUN_00424356();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  puVar3 = DAT_00434e80;
  iVar2 = FUN_00425f29((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*puVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    puVar3 = FUN_0041ba30(puVar3,iVar2 * 4 + 8);
    if (puVar3 == (uint *)0x0) {
      return 0xffffffff;
    }
    puVar3[iVar2] = (uint)param_1;
    puVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      puVar3[iVar2] = (uint)param_1;
      goto LAB_00425ed6;
    }
    puVar6 = puVar3 + iVar2;
    FUN_0041b8c0(puVar3[iVar2]);
    for (; *puVar6 != 0; puVar6 = puVar6 + 1) {
      iVar2 = iVar2 + 1;
      *puVar6 = puVar6[1];
    }
    puVar3 = FUN_0041ba30(puVar3,iVar2 << 2);
    if (puVar3 == (uint *)0x0) goto LAB_00425ed6;
  }
  DAT_00434e80 = puVar3;
LAB_00425ed6:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    puVar3 = FUN_0041b590(sVar4 + 2);
    if (puVar3 != (uint *)0x0) {
      FUN_00423540(puVar3,param_1);
      pbVar5 = (byte *)(((int)puVar3 - (int)param_1) + (int)puVar1);
      *pbVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)puVar3,(LPCSTR)(~-(uint)bVar7 & (uint)(pbVar5 + 1)));
      FUN_0041b8c0((int)puVar3);
    }
  }
  return 0;
}



int __cdecl FUN_00425f29(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_00434e80;
  piVar2 = DAT_00434e80;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_00434e80 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_00434e80 >> 2;
}



uint * __cdecl FUN_00425f81(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = FUN_0041b590(iVar5 * 4 + 4);
    if (puVar3 == (uint *)0x0) {
      __amsg_exit(9);
    }
    puVar4 = (uint *)*param_1;
    puVar6 = puVar3;
    while (puVar4 != (uint *)0x0) {
      param_1 = param_1 + 1;
      puVar4 = FUN_00426e08(puVar4);
      *puVar6 = (uint)puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (uint *)0x0;
}



uint __thiscall FUN_00425fe8(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_00426033(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_004260c5(uVar1);
  return uVar1;
}



void __thiscall FUN_0042601d(void *this,uint param_1,uint param_2)

{
  FUN_00425fe8(this,param_1,param_2 & 0xfff7ffff);
  return;
}



uint __cdecl FUN_00426033(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}



uint __cdecl FUN_004260c5(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)((param_1 & 0x10) != 0);
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = param_1 & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}



uint __cdecl FUN_0042614e(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_00435050 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_0043680c);
    bVar1 = DAT_00436808 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_0043680c);
      this = (void *)0x13;
      FUN_0042152d(0x13);
    }
    param_1 = FUN_004261bd(this,param_1);
    if (bVar1) {
      FUN_0042158e(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_0043680c);
    }
  }
  return param_1;
}



uint __thiscall FUN_004261bd(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_00435050 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_00432104 < 2) {
        uVar2 = (byte)PTR_DAT_00431ef8[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_0041eea6(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_00431ef8[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_0042311b(DAT_00435050,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



undefined4 __cdecl FUN_00426288(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}



void __cdecl FUN_004262d1(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_00426e33(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_00426e33(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



undefined4 __cdecl FUN_00426327(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  bVar3 = 0x1f - (char)(param_2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_00426288(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_004262d1(param_1,param_2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}



void __cdecl FUN_004263b3(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 - (int)param_2;
  iVar2 = 3;
  do {
    *(undefined4 *)(iVar1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



void __cdecl FUN_004263ce(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



undefined4 __cdecl FUN_004263da(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}



void __cdecl FUN_004263f5(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;
  
  local_8 = 3;
  iVar2 = (int)param_2 / 0x20;
  iVar5 = (int)param_2 % 0x20;
  param_2 = 0;
  bVar3 = (byte)iVar5;
  puVar6 = param_1;
  do {
    uVar1 = *puVar6;
    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;
    puVar6 = puVar6 + 1;
    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar5 = 2;
  iVar4 = 8;
  do {
    if (iVar5 < iVar2) {
      *(undefined4 *)(iVar4 + (int)param_1) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar4);
  return;
}



undefined4 __cdecl FUN_00426482(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)*param_1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_004263da((int *)&local_10);
    if (iVar2 != 0) {
LAB_004265ae:
      uVar5 = 0;
      goto LAB_004265b0;
    }
    FUN_004263ce(&local_10);
  }
  else {
    FUN_004263b3((int)local_1c,&local_10);
    iVar2 = FUN_00426327((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_004263ce(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_004263ce(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_004263f5(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_004265b0;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_004263f5(&local_10,param_3[3]);
        goto LAB_004265ae;
      }
      FUN_004263b3((int)&local_10,local_1c);
      FUN_004263f5(&local_10,iVar2 - iVar4);
      FUN_00426327((int)&local_10,param_3[2]);
      FUN_004263f5(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_004265b0:
  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar5;
}



void __cdecl FUN_004265ee(ushort *param_1,uint *param_2)

{
  FUN_00426482(param_1,param_2,(int *)&DAT_004328d8);
  return;
}



void __cdecl FUN_00426604(ushort *param_1,uint *param_2)

{
  FUN_00426482(param_1,param_2,(int *)&DAT_004328f0);
  return;
}



void __thiscall FUN_0042661a(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_00426fd4(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_004265ee(local_10,param_1);
  return;
}



void __thiscall FUN_00426647(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_00426fd4(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_00426604(local_10,param_1);
  return;
}



void __cdecl FUN_00426674(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;
  
  pcVar1 = param_1;
  pcVar4 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar2 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar5 = *pcVar4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        pcVar4 = pcVar4 + 1;
      }
      *pcVar2 = cVar5;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  *pcVar2 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar4)) {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
      *pcVar2 = '0';
    }
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*pcVar1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar3 = _strlen(_Str);
    FUN_00426800((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}



int * __cdecl FUN_004266eb(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_stack_ffffffbc;
  undefined2 uVar4;
  short local_2c;
  char local_2a;
  uint local_28 [6];
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffbc >> 0x10);
  FUN_00426747(&local_10,&param_1);
  iVar3 = FUN_004274a5(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2a;
  param_3[1] = (int)local_2c;
  FUN_00423540(param_4,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}



void __cdecl FUN_00426747(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *param_2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  param_1[1] = local_8;
  *param_1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *param_1 >> 0x1f | local_8 * 2;
    *param_1 = *param_1 * 2;
    param_1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return;
}



undefined4 * __cdecl FUN_00426800(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_004269b7_caseD_2;
        case 3:
          goto switchD_004269b7_caseD_3;
        }
        goto switchD_004269b7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_004269b7_caseD_0;
      case 1:
        goto switchD_004269b7_caseD_1;
      case 2:
        goto switchD_004269b7_caseD_2;
      case 3:
        goto switchD_004269b7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004269b7_caseD_2;
            case 3:
              goto switchD_004269b7_caseD_3;
            }
            goto switchD_004269b7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004269b7_caseD_2;
            case 3:
              goto switchD_004269b7_caseD_3;
            }
            goto switchD_004269b7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
          *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined *)((int)puVar4 + 1) = *(undefined *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004269b7_caseD_2;
            case 3:
              goto switchD_004269b7_caseD_3;
            }
            goto switchD_004269b7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_004269b7_caseD_1:
      *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_004269b7_caseD_2:
      *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
      *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_004269b7_caseD_3:
      *(undefined *)((int)puVar4 + 3) = *(undefined *)((int)puVar3 + 3);
      *(undefined *)((int)puVar4 + 2) = *(undefined *)((int)puVar3 + 2);
      *(undefined *)((int)puVar4 + 1) = *(undefined *)((int)puVar3 + 1);
      return param_1;
    }
switchD_004269b7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00426835_caseD_2;
      case 3:
        goto switchD_00426835_caseD_3;
      }
      goto switchD_00426835_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00426835_caseD_0;
    case 1:
      goto switchD_00426835_caseD_1;
    case 2:
      goto switchD_00426835_caseD_2;
    case 3:
      goto switchD_00426835_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined *)param_1 = *(undefined *)param_2;
        *(undefined *)((int)param_1 + 1) = *(undefined *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined *)((int)param_1 + 2) = *(undefined *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00426835_caseD_2;
          case 3:
            goto switchD_00426835_caseD_3;
          }
          goto switchD_00426835_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined *)param_1 = *(undefined *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined *)((int)param_1 + 1) = *(undefined *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00426835_caseD_2;
          case 3:
            goto switchD_00426835_caseD_3;
          }
          goto switchD_00426835_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined *)param_1 = *(undefined *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00426835_caseD_2;
          case 3:
            goto switchD_00426835_caseD_3;
          }
          goto switchD_00426835_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00426835_caseD_1:
    *(undefined *)puVar3 = *(undefined *)param_2;
    return param_1;
  case 2:
switchD_00426835_caseD_2:
    *(undefined *)puVar3 = *(undefined *)param_2;
    *(undefined *)((int)puVar3 + 1) = *(undefined *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00426835_caseD_3:
    *(undefined *)puVar3 = *(undefined *)param_2;
    *(undefined *)((int)puVar3 + 1) = *(undefined *)((int)param_2 + 1);
    *(undefined *)((int)puVar3 + 2) = *(undefined *)((int)param_2 + 2);
    return param_1;
  }
switchD_00426835_caseD_0:
  return param_1;
}



void FUN_00426b35(void)

{
  __amsg_exit(2);
  return;
}



int __cdecl FUN_00426b3e(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  DWORD *pDVar6;
  HANDLE hFile;
  BOOL BVar7;
  undefined1 unaff_BP;
  int iVar8;
  uint uVar9;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  FUN_004203d0(unaff_BP);
  iVar8 = 0;
  DVar1 = FUN_004253ba(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_004253ba(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    uVar9 = param_2 - DVar2;
    if ((int)uVar9 < 1) {
      if ((int)uVar9 < 0) {
        FUN_004253ba(param_1,param_2,0);
        hFile = (HANDLE)FUN_00424fac(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_00420791();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_0042079a();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x426bab;
      iVar3 = FUN_00427738(param_1,0x8000);
      do {
        uVar4 = 0x1000;
        if ((int)uVar9 < 0x1000) {
          uVar4 = uVar9;
        }
        iVar5 = FUN_00422f0f(param_1,local_1008,uVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_0042079a();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_00420791();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        uVar9 = uVar9 - iVar5;
      } while (0 < (int)uVar9);
      FUN_00427738(param_1,iVar3);
    }
    FUN_004253ba(param_1,DVar1,0);
  }
  return iVar8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void * __cdecl FUN_00426c70(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  void *this;
  uint uVar6;
  bool bVar7;
  uint uVar8;
  
  iVar2 = _DAT_0043680c;
  if (param_3 != (void *)0x0) {
    if (DAT_00435050 == 0) {
      do {
        bVar3 = *param_1;
        cVar1 = *param_2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar6 = (uint)uVar4;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar6 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar6;
        bVar3 = (byte)uVar6;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar6 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar7 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_00426ccf;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      param_3 = (void *)0x0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar7 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_00426ccf:
        param_3 = (void *)0xffffffff;
        if (!bVar7) {
          param_3 = (void *)0x1;
        }
      }
    }
    else {
      LOCK();
      _DAT_0043680c = _DAT_0043680c + 1;
      UNLOCK();
      bVar7 = 0 < DAT_00436808;
      if (bVar7) {
        LOCK();
        UNLOCK();
        _DAT_0043680c = iVar2;
        FUN_0042152d(0x13);
      }
      uVar8 = (uint)bVar7;
      uVar5 = 0;
      uVar6 = 0;
      do {
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);
        uVar6 = CONCAT31((int3)(uVar6 >> 8),*param_2);
        if ((uVar5 == 0) || (uVar6 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar6 = FUN_004261bd(param_3,uVar6);
        uVar5 = FUN_004261bd(this,uVar5);
        bVar7 = uVar5 < uVar6;
        if (uVar5 != uVar6) goto LAB_00426d45;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      param_3 = (void *)0x0;
      bVar7 = uVar5 < uVar6;
      if (uVar5 != uVar6) {
LAB_00426d45:
        param_3 = (void *)0xffffffff;
        if (!bVar7) {
          param_3 = (void *)0x1;
        }
      }
      if (uVar8 == 0) {
        LOCK();
        _DAT_0043680c = _DAT_0043680c + -1;
        UNLOCK();
      }
      else {
        FUN_0042158e(0x13);
      }
    }
  }
  return param_3;
}



byte * __cdecl FUN_00426d71(byte *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (DAT_004365ec == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
  }
  else {
    FUN_0042152d(0x19);
    while( true ) {
      bVar1 = *param_1;
      uVar3 = (uint)bVar1;
      if (bVar1 == 0) break;
      if (((&DAT_00436701)[uVar3] & 4) == 0) {
        pbVar2 = param_1;
        if (param_2 == uVar3) break;
      }
      else {
        pbVar2 = param_1 + 1;
        if (param_1[1] == 0) {
          FUN_0042158e(0x19);
          return (byte *)0x0;
        }
        if (param_2 == CONCAT11(bVar1,param_1[1])) {
          FUN_0042158e(0x19);
          return param_1;
        }
      }
      param_1 = pbVar2 + 1;
    }
    FUN_0042158e(0x19);
    pbVar2 = (byte *)(~-(uint)(param_2 != uVar3) & (uint)param_1);
  }
  return pbVar2;
}



uint * __cdecl FUN_00426e08(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  
  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = FUN_0041b590(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_00423540(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}



undefined4 __cdecl FUN_00426e33(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}



// Library Function - Single Match
//  ___add_12
// 
// Library: Visual Studio 2003 Release

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00426e33(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_00426e33(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_00426e33(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_00426e33(param_1[2],param_2[2],param_1 + 2);
  return;
}



void __cdecl FUN_00426eb2(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}



void __cdecl FUN_00426ee0(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}



void __cdecl FUN_00426f0d(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar1 = param_3;
  local_8 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      FUN_00426eb2(puVar1);
      FUN_00426eb2(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_00426eb2(puVar1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*param_1;
      ___add_12(puVar1,&local_14);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  while (puVar1[2] == 0) {
    puVar1[2] = puVar1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
    *puVar1 = *puVar1 << 0x10;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    FUN_00426eb2(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}



undefined4 __thiscall
FUN_00426fd4(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = param_3;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_0042702b:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_00427048:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_0042726d;
    }
    if (bVar6 == DAT_00432108) goto LAB_00427057;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_00427347;
    }
    goto LAB_0042702b;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_00427048;
    iVar9 = iVar1;
    if (bVar6 != DAT_00432108) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_004270dc;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_004270b5;
    }
    goto LAB_0042702b;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_00427048;
    if (bVar6 == DAT_00432108) {
LAB_00427057:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_0042734c;
    }
    goto LAB_0042702b;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_00432104 < 2) {
        uVar3 = (byte)PTR_DAT_00431ef8[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_00431ef8;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_0041eea6(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_00432108) goto LAB_004271c9;
    goto LAB_0042702b;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_00432104 < 2) {
        uVar3 = (byte)PTR_DAT_00431ef8[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_00431ef8;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_0041eea6(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_004271c9:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_004270dc:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_004270b5:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_00427347;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_0042702b;
  case 5:
    local_28 = iVar5;
    if (DAT_00432104 < 2) {
      uVar3 = (byte)PTR_DAT_00431ef8[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_00431ef8;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_0041eea6(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_0042726d;
    goto LAB_0042734c;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_004272a2;
      if (bVar6 == 0x2d) goto LAB_00427296;
      if (bVar6 != 0x30) goto LAB_0042734c;
LAB_0042723b:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_0042702b;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_0042723b;
      goto LAB_0042734c;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_00427347;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_004272cd;
  default:
    goto switchD_00427037_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_004272a2:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_0042734c;
LAB_00427296:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_0042702b;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_00427037_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_0042702b;
    goto LAB_0042734c;
  }
  iVar9 = 9;
LAB_0042726d:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_0042702b;
LAB_004272cd:
  if (DAT_00432104 < 2) {
    uVar3 = (byte)PTR_DAT_00431ef8[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_00431ef8;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_0041eea6(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_00427317;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_0042730f;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_004272cd;
LAB_0042730f:
  pbVar7 = (byte *)0x1451;
LAB_00427317:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_00432104 < 2) {
      uVar3 = (byte)PTR_DAT_00431ef8[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_00431ef8;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_0041eea6(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_00427347:
  pbVar7 = pbVar8 + -1;
LAB_0042734c:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_0042745a;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_00426f0d(local_60,local_8,(uint *)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + param_5;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -param_6;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_004279b9((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_004273df;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44 = local_3a;
  }
LAB_004273df:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_0042745a:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}



undefined4 __cdecl
FUN_004274a5(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined local_a;
  char cStack_9;
  undefined4 local_8;
  
  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 != 0) || (param_2 != 0)) || (param_1 != 0)) {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_0042759a;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_0042759a:
            pcVar11 = "1#QNAN";
            goto LAB_0042759f;
          }
          pcVar11 = "1#IND";
        }
        FUN_00423540((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_0042759f:
        FUN_00423540((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined *)((int)psVar3 + 3) = 6;
      }
      return 0;
    }
    local_14 = 0;
    local_a = (undefined)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_004279b9((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_00427799((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    iVar10 = param_4;
    if (((param_5 & 1) == 0) || (iVar10 = param_4 + sVar8, 0 < param_4 + sVar8)) {
      if (0x15 < iVar10) {
        iVar10 = 0x15;
      }
      iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
      local_a = 0;
      cStack_9 = '\0';
      param_6 = (short *)0x8;
      do {
        FUN_00426eb2((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_00426ee0((uint *)&local_14);
        }
      }
      param_4 = iVar10 + 1;
      psVar6 = psVar3 + 2;
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      if (0 < param_4) {
        do {
          local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
          local_e._0_2_ = (undefined2)uVar2;
          local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
          local_12._0_2_ = (undefined2)uVar5;
          param_1 = CONCAT22((undefined2)local_12,local_14);
          param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
          local_12 = uVar5;
          local_e = uVar2;
          FUN_00426eb2((uint *)&local_14);
          FUN_00426eb2((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_00426eb2((uint *)&local_14);
          cVar4 = cStack_9;
          cStack_9 = '\0';
          psVar6 = (short *)((int)param_6 + 1);
          param_4 = param_4 + -1;
          *(char *)param_6 = cVar4 + '0';
          param_6 = psVar6;
          uVar5 = local_12;
          uVar2 = local_e;
        } while (param_4 != 0);
      }
      psVar7 = psVar6 + -1;
      psVar1 = psVar3 + 2;
      if ('4' < *(char *)((int)psVar6 + -1)) {
        for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
          if (*(char *)psVar7 != '9') {
            if (psVar1 <= psVar7) goto LAB_004276f7;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_004276f7:
        *(char *)psVar7 = *(char *)psVar7 + '\x01';
LAB_004276f9:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if (*(char *)psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_004276f9;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined *)(psVar3 + 1) = 0x20;
      *(undefined *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_0042772f;
    }
  }
  *psVar3 = 0;
  *(undefined *)(psVar3 + 1) = 0x20;
  *(undefined *)((int)psVar3 + 3) = 1;
  *(undefined *)(psVar3 + 2) = 0x30;
LAB_0042772f:
  *(undefined *)((int)psVar3 + 5) = 0;
  return 1;
}



int __cdecl FUN_00427738(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_00420791();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_00436820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}



void __cdecl FUN_00427799(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_0042783c:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_0042783c;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_00426e33(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_004278f0:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_00426ee0((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_00426eb2((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_004278f0;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_00427999;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_00427999:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}



void __cdecl FUN_004279b9(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  int *piVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  int iStack_8;
  
  puVar3 = &DAT_004328f0;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar3 = (undefined *)0x432a50;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      puVar3 = puVar3 + 0x54;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        piVar4 = (int *)(puVar3 + uVar2 * 0xc);
        if (0x7fff < *(ushort *)(puVar3 + uVar2 * 0xc)) {
          local_10 = (undefined2)*piVar4;
          local_e._0_2_ = (undefined2)((uint)*piVar4 >> 0x10);
          local_e._2_2_ = (undefined2)piVar4[1];
          uStack_a = (undefined2)((uint)piVar4[1] >> 0x10);
          iStack_8 = piVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          piVar4 = (int *)&local_10;
        }
        FUN_00427799(param_1,piVar4);
      }
    }
  }
  return;
}



void FUN_00427a3f(void)

{
  void *this;
  int unaff_EBP;
  
  FUN_00429af8();
  this = (void *)FUN_0041bfd0(0x54);
  *(void **)(unaff_EBP + -0x10) = this;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (this != (void *)0x0) {
    FUN_004286e9(this,2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00427d88();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



void FUN_00427a84(void)

{
  FUN_0042047d(0x427a90);
  return;
}



void FUN_00427ab0(void)

{
  FUN_0042803b(&DAT_00435208,(void *)((int)&DAT_00435210 + *(int *)(DAT_00435210 + 4)),1);
  return;
}



void FUN_00427ad3(void)

{
  FUN_0042047d(0x427adf);
  return;
}



undefined4 __fastcall FUN_00427ae9(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
  }
  iVar1 = *(int *)(*param_1 + 4);
  uVar2 = *(uint *)(iVar1 + 8 + (int)param_1);
  if (uVar2 != 0) {
    *(uint *)((int)param_1 + iVar1 + 8) = uVar2 | 2;
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
      FUN_004282b8((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
    }
    return 0;
  }
  piVar3 = *(int **)((int)param_1 + iVar1 + 0x20);
  if (piVar3 != (int *)0x0) {
    FUN_00427c36(piVar3);
  }
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return 1;
}



void __fastcall FUN_00427b5d(int *param_1)

{
  uint *puVar1;
  int iVar2;
  
  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1) = 0;
  if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0x25) & 0x20) != 0) {
    iVar2 = (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 4) + 4))();
    if (iVar2 == -1) {
      *(undefined4 *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) = 6;
    }
  }
  if ((*(byte *)(*(int *)(*param_1 + 4) + 0x25 + (int)param_1) & 0x40) != 0) {
    iVar2 = FUN_0041f0ff((int *)&DAT_00431c98);
    if (iVar2 == -1) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 2;
    }
    iVar2 = FUN_0041f0ff((int *)&DAT_00431cb8);
    if (iVar2 == -1) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 2;
    }
  }
  iVar2 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar2 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar2 + 0x34));
  }
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
  }
  return;
}



int * __thiscall FUN_00427c0d(void *this,char *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00427ae9((int *)this);
  if (iVar1 != 0) {
    FUN_00427df9(this,"",param_1);
    FUN_00427b5d((int *)this);
  }
  return (int *)this;
}



int * __fastcall FUN_00427c36(int *param_1)

{
  uint *puVar1;
  int iVar2;
  
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
  }
  iVar2 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar2 + 0x30) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(iVar2 + 0x34));
  }
  iVar2 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 4))();
  if (iVar2 == -1) {
    puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
    *puVar1 = *puVar1 | 2;
  }
  iVar2 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar2 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar2 + 0x34));
  }
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
  }
  return param_1;
}



int * FUN_00427ce9(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_0042b734;
    FUN_00428b7f(extraout_ECX + 2);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_0042b730;
  FUN_00428c43((void *)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX),iVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[1] = 0;
  return extraout_ECX;
}



void __fastcall FUN_00427d4e(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -8) + 4) + -8 + param_1) = &PTR_LAB_0042b730;
  return;
}



int * FUN_00427d88(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_0042b744;
    FUN_00428b7f(extraout_ECX + 2);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  FUN_00427ce9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_0042b740;
  return extraout_ECX;
}



void __fastcall FUN_00427de6(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -8) + 4) + -8 + param_1) = &PTR_LAB_0042b740;
  FUN_00427d4e(param_1);
  return;
}



int * __thiscall FUN_00427df9(void *this,char *param_1,char *param_2)

{
  uint *puVar1;
  bool bVar2;
  size_t sVar3;
  size_t sVar4;
  uint uVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  sVar3 = _strlen(param_1);
  sVar4 = _strlen(param_2);
                    // WARNING: Load size is inaccurate
  uVar5 = *(uint *)(*(int *)(*this + 4) + 0x30 + (int)this);
  if (sVar4 + sVar3 < uVar5) {
    local_8 = (uVar5 - sVar4) - sVar3;
  }
  else {
    local_8 = 0;
  }
  if (((*(byte *)((int)this + *(int *)(*this + 4) + 0x24) & 10) == 0) &&
     (iVar8 = local_8 + -1, bVar2 = 0 < local_8, iVar7 = local_8, local_8 = iVar8, bVar2)) {
    do {
                    // WARNING: Load size is inaccurate
      uVar5 = FUN_00427f65(*(void **)((int)this + *(int *)(*this + 4) + 4),
                           (uint)*(byte *)((int)this + *(int *)(*this + 4) + 0x2c));
      if (uVar5 == 0xffffffff) {
                    // WARNING: Load size is inaccurate
        puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
        *puVar1 = *puVar1 | 6;
      }
      iVar7 = iVar7 + -1;
      local_8 = local_8 + -1;
    } while (iVar7 != 0);
  }
                    // WARNING: Load size is inaccurate
  if ((sVar3 != 0) &&
     (sVar6 = (**(code **)(**(int **)(*(int *)(*this + 4) + 4 + (int)this) + 0x14))(param_1,sVar3),
     sVar6 != sVar3)) {
                    // WARNING: Load size is inaccurate
    puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
    *puVar1 = *puVar1 | 6;
  }
                    // WARNING: Load size is inaccurate
  if (((*(byte *)(*(int *)(*this + 4) + 0x24 + (int)this) & 8) != 0) &&
     (iVar7 = local_8 + -1, bVar2 = 0 < local_8, iVar8 = local_8, local_8 = iVar7, bVar2)) {
    do {
                    // WARNING: Load size is inaccurate
      uVar5 = FUN_00427f65(*(void **)((int)this + *(int *)(*this + 4) + 4),
                           (uint)*(byte *)((int)this + *(int *)(*this + 4) + 0x2c));
      if (uVar5 == 0xffffffff) {
                    // WARNING: Load size is inaccurate
        puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
        *puVar1 = *puVar1 | 6;
      }
      iVar8 = iVar8 + -1;
      local_8 = local_8 + -1;
    } while (iVar8 != 0);
  }
                    // WARNING: Load size is inaccurate
  sVar3 = (**(code **)(**(int **)(*(int *)(*this + 4) + 4 + (int)this) + 0x14))(param_2,sVar4);
  if (sVar3 != sVar4) {
                    // WARNING: Load size is inaccurate
    puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
    *puVar1 = *puVar1 | 6;
  }
                    // WARNING: Load size is inaccurate
  if (((*(byte *)(*(int *)(*this + 4) + 0x24 + (int)this) & 2) != 0) && (0 < local_8)) {
    do {
                    // WARNING: Load size is inaccurate
      uVar5 = FUN_00427f65(*(void **)((int)this + *(int *)(*this + 4) + 4),
                           (uint)*(byte *)((int)this + *(int *)(*this + 4) + 0x2c));
      if (uVar5 == 0xffffffff) {
                    // WARNING: Load size is inaccurate
        puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
        *puVar1 = *puVar1 | 6;
      }
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return (int *)this;
}



uint __thiscall FUN_00427f65(void *this,uint param_1)

{
  uint uVar1;
  
  if (*(undefined **)((int)this + 0x1c) < *(undefined **)((int)this + 0x20)) {
    **(undefined **)((int)this + 0x1c) = (undefined)param_1;
    *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
    uVar1 = param_1 & 0xff;
  }
  else {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0x1c))(param_1);
  }
  return uVar1;
}



void FUN_00427f91(void)

{
  void *this;
  int unaff_EBP;
  
  FUN_00429af8();
  this = (void *)FUN_0041bfd0(0x54);
  *(void **)(unaff_EBP + -0x10) = this;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (this != (void *)0x0) {
    FUN_004286e9(this,1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00427d88();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



void FUN_00427fd6(void)

{
  FUN_0042047d(0x427fe2);
  return;
}



void FUN_00428002(void)

{
  FUN_0042803b(&DAT_00435268,(void *)((int)&DAT_00435270 + *(int *)(DAT_00435270 + 4)),-1);
  return;
}



void FUN_00428025(void)

{
  FUN_0042047d(0x428031);
  return;
}



void * __thiscall FUN_0042803b(void *this,void *param_1,int param_2)

{
  *(undefined4 *)((int)param_1 + 0x1c) = 1;
  if ((-1 < param_2) && (*(undefined4 **)((int)param_1 + 0x20) = &DAT_00435270, 0 < param_2)) {
    FUN_00428069(param_1,0x2000);
  }
  return this;
}



uint __thiscall FUN_00428069(void *this,uint param_1)

{
  uint uVar1;
  
  if (*(int *)((int)this + 0x34) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)((int)this + 0x38));
  }
  uVar1 = *(uint *)((int)this + 0x24);
  *(uint *)((int)this + 0x24) = uVar1 | param_1;
  if (*(int *)((int)this + 0x34) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)((int)this + 0x38));
  }
  return uVar1;
}



int * __thiscall FUN_004280a1(void *this,int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = FUN_00428373(this,1);
  if (iVar2 != 0) {
    if (param_2 != 0) {
      if (param_2 != 1) {
        do {
                    // WARNING: Load size is inaccurate
          iVar2 = FUN_0042928e(*(int **)(*(int *)(*this + 4) + 4 + (int)this));
          if (iVar2 == -1) {
                    // WARNING: Load size is inaccurate
            puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
            *puVar1 = *puVar1 | 1;
            if (uVar3 == 0) {
                    // WARNING: Load size is inaccurate
              puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
              *puVar1 = *puVar1 | 2;
            }
            break;
          }
          if (iVar2 == param_3) {
            if (*(int *)((int)this + 4) != 0) {
                    // WARNING: Load size is inaccurate
              *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
              FUN_00429255(*(int **)(*(int *)(*this + 4) + 4 + (int)this));
            }
            break;
          }
          if (param_1 != 0) {
            *(char *)(uVar3 + param_1) = (char)iVar2;
          }
                    // WARNING: Load size is inaccurate
          FUN_00429255(*(int **)(*(int *)(*this + 4) + 4 + (int)this));
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_2 - 1U);
      }
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + uVar3;
    }
    FUN_00428162((int *)this);
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    *(undefined *)(uVar3 + param_1) = 0;
  }
  *(undefined4 *)((int)this + 4) = 0;
  return (int *)this;
}



void __fastcall FUN_00428162(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
  }
  return;
}



int * __thiscall FUN_00428197(void *this,undefined4 param_1)

{
  int iVar1;
  
                    // WARNING: Load size is inaccurate
  iVar1 = *(int *)(*(int *)(*this + 4) + 4 + (int)this);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
                    // WARNING: Load size is inaccurate
  iVar1 = (**(code **)(**(int **)(*(int *)(*this + 4) + 4 + (int)this) + 0x10))(param_1,1);
  if (iVar1 == -1) {
                    // WARNING: Load size is inaccurate
    FUN_004281ff((void *)(*(int *)(*this + 4) + (int)this),
                 *(uint *)(*(int *)(*this + 4) + 8 + (int)this) | 2);
  }
                    // WARNING: Load size is inaccurate
  iVar1 = *(int *)(*(int *)(*this + 4) + 4 + (int)this);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return (int *)this;
}



void __thiscall FUN_004281ff(void *this,undefined4 param_1)

{
  if (*(int *)((int)this + 0x34) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)((int)this + 0x38));
  }
  *(undefined4 *)((int)this + 8) = param_1;
  if (*(int *)((int)this + 0x34) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)((int)this + 0x38));
  }
  return;
}



int __fastcall FUN_0042822d(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar2 + 0x30) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(iVar2 + 0x34));
  }
  iVar2 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0xc))(0,1,1);
  if (iVar2 == -1) {
    FUN_004281ff((void *)(*(int *)(*param_1 + 4) + (int)param_1),
                 *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2);
  }
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return iVar2;
}



void __cdecl FUN_00428297(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  return;
}



void __cdecl FUN_004282a2(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



void __cdecl FUN_004282ad(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return;
}



void __cdecl FUN_004282b8(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return;
}



int * FUN_004282ee(void)

{
  uint *puVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_0042b754;
    FUN_00428b7f(extraout_ECX + 3);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_0042b750;
  FUN_00428c43((void *)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX),iVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  puVar1 = (uint *)(*(int *)(*extraout_ECX + 4) + 0x24 + (int)extraout_ECX);
  *puVar1 = *puVar1 | 1;
  extraout_ECX[2] = 0;
  extraout_ECX[1] = 0;
  return extraout_ECX;
}



void __fastcall FUN_00428364(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0xc) + 4) + -0xc + param_1) = &PTR_LAB_0042b750;
  return;
}



undefined4 __thiscall FUN_00428373(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
                    // WARNING: Load size is inaccurate
  if (*(int *)((int)this + *(int *)(*this + 4) + 0x34) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)((int)this + *(int *)(*this + 4) + 0x38));
  }
  if (param_1 != 0) {
    *(undefined4 *)((int)this + 8) = 0;
  }
                    // WARNING: Load size is inaccurate
  iVar2 = *(int *)(*this + 4);
  uVar1 = *(uint *)(iVar2 + 8 + (int)this);
  if (uVar1 == 0) {
    if (*(int *)((int)this + iVar2 + 0x20) != 0) {
      if (param_1 != 0) {
        iVar2 = FUN_00428454(*(int *)((int)this + iVar2 + 4));
        if (param_1 <= iVar2) goto LAB_004283d5;
      }
                    // WARNING: Load size is inaccurate
      FUN_00427c36(*(int **)(*(int *)(*this + 4) + 0x20 + (int)this));
    }
LAB_004283d5:
                    // WARNING: Load size is inaccurate
    iVar2 = *(int *)(*(int *)(*this + 4) + 4 + (int)this);
    if (*(int *)(iVar2 + 0x30) < 0) {
      FUN_004282ad((LPCRITICAL_SECTION)(iVar2 + 0x34));
    }
                    // WARNING: Load size is inaccurate
    if ((param_1 == 0) && ((*(byte *)(*(int *)(*this + 4) + 0x24 + (int)this) & 1) != 0)) {
      FUN_00428545((int *)this);
                    // WARNING: Load size is inaccurate
      uVar1 = *(uint *)(*(int *)(*this + 4) + 8 + (int)this);
      if (uVar1 != 0) {
        *(uint *)(*(int *)(*this + 4) + 8 + (int)this) = uVar1 | 2;
                    // WARNING: Load size is inaccurate
        iVar2 = *(int *)(*(int *)(*this + 4) + 4 + (int)this);
        if (*(int *)(iVar2 + 0x30) < 0) {
          FUN_004282b8((LPCRITICAL_SECTION)(iVar2 + 0x34));
        }
        goto LAB_00428431;
      }
    }
    uVar3 = 1;
  }
  else {
    *(uint *)((int)this + iVar2 + 8) = uVar1 | 2;
LAB_00428431:
                    // WARNING: Load size is inaccurate
    if (*(int *)((int)this + *(int *)(*this + 4) + 0x34) < 0) {
      FUN_004282b8((LPCRITICAL_SECTION)((int)this + *(int *)(*this + 4) + 0x38));
    }
    uVar3 = 0;
  }
  return uVar3;
}



int __fastcall FUN_00428454(int param_1)

{
  if (*(uint *)(param_1 + 0x28) < *(uint *)(param_1 + 0x2c)) {
    return *(uint *)(param_1 + 0x2c) - *(uint *)(param_1 + 0x28);
  }
  return 0;
}



int * __thiscall FUN_00428464(void *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *this_00;
  uint uVar5;
  undefined local_8;
  
  uVar5 = 0;
  iVar2 = FUN_00428373(this,0);
  if (iVar2 == 0) {
    return (int *)this;
  }
                    // WARNING: Load size is inaccurate
  iVar2 = *(int *)(*(int *)(*this + 4) + 0x30 + (int)this);
  *(undefined4 *)(*(int *)(*this + 4) + 0x30 + (int)this) = 0;
  if ((param_1 != 0) && (iVar2 != 1)) {
    do {
                    // WARNING: Load size is inaccurate
      iVar3 = FUN_0042928e(*(int **)(*(int *)(*this + 4) + 4 + (int)this));
      if (iVar3 == -1) {
                    // WARNING: Load size is inaccurate
        puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
        *puVar1 = *puVar1 | 1;
        if (uVar5 != 0) goto LAB_00428509;
                    // WARNING: Load size is inaccurate
        puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
        *puVar1 = *puVar1 | 6;
        break;
      }
      uVar4 = FUN_00420347(this_00,iVar3);
      if (uVar4 != 0) break;
      local_8 = (undefined)iVar3;
      *(undefined *)(uVar5 + param_1) = local_8;
                    // WARNING: Load size is inaccurate
      FUN_00429255(*(int **)(*(int *)(*this + 4) + 4 + (int)this));
      uVar5 = uVar5 + 1;
    } while (uVar5 < iVar2 - 1U);
    if (uVar5 != 0) {
LAB_00428509:
      *(undefined *)(uVar5 + param_1) = 0;
      goto LAB_00428510;
    }
  }
                    // WARNING: Load size is inaccurate
  puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
  *puVar1 = *puVar1 | 2;
LAB_00428510:
  FUN_00428162((int *)this);
  return (int *)this;
}



int __thiscall FUN_00428520(void *this,char param_1)

{
  char *pcVar1;
  int iVar2;
  
  if (*(uint *)((int)this + 0x24) < *(uint *)((int)this + 0x28)) {
    pcVar1 = (char *)(*(uint *)((int)this + 0x28) - 1);
    *(char **)((int)this + 0x28) = pcVar1;
    *pcVar1 = param_1;
    iVar2 = (int)param_1;
  }
  else {
                    // WARNING: Load size is inaccurate
    iVar2 = (**(code **)(*this + 0x24))((int)param_1);
  }
  return iVar2;
}



void __fastcall FUN_00428545(int *param_1)

{
  int iVar1;
  uint uVar2;
  void *extraout_ECX;
  void *this;
  void *extraout_ECX_00;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  uVar2 = FUN_0042928e(*(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
  this = extraout_ECX;
  while (uVar2 != 0xffffffff) {
    uVar2 = FUN_00420347(this,uVar2);
    if (uVar2 == 0) goto LAB_004285a3;
    uVar2 = FUN_00429209(*(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
    this = extraout_ECX_00;
  }
  FUN_004281ff((void *)(*(int *)(*param_1 + 4) + (int)param_1),
               *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 1);
LAB_004285a3:
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return;
}



int * FUN_004285e9(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *extraout_ECX = (int)&DAT_0042b764;
    FUN_00428b7f(extraout_ECX + 3);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  puVar4 = (undefined4 *)FUN_0041bfd0(0x54);
  *(undefined4 **)(unaff_EBP + 0x14) = puVar4;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar4 != (undefined4 *)0x0) {
    FUN_004286b3(puVar4);
  }
  *(undefined *)(unaff_EBP + -4) = 0;
  FUN_004282ee();
  iVar2 = *(int *)(*extraout_ECX + 4);
  uVar3 = *(uint *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined ***)(iVar2 + (int)extraout_ECX) = &PTR_LAB_0042b760;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  piVar5 = FUN_004292b3(*(void **)(*(int *)(*extraout_ECX + 4) + 4 + (int)extraout_ECX),
                        *(LPCSTR *)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc) | 1,uVar3);
  if (piVar5 == (int *)0x0) {
    puVar1 = (uint *)(*(int *)(*extraout_ECX + 4) + 8 + (int)extraout_ECX);
    *puVar1 = *puVar1 | 2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



void __fastcall FUN_004286a0(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0xc) + 4) + -0xc + param_1) = &PTR_LAB_0042b760;
  FUN_00428364(param_1);
  return;
}



undefined4 * __fastcall FUN_004286b3(undefined4 *param_1)

{
  FUN_00429429(param_1);
  param_1[0x14] = 0;
  param_1[0x13] = 0xffffffff;
  *param_1 = &PTR_FUN_0042b788;
  return param_1;
}



int __thiscall FUN_004286cd(void *this,byte param_1)

{
  FUN_00428708();
  if ((param_1 & 1) != 0) {
    FUN_0041bfc0((int)this);
  }
  return (int)this;
}



undefined4 * __thiscall FUN_004286e9(void *this,undefined4 param_1)

{
  FUN_00429429((undefined4 *)this);
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x4c) = param_1;
  *(undefined ***)this = &PTR_FUN_0042b788;
  return (undefined4 *)this;
}



void FUN_00428708(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_FUN_0042b788;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[0xc] < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(extraout_ECX + 0xd));
  }
  if (extraout_ECX[0x14] == 0) {
    FUN_00428907((int)extraout_ECX);
  }
  else {
    FUN_0042875f(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00429484(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



int * __fastcall FUN_0042875f(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x13] != -1) {
    if (param_1[0xc] < 0) {
      FUN_004282ad((LPCRITICAL_SECTION)(param_1 + 0xd));
    }
    iVar1 = (**(code **)(*param_1 + 4))();
    iVar2 = FUN_00421378(param_1[0x13]);
    if ((iVar2 != -1) && (iVar1 != -1)) {
      param_1[0x13] = -1;
      if (-1 < param_1[0xc]) {
        return param_1;
      }
      FUN_004282b8((LPCRITICAL_SECTION)(param_1 + 0xd));
      return param_1;
    }
    if (param_1[0xc] < 0) {
      FUN_004282b8((LPCRITICAL_SECTION)(param_1 + 0xd));
    }
  }
  return (int *)0x0;
}



undefined4 __thiscall FUN_004287c2(void *this,uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_004295ec((int *)this);
  if ((iVar1 != -1) && (iVar1 = FUN_00428907((int)this), iVar1 != -1)) {
    if (*(int *)((int)this + 8) == 0) {
      *(undefined4 *)((int)this + 0x18) = *(undefined4 *)((int)this + 0x10);
      *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x10);
      *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x14);
    }
    if (param_1 != 0xffffffff) {
      if ((*(int *)((int)this + 8) == 0) &&
         (*(uint *)((int)this + 0x1c) < *(uint *)((int)this + 0x20))) {
        FUN_00427f65(this,param_1);
      }
      else {
        iVar1 = FUN_00422eaa(*(uint *)((int)this + 0x4c),(char *)&param_1,1);
        if (iVar1 != 1) {
          return 0xffffffff;
        }
      }
    }
    return 1;
  }
  return 0xffffffff;
}



uint __fastcall FUN_00428833(int *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  iVar3 = FUN_00428454((int)param_1);
  if (iVar3 != 0) {
    return (uint)*(byte *)param_1[10];
  }
  iVar3 = FUN_004295ec(param_1);
  if ((iVar3 != -1) && (iVar3 = FUN_00428907((int)param_1), iVar3 != -1)) {
    if (param_1[2] == 0) {
      pcVar1 = (char *)param_1[4];
      if (pcVar1 < (char *)param_1[5]) {
        pcVar4 = (char *)param_1[5] + -(int)pcVar1;
      }
      else {
        pcVar4 = (char *)0x0;
      }
      iVar3 = FUN_00425605(param_1[0x13],pcVar1,pcVar4);
      if (0 < iVar3) {
        pbVar2 = (byte *)param_1[4];
        param_1[3] = -1;
        param_1[9] = (int)pbVar2;
        param_1[10] = (int)pbVar2;
        param_1[0xb] = (int)(pbVar2 + iVar3);
        return (uint)*pbVar2;
      }
    }
    else {
      iVar3 = FUN_00425605(param_1[0x13],(char *)((int)&uStack_8 + 3),(char *)0x1);
      if (0 < iVar3) {
        return (uint)uStack_8 >> 0x18;
      }
    }
  }
  return 0xffffffff;
}



undefined4 __fastcall FUN_00428907(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  DWORD DVar4;
  char *pcVar5;
  uint uVar6;
  
  if (*(uint *)(param_1 + 0x4c) == 0xffffffff) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 8) == 0) {
    pcVar5 = *(char **)(param_1 + 0x18);
    if (*(char **)(param_1 + 0x1c) < pcVar5) {
      uVar6 = 0;
    }
    else {
      uVar6 = (int)*(char **)(param_1 + 0x1c) - (int)pcVar5;
    }
    if ((uVar6 != 0) &&
       (uVar2 = FUN_00422eaa(*(uint *)(param_1 + 0x4c),pcVar5,uVar6), uVar2 != uVar6)) {
      if (0 < (int)uVar2) {
        if (*(int *)(param_1 + 0x20) != 0) {
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - uVar2;
        }
        FUN_00426800(*(undefined4 **)(param_1 + 0x18),
                     (undefined4 *)(uVar2 + (int)*(undefined4 **)(param_1 + 0x18)),uVar6 - uVar2);
      }
      return 0xffffffff;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar3 = FUN_00428454(param_1);
    if (0 < iVar3) {
      uVar6 = *(uint *)(param_1 + 0x4c);
      bVar1 = *(byte *)((&DAT_00436820)[(int)uVar6 >> 5] + 4 + (uVar6 & 0x1f) * 0x24);
      if ((bVar1 & 0x80) != 0) {
        for (pcVar5 = *(char **)(param_1 + 0x28); pcVar5 < *(char **)(param_1 + 0x2c);
            pcVar5 = pcVar5 + 1) {
          if (*pcVar5 == '\n') {
            iVar3 = iVar3 + 1;
          }
        }
        if ((bVar1 & 2) != 0) {
          iVar3 = iVar3 + 1;
        }
      }
      DVar4 = FUN_00425355(uVar6,-iVar3,1);
      if (DVar4 == 0xffffffff) {
        return 0xffffffff;
      }
    }
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return 0;
}



void * __thiscall FUN_004289e2(void *this,int param_1,int param_2)

{
  if ((*(int *)((int)this + 0x4c) == -1) || (*(int *)((int)this + 0x14) == 0)) {
    if ((param_1 == 0) || (param_2 < 1)) {
      *(undefined4 *)((int)this + 8) = 1;
    }
    else {
      if (*(int *)((int)this + 0x30) < 0) {
        FUN_004282ad((LPCRITICAL_SECTION)((int)this + 0x34));
      }
      FUN_00429637(this,param_1,param_1 + param_2,0);
      if (*(int *)((int)this + 0x30) < 0) {
        FUN_004282b8((LPCRITICAL_SECTION)((int)this + 0x34));
      }
    }
  }
  else {
    this = (void *)0x0;
  }
  return this;
}



int * FUN_00428a46(void)

{
  undefined4 *puVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    *extraout_ECX = (int)&DAT_0042b7bc;
    FUN_00428b7f(extraout_ECX + 2);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  puVar1 = (undefined4 *)FUN_0041bfd0(0x54);
  *(undefined4 **)(unaff_EBP + 8) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004286b3(puVar1);
  }
  *(undefined *)(unaff_EBP + -4) = 0;
  FUN_00427ce9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_0042b7b8;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  return extraout_ECX;
}



void __fastcall FUN_00428af7(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -8) + 4) + -8 + param_1) = &PTR_LAB_0042b7b8;
  FUN_00427d4e(param_1);
  return;
}



void __thiscall FUN_00428b0a(void *this,LPCSTR param_1,uint param_2,uint param_3)

{
  void *this_00;
  int *piVar1;
  
                    // WARNING: Load size is inaccurate
  this_00 = *(void **)(*(int *)(*this + 4) + 4 + (int)this);
  if ((*(int *)((int)this_00 + 0x4c) == -1) &&
     (piVar1 = FUN_004292b3(this_00,param_1,param_2 | 2,param_3), piVar1 != (int *)0x0)) {
    return;
  }
                    // WARNING: Load size is inaccurate
  FUN_004281ff((void *)(*(int *)(*this + 4) + (int)this),
               *(uint *)(*(int *)(*this + 4) + 8 + (int)this) | 2);
  return;
}



void __fastcall FUN_00428b4c(int *param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = FUN_0042875f(*(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
  if (piVar1 == (int *)0x0) {
    uVar2 = *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2;
  }
  else {
    uVar2 = 0;
  }
  FUN_004281ff((void *)(*(int *)(*param_1 + 4) + (int)param_1),uVar2);
  return;
}



undefined4 * __fastcall FUN_00428b7f(undefined4 *param_1)

{
  int iVar1;
  
  param_1[0xd] = 0xffffffff;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[7] = 0;
  *param_1 = &PTR_FUN_0042b7d4;
  param_1[2] = 4;
  param_1[10] = 6;
  *(undefined *)(param_1 + 0xb) = 0x20;
  FUN_00428297((LPCRITICAL_SECTION)(param_1 + 0xe));
  iVar1 = DAT_00435300;
  DAT_00435300 = DAT_00435300 + 1;
  if (iVar1 == 0) {
    FUN_00428297((LPCRITICAL_SECTION)&DAT_004352c8);
  }
  return param_1;
}



undefined4 * __thiscall FUN_00428bdd(void *this,byte param_1)

{
  FUN_00428bf9((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_0041bfc0((int)this);
  }
  return (undefined4 *)this;
}



void __fastcall FUN_00428bf9(undefined4 *param_1)

{
  param_1[0xd] = 0xffffffff;
  *param_1 = &PTR_FUN_0042b7d4;
  DAT_00435300 = DAT_00435300 + -1;
  if (DAT_00435300 == 0) {
    FUN_004282a2((LPCRITICAL_SECTION)&DAT_004352c8);
  }
  FUN_004282a2((LPCRITICAL_SECTION)(param_1 + 0xe));
  if ((param_1[7] != 0) && ((undefined4 *)param_1[1] != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  param_1[1] = 0;
  param_1[2] = 4;
  return;
}



void __thiscall FUN_00428c43(void *this,int param_1)

{
  if ((*(int *)((int)this + 0x1c) != 0) && (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)((int)this + 4))(1);
  }
  *(int *)((int)this + 4) = param_1;
  if (param_1 == 0) {
    *(uint *)((int)this + 8) = *(uint *)((int)this + 8) | 4;
  }
  else {
    *(uint *)((int)this + 8) = *(uint *)((int)this + 8) & 0xfffffffb;
  }
  return;
}



undefined4 * __fastcall FUN_00428c72(undefined4 *param_1)

{
  FUN_00429429(param_1);
  *param_1 = &PTR_FUN_0042b7dc;
  param_1[0x13] = 1;
  param_1[0x14] = 1;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  return param_1;
}



int __thiscall FUN_00428c98(void *this,byte param_1)

{
  FUN_00428cb4();
  if ((param_1 & 1) != 0) {
    FUN_0041bfc0((int)this);
  }
  return (int)this;
}



void FUN_00428cb4(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0042b7dc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((extraout_ECX[0x13] != 0) && (extraout_ECX[4] != 0)) {
    if ((code *)extraout_ECX[0x18] == (code *)0x0) {
      FUN_0041bfc0(extraout_ECX[4]);
    }
    else {
      (*(code *)extraout_ECX[0x18])();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00429484(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



undefined4 __fastcall FUN_00428d06(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c) = 0;
  return *(undefined4 *)(param_1 + 0x10);
}



undefined4 __fastcall FUN_00428d0e(void *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_8;
  
  local_8 = *(int *)((int)param_1 + 0x50);
  iVar10 = 1;
  if (1 < local_8) {
    iVar10 = local_8;
  }
  uVar8 = *(uint *)((int)param_1 + 0x14);
  uVar1 = *(uint *)((int)param_1 + 0x10);
  if (uVar1 < uVar8) {
    iVar4 = uVar8 - uVar1;
  }
  else {
    iVar4 = 0;
  }
  if (local_8 <= iVar4 + iVar10) {
    if (local_8 < 2) {
      local_8 = 1;
    }
    if (uVar1 < uVar8) {
      iVar10 = uVar8 - uVar1;
    }
    else {
      iVar10 = 0;
    }
    local_8 = iVar10 + local_8;
  }
  iVar10 = 0;
  if (*(code **)((int)param_1 + 0x5c) == (code *)0x0) {
    puVar5 = (undefined4 *)FUN_0041bfd0(local_8);
  }
  else {
    puVar5 = (undefined4 *)(**(code **)((int)param_1 + 0x5c))();
  }
  if (puVar5 == (undefined4 *)0x0) {
    uVar6 = 0xffffffff;
  }
  else {
    puVar2 = *(undefined4 **)((int)param_1 + 0x14);
    puVar7 = *(undefined4 **)((int)param_1 + 0x10);
    if (puVar7 < puVar2) {
      iVar4 = (int)puVar2 - (int)puVar7;
    }
    else {
      iVar4 = 0;
    }
    if (iVar4 != 0) {
      if (puVar7 < puVar2) {
        uVar8 = (int)puVar2 - (int)puVar7;
      }
      else {
        uVar8 = 0;
      }
      FUN_00423630(puVar5,puVar7,uVar8);
      puVar7 = *(undefined4 **)((int)param_1 + 0x10);
      iVar10 = (int)puVar5 - (int)puVar7;
    }
    if (*(code **)((int)param_1 + 0x60) == (code *)0x0) {
      FUN_0041bfc0((int)puVar7);
    }
    else {
      (**(code **)((int)param_1 + 0x60))();
    }
    FUN_00429637(param_1,puVar5,local_8 + (int)puVar5,0);
    if ((iVar10 != 0) && (*(int *)((int)param_1 + 0x2c) != 0)) {
      *(int *)((int)param_1 + 0x24) = *(int *)((int)param_1 + 0x24) + iVar10;
      *(int *)((int)param_1 + 0x28) = *(int *)((int)param_1 + 0x28) + iVar10;
      *(undefined4 *)((int)param_1 + 0xc) = 0xffffffff;
      *(int *)((int)param_1 + 0x2c) = *(int *)((int)param_1 + 0x2c) + iVar10;
    }
    if (*(int *)((int)param_1 + 0x20) != 0) {
      iVar4 = *(int *)((int)param_1 + 0x18);
      iVar3 = *(int *)((int)param_1 + 0x1c);
      iVar9 = *(int *)((int)param_1 + 0x20) + iVar10;
      iVar10 = iVar4 + iVar10;
      *(int *)((int)param_1 + 0x20) = iVar9;
      *(int *)((int)param_1 + 0x18) = iVar10;
      *(int *)((int)param_1 + 0x1c) = iVar10;
      if (iVar9 != 0) {
        *(int *)((int)param_1 + 0x1c) = (iVar10 - iVar4) + iVar3;
      }
    }
    uVar6 = 1;
  }
  return uVar6;
}



undefined4 __thiscall FUN_00428e27(void *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(uint *)((int)this + 0x1c) < *(uint *)((int)this + 0x20)) {
LAB_00428e80:
    if ((param_1 != -1) &&
       (**(undefined **)((int)this + 0x1c) = (char)param_1, *(int *)((int)this + 0x20) != 0)) {
      *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
    }
    uVar2 = 1;
  }
  else {
    if (*(int *)((int)this + 0x4c) != 0) {
      iVar1 = FUN_00428d0e(this);
      if (iVar1 != -1) {
        if (*(int *)((int)this + 0x20) == 0) {
          iVar1 = (*(int *)((int)this + 0x2c) - *(int *)((int)this + 0x24)) +
                  *(int *)((int)this + 0x10);
          *(int *)((int)this + 0x18) = iVar1;
          *(int *)((int)this + 0x1c) = iVar1;
          *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x14);
        }
        else {
          uVar2 = *(undefined4 *)((int)this + 0x1c);
          *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x18);
          *(int *)((int)this + 0x20) = *(int *)((int)this + 0x14);
          if (*(int *)((int)this + 0x14) != 0) {
            *(undefined4 *)((int)this + 0x1c) = uVar2;
          }
        }
        goto LAB_00428e80;
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



uint __fastcall FUN_00428e9e(int param_1)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x28);
  if (*(byte **)(param_1 + 0x2c) <= pbVar2) {
    if (*(byte **)(param_1 + 0x2c) < *(byte **)(param_1 + 0x1c)) {
      iVar1 = *(int *)(param_1 + 0x24);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x10);
      *(byte **)(param_1 + 0x2c) = *(byte **)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
      *(byte **)(param_1 + 0x28) = pbVar2 + (*(int *)(param_1 + 0x10) - iVar1);
    }
    pbVar2 = *(byte **)(param_1 + 0x28);
    if (*(byte **)(param_1 + 0x2c) <= pbVar2) {
      return 0xffffffff;
    }
  }
  return (uint)*pbVar2;
}



int __thiscall FUN_00428ede(void *this,int param_1,int param_2,byte param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -1;
  if ((param_3 & 1) != 0) {
    FUN_00428e9e((int)this);
    if (param_2 == 0) {
      iVar3 = *(int *)((int)this + 0x24);
    }
    else if (param_2 == 1) {
      iVar3 = *(int *)((int)this + 0x28);
    }
    else {
      if (param_2 != 2) {
        return -1;
      }
      iVar3 = *(int *)((int)this + 0x2c);
    }
    uVar1 = iVar3 + param_1;
    iVar3 = uVar1 - *(uint *)((int)this + 0x24);
    if (uVar1 < *(uint *)((int)this + 0x24)) {
      return -1;
    }
    if (*(uint *)((int)this + 0x2c) < uVar1) {
      return -1;
    }
    if (*(uint *)((int)this + 0x2c) != 0) {
      *(uint *)((int)this + 0x28) = uVar1;
    }
  }
  if ((param_3 & 2) == 0) {
    return iVar3;
  }
  if ((*(int *)((int)this + 0x20) == 0) && (iVar3 = FUN_00428e27(this,-1), iVar3 == -1)) {
    return -1;
  }
  if (param_2 == 0) {
    iVar3 = *(int *)((int)this + 0x18);
  }
  else if (param_2 == 1) {
    iVar3 = *(int *)((int)this + 0x1c);
  }
  else {
    if (param_2 != 2) {
      return -1;
    }
    iVar3 = *(int *)((int)this + 0x20);
  }
  uVar1 = iVar3 + param_1;
  iVar3 = uVar1 - *(uint *)((int)this + 0x18);
  if (*(uint *)((int)this + 0x18) <= uVar1) {
    if (uVar1 <= *(uint *)((int)this + 0x20)) {
LAB_00428f9a:
      if (*(int *)((int)this + 0x20) != 0) {
        *(uint *)((int)this + 0x1c) = uVar1;
        return iVar3;
      }
      return iVar3;
    }
    if (*(int *)((int)this + 0x4c) != 0) {
      iVar2 = *(int *)((int)this + 0x50);
      if (*(int *)((int)this + 0x50) <= iVar3) {
        iVar2 = iVar3;
      }
      *(int *)((int)this + 0x50) = iVar2;
      iVar2 = FUN_00428d0e(this);
      if (iVar2 != -1) goto LAB_00428f9a;
    }
  }
  return -1;
}



int * FUN_00428fac(void)

{
  undefined4 *puVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00429af8();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    *extraout_ECX = (int)&DAT_0042b810;
    FUN_00428b7f(extraout_ECX + 2);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  puVar1 = (undefined4 *)FUN_0041bfd0(100);
  *(undefined4 **)(unaff_EBP + 8) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00428c72(puVar1);
  }
  *(undefined *)(unaff_EBP + -4) = 0;
  FUN_00427ce9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_0042b80c;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  return extraout_ECX;
}



void __fastcall FUN_0042905d(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -8) + 4) + -8 + param_1) = &PTR_LAB_0042b80c;
  FUN_00427d4e(param_1);
  return;
}



int * __thiscall FUN_00429070(void *this,uint param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_00427ae9((int *)this);
  if (iVar2 != 0) {
                    // WARNING: Load size is inaccurate
    if (*(int *)((int)this + *(int *)(*this + 4) + 0x30) == 0) {
      uVar4 = param_1 & 0xff;
      uVar3 = FUN_00427f65(*(void **)((int)this + *(int *)(*this + 4) + 4),uVar4);
      if (uVar3 == 0xffffffff) {
                    // WARNING: Load size is inaccurate
        iVar2 = (**(code **)(**(int **)(*(int *)(*this + 4) + 4 + (int)this) + 0x1c))(uVar4);
        if (iVar2 == -1) {
                    // WARNING: Load size is inaccurate
          puVar1 = (uint *)(*(int *)(*this + 4) + 8 + (int)this);
          *puVar1 = *puVar1 | 6;
        }
      }
    }
    else {
      param_1 = (uint)CONCAT12((undefined)param_1,(short)param_1);
      FUN_00427df9(this,"",(char *)((int)&param_1 + 2));
    }
    FUN_00427b5d((int *)this);
  }
  return (int *)this;
}



int * __thiscall FUN_004290ec(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
                    // WARNING: Load size is inaccurate
  iVar1 = *(int *)(*(int *)(*this + 4) + 4 + (int)this);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282ad((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
                    // WARNING: Load size is inaccurate
  iVar1 = (**(code **)(**(int **)(*(int *)(*this + 4) + 4 + (int)this) + 0xc))(param_1,param_2,2);
  if (iVar1 == -1) {
                    // WARNING: Load size is inaccurate
    FUN_004281ff((void *)(*(int *)(*this + 4) + (int)this),
                 *(uint *)(*(int *)(*this + 4) + 8 + (int)this) | 2);
  }
                    // WARNING: Load size is inaccurate
  iVar1 = *(int *)(*(int *)(*this + 4) + 4 + (int)this);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_004282b8((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return (int *)this;
}



int * __thiscall FUN_00429158(void *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  char local_18 [12];
  undefined2 local_c;
  undefined uStack_a;
  undefined local_9;
  ushort local_8;
  undefined uStack_6;
  undefined local_5;
  
  local_c = 0x6425;
  uStack_a = 0;
  local_9 = 0;
  local_8 = 0;
  uStack_6 = 0;
  local_5 = 0;
  iVar3 = FUN_00427ae9((int *)this);
  if (iVar3 != 0) {
    if (param_1 != 0) {
                    // WARNING: Load size is inaccurate
      uVar1 = *(uint *)((int)this + *(int *)(*this + 4) + 0x24);
      if ((uVar1 & 0x60) == 0) {
        if ((0 < param_1) && ((uVar1 & 0x400) != 0)) {
          local_8 = CONCAT11(local_8._1_1_,0x2b);
        }
      }
      else {
        if ((uVar1 & 0x40) == 0) {
          local_c = CONCAT11(0x6f,(byte)local_c);
        }
        else {
          bVar2 = ~(byte)(uVar1 >> 4);
          local_c = CONCAT11(bVar2,(byte)local_c) & 0x20ff | 0x5800;
          local_8 = CONCAT11(bVar2,(undefined)local_8) & 0x20ff | 0x5800;
        }
        if ((*(byte *)((int)this + *(int *)(*this + 4) + 0x24) & 0x80) != 0) {
          local_8 = CONCAT11(local_8._1_1_,0x30);
        }
      }
    }
    FUN_0041ec4a(local_18,(byte *)&local_c);
    FUN_00427df9(this,(char *)&local_8,local_18);
    FUN_00427b5d((int *)this);
  }
  return (int *)this;
}



uint __fastcall FUN_00429209(int *param_1)

{
  uint uVar1;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      (**(code **)(*param_1 + 0x20))();
    }
    uVar1 = (**(code **)(*param_1 + 0x20))();
    param_1[3] = uVar1;
    return uVar1;
  }
  if ((param_1[0xb] == 0) || ((uint)param_1[0xb] <= (uint)param_1[10])) {
    (**(code **)(*param_1 + 0x20))();
  }
  param_1[10] = param_1[10] + 1;
  if ((byte *)param_1[10] < (byte *)param_1[0xb]) {
    return (uint)*(byte *)param_1[10];
  }
  uVar1 = (**(code **)(*param_1 + 0x20))();
  return uVar1;
}



void __fastcall FUN_00429255(int *param_1)

{
  if (param_1[2] == 0) {
    if ((uint)param_1[0xb] <= (uint)param_1[10]) {
      (**(code **)(*param_1 + 0x20))();
    }
    if ((uint)param_1[10] < (uint)param_1[0xb]) {
      param_1[10] = param_1[10] + 1;
    }
    return;
  }
  if (param_1[3] == -1) {
    (**(code **)(*param_1 + 0x20))();
    return;
  }
  param_1[3] = -1;
  return;
}



int __fastcall FUN_0042928e(int *param_1)

{
  int iVar1;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      iVar1 = (**(code **)(*param_1 + 0x20))();
      param_1[3] = iVar1;
    }
    return param_1[3];
  }
  iVar1 = (**(code **)(*param_1 + 0x20))();
  return iVar1;
}



int * __thiscall FUN_004292b3(void *this,LPCSTR param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)((int)this + 0x4c) == -1) {
    uVar3 = (-(uint)((param_2 & 0x80) != 0) & 0x4000) + 0x4000;
    if ((param_2 & 0x20) == 0) {
      uVar3 = uVar3 | 0x100;
    }
    uVar4 = 0x40;
    if ((param_2 & 0x40) != 0) {
      uVar3 = uVar3 | 0x400;
    }
    if ((param_2 & 8) != 0) {
      param_2 = param_2 | 2;
      uVar3 = uVar3 | 8;
    }
    if ((param_2 & 0x10) != 0) {
      param_2 = param_2 | 2;
      uVar3 = uVar3 | 0x200;
    }
    if ((param_2 & 2) == 0) {
      if ((param_2 & 1) == 0) {
        return (int *)0x0;
      }
    }
    else {
      if ((param_2 & 1) == 0) {
        uVar3 = uVar3 | 1;
      }
      else {
        uVar3 = uVar3 | 2;
      }
      if ((param_2 & 0x4d) == 0) {
        param_2 = param_2 | 0x10;
        uVar3 = uVar3 | 0x200;
      }
    }
    uVar2 = param_3 & 0xe00;
    if (uVar2 != 0) {
      if (uVar2 == 0x800) {
        uVar4 = 0x10;
      }
      else if (uVar2 == 0xa00) {
        uVar4 = 0x20;
      }
      else if (uVar2 == 0xc00) {
        uVar4 = 0x30;
      }
      else if (uVar2 == 0xe00) {
        uVar4 = 0x40;
      }
    }
    uVar3 = FUN_00425086(param_1,uVar3,uVar4,0x180);
    *(uint *)((int)this + 0x4c) = uVar3;
    if (uVar3 != 0xffffffff) {
      if (*(int *)((int)this + 0x30) < 0) {
        FUN_004282ad((LPCRITICAL_SECTION)((int)this + 0x34));
      }
      *(undefined4 *)((int)this + 0x50) = 1;
      if ((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 0x14) == 0)) {
        iVar1 = FUN_0041bfd0(0x200);
        if (iVar1 == 0) {
          *(undefined4 *)((int)this + 8) = 1;
        }
        else {
          FUN_00429637(this,iVar1,iVar1 + 0x200,1);
        }
      }
                    // WARNING: Load size is inaccurate
      if (((param_2 & 4) == 0) || (iVar1 = (**(code **)(*this + 0xc))(0,2,param_2), iVar1 != -1)) {
        if (*(int *)((int)this + 0x30) < 0) {
          FUN_004282b8((LPCRITICAL_SECTION)((int)this + 0x34));
          return (int *)this;
        }
        return (int *)this;
      }
      FUN_0042875f((int *)this);
      if (*(int *)((int)this + 0x30) < 0) {
        FUN_004282b8((LPCRITICAL_SECTION)((int)this + 0x34));
      }
    }
  }
  return (int *)0x0;
}



undefined4 * __fastcall FUN_00429429(undefined4 *param_1)

{
  param_1[3] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *param_1 = &PTR_FUN_0042b824;
  FUN_00428297((LPCRITICAL_SECTION)(param_1 + 0xd));
  return param_1;
}



undefined4 * __thiscall FUN_00429468(void *this,byte param_1)

{
  FUN_00429484((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_0041bfc0((int)this);
  }
  return (undefined4 *)this;
}



void __fastcall FUN_00429484(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0042b824;
  FUN_004282a2((LPCRITICAL_SECTION)(param_1 + 0xd));
  FUN_004295d5((int)param_1);
  if ((param_1[1] != 0) && (param_1[4] != 0)) {
    FUN_0041bfc0(param_1[4]);
  }
  return;
}



int __thiscall FUN_004294e8(void *this,undefined *param_1,int param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      if ((*(int *)((int)this + 8) == 0) &&
         (*(undefined **)((int)this + 0x1c) < *(undefined **)((int)this + 0x20))) {
        **(undefined **)((int)this + 0x1c) = *param_1;
        *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
      }
      else {
                    // WARNING: Load size is inaccurate
        iVar1 = (**(code **)(*this + 0x1c))(*param_1);
        if (iVar1 == -1) {
          return local_8;
        }
      }
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
    } while (param_2 != 0);
  }
  return local_8;
}



int __thiscall FUN_0042953e(void *this,undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  local_8 = 0;
  if (*(int *)((int)this + 8) == 0) {
                    // WARNING: Load size is inaccurate
    while ((param_2 != 0 && (iVar2 = (**(code **)(*this + 0x20))(), iVar2 != -1))) {
      uVar3 = *(int *)((int)this + 0x2c) - (int)*(undefined4 **)((int)this + 0x28);
      if ((int)param_2 <= (int)uVar3) {
        uVar3 = param_2;
      }
      if (0 < (int)uVar3) {
        FUN_00423630(param_1,*(undefined4 **)((int)this + 0x28),uVar3);
        param_1 = (undefined4 *)((int)param_1 + uVar3);
        *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + uVar3;
        local_8 = local_8 + uVar3;
        param_2 = param_2 - uVar3;
      }
    }
  }
  else {
    if (*(int *)((int)this + 0xc) == -1) {
                    // WARNING: Load size is inaccurate
      uVar1 = (**(code **)(*this + 0x20))();
      *(undefined4 *)((int)this + 0xc) = uVar1;
    }
    if (param_2 != 0) {
      do {
        param_2 = param_2 - 1;
        if (*(int *)((int)this + 0xc) == -1) {
          return local_8;
        }
        *(undefined *)param_1 = *(undefined *)((int)this + 0xc);
                    // WARNING: Load size is inaccurate
        param_1 = (undefined4 *)((int)param_1 + 1);
        local_8 = local_8 + 1;
        uVar1 = (**(code **)(*this + 0x20))();
        *(undefined4 *)((int)this + 0xc) = uVar1;
      } while (param_2 != 0);
    }
  }
  return local_8;
}



undefined4 __fastcall FUN_004295d5(int param_1)

{
  if ((*(uint *)(param_1 + 0x2c) <= *(uint *)(param_1 + 0x28)) &&
     (*(uint *)(param_1 + 0x1c) <= *(uint *)(param_1 + 0x18))) {
    return 0;
  }
  return 0xffffffff;
}



int __fastcall FUN_004295ec(int *param_1)

{
  int iVar1;
  
  if ((param_1[2] == 0) && (param_1[4] == 0)) {
    iVar1 = (**(code **)(*param_1 + 0x28))();
    return (-(uint)(iVar1 != -1) & 2) - 1;
  }
  return 0;
}



undefined4 __fastcall FUN_0042960a(void *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0041bfd0(0x200);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  FUN_00429637(param_1,iVar1,iVar1 + 0x200,1);
  return 1;
}



void __thiscall FUN_00429637(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(int *)((int)this + 4) != 0) && (*(int *)((int)this + 0x10) != 0)) {
    FUN_0041bfc0(*(int *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0x10) = param_1;
  *(undefined4 *)((int)this + 4) = param_3;
  *(undefined4 *)((int)this + 0x14) = param_2;
  return;
}



int __thiscall FUN_0042967f(void *this,char param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (*(uint *)((int)this + 0x24) < *(uint *)((int)this + 0x28)) {
    iVar2 = FUN_00428520(this,param_1);
  }
  else {
                    // WARNING: Load size is inaccurate
    iVar2 = 1;
    iVar3 = (**(code **)(*this + 0xc))(0xffffffff,1);
    if (iVar3 == -1) {
      iVar2 = -1;
    }
    else if ((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 0x2c) != 0)) {
      puVar1 = *(undefined4 **)((int)this + 0x28);
      FUN_00426800((undefined4 *)((int)puVar1 + 1),puVar1,
                   (*(int *)((int)this + 0x2c) - (int)puVar1) - 1);
      **(undefined **)((int)this + 0x28) = (char)iVar2;
    }
  }
  return iVar2;
}



void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    // WARNING: Could not recover jumptable at 0x004296e0. Too many branches
                    // WARNING: Treating indirect jump as call
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}



undefined4 __cdecl FUN_004296f0(int param_1,char *param_2)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_00432d2c;
  pcVar2 = &DAT_00432d28;
  piVar1 = FUN_00427c0d(&DAT_00435210,&DAT_00432d24);
  piVar1 = FUN_00429158(piVar1,param_1);
  piVar1 = FUN_00427c0d(piVar1,pcVar2);
  piVar1 = FUN_00427c0d(piVar1,param_2);
  FUN_00427c0d(piVar1,pcVar3);
  FUN_0041ef48(1);
  return 0x1b6;
}



void FUN_00429810(undefined *UNRECOVERED_JUMPTABLE)

{
                    // WARNING: Load size is inaccurate
  ExceptionList = *ExceptionList;
                    // WARNING: Could not recover jumptable at 0x0042983b. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



void FUN_00429844(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    // WARNING: Could not recover jumptable at 0x00429849. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



void FUN_0042984b(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    // WARNING: Could not recover jumptable at 0x00429850. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



void FUN_00429852(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x42987a,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}



undefined4 __cdecl
FUN_004298a1(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_00429b65(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}



undefined4 __cdecl
FUN_004298d7(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_0042992b;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}



void __cdecl FUN_0042992b(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_00429b65(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}



undefined4 __cdecl
FUN_00429950(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined *local_10;
  undefined *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_00429a06;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x4299d8;
  local_2c = (undefined4 *)ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_00420f76();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
                    // WARNING: Load size is inaccurate
    *local_2c = *ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}



undefined4 __cdecl FUN_00429a06(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_00429b65(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_00429852(param_2,param_1);
  }
                    // WARNING: Could not recover jumptable at 0x00429a70. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}



int __cdecl FUN_00429a7b(uint param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_8;
  
  uVar2 = param_1;
  local_8 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = local_8;
  param_1 = local_8;
  if (-1 < param_2) {
    do {
      if (uVar3 == 0xffffffff) {
        FUN_0042a42d();
      }
      uVar3 = uVar3 - 1;
      if (((*(int *)(iVar1 + 4 + uVar3 * 0x14) < param_3) &&
          (param_3 <= *(int *)(iVar1 + uVar3 * 0x14 + 8))) || (uVar3 == 0xffffffff)) {
        param_2 = param_2 + -1;
        local_8 = param_1;
        param_1 = uVar3;
      }
    } while (-1 < param_2);
  }
  uVar3 = uVar3 + 1;
  *param_4 = uVar3;
  *param_5 = local_8;
  if ((*(uint *)(uVar2 + 0xc) < local_8) || (local_8 < uVar3)) {
    FUN_0042a42d();
  }
  return iVar1 + uVar3 * 0x14;
}



void FUN_00429af8(void)

{
  undefined auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}



void __fastcall FUN_00429b17(undefined4 *param_1)

{
  *param_1 = &type_info::vftable;
  FUN_0042152d(0x1b);
  if (param_1[1] != 0) {
    FUN_0041b8c0(param_1[1]);
  }
  FUN_0042158e(0x1b);
  return;
}



undefined4 * __thiscall FUN_00429b40(void *this,byte param_1)

{
  FUN_00429b17((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_0041bfc0((int)this);
  }
  return (undefined4 *)this;
}



undefined4 __cdecl
FUN_00429b65(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_0042a42d();
  }
  if ((*(byte *)&param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_00429c00(param_1,param_2,param_3,param_4,(uint)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_00429eba((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}



void __cdecl
FUN_00429c00(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_0042a42d();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_00420f76();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_00420f76();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_00420f76();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_0042a4e7(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_0042a42d();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_00429d88;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_0042a42d();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_00429a7b(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_0042a2f2((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; iVar5 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_00429e5d(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_00429f6e(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                iVar5 = local_14;
                goto LAB_00429d68;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
        }
LAB_00429d68:
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_00429d88:
  if (param_6 == '\0') {
    FUN_00429db3(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_0042a3cc();
  return;
}



void __cdecl
FUN_00429db3(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_00420f76();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_00429950(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_00429a7b(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_00429f6e(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}



undefined4 __cdecl FUN_00429e5d(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_00429eb4:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_00429e8e:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_00429eb4;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_00429e8e;
    }
    uVar2 = 0;
  }
  return uVar2;
}



void __cdecl FUN_00429eba(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042b858;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_0042a42d();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_14;
  return;
}



void __cdecl
FUN_00429f6e(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_0042a12e((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  FUN_00429852(param_10,param_1);
  FUN_00429eba((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_00429fe9((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_00429810(UNRECOVERED_JUMPTABLE);
  }
  return;
}



undefined4 __cdecl
FUN_00429fe9(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042b868;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00420f76();
  FUN_00420f76();
  pDVar1 = FUN_00420f76();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_00420f76();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_004298d7(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_0042a0b6();
  ExceptionList = local_14;
  return uVar2;
}



void FUN_0042a0b6(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_00420f76();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_00420f76();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_0042a2f2((int)unaff_EDI);
  }
  return;
}



void __cdecl FUN_0042a12e(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar5;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042b880;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar2 = FUN_0042a4e7(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_0042a503(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_0042a359(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_00426800(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_0042a4e7(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_0042a503(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_0042a51f(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) != 0) {
            FUN_0042a359(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_0042984b(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_0042a359(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_00429844(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_0042a4e7(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_0042a503(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_00426800(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_0042a1bc;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_0042a4e7(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_0042a503(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_0042a1bc:
      iVar3 = FUN_0042a359(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_0042a42d();
  ExceptionList = local_14;
  return;
}



void __cdecl FUN_0042a2f2(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042b890;
  puStack_10 = &LAB_00421114;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_00429844(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}



int __cdecl FUN_0042a359(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}



// WARNING: Restarted to delay deadcode elimination for space: stack
// Library Function - Single Match
//  __CallSettingFrame@12
// 
// Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
// Studio 2019 Release

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}



void FUN_0042a3cc(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042b8a0;
  puStack_10 = &LAB_00421114;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_00420f76();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_00420f76();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_00420108();
  return;
}



void FUN_0042a42d(void)

{
  void *pvStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042b8b8;
  puStack_10 = &LAB_00421114;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_00432d70 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_00432d70)();
  }
  local_8 = 0xffffffff;
  FUN_0042a3cc();
  return;
}



int FUN_0042a483(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_0042a3cc();
    return iVar3;
  }
  if ((DAT_00435308 != (FARPROC)0x0) &&
     (bVar2 = FUN_0042a51f(DAT_00435308), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_00435308)(param_1);
    return iVar3;
  }
  return 0;
}



bool __cdecl FUN_0042a4e7(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}



bool __cdecl FUN_0042a503(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}



bool __cdecl FUN_0042a51f(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}



uint __cdecl FUN_0042a556(byte param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  pbVar2 = param_2;
  if (param_2[1] == 0x3a) {
    pbVar2 = param_2 + 2;
  }
  bVar1 = *pbVar2;
  if ((((bVar1 == 0x5c) || (bVar1 == 0x2f)) && (pbVar2[1] == 0)) ||
     (((param_1 & 0x10) != 0 || (uVar4 = 0x8000, bVar1 == 0)))) {
    uVar4 = 0x4040;
  }
  uVar4 = uVar4 | (uint)(~param_1 & 1 | 2) << 7;
  pbVar2 = FUN_0042aace(param_2,0x2e);
  if (pbVar2 != (byte *)0x0) {
    iVar3 = FUN_0042a939(pbVar2,&DAT_0042b8e8);
    if (iVar3 != 0) {
      iVar3 = FUN_0042a939(pbVar2,&DAT_0042b8e0);
      if (iVar3 != 0) {
        iVar3 = FUN_0042a939(pbVar2,&DAT_0042b8d8);
        if (iVar3 != 0) {
          iVar3 = FUN_0042a939(pbVar2,&DAT_0042b8d0);
          if (iVar3 != 0) goto LAB_0042a5f7;
        }
      }
    }
    uVar4 = uVar4 | 0x40;
  }
LAB_0042a5f7:
  return (uVar4 & 0x1c0) >> 6 | uVar4 | uVar4 >> 3 & 0x38;
}



undefined4 __cdecl FUN_0042a60e(byte *param_1,int *param_2)

{
  byte *pbVar1;
  DWORD *pDVar2;
  uint uVar3;
  uint *_Str;
  size_t sVar4;
  int iVar5;
  UINT UVar6;
  BOOL BVar7;
  DWORD DVar8;
  uint local_268 [65];
  _WIN32_FIND_DATAA local_164;
  int local_24;
  _FILETIME local_20;
  HANDLE local_18;
  _SYSTEMTIME local_14;
  
  pbVar1 = FUN_0042aca3(param_1,&DAT_0042b8f4);
  if (pbVar1 != (byte *)0x0) {
LAB_0042a641:
    pDVar2 = FUN_00420791();
    *pDVar2 = 2;
    pDVar2 = FUN_0042079a();
    *pDVar2 = 2;
    return 0xffffffff;
  }
  if (param_1[1] == 0x3a) {
    if ((*param_1 != 0) && (param_1[2] == 0)) goto LAB_0042a641;
    uVar3 = FUN_0042ac28((int)(char)*param_1);
    local_24 = uVar3 - 0x60;
  }
  else {
    local_24 = FUN_0042abe5();
  }
  local_18 = FindFirstFileA((LPCSTR)param_1,&local_164);
  if (local_18 == (HANDLE)0xffffffff) {
    pbVar1 = FUN_0042aca3(param_1,&DAT_0042b8f0);
    if ((((pbVar1 == (byte *)0x0) ||
         (_Str = FUN_0042ab40(local_268,(LPCSTR)param_1,0x104), _Str == (uint *)0x0)) ||
        ((sVar4 = _strlen((char *)_Str), sVar4 != 3 &&
         (iVar5 = FUN_0042a8c9((char *)_Str), iVar5 == 0)))) ||
       (UVar6 = GetDriveTypeA((LPCSTR)_Str), UVar6 < 2)) {
      pDVar2 = FUN_00420791();
      *pDVar2 = 2;
      pDVar2 = FUN_0042079a();
      *pDVar2 = 2;
      return 0xffffffff;
    }
    local_164.dwFileAttributes = 0x10;
    local_164.nFileSizeHigh = 0;
    local_164.nFileSizeLow = 0;
    local_164.cFileName[0] = '\0';
    iVar5 = FUN_00424031(0x7bc,1,1,0,0,0,-1);
    param_2[7] = iVar5;
    param_2[6] = iVar5;
    param_2[8] = iVar5;
  }
  else {
    BVar7 = FileTimeToLocalFileTime(&local_164.ftLastWriteTime,&local_20);
    if ((BVar7 == 0) || (BVar7 = FileTimeToSystemTime(&local_20,&local_14), BVar7 == 0)) {
LAB_0042a8ac:
      DVar8 = GetLastError();
      FUN_0042071e(DVar8);
      FindClose(local_18);
      return 0xffffffff;
    }
    iVar5 = FUN_00424031((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                         (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,-1);
    param_2[7] = iVar5;
    if ((local_164.ftLastAccessTime.dwLowDateTime != 0) ||
       (local_164.ftLastAccessTime.dwHighDateTime != 0)) {
      BVar7 = FileTimeToLocalFileTime(&local_164.ftLastAccessTime,&local_20);
      if ((BVar7 == 0) || (BVar7 = FileTimeToSystemTime(&local_20,&local_14), BVar7 == 0))
      goto LAB_0042a8ac;
      iVar5 = FUN_00424031((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                           (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,-1);
    }
    param_2[6] = iVar5;
    if ((local_164.ftCreationTime.dwLowDateTime == 0) &&
       (local_164.ftCreationTime.dwHighDateTime == 0)) {
      iVar5 = param_2[7];
    }
    else {
      BVar7 = FileTimeToLocalFileTime(&local_164.ftCreationTime,&local_20);
      if ((BVar7 == 0) || (BVar7 = FileTimeToSystemTime(&local_20,&local_14), BVar7 == 0))
      goto LAB_0042a8ac;
      iVar5 = FUN_00424031((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                           (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,-1);
    }
    param_2[8] = iVar5;
    FindClose(local_18);
  }
  uVar3 = FUN_0042a556((byte)local_164.dwFileAttributes,param_1);
  *(short *)((int)param_2 + 6) = (short)uVar3;
  param_2[5] = local_164.nFileSizeLow;
  *param_2 = local_24 + -1;
  param_2[4] = local_24 + -1;
  *(undefined2 *)(param_2 + 2) = 1;
  *(undefined2 *)(param_2 + 1) = 0;
  *(undefined2 *)(param_2 + 3) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0;
  return 0;
}



undefined4 __cdecl FUN_0042a8c9(char *param_1)

{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char cVar4;
  
  sVar2 = _strlen(param_1);
  if (((4 < sVar2) && ((*param_1 == '\\' || (*param_1 == '/')))) &&
     ((param_1[1] == '\\' || (param_1[1] == '/')))) {
    pcVar3 = param_1 + 3;
    cVar4 = param_1[3];
    while (((cVar4 != '\0' && (cVar4 != '\\')) && (cVar4 != '/'))) {
      pcVar1 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar4 = *pcVar1;
    }
    if ((*pcVar3 != '\0') && (pcVar3 = pcVar3 + 1, *pcVar3 != '\0')) {
      for (; (cVar4 = *pcVar3, cVar4 != '\0' && ((cVar4 != '\\' && (cVar4 != '/'))));
          pcVar3 = pcVar3 + 1) {
      }
      if ((*pcVar3 == '\0') || (pcVar3[1] == '\0')) {
        return 1;
      }
    }
  }
  return 0;
}



int __cdecl FUN_0042a939(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  byte *local_10;
  byte *local_c;
  byte local_8;
  byte local_7;
  
  if (DAT_004365ec == 0) {
    iVar3 = FUN_00407400((char *)param_1,(char *)param_2);
  }
  else {
    FUN_0042152d(0x19);
    local_10 = param_2 + -1;
    local_c = param_1 + -1;
    do {
      uVar7 = (uint)*param_1;
      pbVar4 = param_1 + 1;
      pbVar1 = local_c + 1;
      if (((&DAT_00436701)[uVar7] & 4) == 0) {
        param_1 = pbVar4;
        local_c = pbVar1;
        if (((&DAT_00436701)[uVar7] & 0x10) == 0x10) {
          uVar7 = (uint)(byte)(&DAT_00436600)[uVar7];
        }
      }
      else if (*pbVar4 == 0) {
        uVar7 = 0;
        param_1 = pbVar4;
        local_c = pbVar1;
      }
      else {
        iVar3 = FUN_0042311b(DAT_00436804,0x200,(char *)pbVar1,2,(LPWSTR)&local_8,2,DAT_004365d4,1);
        if (iVar3 == 1) {
          uVar7 = (uint)local_8;
        }
        else {
          if (iVar3 != 2) goto LAB_0042aa9d;
          uVar7 = (uint)local_8 * 0x100 + (uint)local_7;
        }
        param_1 = param_1 + 2;
        local_c = local_c + 2;
      }
      bVar2 = *param_2;
      uVar5 = (ushort)bVar2;
      pbVar4 = param_2 + 1;
      pbVar1 = local_10 + 1;
      if (((&DAT_00436701)[bVar2] & 4) == 0) {
        param_2 = pbVar4;
        local_10 = pbVar1;
        if (((&DAT_00436701)[bVar2] & 0x10) == 0x10) {
          uVar5 = (ushort)(byte)(&DAT_00436600)[bVar2];
        }
      }
      else if (*pbVar4 == 0) {
        uVar5 = 0;
        param_2 = pbVar4;
        local_10 = pbVar1;
      }
      else {
        iVar3 = FUN_0042311b(DAT_00436804,0x200,(char *)pbVar1,2,(LPWSTR)&local_8,2,DAT_004365d4,1);
        if (iVar3 == 1) {
          uVar5 = (ushort)local_8;
        }
        else {
          if (iVar3 != 2) {
LAB_0042aa9d:
            FUN_0042158e(0x19);
            return 0x7fffffff;
          }
          uVar5 = (ushort)local_8 * 0x100 + (ushort)local_7;
        }
        param_2 = param_2 + 2;
        local_10 = local_10 + 2;
      }
      uVar6 = (ushort)uVar7;
      if (uVar6 != uVar5) {
        FUN_0042158e(0x19);
        return (-(uint)(uVar5 < uVar6) & 2) - 1;
      }
    } while (uVar6 != 0);
    FUN_0042158e(0x19);
    iVar3 = 0;
  }
  return iVar3;
}



byte * __cdecl FUN_0042aace(byte *param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar5 = (byte *)0x0;
  if (DAT_004365ec == 0) {
    pbVar5 = (byte *)_strrchr((char *)param_1,param_2);
  }
  else {
    FUN_0042152d(0x19);
    do {
      bVar4 = *param_1;
      if (((&DAT_00436701)[bVar4] & 4) == 0) {
        bVar6 = param_2 == bVar4;
LAB_0042ab29:
        pbVar3 = param_1;
        if (bVar6) {
          pbVar5 = param_1;
        }
      }
      else {
        bVar1 = param_1[1];
        pbVar3 = param_1 + 1;
        if (bVar1 == 0) {
          bVar6 = pbVar5 == (byte *)0x0;
          param_1 = pbVar3;
          bVar4 = bVar1;
          goto LAB_0042ab29;
        }
        uVar2 = CONCAT11(bVar4,bVar1);
        bVar4 = bVar1;
        if (param_2 == uVar2) {
          pbVar5 = param_1;
        }
      }
      param_1 = pbVar3 + 1;
    } while (bVar4 != 0);
    FUN_0042158e(0x19);
  }
  return pbVar5;
}



uint * __cdecl FUN_0042ab40(uint *param_1,LPCSTR param_2,uint param_3)

{
  LPCSTR lpFileName;
  uint *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  
  lpFileName = param_2;
  if ((param_2 != (LPCSTR)0x0) && (*param_2 != '\0')) {
    puVar1 = param_1;
    if (param_1 == (uint *)0x0) {
      puVar1 = FUN_0041b590(0x104);
      if (puVar1 == (uint *)0x0) {
        pDVar2 = FUN_00420791();
        *pDVar2 = 0xc;
        return (uint *)0x0;
      }
      param_3 = 0x104;
    }
    DVar3 = GetFullPathNameA(lpFileName,param_3,(LPSTR)puVar1,&param_2);
    if (DVar3 < param_3) {
      if (DVar3 != 0) {
        return puVar1;
      }
      if (param_1 == (uint *)0x0) {
        FUN_0041b8c0((int)puVar1);
      }
      DVar3 = GetLastError();
      FUN_0042071e(DVar3);
    }
    else {
      if (param_1 == (uint *)0x0) {
        FUN_0041b8c0((int)puVar1);
      }
      pDVar2 = FUN_00420791();
      *pDVar2 = 0x22;
    }
    return (uint *)0x0;
  }
  puVar1 = FUN_0042ad38(param_1,param_3);
  return puVar1;
}



int FUN_0042abe5(void)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  byte local_108;
  char local_107;
  
  iVar3 = 0;
  DVar1 = GetCurrentDirectoryA(0x104,(LPSTR)&local_108);
  if ((DVar1 != 0) && (local_107 == ':')) {
    uVar2 = FUN_0041f299((uint)local_108);
    iVar3 = uVar2 - 0x40;
  }
  return iVar3;
}



uint __cdecl FUN_0042ac28(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined uVar5;
  undefined2 local_8;
  
  uVar4 = param_1;
  if (param_1 < 0x100) {
    if (((&DAT_00436701)[param_1] & 0x10) == 0x10) {
      uVar4 = (uint)(byte)(&DAT_00436600)[param_1];
    }
  }
  else {
    uVar5 = (undefined)param_1;
    uVar2 = param_1 >> 8;
    uVar1 = param_1 >> 8;
    param_1 = CONCAT13(uVar5,CONCAT12((char)uVar1,(undefined2)param_1));
    if ((((&DAT_00436701)[uVar2 & 0xff] & 4) != 0) &&
       (iVar3 = FUN_0042311b(DAT_00436804,0x100,(char *)((int)&param_1 + 2),2,&local_8,2,
                             DAT_004365d4,1), iVar3 != 0)) {
      uVar4 = (uint)CONCAT11((undefined)local_8,local_8._1_1_);
    }
  }
  return uVar4;
}



byte * __cdecl FUN_0042aca3(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (DAT_004365ec == 0) {
    pbVar2 = FUN_00425ac0(param_1,param_2);
    return pbVar2;
  }
  FUN_0042152d(0x19);
  bVar1 = *param_1;
  while (bVar1 != 0) {
    bVar1 = *param_2;
    pbVar2 = param_2;
    while (bVar1 != 0) {
      bVar1 = *pbVar2;
      if (((&DAT_00436701)[bVar1] & 4) == 0) {
        pbVar3 = pbVar2;
        if (bVar1 == *param_1) break;
      }
      else if (((bVar1 == *param_1) && (pbVar2[1] == param_1[1])) ||
              (pbVar3 = pbVar2 + 1, pbVar2[1] == 0)) break;
      pbVar2 = pbVar3 + 1;
      bVar1 = *pbVar2;
    }
    if ((*pbVar2 != 0) ||
       ((((&DAT_00436701)[*param_1] & 4) != 0 && (param_1 = param_1 + 1, *param_1 == 0)))) break;
    param_1 = param_1 + 1;
    bVar1 = *param_1;
  }
  FUN_0042158e(0x19);
  return (byte *)(-(uint)(*param_1 != 0) & (uint)param_1);
}



uint * __cdecl FUN_0042ad38(uint *param_1,uint param_2)

{
  uint *puVar1;
  
  FUN_0042152d(0xc);
  puVar1 = FUN_0042ad5f(0,param_1,param_2);
  FUN_0042158e(0xc);
  return puVar1;
}



uint * __cdecl FUN_0042ad5f(uint param_1,uint *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  uint *puVar5;
  uint local_10c [65];
  LPSTR local_8;
  
  uVar4 = param_1;
  if (param_1 == 0) {
    DVar3 = GetCurrentDirectoryA(0x104,(LPSTR)local_10c);
  }
  else {
    iVar1 = FUN_0042ae34(param_1);
    if (iVar1 == 0) {
      pDVar2 = FUN_0042079a();
      *pDVar2 = 0xf;
      pDVar2 = FUN_00420791();
      *pDVar2 = 0xd;
      return (uint *)0x0;
    }
    param_1 = (uint)CONCAT12(0x2e,CONCAT11(0x3a,(char)uVar4 + '@'));
    DVar3 = GetFullPathNameA((LPCSTR)&param_1,0x104,(LPSTR)local_10c,&local_8);
  }
  if ((DVar3 != 0) && (uVar4 = DVar3 + 1, uVar4 < 0x105)) {
    if (param_2 == (uint *)0x0) {
      if ((int)uVar4 <= (int)param_3) {
        uVar4 = param_3;
      }
      puVar5 = FUN_0041b590(uVar4);
      if (puVar5 != (uint *)0x0) {
LAB_0042ae20:
        puVar5 = FUN_00423540(puVar5,local_10c);
        return puVar5;
      }
      pDVar2 = FUN_00420791();
      *pDVar2 = 0xc;
    }
    else {
      puVar5 = param_2;
      if ((int)uVar4 <= (int)param_3) goto LAB_0042ae20;
      pDVar2 = FUN_00420791();
      *pDVar2 = 0x22;
    }
  }
  return (uint *)0x0;
}



undefined4 __cdecl FUN_0042ae34(uint param_1)

{
  char cVar1;
  UINT UVar2;
  
  if (param_1 != 0) {
    cVar1 = (char)param_1;
    param_1 = (uint)CONCAT12(0x5c,CONCAT11(0x3a,cVar1 + '@'));
    UVar2 = GetDriveTypeA((LPCSTR)&param_1);
    if ((UVar2 == 0) || (UVar2 == 1)) {
      return 0;
    }
  }
  return 1;
}



void Unwind_0042ae6c(void)

{
  int unaff_EBP;
  
  FUN_0041bfc0(*(int *)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042ae80(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00428bf9((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8));
    return;
  }
  return;
}



void Unwind_0042aea4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00428bf9((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8));
    return;
  }
  return;
}



void Unwind_0042aec8(void)

{
  int unaff_EBP;
  
  FUN_0041bfc0(*(int *)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042aedc(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00428bf9((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
    return;
  }
  return;
}



void Unwind_0042af00(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00428bf9((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
    return;
  }
  return;
}



void Unwind_0042af1a(void)

{
  int unaff_EBP;
  
  FUN_0041bfc0(*(int *)(unaff_EBP + 0x14));
  return;
}



void Unwind_0042af24(void)

{
  int unaff_EBP;
  
  FUN_00428364(*(int *)(unaff_EBP + -0x14) + 0xc);
  return;
}



void Unwind_0042af3c(void)

{
  int unaff_EBP;
  
  FUN_00429484(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042af50(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00428bf9((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8));
    return;
  }
  return;
}



void Unwind_0042af6a(void)

{
  int unaff_EBP;
  
  FUN_0041bfc0(*(int *)(unaff_EBP + 8));
  return;
}



void Unwind_0042af80(void)

{
  int unaff_EBP;
  
  FUN_00429484(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042af94(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00428bf9((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8));
    return;
  }
  return;
}



void Unwind_0042afae(void)

{
  int unaff_EBP;
  
  FUN_0041bfc0(*(int *)(unaff_EBP + 8));
  return;
}


