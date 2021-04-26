// 프로그래머스 level2 : 기능개발
function solution(progresses, speeds) {
    const answer = [];
    const len = progresses.length;
    
    let cnt = 0;
    
    for (let i = 0; i < len; i++) {
        if(progresses[i] >= 100) {
            cnt++;
            continue;
        }
        else if(cnt) {
            answer.push(cnt);
            cnt = 0;
        }
        
        let remain_days = parseInt((100 - progresses[i] - 1) / speeds[i]) + 1;
        
        for (let j = i; j < len; j++) {
            progresses[j] += remain_days * speeds[j];
        }
        cnt = 1;
    }
    
    if(cnt)
        answer.push(cnt);
    
    return answer;
}