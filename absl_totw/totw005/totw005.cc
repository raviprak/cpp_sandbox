// https://abseil.io/tips/5
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	std::string s1 = "Hello";
	std::string s2 = "World!";

	// Asan catches this. Holding a reference to a temporary object.
	const char *p1 = (s1 + s2).c_str();
	std::cout << "Length of the concatenated string is " << strlen(p1);

	return 0;
}

/*
=================================================================
==17352==ERROR: AddressSanitizer: stack-use-after-scope on address 0x7f23b18000d0 at pc 0x7f23b3c666d1 bp 0x7ffe519015b0 sp 0x7ffe51900d70
READ of size 12 at 0x7f23b18000d0 thread T0
	#0 0x7f23b3c666d0 in __interceptor_strlen.part.0 (/lib64/libasan.so.8+0x666d0) (BuildId: bac59ca9f1e357781008d7f6982314d30ca62672)
	#1 0x40257c in main (/home/raviprak/Code/github/cpp_sandbox/build/absl_totw/totw005/totw005+0x40257c) (BuildId: 52100becf3b04651ade37fc9a9fd7f08624afe5d)
	#2 0x7f23b3649b49 in __libc_start_call_main (/lib64/libc.so.6+0x27b49) (BuildId: 245240a31888ad5c11bbc55b18e02d87388f59a9)
	#3 0x7f23b3649c0a in __libc_start_main_alias_2 (/lib64/libc.so.6+0x27c0a) (BuildId: 245240a31888ad5c11bbc55b18e02d87388f59a9)
	#4 0x402274 in _start (/home/raviprak/Code/github/cpp_sandbox/build/absl_totw/totw005/totw005+0x402274) (BuildId: 52100becf3b04651ade37fc9a9fd7f08624afe5d)

Address 0x7f23b18000d0 is located in stack of thread T0 at offset 208 in frame
	#0 0x402345 in main (/home/raviprak/Code/github/cpp_sandbox/build/absl_totw/totw005/totw005+0x402345) (BuildId: 52100becf3b04651ade37fc9a9fd7f08624afe5d)

  This frame has 5 object(s):
	[32, 33) '<unknown>'
	[48, 49) '<unknown>'
	[64, 96) 's1' (line 9)
	[128, 160) 's2' (line 10)
	[192, 224) '<unknown>' <== Memory access at offset 208 is inside this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
	  (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-scope (/lib64/libasan.so.8+0x666d0) (BuildId: bac59ca9f1e357781008d7f6982314d30ca62672) in __interceptor_strlen.part.0
Shadow bytes around the buggy address:
  0x7f23b17ffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f23b17ffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f23b17fff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f23b17fff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f23b1800000: f1 f1 f1 f1 f8 f2 f8 f2 00 00 00 00 f2 f2 f2 f2
=>0x7f23b1800080: 00 00 00 00 f2 f2 f2 f2 f8 f8[f8]f8 f3 f3 f3 f3
  0x7f23b1800100: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f23b1800180: f5 f5 f5 f5 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f23b1800200: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f23b1800280: f5 f5 f5 f5 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f23b1800300: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==17352==ABORTING
*/