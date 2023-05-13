#include"Heap.h"
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>




void Swap(DataType* left, DataType* right) {
	int temp = *left;
	*left = *right;
	*right = *left;
}


//调整树相当与调整一个数组，将地址元素传进来之后我们不知道它有多少个节点，所以将元素的个数也传进来，调整的对象就是parent
void AdjustDown(DataType array[], int size, int parent) {
	int child = parent * 2 + 1;//child标记parent的左孩子，树是完全二叉树，先有左再有右孩子



	while (child < size) {
		//在保证有右孩子的时候，找两个孩子之中较小的孩子，要不会使得数组越界
		//因为是完全二叉树，所以可以使用child+1<size进行表示
		if (child + 1 < size && array[child + 1] < array[child]) {
			child += 1;//这里就是标记较小的孩子
		}

		//检测parent是否满足堆的特性,不满足就进行交换
		if (array[child] < array[parent]) {
			//交换双亲和孩子的大小，保证较小的在上边
			//要交换两个元素的大小需要传入的是地址
			Swap(&array[parent], &array[child]);
			//将双亲往下移动
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}


}



//向上调整
void AdjustUp(DataType array[], int size, int child) {
	int parent = (child - 1) / 2;

	while (child) {
		if (array[child] < array[parent]) {
			Swap(array[child], array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}

}

/////////////////////////堆的各种实现////////////////////////////////////////


//堆的构建

//先将输入的这些元素拷贝到堆中的数组之中
void HeapCreat(Heap* hp, DataType* a, int n) {
	hp->array = (DataType*)malloc(sizeof(DataType) * n);
	if (hp->array == NULL) {
		assert(0);
		return;
	}
	hp->CapaCity = n;

	memcpy(hp->array, a, sizeof(DataType) * n);//注意这个函数拷贝的时候第三个参数就是拷贝的是字节的大小

	hp->size = n;

	//对堆进行调整
	// 这个的调整方式就是需要保证除了叶子节点其他的都满足堆的特性，所以要先要求后边为堆
	//因为不能保证每次调整的时候都是完全二叉树，所以需要从下边的倒数第一个非叶子节点开始往上调整
	//最后一个叶子节点的下标是n-1，求他的双亲就是(n-1-1）/2

	for (int root = (n - 2) / 2;root >= 0;root--) {
		//每次减去1就是往上进行调整每一棵树，最后0就是调整n
		AdjustDown(hp->array, hp->size, root);
	}

}

//堆的销毁


void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->CapaCity = 0;
	hp->size = 0;
}
//堆的销毁就是将堆中申请的空间释放掉


//检查堆的空间是否足够
//与顺序表中的类似，，都是使用二倍开辟，然后将元素拷贝进去
void CheckHeap(Heap *hp) {
	assert(hp);

	if (hp->CapaCity == hp->size) {
		int newCapaCity = hp->CapaCity * 2;


		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapaCity);


		if (temp == NULL) {
			assert(0);
			printf("空间申请失败！！！");
			return;
		}

		memcpy(temp, hp->array, sizeof(DataType) * hp->size);

		free(hp->array);

		hp->array = temp;
		hp->CapaCity = newCapaCity;

	}
}



//堆的插入

void HeapPush(Heap* hp, DataType x) {
	assert(hp);
	CheckHeap(hp);
	hp->array[hp->size] = x;
	hp->size++;

	AdjustUp(hp->array, hp->size, hp->array[hp->size]);

}
//堆的插入就是将元素插入后再次调整，保证堆的结构完整
//插入到最后一个元素，然后再往上调


//堆的删除

void HeapPop(Heap* hp) {
	if (HeapEmpty(hp)) {
		return;
	}
	//堆中有元素
	//进行交换
	Swap(&hp->array[0], &hp->array[hp->size - 1]);

	//堆中的元素个数减一
	hp->size--;


	//将堆顶的元素往下调
	AdjustDown(hp->array, hp->size, 0);

}
//将堆顶元素删除，再进行调整，再将个数减一
//删除的方法是将最后一个元素和堆顶的元素进行交换，然后size--，最后一个元素就访问不到了，之后再进行调整



//获取堆顶元素

DataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->array[0];
}
//比较简单，就是将数组的第一个元素a[0]输出就行


//堆中数据的个数

int HeapSize(Heap* hp) {
	assert(hp);
	return hp->size;
}
//就是将堆中的个数输出就行



//堆的判空

int HeapEmpty(Heap* hp) {
	assert(hp);
	return 0 == hp->size;//如果堆元素的个数为0的话就会返回真
}
//直接就是判断堆元素个数是否为0

void TestHeap() {

	DataType array[] = { 27,10,32,15.16 };
	Heap hp;
	HeapCreat(&hp, array, sizeof(array) / sizeof(array[0]));


	printf("size = %d\n", HeapSize(&hp));
	printf("size = %d\n", HeapTop(&hp));


	HeapPop(&hp);

	printf("size = %d\n", HeapSize(&hp));
	printf("size = %d\n", HeapTop(&hp));

	//.......
	HeapDestory(&hp);

}


//堆的排序就是
/*
1.建堆 升序就是建大堆，将根节点最大的堆叫做最大堆或大根堆，根节点最小的堆叫做最小堆或小根堆。
因为利用堆排序的思想就是建立堆之后1利用堆删除的思想，将堆顶最大的或者最小的元素与最后一个
叶子节点交换位置，如：建立大堆的话就是将最大的元素放到了最后边，实现了升序的功能
调整好之后将堆顶元素与最后一个元素进行交换位置，然后让size-1；
*/

Heap* LessSort(int array[], int size) {

	//实现利用堆思想从小到大排序，就是要把大的元素放到后边，所以建大堆
	int lastNodeLeaf = (size - 2) / 2;
	for (int root = lastNodeLeaf;root >= 0;root--) {
		AdjustDown(array, size, root);
	}

	//利用堆删除的思想进行排序
	int end = size - 1;
	while (end) {
		swap(&array[0], &array[end]);
		AdjustDown(array, end, 0);
		end--;
	}
}








/*
* Top-k问题
* 因为数据量可能太大导致无法运行或者需要时间太长，这时候如果要求前k个最大的或者最小的元素
* 先把前k个元素进行加建堆，如果是要进行求前k个最大的元素，就i要建小堆，把较小的元素放到首位然后
* 与n-k中较大的元素进行替换，然后再进行调整，保证每一次替换出去的都是最小的哪一个
* 前k给最小的也是一样的，只不过要建一个大堆，保证每次换出去的都是较大的哪一个元素
*/



int main() {
	TestHeap();
	return 0;
}