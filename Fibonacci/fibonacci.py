__author__ = 'diogommartins'


def fibonacci_map(n: int, cache={}) -> int:
    if n <= 2:
        return 1
    else:
        v = cache.get(n)
        if v:
            return v
        else:
            v = fibonacci_map(n - 1, cache) + fibonacci_map(n - 2, cache)
            cache[n] = v
            return v

def fibonacci_dp_array(n: int) -> int:
    f = [0, 1, 1]
    for i in range(3, n+1):
        f.append(f[i-1] + f[1-2])
    return f[n-1]

def fibonacci_memory_efficient(n: int) -> int:
    if n <= 2:
        return 1

    i_minus_1 = 1
    i_minus_2 = 1

    for i in range(3, n+1):
        fn = i_minus_1 + i_minus_2
        i_minus_2 = i_minus_1
        i_minus_1 = fn

    return fn


if __name__ == "__main__":
    for n in range(3, 20):
        assert fibonacci_dp_array(n) == fibonacci_map(n) == fibonacci_memory_efficient(n)

