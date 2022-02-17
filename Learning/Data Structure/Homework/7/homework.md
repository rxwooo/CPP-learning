# ���ݽṹ��ҵ
<br/>

***
# 7.7
## 7.7.1
�ڽӾ���
| |a|b|c|d|e|f|g|h|
|-|-|-|-|-|-|-|-|-|
|a|��|4|3|��|��|��|��|��|
|b|4|��|5|5|9|��|��|��|
|c|3|5|��|5|��|��|��|5|
|d|��|5|5|��|7|6|5|4|
|e|��|9|��|7|��|3|��|��|
|f|��|��|��|6|3|��|2|��|
|g|��|��|��|5|��|2|��|6|
|h|��|��|5|4|��|��|6|��|

<img src="����ķ.jpg" width=70%>

## 7.7.2
�ڽӱ�  
a -> 2 -> 1^  
b -> 0 -> 2 -> 3 -> 4^  
c -> 7 -> 3 -> 1 -> 0^  
d -> 1 -> 2 -> 7 -> 6 -> 5 -> 4^  
e -> 1 -> 3 -> 5^  
f -> 4 -> 3 -> 6^  
g -> 5 -> 3 -> 7^  
h -> 6 -> 3 -> 2^  
<img src="��³˹����.jpg" width=70%>
<br/><br/><br/><br/>
***



# 7.10

|      |��|A|B|C|D|E|F|G|H|I|J|K|��|
|------|-|-|-|-|-|-|-|-|-|-|-|-|-|
|ve(vi)|0|1|6|17|3|34|4|3|13|1|31|22|44|
|vl(vi)|0|20|24|26|19|34|8|3|13|7|31|22|44|
<br/><br/>
|     |<��,A>|<��,B>|<��,D>|<��,F>|<��,G>|<��,I>|<A,C>|<B,C>|
| --  | --- | --- | --- | --- | --- | --- | --- | --- |
|e(ai)|0|0|0|0|0|0|0|1|6|
|l(ai)|19|18|16|4|0|6|20|24|
|     |<D,C>|<D,E>|<D,J>|<F,E>|<F,H>|<G,��>|<G,H>|<I,H>|
|e(ai)|3|3|3|4|4|3|3|1|
|l(ai)|19|26|25|23|8|23|3|7|
|     |<C,E>|<H,C>|<H,J>|<H,K>|<K,J>|<J,E>|<J,��>|<E,��>|
|e(ai)|17|13|13|13|22|31|31|34|
|l(ai)|26|22|27|13|22|31|32|34|
<br/>
�ؼ�·������ -> G -> H -> K -> J -> E -> ��

<br/><br/><br/><br/>
***
# 7.11
<img src="���·��.png" width=80%>

<br/><br/><br/><br/>
***
# 7.22
������ʵ���㷨��������Ҫ����
```
//���ض���u��ͼ/���е�λ��
int LocateVex(ALGraph G, VertexType u) {
    int i;
    
    for(i = 0; i < G.vexnum; i++) {
        if(G.vertices[i].data == u) {
            return i;
        }
    }
    return -1;
}
//ͨ��������ȱ������ж϶���vi��vj֮���Ƿ����·��
void Alg(ALGraph G, VertexType vi, VertexType vj) {
    int i, j, k;
    int path[MAX_VERTEX_NUM + 1];
    
    for(k = 0; k < G.vexnum; k++) {
        vis[k] = FALSE;
    }
    
    i = LocateVex(G, vi);
    j = LocateVex(G, vj);
    
    path[0] = 0;
    
    if(DFS_7_22(G, i, j, path) == ERROR) {
        printf("%c �� %c ֮�䲻����ͨ·��\n", vi, vj);
        return;
    }

    printf("%c �� %c ֮���ͨ·Ϊ��", vi, vj);
    for(k = 1; k <= path[0]; k++) {
        printf("%c ", GetVex(G, path[k]));
    }
    printf("\n");
}

//������ȱ���ͼG�����Ҷ���i������j֮���·������path
static Status DFS(ALGraph G, int i, int j, int path[MAX_VERTEX_NUM + 1]) {
    int w;
    
    // ������i����·��
    vis[i] = TRUE;
    path[0]++;
    path[path[0]] = i;
    
    if(i == j) {
        return OK;
    }
    
    // ����vi�����ڽӵ�
    for(w = FirstAdjVex(G, GetVex(G, i)); w >= 0; w = NextAdjVex(G, GetVex(G, i), GetVex(G, w))) {
        // �����ѷ��ʵĶ���
        if(vis[w]) {
            continue;
        }
        
        // �ݹ�(�������)
        if(DFS(G, w, j, path) == OK) {
            return OK;
        }
    }
    
    // �Ƴ�����i
    vis[i] = FALSE;
    path[0]--;
    
    return ERROR;
}
```

<br/><br/><br/><br/>
***

## 7.27  
������ʵ���㷨����Ҫ����
```
Status PathGra(ALGraph G, int start, int end, int k, int path[MAX_VERTEX_NUM]) {
    int w;
    
    path[0]++;
    path[path[0]] = start;
    vis[start] = TRUE;  // ��Ǹö����ѷ���
    
    // ��������յ㣬����Ҫ�����η���
    if(start == end) {
        // ������ = ·������+1
        if(path[0] == k + 1) {
            return OK;
        }
    } else {
        // ������ȱ���
        for(w = FirstAdjVex(G, G.vertices[start].data);
            w >= 0;
            w = NextAdjVex(G, G.vertices[start].data, G.vertices[w].data)) {
            // �����ѷ��ʹ��Ķ���
            if(vis[w] == TRUE) {
                continue;
            }
            
            if(PathGra(G, w, end, k, path) == OK) {
                return OK;
            }
        }
    }
    
    // ��·�����Ƴ��ö��㣬������״̬����Ϊ"�ѷ���"
    path[0]--;
    vis[start] = FALSE;  // ������ʱ��
    
    return ERROR;
}
```