#include <iostream>
#include <vector>
#include <queue>

std::vector<int> tasks;

bool RequestQuests(std::string input)
{
    bool success = true;
    size_t pos = 0;
    while ((pos = input.find(',')) != std::string::npos)
    {
        std::string taskString = input.substr(0, pos);
        input.erase(0, pos + 1);

        try
        {
            int taskReward = std::stoi(taskString);
            if (taskReward >= 0)
            {
                tasks.push_back(taskReward);
            }
            else
            {
                std::cout << "error" << std::endl;
                success = false;
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "error" << std::endl;
            success = false;
            break;
        }
    }

    try
    {
        int taskReward = std::stoi(input);
        if (taskReward >= 0)
        {
            tasks.push_back(taskReward);
        }
        else
        {
            std::cout << "error" << std::endl;
            success = false;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "error" << std::endl;
        success = false;
    }

    return success;
}

int CalculateTotalReward(std::vector<int> &tasks)
{
    int totalReward = 0;
    std::queue<int> taskQueue;

    for (int task : tasks)
    {
        taskQueue.push(task);
    }

    int morningTasks = 3;
    int noonTasks = 2;
    int nightTasks = 1;

    while (!taskQueue.empty())
    {
        for (int i = 0; i < morningTasks && !taskQueue.empty(); i++)
        {
            totalReward += taskQueue.front() * 3;
            taskQueue.pop();
        }

        for (int i = 0; i < noonTasks && !taskQueue.empty(); i++)
        {
            totalReward += taskQueue.front() * 2;
            taskQueue.pop();
        }

        for (int i = 0; i < nightTasks && !taskQueue.empty(); i++)
        {
            totalReward += taskQueue.front();
            taskQueue.pop();
        }
    }

    return totalReward;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    if (RequestQuests(input))
    {
        int totalReward = CalculateTotalReward(tasks);
        std::cout << totalReward << std::endl;
    }

    return 0;
}
