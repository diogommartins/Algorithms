def fibonacci_map(n, hash_map={})
  if n <= 2
    return 1
  end
  v = hash_map[n]
  if v
    return v
  end
  v = fibonacci_map(n-1, hash_map) + fibonacci_map(n-2, hash_map)
  hash_map[n] = v
  v
end


def fibonacci_dp_array(n)
  if n <= 2
    return 1
  end

  f = [0, 1 ,1]

  for i in 3..n
    f[i] = f[i-1] + f[i-2]
  end

  f[n]
end


def fibonacci_memory_efficient(n)
  if n <= 2
    return 1
  end

  i_minus_1 = 1
  i_minus_2 = 1
  fn = 0

  for i in  3..n
    fn = i_minus_1 + i_minus_2
    i_minus_2 = i_minus_1
    i_minus_1 = fn
  end

  fn
end

puts 'Map fib(10): ' + fibonacci_map(10).to_s
puts 'Array fib(10): ' + fibonacci_dp_array(10).to_s
puts 'Memory efficient fib(10): ' + fibonacci_memory_efficient(10).to_s
