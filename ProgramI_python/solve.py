import math

def find_next_aspensor(start, end, index, aspensors, length):
  max_end = end
  for i in range(index, len(aspensors)):
    left, right = aspensors[i]
    if left > end:
      break
    if right > max_end:
      max_end = right

  return i, max_end

# Sprinklers have the position as key and radius as value
def find_min_aspensor_count(length, width, aspensors):
  # Sprinklers with radius <= width / 2 are useless, as they will require another
  # sprinkler to cover their distance vertically.
  # The effective radius of each sprinkler is how much it can cover horizontally
  # after covering the whole ground vertically.
  aspensors = [(p, math.sqrt(r**2 - (width / 2)**2))  for (p, r) in aspensors if r > width / 2]
  if (len(aspensors) == 0):
    return None

  aspensors = [(max(p - r, 0), p + r) for (p, r) in aspensors]
  aspensors.sort(key = lambda s: (s[0], -s[1]))

  # There is no solution if the first aspensor can't cover the ground to the left side.
  start, end = aspensors[0]
  if (start > 0):
    return None

  minimum_count = 1
  i = 0
  while i < len(aspensors) and end < length:
    _, right = aspensors[i]
    j = i + 1
    while j < len(aspensors) and aspensors[j][0] < right:
      if aspensors[j][1] > end:
        end = aspensors[j][1]
      j += 1
    minimum_count += 1
    i = j

  return minimum_count if end >= length else None