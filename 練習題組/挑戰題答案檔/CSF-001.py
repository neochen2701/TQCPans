def process_cat_logs(n, logs):
    activities_count = {}
    
    for log in logs:
        activity = log.split(' ', 1)[1]
        activities_count[activity] = activities_count.get(activity, 0) + 1
    print(len(activities_count))
    
    sorted_activities = sorted(activities_count.items(), key=lambda x: (-x[1], x[0]))
    
    for activity, count in sorted_activities:
        print(f"{count} {activity}")

if __name__ == '__main__':
    n = int(input())
    logs = [input() for _ in range(n)]
    process_cat_logs(n, logs)
