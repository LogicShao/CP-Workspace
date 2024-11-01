import os
import random


def makedata():
    T = 1
    n = 5
    a = [random.randint(1, 100) for i in range(n)]
    k = random.randint(0, sum(a))
    data = f"{T}\n{n} {k}\n{' '.join(map(str, a))}\n"
    with open("data.in", "w") as f:
        f.write(data)


def main():
    os.system("g++ K.cpp -o K.exe -std=c++20 -O2")
    os.system("g++ std.cpp -o std.exe -std=c++20 -O2")

    for i in range(10000):
        makedata()
        os.system("K.exe < data.in > K.out")
        os.system("std.exe < data.in > std.out")
        if os.system("fc K.out std.out"):
            print("Wa on test", i)
            break
        print("AC on test", i)


if __name__ == "__main__":
    main()
