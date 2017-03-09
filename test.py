def makeParts(arr, chunkSize):
  length = len(arr)
  divide = length / chunkSize
  remain = length % chunkSize
  inc = 0
  answer = []
  if remain == 0:
      while inc < length:
          answer.append(arr[inc:chunkSize])
          inc += chunkSize
      return answer
  else:
      for i in range(0, divide):
          if i == divide:
              answer.append(arr[inc:remain])
              return answer
          else:
              answer.append(arr[inc:chunkSize])
              inc += chunkSize
      return answer

print makeParts([1, 2, 3, 4, 5,], 2)