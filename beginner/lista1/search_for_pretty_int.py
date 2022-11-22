# AA Iniciante 2022.1 - Lista 01: Ad-Hoc 1
# K. Search for Pretty Integers
# author: uncoded

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    inters = set(a) & set(b)
    if inters:
        print(min(inters))
    else:
        min_a = min(a)
        min_b = min(b)
        print(min(min_a, min_b) * 10 + max(min_a, min_b))

if __name__ == "__main__":
    main()

