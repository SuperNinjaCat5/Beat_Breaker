g++ src\main.cpp `
    src\modules\MusicPlayer.cpp `
    src\modules\Metronome.cpp `
    src\modules\Composer.cpp `
    src\modules\Judge.cpp `
    src\modules\Referee.cpp `
    src\modules\Display.cpp `
    src\scenes\StartMenu.cpp `
    -Iinclude `
    -o BeatBreaker.exe `
    -lraylib -lopengl32 -lgdi32 -lwinmm `
    -O2 -s

if ($LASTEXITCODE -eq 0) {
    Write-Host "Release build successful!"
    
    # Create distribution folder
    if (Test-Path ".\dist") {
        Remove-Item ".\dist" -Recurse -Force
    }
    New-Item -ItemType Directory -Path ".\dist"
    
    Copy-Item "BeatBreaker.exe" ".\dist\"
    
    Copy-Item "C:\msys64\mingw64\bin\libraylib.dll" ".\dist\" -ErrorAction SilentlyContinue
    
    Copy-Item "assets" ".\dist\assets" -Recurse
    Copy-Item "levels" ".\dist\levels" -Recurse
    
    Write-Host "Distribution folder created at .\dist\"
    Write-Host "Zip this folder to share!"
} else {
    Write-Host "Build failed!"
}