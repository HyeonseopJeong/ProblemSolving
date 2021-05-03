//programmes : 124 나라의 숫자(level 2)
function solution(n) {
    if(n === 0) return '';
    
    let answer = solution(parseInt((n - 1) / 3)) + [4, 1, 2][n % 3];
    
    return answer;
}