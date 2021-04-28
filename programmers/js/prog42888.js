function solution(record) {
    const answer = [];
    const tmp = [];
    const id_to_nick = {};
    
    record.forEach((e)=>{
        const [behavior, id, nickname] = e.split(' ');

        if(behavior !== "Change") {
            tmp.push([behavior, id]);
        } 
        if(nickname) {
            id_to_nick[id] = nickname;
        }
    });

    tmp.forEach((e) => {
        const [behavior, id] = e;
        if(behavior === "Enter")
            answer.push(`${id_to_nick[id]}님이 들어왔습니다.`);
        else
            answer.push(`${id_to_nick[id]}님이 나갔습니다.`);
    });
    
    return answer;
}

console.log(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]));
