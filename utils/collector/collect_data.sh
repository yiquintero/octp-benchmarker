#!/bin/bash

# path to simulation output files
sources=('../run_no_octp/' '../run_sd_o_tc_v_rdf/' '../run_sd_o/' '../run_viscosity/' '../run_rdf/' '../run_tc/')

# directories where collected data will be placed - must match order of sources
destinations=('octp_none' 'octp_all' 'octp_selfdiffusion_onsager' 'octp_viscosity' 'octp_rdf' 'octp_tc')

# number of particles
np=('512')

# number of time steps
nts=('100K' '500K')
ntsnum=(100000 500000)

# create destination directories
for dir in "${destinations[@]}"
do
    mkdir -p data/$dir
done

# collect simulation output data
it=0
itts=0
for dir in "${sources[@]}"
do

    for ts in "${nts[@]}"
    do
        # for i in 0 1 2 3 4 5 6 7 8 9
        for i in 0
        do
            origin=${dir}${np}p/${np}p_${ts}ts_16mpi_run${i}/slurm*
            dest=data/${destinations[$it]}/${np}_${ts}_${i}.txt

            touch $dest

            # add number of particles
            echo $np >> $dest

            # add number of time steps
            echo ${ntsnum[$itts]} >> $dest

            # collect memory
            tail -n 3 $origin | head -n 1 >> $dest

            # collect wall-clock
            tail -n 4 $origin | head -n 1 >> $dest

            # collect loop time
            tail -n 41 $origin | head -n 1 >> $dest

            # collect mpi
            tail -n 36 $origin | head -10 >> $dest
        done
        itts=$((itts+1))    
    done
    it=$((it+1))
    itts=$((0))
done