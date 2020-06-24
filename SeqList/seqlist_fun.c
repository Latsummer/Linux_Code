#include"Seqlist.h"
#include<stdlib.h>

void SeqListInit(SeqList* sl)//初始化
{
  sl->size = 0;
  sl->capicity = 20;
  sl->arr = (SLDataType*)malloc(sizeof(SLDataType) * sl->capicity);
}
void SeqListDestory(SeqList* sl)//销毁
{
  sl->size = 0;
  free(sl->arr);
  printf("已删除\n");
}
void SeqListPrint(SeqList* sl)//打印
{
  size_t i = 0;
  for(i = 0; i < sl->size; i++)
  {
    printf("%d ", sl->arr[i]);
  }
  printf("\n");
}
void CheckCapacity(SeqList* sl)//检查或扩容
{
  if(sl->size >= sl->capicity)
  {
    sl->capicity *= 2;
    sl->arr = realloc(sl->arr, sizeof(SLDataType) * sl->capicity);
  }
}
void PushBack(SeqList* sl, SLDataType data)//尾插
{
  CheckCapacity(sl);
  sl->arr[sl->size++] = data;
}
void PopBack(SeqList* sl)//尾删
{
  sl->size--;
}
void PushFront(SeqList* sl, SLDataType data)//头插
{
  CheckCapacity(sl);
  size_t end = sl->size;
  while(end > 0)
  {
    sl->arr[end] = sl->arr[end - 1];
    end--;
  }
  sl->size++;
  sl->arr[0] = data;
}
void PopFront(SeqList* sl)//头删
{
  size_t i = 0;
  for(i = 0; i < sl->size; i++)
  {
    sl->arr[i] = sl->arr[i + 1];
  }
  sl->size--;
}

int SeqListFind(SeqList* sl, SLDataType data)//查找
{
  size_t find = 0;
  for(find = 0; find < sl->size; find++)
  {
    if(sl->arr[find] == data)
      return find + 1;
  }
  return 0;
}
void SeqListInsert(SeqList* sl, size_t pos, SLDataType data)//pos位置插入
{
  CheckCapacity(sl);
  size_t end = sl->size;
  while(end > (pos - 1))
  {
    sl->arr[end] = sl->arr[end - 1];
    end--;
  }
  sl->size++;
  sl->arr[pos - 1] = data;
}
void SeqListErase(SeqList* sl, size_t pos)//pos位置删除
{
  size_t erase = pos - 1;
  while(erase < sl->size)
  {
    sl->arr[erase] = sl->arr[erase + 1];
    erase++;
  }
  sl->size--;
}
