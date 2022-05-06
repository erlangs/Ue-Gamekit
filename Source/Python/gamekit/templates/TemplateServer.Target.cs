// BSD 3-Clause License Copyright (c) 2022, Pierre Delaunay All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class {ProjectName}ServerTarget : TargetRules
{
    public {ProjectName}ServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("{ProjectName}");
    }
}
