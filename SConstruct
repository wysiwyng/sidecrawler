debug = int(ARGUMENTS.get('debug', 1))

env = Environment()

env.Append(CPPPATH=['dep/polycode/Core/include', 'dep/polycode/Core/Dependencies/include', 'dep/polycode/Core/Dependencies/include/AL', 'dep/polycode/Modules/include', 'dep/polycode/Modules/Dependencies/include', 'dep/polycode/Modules/Dependencies/include/bullet'])
env.Append(LIBPATH=['dep/polycode/Core/lib', 'dep/polycode/Core/Dependencies/lib', 'dep/polycode/Modules/lib', 'dep/polycode/Modules/Dependencies/lib'])

env.ParseConfig( 'pkg-config --cflags --libs gtk+-3.0' )

env.Append(CCFLAGS='-Wall')
env.Append(CCFLAGS='-pthread')

if debug:
    env.Append(CCFLAGS='-O0')
    env.Append(CCFLAGS='-g3')

    env.Append(LIBS = ['rt', 'dl', 'pthread', 'Polycore_d', 'freetype_d', 'liblibvorbisfiled', 'liblibvorbisd', 'libliboggd', 'openald', 'physfsd', 'png15d', 'z', 'GL', 'GLU', 'SDL', 'Polycode2DPhysics_d', 'Box2D_d', 'Polycode3DPhysics_d', 'BulletDynamics_d', 'BulletCollision_d', 'LinearMath_d', 'X11'])

    blarg = 'bin/linux/debug'
else:
    env.Append(CCFLAGS='-O3')

    env.Append(LIBS = ['rt', 'dl', 'pthread', 'Polycore', 'freetype', 'liblibvorbisfile', 'liblibvorbis', 'liblibogg', 'openal', 'physfs', 'png15', 'z', 'GL', 'GLU', 'SDL', 'Polycode2DPhysics', 'Box2D', 'Polycode3DPhysics', 'BulletDynamics', 'BulletCollision', 'LinearMath', 'X11'])

    blarg = 'bin/linux/release'

AlwaysBuild(env.Install(blarg, 'res'))
SConscript('SConscript', variant_dir=blarg, exports={'env' : env}, duplicate=0)

