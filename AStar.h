#pragma once

class Path
{
public:
	vector<Vector2> Find(const Vector2& startNode, const Vector2& endNode, string** mapArray , const int w, const int h)
	{
		vector<Vector2> finalPath, openList, closedList;

		finalPath.push_back(startNode);
		openList.push_back(startNode);
		closedList.push_back(startNode);

		while (!openList.empty())
		{
			for (size_t i = 0; i < openList.size(); ++i)
			{
				if (openList[i].x == endNode.x && openList[i].y == endNode.y)
					return finalPath;

				priority_queue<Vector2> nodeQueue;

				for (int x = -1; x <= 1; x += 2)
				{
						const int current_x = openList[i].x + x;
						const int current_y = openList[i].y;

						bool alreadyCheckedNode = false;
						for (size_t i = 0; i < closedList.size(); ++i)
						{
							if (current_x == closedList[i].x && current_y == closedList[i].y)
							{
								alreadyCheckedNode = true;
								break;
							}
						}

						if (alreadyCheckedNode)
							continue;

						if (current_x < 0 || current_x > w || current_y < 0 || current_y > h || (openList[i].x == current_x && openList[i].y == current_y))
							continue;

						if (mapArray[current_x][current_y] == "бс")
							continue;

						const int xNodeDifference = abs(current_x - (openList[i].x));
						const int yNodeDifference = abs(current_y - (openList[i].y));

						const int direction = xNodeDifference == 1 && yNodeDifference == 1 ? 14 : 10;

						const int xDistance = abs(current_x - endNode.x);
						const int yDistance = abs(current_y - endNode.y);
						int heuristic = 10 * (xDistance + yDistance);

						nodeQueue.push(Vector2(current_x, current_y, heuristic));
				}

				for (int y = -1; y <= 1; y += 2)
				{
					const int current_x = openList[i].x;
					const int current_y = openList[i].y + y;

					bool alreadyCheckedNode = false;
					for (size_t i = 0; i < openList.size(); ++i)
					{
						if (current_x == openList[i].x && current_y == openList[i].y)
						{
							alreadyCheckedNode = true;
							break;
						}
					}

					if (alreadyCheckedNode)
						continue;

					if (current_x < 0 || current_x > w || current_y < 0 || current_y > h || (openList[i].x == current_x && openList[i].y == current_y))
						continue;

					if (mapArray[current_x][current_y] == "бс")
						continue;

					const int xNodeDifference = abs(current_x - (openList[i].x));
					const int yNodeDifference = abs(current_y - (openList[i].y));

					const int direction = xNodeDifference == 1 && yNodeDifference == 1 ? 14 : 10;

					const int xDistance = abs(current_x - endNode.x);
					const int yDistance = abs(current_y - endNode.y);
					int heuristic = 10 * (xDistance + yDistance);

					nodeQueue.push(Vector2(current_x, current_y, heuristic));
				}

				if (!nodeQueue.empty())
				{
					openList.push_back(nodeQueue.top());
					finalPath.push_back(nodeQueue.top());

					// Put into closed list
					while (!nodeQueue.empty())
					{
						closedList.push_back(nodeQueue.top());
						nodeQueue.pop();
					}
				}
			}
		}

		return finalPath;
	}
};

