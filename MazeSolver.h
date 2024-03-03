#pragma once

#include <array>
#include <ostream>
#include <string>
#include <vector>

struct Point
{
    int32_t x;
    int32_t y;
};

class MazeSolver
{
public:
    static std::vector<Point> solve(const std::vector<std::string>& maze, const char& wall, const Point& start, const Point& end)
    {
        std::vector<Point> path;
        std::vector<std::vector<bool>> seen(maze.size(), std::vector<bool>(maze[0].size(), false));

        walk(maze, wall, start, end, seen, path);

        return path;
    }

private:
    static bool walk(
        const std::vector<std::string>& maze,
        const char& wall,
        const Point& current,
        const Point& end,
        std::vector<std::vector<bool>>& seen,
        std::vector<Point>& path)
    {
        if(current.x < 0 || current.x > maze[0].size() ||
            current.y < 0 || current.y > maze.size())
        {
            return false;
        }

        if(maze[current.y][current.x] == wall)
        {
            return false;
        }

        if(current.x == end.x && current.y == end.y)
        {
            path.push_back(current);
            return true;
        }

        if(seen[current.y][current.x])
        {
            return false;
        }

        seen[current.y][current.x] = true;
        path.push_back(current);

        for(int8_t i=0; i < std::size(m_dir); i++)
        {
            if(walk(maze, wall,{current.x + m_dir[i].x, current.y + m_dir[i].y}, end, seen, path))
            {
                return true;
            }
        }

        path.pop_back();

        return false;
    }

    static constexpr Point m_dir[4] =
        {
        {-1,  0},
        { 1,  0},
        { 0, -1},
        { 0,  1}
        };
};
