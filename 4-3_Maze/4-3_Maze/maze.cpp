#include <iostream>
#define MAZE_SIZE 5
#define CRT_SECURE_NO_WARNINGS
using namespace std;

// 2차원 배열, 0은 길, 1은 벽
int maze[MAZE_SIZE][MAZE_SIZE] =
{ { 0, 1, 1, 1, 1 },
{ 0, 0, 0, 1, 1 },
{ 1, 1, 0, 1, 1 },
{ 1, 1, 0, 0, 1 },
{ 1, 1, 1, 0, 1 } };
// 이런 식으로 표현
// 경로 : [0, 0] -> [1, 0] -> [1, 1] -> [1, 2]...


// UP = 2^0, RIGHT = 2^1, DOWN = 2^2, LEFT = 2^3


// 미로 그리기
int CMaze::GetShape(int x, int y)
{
	int shape = 0;
	if (m_arrayMaze[y][x] != 0) // 벽이 있는 경우만 경우의 수 따진다
	{
		if (y > 0 && m_arrayMaze[y - 1][x]) // 위쪽에 벽이 있나?
			shape |= UP; // OR 연산
		if (y < MAZE_SIZE - 1 && m_arrayMaze[y + 1][x]) // 아랫쪽?
			shape |= DOWN;
		if (x > 0 && m_arrayMaze[y][x - 1]) // 왼쪽?
			shape |= LEFT;
		if (x < MAZE_SIZE - 1 && m_arrayMaze[y][x + 1]) // 오른쪽?
			shape |= RIGHT;
	}
	return shape;
}
// 강의에선 MFC 사용하여 미로 그림, 여기선 참고만


// 최단경로를 일차원 배열에 x,y 순으로 차례대로 넣음
// 마지막은 -1, -1로 함
void CMaze::ShortestPath()
{
	int i, j = 0;
	int x, y;
	int x1, y1;
	while (m_arrayRecord[i] >= 0)
	{
		x = m_arrayRecord[i];
		y = m_arrayRecord[i + 1];
		j = i + 2; // 한 좌표가 두 개의 정수이므로 다음 좌표는 +2
		while (m_arrayRecord[i] >= 0)
		{
			x1 = m_arrayRecord[j];
			y1 = m_arrayRecord[j + 1];
			if (x == x1 && y == y1) // 같은 좌표 발견되면
				j = DeletePath(i, j); // 중복 경로 삭제
			j += 2; // 다음 좌표로
		}
		i += 2;
	}
}


int main(void) {

}