import solve
import test_generator
from time import time
# Generate the tests in the tests file
test_generator.generate_tests('tests.txt')

tests = open('tests.txt').read().split('\n')
numbers = []
for line in tests:
  numbers.extend(list(map(lambda x: float(x), line.split(' '))))

test_count = int(numbers[0])
index = 1

for test in range(test_count):
  length = numbers[index]
  index += 1

  width = numbers[index]
  index += 1

  n = int(numbers[index])
  index += 1

  position = []
  for i in range(n):
    position.append(numbers[index])
    index += 1

  radius = []
  for i in range(n):
    radius.append(numbers[index])
    index += 1
  start = time()
  min_aspensor_count = solve.find_min_aspensor_count(length, width, zip(position, radius))
  stop = time()
  print("We will need a min of  : ", min_aspensor_count)
  timeElapsed = stop - start
  print(timeElapsed)