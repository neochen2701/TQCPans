# 健康指標分析
def Calculate(num):
    thousand = num // 1000
    num = num % 1000
    hundred = num // 100
    num = num % 100
    ten = num // 10
    num = num % 10

    result = abs((thousand*hundred)-ten)*pow(3,num)
    result = str(bin(result))[2:]
    
    count = 0
    for i in range(len(result)):
        if result[i]=='1':
            count += 1

    return count

def data_sort(numbers):

    def key_function(num):
        return Calculate(num)

    sorted_numbers = sorted(numbers, key=key_function)

    return sorted_numbers

def PrintResult(result_list):
    result = ""
    
    for i in range(len(result_list)-1):
        result += str(result_list[i])+" "
    
    result += str(result_list[-1])
    
    print(result)

def func():
    data_list = list()  

    N = int(input())
    for _ in range(N):
        data_list.append(int(input()))

    result_list = data_sort(data_list)
    PrintResult(result_list)

if __name__ == "__main__":
    func()
