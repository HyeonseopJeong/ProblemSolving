// 프로그래머스 level 1 : 로또의 최고 순위와 최저 순위
// array api : filter(), include() 써보기!

function solution(lottos, win_nums) {
    let zero_num = lottos.filter((el) => el === 0).length;
    let match_num = 0;
    
    for(let n of lottos) {
        if(win_nums.includes(n))
            match_num += 1;
    }
    
    let best = 7 - match_num - zero_num;
    let worst = 7 - match_num;
    
    if(best === 7) best -= 1;
    if(worst === 7) worst -= 1;
    
    return [best, worst];
}