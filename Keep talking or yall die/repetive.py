def solve_maze(maze, start, end):
    def is_valid(x, y, maze):
        if x >= 0 and x < len(maze) and y >= 0 and y < len(maze[0]) and maze[x][y] != "#":
            return True
        return False

    def mark_path(x, y, maze, path):
        if [x, y] == end:
            path.append([x, y])
            return True
        if is_valid(x, y, maze):
            maze[x][y] = "#"
            path.append([x, y])
            if mark_path(x + 1, y, maze, path) or mark_path(x - 1, y, maze, path) or mark_path(x, y + 1, maze, path) or mark_path(x, y - 1, maze, path):
                return True
            path.pop()
        return False

    path = []
    mark_path(start[0], start[1], maze, path)
    return path

maze = [["#", "#", "#", "#", "#", "#", "#"],
        ["#", ".", ".", ".", "#", ".", "#"],
        ["#", ".", "#", ".", "#", ".", "#"],
        ["#", ".", "#", ".", ".", ".", "#"],
        ["#", "#", "#", "#", "#", "#", "#"]
]

start = [3, 1]
end = [1, 7]

print(solve_maze(maze, start, end))
