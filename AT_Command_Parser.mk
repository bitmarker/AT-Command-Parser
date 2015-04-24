##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AT_Command_Parser
ConfigurationName      :=Debug
WorkspacePath          := "/Users/leonidlezner/Documents/Dev/Leo"
ProjectPath            := "/Users/leonidlezner/Documents/Dev/Leo/AT_Command_Parser"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Leonid Lezner
Date                   :=2015-04-24
CodeLitePath           :="/Users/leonidlezner/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="AT_Command_Parser.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/at_parser.c$(ObjectSuffix) $(IntermediateDirectory)/my_string.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/leonidlezner/Documents/Dev/Leo/AT_Command_Parser/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/at_parser.c$(ObjectSuffix): at_parser.c $(IntermediateDirectory)/at_parser.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/leonidlezner/Documents/Dev/Leo/AT_Command_Parser/at_parser.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/at_parser.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/at_parser.c$(DependSuffix): at_parser.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/at_parser.c$(ObjectSuffix) -MF$(IntermediateDirectory)/at_parser.c$(DependSuffix) -MM "at_parser.c"

$(IntermediateDirectory)/at_parser.c$(PreprocessSuffix): at_parser.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/at_parser.c$(PreprocessSuffix) "at_parser.c"

$(IntermediateDirectory)/my_string.c$(ObjectSuffix): my_string.c $(IntermediateDirectory)/my_string.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/leonidlezner/Documents/Dev/Leo/AT_Command_Parser/my_string.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/my_string.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/my_string.c$(DependSuffix): my_string.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/my_string.c$(ObjectSuffix) -MF$(IntermediateDirectory)/my_string.c$(DependSuffix) -MM "my_string.c"

$(IntermediateDirectory)/my_string.c$(PreprocessSuffix): my_string.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/my_string.c$(PreprocessSuffix) "my_string.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


