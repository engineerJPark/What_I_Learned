# 오목 인공지능 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ

오목과 같은 zero-sum 게임은 minimax, alpha-pruning 알고리즘을 이용한다.

## mininax

2인 zero-sum 게임에서 가장 기본이 되는 알고리즘.
인공지능과 사람이 모두 최적에 가까운 수를 둔다는 가정을 두고 논리를 전개한다.

minimax 알고리즘의 평가함수는 상황에 따라서 다르게 작성할 수 있다.

- 정해진 depth까지 노드의 가짓수를 탐색한다.
- 모든 플레이어가 합리적이라는 가정을 한다. 우리는 평가가 높은 경우만 선택한다. 상대는 우리의 상황에 대해 평가각 낮은 경우만을 선택한다.
- 우리를 max, 상대방을 min으로 정한다.

4수 앞을 내다본다고 하면, 4수에서 3수, 2수, 1수로 역으로 계산해서 1수를 계산한다.
깊이 우선 탐색(DFS). 모든 경우를 탐색.

## Alpha-Beta Pruning 알고리즘

minimax를 개선한 알고리즘이다. 깊이 우선 탐색(DFS)
- 도달 가능성 없는 노드는 탐색하지 않는다.
- 예를 들면, max 노드의 min 자식 노드 중 하나가 3이라는 값을 가지면, max노드는 항상 3 이상이다. 그러므로 max 노드의 min의 자식 노드 중, max 노드가 3 이하의 값을 가지게 하는 노드가 하나라도 있다면 해당 min 노드는 더 이상 탐색하지 않는다.

## 평가 함수의 작성

minimax, alpha-beta pruning 알고리즘은 정해진 작성방법이 있다.
평가함수는 알고리즘 설계자가 임의로 설정해야한다.
평가함수 알고리즘의 효율성 개선을 위해 노력하자.

## 오목 게임에서의 평가 함수

열린사가 닫힌 삼보다 강력한 수 인 건 당연
열린삼이 닫힌 사보다 가치로운지는 모름
이런 상황들을 종합해서 정량화해야한다.
예를들면
- 오목 1000000
- 열린 사 : 200000
- 하나 닫힌 사 : 15000
- 열린 삼 : 4000
- 닫힌 사 : 1500
- 하나 닫힌 삼 : 1500
- 열린 이 : 1500
- 닫힌 삼 300
- 하나 닫힌 이 : 300
- 닫힌 이 : 50
- 바둑판의 천원점과 가까울 수록 점수 가산하기

----

# 구현

Menuform.cs에서 '인공지능 연습'버튼 생성 : AIPlayButton
AIPlayForm.cs 만들기 : 크기 880 580으로 수정하기. picutre box 그리기
그 전에 혼자하기랑 같은 방법으로 UI만들기
