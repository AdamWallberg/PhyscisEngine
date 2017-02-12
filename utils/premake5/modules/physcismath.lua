PM_ROOT_DIR = "H:/Programming/C++/PhyscisMath/"

function pm_enable()
	
	includedirs {
		PM_ROOT_DIR .. "source/code/",
	}
	
	libdirs {
		PM_ROOT_DIR .. "lib/",
	}
	
	links{
		"PhyscisMath_$(Configuration)",
	}
		
end