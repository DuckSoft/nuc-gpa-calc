' =========================
' 注意：这是FreeBasic文件！
' =========================

declare function getGP(score as single, point as single) as single

print !"中北大学GPA计算器\n" _
		!"--------------------------\n" _
		!"附：五级制科目分数折合表：\n" _
		!"  优秀：95  |  良好：85\n" _
		!"  中等：75  |  及格：65\n" _
		!"--------------------------\n"

dim as single sumPoint, sumGP
dim as integer n = 1

do
	dim as single nPoint
	print using !"课程 _#& 学分(如：4.0；输入负数结束):"; n
	input "->",nPoint
	
	if nPoint<0 then
		if n=1 then	end
		exit do
	else
		sumPoint+=nPoint
		dim as integer nScore
		
		scoreinput:
			print using !"课程 _#& 考试成绩(0～100):"; n
			input "->",nScore
			
		if nScore<0 orelse nScore > 100 then
			print " 输入的成绩无效！请重新输入！"
			goto scoreinput
		endif
		
		sumGP+=getGP(nScore,nPoint)
	endif
	print ""
	
	n+=1
loop

print using _
	!"================\n" _
	!"你的GPA是：\n" _
	!" => #.#\n" _
	!"================\n"; sumGP/sumPoint

sleep

function getGP(score as single, pt as single) as single
	if score < 60 then
		return 0.0
	else
		return pt*(score/10-5)
	endif
end function


