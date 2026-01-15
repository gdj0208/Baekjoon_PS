
def get_type_and_degree() :
    type, degree = list(map(int, input().split()))
    return type, degree

def get_crys(type, degree) :
    # 등차수열의 합 = (항의 수 * (2*첫 항 + 등차*(항의 수 - 1) )) / 2
    return (degree + 1) * ((type - 2) * degree + 2) // 2

print(get_crys(*get_type_and_degree()))