import random

TEST_COUNT = 10
SPRINKLER_COUNT_LIMIT = 100
SIZE_LIMIT = 10000

def generate_tests(file_name):
  tests_file = open(file_name, 'w')

  tests = []
  for i in range(TEST_COUNT):
    length = random.uniform(1, SIZE_LIMIT)
    width = random.uniform(1, length / 10)
    sprinkler_count = random.randint(1, SPRINKLER_COUNT_LIMIT)
    position = [random.uniform(0, length) for iter in range(sprinkler_count)]
    radius = [random.uniform(0, length / 8) for iter in range(sprinkler_count)]

    position_str = ' '.join(list(map(lambda x: str(x), position)))
    radius_str = ' '.join(list(map(lambda x: str(x), radius)))
    test = str(length) + ' ' + str(width) + ' ' + str(sprinkler_count) + '\n' + position_str + '\n' + radius_str
    tests.append(test)

  tests_file.write(str(TEST_COUNT) + '\n')
  tests_file.write('\n'.join(tests))
  tests_file.close()