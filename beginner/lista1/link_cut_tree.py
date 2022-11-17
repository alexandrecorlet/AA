# AA Iniciante - Lista 01: Ad-Hoc 1
# E. Link/Cut Tree
# author: uncoded

def main():
    l, r, k = map(int, input().split())
    ok, power = False, 1
    while power <= r:
        if l <= power:
            print(power, end=" ")
            ok = True 
        power *= k
    print("\n" if ok else -1)


if __name__ == "__main__":
    main()

