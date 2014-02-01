dx = [1, -1, 1, -1, 2, -2, 2, -2]
dy = [2, -2, -2, 2, 1, -1, -1, 1]

dmax = 8

def inLimit(x, y, n, m):
	if 0 <= x <= n and 0 <= y <= m:
		return True
	else:
		return False

def bfs(startNode, endNode, n, m):
	global dx, dy, dmax

	if startNode == endNode:
		return 0
	mp = [[False] * (m + 1) for i in xrange(0, n + 1)]
	mp[startNode[0]][startNode[1]] = True
	
	head = 0
	tail = 0
	startNode.append(0)
	queue = []
	queue.append(startNode)
	head += 1
	while tail < head:
		x = queue[tail][0]
		y = queue[tail][1]
		npath = queue[tail][2] + 1
		for i in xrange(0, dmax):
			nx = x + dx[i]
			ny = y + dy[i]
			if inLimit(nx, ny, n, m):
				if [nx, ny] == endNode:
					return npath
				if mp[nx][ny] == False:
					mp[nx][ny] = True
					queue.append([nx, ny, npath])
					head += 1
		tail += 1
	return -1


if __name__ == '__main__':
    ans = bfs([0, 0], [n, m], n, m)
    print ans