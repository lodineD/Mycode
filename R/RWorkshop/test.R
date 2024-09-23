PatientID = c(1,2,3,4)
AdmData = c("10/15/2009", "11/01/2009", "10/21/2009", "10/28/2009")
Age = c(25, 34, 28, 52)
Diabetes = c("Type1","Type2","Type3","Type1")
Status = c("Poor", "Improved","Excellent", "Poor")
rname1 = c("PatientID", "AdmData", "Age", "Diabetes","Status")

PatientData = data.frame(PatientID, AdmData, Age, Diabetes, Status)

PatientData
PatientData[c("PatientID", "Age")]
PatientData$Status

Age
# attach()函数用于把一部分数据表单存入内存中，输入列可以直接显示结果age
# attach(PatientData) # 由于已经运行过了，所以这个函数在此文件中没有作用

with(PatientData, {Age*PatientID})
