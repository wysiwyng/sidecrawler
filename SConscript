Import('env')

env.Append(CPPPATH=['src', 'dep/nfd', 'dep/nfd/include'])

sources = Split("""
src/linuxMain.cpp
src/PolycodeTemplateApp.cpp
dep/nfd/nfd_common.c
dep/nfd/nfd_gtk.c
""")

object_list = env.Object(source = sources)
t = env.Program(target = 'polytest', source = object_list)
Clean(t, 'res')
