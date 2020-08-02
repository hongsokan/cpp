#include <iostream>
#define MAZE_SIZE 5
#define CRT_SECURE_NO_WARNINGS
using namespace std;

// 2���� �迭, 0�� ��, 1�� ��
int maze[MAZE_SIZE][MAZE_SIZE] =
{ { 0, 1, 1, 1, 1 },
{ 0, 0, 0, 1, 1 },
{ 1, 1, 0, 1, 1 },
{ 1, 1, 0, 0, 1 },
{ 1, 1, 1, 0, 1 } };
// �̷� ������ ǥ��
// ��� : [0, 0] -> [1, 0] -> [1, 1] -> [1, 2]...


// UP = 2^0, RIGHT = 2^1, DOWN = 2^2, LEFT = 2^3


// �̷� �׸���
int CMaze::GetShape(int x, int y)
{
	int shape = 0;
	if (m_arrayMaze[y][x] != 0) // ���� �ִ� ��츸 ����� �� ������
	{
		if (y > 0 && m_arrayMaze[y - 1][x]) // ���ʿ� ���� �ֳ�?
			shape |= UP; // OR ����
		if (y < MAZE_SIZE - 1 && m_arrayMaze[y + 1][x]) // �Ʒ���?
			shape |= DOWN;
		if (x > 0 && m_arrayMaze[y][x - 1]) // ����?
			shape |= LEFT;
		if (x < MAZE_SIZE - 1 && m_arrayMaze[y][x + 1]) // ������?
			shape |= RIGHT;
	}
	return shape;
}
// ���ǿ��� MFC ����Ͽ� �̷� �׸�, ���⼱ ����


// �ִܰ�θ� ������ �迭�� x,y ������ ���ʴ�� ����
// �������� -1, -1�� ��
void CMaze::ShortestPath()
{
	int i, j = 0;
	int x, y;
	int x1, y1;
	while (m_arrayRecord[i] >= 0)
	{
		x = m_arrayRecord[i];
		y = m_arrayRecord[i + 1];
		j = i + 2; // �� ��ǥ�� �� ���� �����̹Ƿ� ���� ��ǥ�� +2
		while (m_arrayRecord[i] >= 0)
		{
			x1 = m_arrayRecord[j];
			y1 = m_arrayRecord[j + 1];
			if (x == x1 && y == y1) // ���� ��ǥ �߰ߵǸ�
				j = DeletePath(i, j); // �ߺ� ��� ����
			j += 2; // ���� ��ǥ��
		}
		i += 2;
	}
}


int main(void) {

}