# Paginate through all functions in range 0x400000-0x600000
# and collect addr + name pairs

$baseUrl = "http://127.0.0.1:53407"
$database = "ce268eb4"
$allFuncs = @()
$offset = 0
$batchSize = 500
$totalExpected = 19556

Write-Host "Starting pagination. Expected total: $totalExpected"

while ($offset -lt $totalExpected) {
    $body = @{
        jsonrpc = "2.0"
        method = "tools/call"
        params = @{
            name = "idalib__entity_query"
            arguments = @{
                database = $database
                queries = @(
                    @{
                        kind = "functions"
                        min_addr = "0x400000"
                        max_addr = "0x600000"
                        offset = $offset
                        count = $batchSize
                        sort_by = "addr"
                    }
                )
            }
        }
        id = 1
    } | ConvertTo-Json -Compress

    $response = Invoke-RestMethod -Uri "$baseUrl/mcp" -Method Post -Body $body -ContentType "application/json" -ErrorAction SilentlyContinue
    if (-not $response -or -not $response.result) {
        Write-Host "Error at offset $offset"
        break
    }

    $funcs = $response.result.content[0].text | ConvertFrom-Json
    $funcs = $funcs[0].data
    $allFuncs += $funcs
    $offset += $batchSize
    Write-Host "Collected $($allFuncs.Count) functions..."
}

$allFuncs | ConvertTo-Json | Out-File -FilePath "$PSScriptRoot\funcs_400000_600000.json" -Encoding utf8
Write-Host "Done! Total: $($allFuncs.Count) functions saved to funcs_400000_600000.json"
