' =========================
' ע�⣺����FreeBasic�ļ���
' =========================

declare function getGP(score as single, point as single) as single

print !"�б���ѧGPA������\n" _
		!"--------------------------\n" _
		!"�����弶�ƿ�Ŀ�����ۺϱ�\n" _
		!"  ���㣺95  |  ���ã�85\n" _
		!"  �еȣ�75  |  ����65\n" _
		!"--------------------------\n"

dim as single sumPoint, sumGP
dim as integer n = 1

do
	dim as single nPoint
	print using !"�γ� _#& ѧ��(�磺4.0�����븺������):"; n
	input "->",nPoint
	
	if nPoint<0 then
		if n=1 then	end
		exit do
	else
		sumPoint+=nPoint
		dim as integer nScore
		
		scoreinput:
			print using !"�γ� _#& ���Գɼ�(0��100):"; n
			input "->",nScore
			
		if nScore<0 orelse nScore > 100 then
			print " ����ĳɼ���Ч�����������룡"
			goto scoreinput
		endif
		
		sumGP+=getGP(nScore,nPoint)
	endif
	print ""
	
	n+=1
loop

print using _
	!"================\n" _
	!"���GPA�ǣ�\n" _
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


