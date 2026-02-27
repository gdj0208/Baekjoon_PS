def paint(matrix, is_blank, size, y, x):
    if(size == 1) :
        matrix[y][x] = is_blank
        return

    blockSize = size // 3
    paint(matrix, 1, blockSize, y, x)
    paint(matrix, 1, blockSize, y, x + blockSize)
    paint(matrix, 1, blockSize, y, x + 2*blockSize)
    paint(matrix, 1, blockSize, y + blockSize, x)
    paint(matrix, 1, blockSize, y + blockSize, x + 2*blockSize)
    paint(matrix, 1, blockSize, y + 2*blockSize, x)
    paint(matrix, 1, blockSize, y + 2*blockSize, x + blockSize)
    paint(matrix, 1, blockSize, y + 2*blockSize, x + 2*blockSize)


def print_mat(matrix, size):
    for y in range(size):
        for x in range(size):
            if matrix[y][x] == 1:
                print("*", end="")
            else :
                print("", end=" ")
        print()

mat_size = int(input())
matrix = [[0 for _ in range(mat_size)] for _ in range(mat_size)]

paint(matrix, 1, mat_size, 0, 0)
print_mat(matrix, mat_size)