
from itertools import combinations
import sys

def get_teams(players, team_size) :
    all_players = set(players)
    results = []

    for team_1 in combinations(players, team_size) :
        team_a = set(team_1)
        team_b = all_players - team_a
        results.append((sorted(list(team_a)), sorted(list(team_b))))

    return results

def get_team_score(matrix, players) :
    sum = 0
    for team in combinations(players, 2) :
        #print("P0 : ", team[0], "P1 : ", team[1])
        sum += (matrix[team[0]][team[1]] + matrix[team[1]][team[0]])
    return sum


N = int(input())
players = list(i for i in range(N))
matrix = [[0] * N] * N

for y in range(N) :
    matrix[y] = list(map(int, input().split()))

teams = get_teams(players, N//2)

min = sys.maxsize
for i, (team_a, team_b) in enumerate(teams) :
    score_a = get_team_score(matrix, team_a)
    #print("Team A : ", score_a)

    score_b = get_team_score(matrix, team_b)
    #print("Team B : ", score_b)

    diff = abs(score_a - score_b)
    min = diff if diff < min else min

print(min)
