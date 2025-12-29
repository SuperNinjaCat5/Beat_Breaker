g++ src\main.cpp `
    src\modules\MusicPlayer.cpp `
    src\modules\Metronome.cpp `
    src\modules\Composer.cpp `
    -Iinclude `
    -o app `
    -lraylib -lopengl32 -lgdi32 -lwinmm

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build successful! Running app..."
    .\app.exe
} else {
    Write-Host "Build failed!"
}
