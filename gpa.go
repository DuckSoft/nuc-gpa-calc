package main

import (
	"fmt"
	"time"
)
func main()  {
	fmt.Println(`中北大学GPA计算器
--------------------------
附：五级制科目分数折合表：
  优秀：95  |  良好：85
  中等：75  |  及格：65
--------------------------`)
	var sumPoint float32 = 0
	var sumGP float32 = 0

	for n:=1; ; n++ {
		var nPoint float32
		fmt.Printf("课程 #%d 学分(如：4.0；输入负数结束):\n ->",n)
		fmt.Scanf("%f\n",&nPoint)

		if nPoint < 0 {
			if n==1 {
				return
			}
			break
		} else {
			sumPoint += nPoint

			var nScore int
scoreinput:
			fmt.Printf("课程 #%d 考试成绩(0～100):\n ->", n)
			fmt.Scanf("%d\n",&nScore)

			if nScore<0 || nScore>100 {
				fmt.Printf(" - 输入的成绩无效！请重新输入！")
				goto scoreinput;
			}

			sumGP += func (score int, point float32) float32 {
				if score < 60 {
					return 0.0;
				} else {
					return point*(float32(score)/10-5);
				}
			} (nScore, nPoint);
		}

		fmt.Println("")
	}

	fmt.Printf(`
================
你的GPA是：
 => %.1f
================`, sumGP/sumPoint)

	time.Sleep(2*time.Second)
}