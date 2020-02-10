#include <stdio.h>
#include <string.h>

struct tdata
{
 char nama[100];
 int priority;
};

tdata heap[1000];
int count;

void upHeap(int index)
{
 if(index == 1) return; // Kita berhenti recursive apabila index == akar pohon

 int tuaIndex = index / 2;
 tdata temp;
 if(heap[index].priority < heap[tuaIndex].priority)
 {
  temp = heap[index];
  heap[index] = heap[tuaIndex];
  heap[tuaIndex] = temp;

  // Setelah orang tua diupdate, kita upheap lagi
  upHeap(tuaIndex);
 }

}

void downHeap(int index)
{
 int curIdx = index;
 int curPrior = heap[index].priority;

 // Bandingkan dengan yang kiri
 if(index*2 < count && curPrior > heap[index*2].priority)
 {
  curIdx = index*2;
  curPrior = heap[index*2].priority;
 }

 // Bandingkan dengan yang kanan
 if(index*2+1 < count && curPrior > heap[index*2+1].priority)
 {
  curIdx = index*2+1;
  curPrior = heap[index*2+1].priority;
 }

 if(curIdx == index) return;

 // Tukar dengan anaknya yang paling kecil
 tdata temp;
 temp = heap[index];
 heap[index] = heap[curIdx];
 heap[curIdx] = temp;

 // Downheap lagi
 downHeap(curIdx);
}

void pushPriority(char *nama, int prior)
{
 // Taruh di paling belakang
 count++;
 strcpy(heap[count].nama,nama);
 heap[count].priority = prior;

 //upHeap (Bandingin sama orang tuanya)
 upHeap(count);
}

void popMinimum()
{
 //Ganti akarnya dengan yang paling belakang
 heap[1] = heap[count];
 count--;

 //Membenarkan heapnya
 downHeap(1);
}

int main()
{
 count = 0;

 pushPriority("Andre",5);
 pushPriority("Budi",4);
 pushPriority("Chico",3);
 pushPriority("Daniel",7);
 pushPriority("Ali",8);
 pushPriority("Jeremia",1);
 pushPriority("Dr.Stranger",2);
 pushPriority("Thanos",10);
 pushPriority("IronMan",15);
 pushPriority("Wiro212",12);

 for(int i=1;i<=count;i++)
 {
  printf("Urutan ke %d = %s dengan prioritas %d\n", i, heap[1].nama, heap[1].priority);
  popMinimum();
 }
 getchar();
 return 0;
}
