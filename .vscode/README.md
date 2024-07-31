# CLeanup Taks

I tried to add something to the task.json today to help me clean up my builds better. I came up with a console command that does exactly what I want .

`rmdir /s /q .\Temp\debug && del /q .\Builds\debug\Tower_debug.lib`

The problem is, it wont work like this in the tasks.json. This does not work, for instance:

```
 {
    "label": "Clean Debug Build Files",
    "type": "shell",
    "command": "rmdir /s .\\Temp\\debug; del .\\Builds\\debug\\Tower_debug.lib",
    "group": "build"
},
```

It does not like the args. A format like this would work:

```
 {
    "label": "Clean Debug Build Files",
    "type": "shell",
    "command": "rmdir",
    "args": ["/s", ".\\Temp\\debug"],
    "group": "build"
},
```

But this would require 2 tasks, one to delete the temp directory, and one to delete the target. I don't want to deal with that, and can't waste any more time trying to figure out how to chain commands in a tasks.json. Oh well, maybe another time.

## I tried again...

```
 {
      "label": "Delete Temp Debug",
      "type": "shell",
      "command": "rmdir",
      "args": [".\\Temp\\debug"]
    },
    {
      "label": "Delete Debug Target",
      "type": "shell",
      "command": "Remove-Item",
      "args": [".\\Builds\\debug\\Tower_debug.lib"]
    },
    {
      "label": "Delete Temp Release",
      "type": "shell",
      "command": "rmdir",
      "args": [".\\Temp\\release"]
    },
    {
      "label": "Delete Release Target",
      "type": "shell",
      "command": "Remove-Item",
      "args": [".\\Builds\\release\\Tower_release.lib"]
    },
    {
      "label": "Clean Debug Build",
      "dependsOn": ["Delete Debug Target", "Debug Build"],
      "group": "build"
    },
    {
      "label": "Clean Release Build",
      "dependsOn": ["Delete Release Target", "Release Build"],
      "group": "build"
    }
```

Using the deponds on works, but the Remove-Item commands are still not working. I'm not sure why. I've relaly spent way too much time on this now.
