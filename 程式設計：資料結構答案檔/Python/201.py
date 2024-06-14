def request_quests(input_str):
    tasks = []
    for part in input_str.split(','):
        try:
            task_reward = int(part)
            if task_reward < 0:
                print("error")
                return None
            tasks.append(task_reward)
        except ValueError:
            print("error")
            return None
    return tasks

def calculate_total_reward(tasks):
    total_reward = 0
    morning_tasks = 3
    noon_tasks = 2
    night_tasks = 1

    i = 0
    while i < len(tasks):
        for _ in range(morning_tasks):
            if i < len(tasks):
                total_reward += tasks[i] * 3
                i += 1
        for _ in range(noon_tasks):
            if i < len(tasks):
                total_reward += tasks[i] * 2
                i += 1
        for _ in range(night_tasks):
            if i < len(tasks):
                total_reward += tasks[i]
                i += 1
                
    return total_reward

input_str = input()
tasks = request_quests(input_str)
if tasks is not None:
    total_reward = calculate_total_reward(tasks)
    print(total_reward)
