// (////////////(((((((((#%,,,*////////////////////////////////////////////,,,/##%#%%%%%%%%%%%%#(((#%%%
// (((((((/////////////#,,,////#///////////////////////////////////////////////*,,%%%%###%%#((##%%%%###
// ########((((((/////,,////(/////////////////////////////////////////////////////,,*%%#(#####%%####%%#
// %%##############,,/////#////,////////////////*/////////////////#//////////////////,,%%%%%%%####(((#%
// %%%%%%%%%%%###,,/,///(//////////////////(///,,//*///////////////#///////////////////,/#####((#%%####
// %%%%%%%&%#%%,,////////////////////%////#/(//,////////////////////#//////////(/////,///,((#%%%%%%%%%%
// %%%%%&#/((,,//////(//////%///////#////(/(///////////(/////////////(//////////#////*////,%%####%%#((#
// %%%%%%%/(,///////(//////%(//////(////#//////////////(////////////////////////////%//////,#%%######%%
// %%%&%%%,//%//////(///((%//(&((#,(#&((/#/////////////*(////((///////%//////////#(/((((/#///%%%%%%%%%#
// %%%%%%,((*//((((#(((((&/((///*.(//((/(((((((((((///(*(((((#(/##((((/(((((((((((##((((((((%(%%%%%%%%#
// %%%%%,(%%((((/(((((((%#(///(...///(/%#(((((((((////.*/((((,((((((#%((((((((((((####((((((((/(/,,%%%%
// %%%%,(%%&((((/((((((#,/(///...#//((((((((((((#(/((..,(///(,/((((((#(((((((((((((((((((((((((((/,###%
// %%%%(%%%#(((/(((((((*.((//....((((#((((((((((((//...*/((/(,#((((((##((((((((((((((((((((((((((((,(##
// %%%%#%%%%((#*(((((((,.///.....((((,(%(((((((#((/....,/(//..,(((#(((#(((((((((((&((((((((#(((((((,###
// &&&&&&&&&((%((((%((%,./(,.%%%%%&(#/((((((((#((#......###%,..,((((((#(((((((((((((((((##(#(((((#(,%##
// &&&&&&&&&&%%%%(((((%#.(%%% ...&&#&&%((((((#((........#(#&%##(((((((#((((((((((((%((#(((((((((#((/%%%
// &&&&&&&&&&&&%(((((###%%%   &&&&#(##(&((((#((.....%%/.&,(%%..,%%&(#(#((((((((((((##(((((#(((((#(&%%%%
// &&&&&&&&&&&&(((((((##.#%  .&&&@&%&&(((((%#........   &&&&##(( .%%&(#((((((((((%#(((((((((((#&(&@@&&&
// &&&&&&&&&&&((((((((##...  .%,*@@%*%.(((/..........  %&&&@%&&&&.. &&&&%%((((((((((((((((((((%&@@@@@@@
// &&&&&&&&&&((&((((%(##*.....&,,,,** ../(,.......... .#(/@@@%/&% .%&(((((((((((#(((((((#(((((%#&&&&&&&
// &&&&&&&&(((%((((((###(,,.,,,.,......../...........  %,**,**%% ...#(%(((((((((.#*#(((((((((#&#%##%&@@
// &&&&&&&((&&((((((#&#%/,,,,,,..........................*,.(.,,,,,%(#(((((((#(#*#/.((#((((((#%%#&&&%%%
// &&&&&&%(&&&(((((#,%#,#,,................................,,,,,,,#(#(((((((%(#//...#(#(((((%%&%%#&&&&%
// &&&&&&(&&&&(((%&#%&#%%..................................,,,,,,(%#((((((#&((***.(.((#(((((&&%##%#&#%&
// &&&&&&&&&&&(((&&&&&%&&,....................................,(#,#(((((%#%(**...(#((((%%((#%%##%&&%%&%
// &&&&&&&&&&&&&(&&&&&&&&&/............**,,,,,,,*............,,..#((((%##%#,...%(&#((((((((%%&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&&&&&&&(%........../,,,,,,,,*............../(#../&##&##.*###(%#((((((#(%%###%&%%##%
// &&&&&&&&&&&&&&&&&&&&&&&(((((.........,,,,,,,,.................*###%####&######(#(((((((%(((%#####%&&
// &&&&&&&&&&&&&&&&&&&&&&&#((((((%.......(,,,,..............,**%######%###%######(#((((((((%#(%(((#%%%%
// &&&&&&&&&&&&&&&&&&&&&&((((((((##%#..................*/******#######&###%%&#####%(((((##((((((%%%%%##
// &&&@@@@@@@@@@@@@&&&@@(((((#((#&#%####.........@*,***********###########%&#%####(#(((((##((((/((%#&&&
// @@@@&&&&&@&&&&&@@@@&((((%#((#&############%@****************%##%####%##&%#&#####%(((((#%#(((%(&&&%##
// &&&&&&&%%&%&&&&&&&&%((((#((#&####&########(****,,,,,,,,,,***%***%####&##%&#%######(((((#%#(((&((%%&%
// %%%%%%&&&&&&&%%%%%((@(((((%#####%%((%#%****%*****************(/***&###%(#%########((((((#&#(((%%((&&
// %&&%##%&%%%%%###((%(((((#%#%####%#((%***(//%****,************#*******###(##########(((((##&#((((##((
// &&%&&&&#(((#%&%(%%(((#(#%######%#%(%***#/*,*****************************(%###,/######((((##&##(((%&%
// %%%%###%&&&%%(#%%(((#((&##%####//(#*****,***************************...,.(*.../...%##%(((####%#((((%
// ####%&&&%%%&(&%##(((#(###*&(...*##****#*****************/******,...../...,(,.............,##%#%#(((%
// &&&&&%###%%((%&&&(((%,..&%.....#(*********/#(*********#***,........,////,/((#///*...........&&&&#(((
// %%%%%###%&&((#%%,......%%*....##..****************(.,,...........#////////#((%/#&&&......(,.*%%%%(((
//                                     キターーーーン

#include<bits/stdc++.h>//                                     キターーーーン

using namespace std;//                                     キターーーーン

vector<pair<int,int>> v[100009];//                                     キターーーーン
bool vst[100009];//                                     キターーーーン

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);//                                     キターーーーン
    int n, m; cin >> n >> m;//                                     キターーーーン
    for(int i=0;i<m;++i) {//                                     キターーーーン
        int a,b,c; cin >> a >> b >> c;//                                     キターーーーン
        v[a].push_back({b,c});//                                     キターーーーン
        v[b].push_back({a,c});//                                     キターーーーン
    }//                                     キターーーーン

    int k; cin >> k;//                                     キターーーーン
    for(int i=0;i<k;++i) {//                                     キターーーーン
        int a,b; cin >> a >> b;//                                     キターーーーン
        v[100001].push_back({a,b});//                                     キターーーーン
    }//                                     キターーーーン

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //                                     キターーーーン
    pq.push({0,100001});//                                     キターーーーン
    while(pq.size()) {//                                     キターーーーン
        int cost = pq.top().first;//                                     キターーーーン
        int city = pq.top().second;//                                     キターーーーン
        pq.pop();//                                     キターーーーン
        
        if(vst[city]) continue;//                                     キターーーーン
        vst[city] = true;//                                     キターーーーン

        if(city == 0) {//                                     キターーーーン
            cout << cost;//                                     キターーーーン
            break;//                                     キターーーーン
        }//                                     キターーーーン

        for(auto it : v[city]) {//                                     キターーーーン
            if(!vst[it.first]) pq.push({cost+it.second,it.first});//                                     キターーーーン
        }//                                     キターーーーン
    }//                                     キターーーーン
    
}//                                     キターーーーン