#include <bits/stdc++.h>

std::string mycode = "G.cpp";
std::string stdcode = "std.cpp";
std::string makecode = "makedata.cpp";

int main() {
  std::cerr << "Compile mycode.exe" << '\n';
  system(std::format("g++ -o mycode.exe {} -O2 -std=c++17", mycode).c_str());
  
  std::cerr << "Compile stdcode.exe" << '\n';
  system(std::format("g++ -o stdcode.exe {} -O2 -std=c++17", stdcode).c_str());
  
  std::cerr << "Compile makecode.exe" << '\n';
  system(std::format("g++ -o makecode.exe {} -O2 -std=c++17", makecode).c_str());
  
  int T = 100000;
  for (int i = 1; i <= T; ++i) {
    std::cerr << "Make data for test " << i << '\n';
    system(std::format("makecode.exe > data.in").c_str());
    
    std::cerr << "Run mycode on test " << i << '\n';
    system(std::format("mycode.exe < data.in > my.out").c_str());
    
    std::cerr << "Run stdcode on test " << i << '\n';
    system(std::format("stdcode.exe < data.in > std.out").c_str());

    if (system("fc my.out std.out")) {
      std::cerr << "WA on test " << i << std::endl;
      return 0;
    }
    std::cerr << "Pass test " << i << std::endl;
  }
}