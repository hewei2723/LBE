# Create a new directed graph for the updated ER diagram
er_diagram_hospital = Digraph('ER Diagram Hospital', format='png')
er_diagram_hospital.attr(rankdir='LR')

# Add entities
er_diagram_hospital.node('Dept', '科室\n(科室名, 科室地址, 科室电话)', shape='box', style='rounded')
er_diagram_hospital.node('Ward', '病房\n(病房号, 地址)', shape='box', style='rounded')
er_diagram_hospital.node('Doctor', '医生\n(工作证号, 姓名, 职称, 年龄)', shape='box', style='rounded')
er_diagram_hospital.node('Patient', '病人\n(住院号, 姓名, 性别)', shape='box', style='rounded')

# Add relationships with labels and cardinality
er_diagram_hospital.edge('Dept', 'Ward', label='1:N', style='bold')
er_diagram_hospital.edge('Dept', 'Doctor', label='1:N', style='bold')
er_diagram_hospital.edge('Ward', 'Patient', label='1:N', style='bold')
er_diagram_hospital.edge('Doctor', 'Patient', label='1:N', style='bold')

# Render the graph
er_diagram_hospital.render('/mnt/data/er_diagram_hospital', view=False)
'/mnt/data/er_diagram_hospital.png'
