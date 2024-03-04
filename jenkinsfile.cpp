pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    echo 'Building the project...'
                    // Add commands or scripts for building your project
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    echo 'Running tests...'
                    // Add commands or scripts for running tests
                    // If a test fails, the pipeline will stop execution and proceed to post condition
                    // Example: sh 'make test'
                }
            }
        }

        stage('Deploy') {
            steps {
                script {
                    echo 'Deploying the application...'
                    // Add commands or scripts for deploying your application
                }
            }
        }
    }

    post {
        always {
            echo 'Post-condition: Display "pipeline failed" in case of any errors.'
        }

        failure {
            echo 'Pipeline failed!'
            // You can add additional actions to be performed in case of failure
            // For example, sending notifications, cleaning up resources, etc.
        }
    }
}
